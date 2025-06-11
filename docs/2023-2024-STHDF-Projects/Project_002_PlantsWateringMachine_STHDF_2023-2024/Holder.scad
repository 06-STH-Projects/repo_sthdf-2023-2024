cylinder_radius = 35;
cylinder_height = 10;
union () {
    difference() {
        cylinder( r = cylinder_radius, h = cylinder_height);
        translate([0,0,-4])
        cylinder( r = cylinder_radius-5, h = cylinder_height+2);
        translate([0,0,1])
        cylinder( r = cylinder_radius-10, h = cylinder_height+5);
    }
    //legs
    translate([cylinder_radius-3,0,0])
        cylinder(r1=2, r2=0.5, h=100);
    translate([-cylinder_radius+3,0,0])
        cylinder(r1=2, r2=0.5, h=100);
    translate([0,cylinder_radius-3,0])
        cylinder(r1=2, r2=0.5, h=100);
    translate([0,-cylinder_radius+3,0])
        cylinder(r1=2, r2=0.5, h=100);
}