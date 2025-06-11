Author: Patrik Heglas


![title](./assets/title.jpeg)


## Motivation

IoT (Internet of Things) domain is getting bigger day by day and it brings many obstacles to overcome. One of which is energy consumption. IoT devices often need external source of power which can be quickly depleted if a device is not operating efficiently. In our case, this can be achieved by optimized recharging. E.g. IoT sensors may be placed in hard to reach places. If we want to avoid changing battery too often, we may incorporate solution to recharge battery. One of which is solar recharging.

Motivation for this project was my diploma thesis which also aims for efficient IoT solution. The goal of this project is to provide solution for efficient power management.

* solar farms: land optimization, eco friendliness, cost efficiency, charge efficiency

* regular user: low maintenance, increase charge efficiency


![business diagram](./assets/business_diag.png)

## Overall goal

> Create simple solution to enhance solar recharging capabilities.

## Value proposition

* energy efficiency

* cost saving

* sustainability

## Resources

solar panels, sun position tracking system, energy storage management*, data analytics tools*, positional system

## Stakeholders

utility companies, solar farms, government authorities, research teams

## Basic procedure

During the final stages of business analysis a basic solar tracking procedure was established. Separate steps are represented in the list below:

1. Customer buys the system.

2. Customer starts the tracker.

3. Customer sets-up tracker (geolocation) by provided interface.

4. Customer connects battery to charge (or other appliance)



## System components

This part represents all system components used to build final product. It consist of two servos providing two-axis rotation capabilities and controller handling movements and user interactions. Solution also provides web interface to configure the position of tracker.

 

ESP32 WROOM - microcontroller responsible for calculations and servo handling. It is also capable of running web server which is used as user interface.


![esp32](./assets/comp_esp32.png)


Servo - system consist of two servos providing two-axis rotation capability. The first servo rotates whole platform in 360 degrees and the second is connected to the platform, providing 180 deg. tilt.


![servo](./assets/comp_servo.png)


Platform - component is a part of the assembly and holds attached solar panel


![platform](./assets/comp_platform.jpeg)


Web interface - web interface component provides easy to use way to setup tracker based on desired geolocation.

![interface](./assets/comp_interface.png)

Architecture diagram below shows system components. On the left side we can find whole assembly which is rotated by two servos (two-axis). On the right side you can find the core of the tracker. ESP32 controller is responsible for position calculations and provides web interface for user to use.


![architecture diagram](./assets/architecture_diagram.png)


## Design stages

In the first stages we were looking for the most suitable solution. It all started with system sketches.


### Firs system sketch

![proto1](./assets/design_proto1.jpeg)



### Web interface wireframe

![wireframe](./assets/des_wireframe.jpeg)



## Assembly with photoresistors

![proto2](./assets/proto2.jpegla)

The second prototype considered only software computation to guide platform rotation. This solution required less components than previous one and was easier and cheaper to implement. As for the structure itself, the model was available online. We just applied small scaling changes to save on material.

The construction consist of the bottom base, top base, arm and platform. Bottom base holds 180 deg. servo that rotates top base according to an azimuth calculated by computational unit. Arm is attached to the top base and provide declination.



## Second and final prototype

![last prototype](./assets/last_proto.jpeg)

## Implementation

There are already many existing open source solutions. In our case we found the most suitable one and changed it a bit to suit our use case. 

Model was imported to Prusa slicer where we can arrange all components to be printed in one run on Prusa i3 MK3S+ printer.



![3d model](./assets/implementation_model.png)



The second part of implementation was to code the logic. We programmed the angle calculations based on formulas. https://www.pveducation.org/pvcdrom/properties-of-sunlight/the-suns-position 





### Web interface

![web](./assets/implementation_web.png)



### Angle calculation visualization

![output](./assets/implementation_debug.png)


After coding phase we moved to building the system rotational platform.

![scheme](./assets/imp_scheme.png)

Hardvare wiring schema

![platfomr](./assets/imp_platform.jpeg)

Platform assembly



The diagram below shows used technologies throughout the project. In consist of controller, servos and the rotating platform. 


![technical diagram](./assets/technical_diagram.png)


## Used tools

During the work on the project i came across many tools first of which is Prusa slicer. This tool even helped me to edit stencils.

![prusa slicer](./assets/used_tools_prusa.png)


The next set of tools is bitbucket, soruce tree and git. I use git regularly so the command line interface was no news for me.


![prusa slicer](./assets/used_tools_git.png)


Very helpful graphical tool, even for everyday use, is Drawio.


![prusa slicer](./assets/used_tools_drawio.png)


And last but not least, Confluence.  :)



## Lessons learned

* 3D printing

* Bitbucket

* Programming servos

* Sun position calculations  

* many more valuable lessons