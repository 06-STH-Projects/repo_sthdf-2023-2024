#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <ESP32Servo.h>
#include <cmath>
#include <math.h>


const char *ssid = "ssid";
const char *password = "topsecretpassword";

AsyncWebServer server(80);
Servo rotor;
Servo tilt;

// Global variables to be set via web interface
double longitude = 0;
double latitude = 0;
String timestamp = "";
double doy = 0;
double hours, minutes = 0;
double zenith = 0;
double timezone = 0;

double rotorPosition = 0;
double tiltPosition = 0;

double azimuth, declination, elevation = 0;

String msg_error = "";

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Define web server routes
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    String html = "<html><body>";
    html += "<h1>Solar Tracker</h1>";
    html += "<form action='/set-variables' method='get'>";
    html += "Longitude: <input type='number' name='longitude' value='" + String(longitude) + "'><br>"; // longtitude
    html += "Day of year : <input type='number' name='doy' value='" + String(doy) + "'><br>";          // day of year
    html += "Timezone: <input type='number' name='timezone' value='" + String(timezone) + "'><br>";    // timezone
    html += "Latitude (theta) : <input max='89' min='-89' name='latitude' step='0.1' type='number' value='" + String(latitude)  + "'><br>";  // latitude 
    html += "Local Time (hh:mm) : <input type='text' name='timestamp' value='" + String(timestamp) + "'><br>";  // local time
    html += "<input type='submit' value='Set Variables'>";
    html += "</form>";
    html += "</body></html>";
    request->send(200, "text/html", html);
  });

  server.on("/set-variables", HTTP_GET, [](AsyncWebServerRequest *request){
    // Update global variables based on form submission
    bool validFormat = request->hasParam("latitude") &&
                       request->hasParam("longitude") &&
                       request->hasParam("timezone") && 
                       request->hasParam("timestamp") &&
                       request->hasParam("doy");
    
    if (validFormat) {
      latitude = request->getParam("latitude")->value().toDouble();
      longitude = request->getParam("longitude")->value().toDouble();
      timestamp =  request->getParam("timestamp")->value();
      doy = request->getParam("doy")->value().toDouble();
      timezone = request->getParam("timezone")->value().toDouble();

      hours = timestamp.substring(0, 2).toDouble();
      minutes = timestamp.substring(3, 5).toDouble();
    
      Serial.println("Global variables updated");
    

      // Calculate sun position
      calculateAngles();
      updateServoPosition();
      
    } else {
      msg_error = "Error: invalid parameters";
    }
    
    request->redirect("/");
  });

  // Start server
  server.begin();


  // Servo setup
  rotor.attach(2);  // GPIO pin 2
  tilt.attach(16);  // GPIO pin 16
  
  rotor.write(0); // Point to the North
  tilt.write(90); // Make sure that it is in vertical position
}

void loop() {
  // Handle other tasks

  calculateAngles();
  updateServoPosition();

  Serial.println(timestamp);
  delay(56000); // Wait (56 + 4) seconds between readjusting. In production solutions, greater value is needed.

    ++ minutes;
    // Recalculate time based on delay (now aat 1 min)
    if (minutes + 1 >= 60) {
      minutes = minutes - 60;
      ++hours;

      if (hours >= 24) {
        hours -= 24;
        doy++;

        if (doy >= 365) {
          day-= 665;
        }
      }

    }
}

double toRad(double degrees) {
    return degrees * (M_PI / 180.0);
}

double toDeg(double radians) {
    return radians * (180.0 / M_PI);
}

double hours_num(double hours, double minutes) {
    return hours + (minutes/60);
}

void calculateAngles() {
  // See calculations in https://www.pveducation.org/pvcdrom/properties-of-sunlight/the-suns-position

  double lstm = 15. * (timezone); // Local Standard Time Meridian
  double b = (360./365.) * (doy - 81.);
  double eot = 9.87*sin(toRad(2*b)) - 7.53*cos(toRad(b)) - 1.5*sin(toRad(b)); // IN MINUTES // Equation of Time
 
  double tc = 4*(longitude - lstm ) + eot; // Time Correction Factor
  double lst = (hours + (minutes/60.)) + (tc/60.); // IN MINUTES // Local Solar Time
  double hra = 15.*(lst - 12.);// Hour Angle
 
  declination = toRad(23.45)*sin(toRad(b));
  elevation = asin(sin(declination)*sin(toRad(latitude)) + cos(declination)*cos(toRad(latitude))*cos(toRad(hra)));
  azimuth = acos((sin(declination)*cos(toRad(latitude)) - cos(declination)*sin(toRad(latitude))*cos(toRad(hra)))/cos(elevation));
 
  // Fix azimuth
  if (lst > 12. || hra > 0) {
     azimuth = 360. - toDeg(azimuth); // converts to deg
  } else {
     azimuth = toDeg(azimuth);
  }

  // Convert to degree
  elevation = toDeg(elevation);
  declination = toDeg(declination);  
  zenith = 90. - elevation;
  
  
  return;
}

void updateServoPosition() {
  rotorPosition = constrain(rotorPosition, 0, 180);
  tiltPosition = constrain(tiltPosition, 0, 180); 
  
  Serial.printf("Zenith: %.2f, Azimuth: %.2f, Elevation: %.2f, Declination: %.2f [deg] \n", zenith, azimuth, elevation, declination);

  rotorPosition = azimuth > 180 ? azimuth - 180 : azimuth;
  tiltPosition = azimuth > 180 ? 90 - declination : 90 + declination;

  Serial.printf("Rotor angle %.1f, tilt angle %.1f", rotorPosition, tiltPosition);
  // Set the servo position
  rotor.write(rotorPosition);
  delay(2000); 
  tilt.write(tiltPosition);
  delay(2000); // Give the servo time to move (adjust as needed)
}
