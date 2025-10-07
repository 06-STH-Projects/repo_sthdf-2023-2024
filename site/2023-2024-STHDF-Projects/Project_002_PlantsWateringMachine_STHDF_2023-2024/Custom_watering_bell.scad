// Parameters
hole_radius = 1;
thickness = 3;
hole_depth = thickness+2;
cylinder1_radius1 = 30;
cylinder1_radius2 = 12;
cylinder1_height = 20;
cylinder2_radius1 = cylinder1_radius1-thickness*2;
cylinder2_radius2 = cylinder1_radius2-thickness;
cylinder2_height = cylinder1_height-thickness*2;
handle_radius = 3;
handle_height = 10;
union(){
    //cylinder
    difference() {
        cylinder( r1 = cylinder1_radius1, r2 = cylinder1_radius2, h = cylinder1_height);
        translate([0,0,thickness])
        cylinder( r1 = cylinder2_radius1, r2 = cylinder2_radius2, h = cylinder2_height);
        
        //hole for handle
        translate([0, 0, cylinder1_height-hole_depth-1])
            cylinder(h = hole_depth+handle_height+1, r = handle_radius);
        
        //holes
        translate([0,0,-1])
            cylinder(r = hole_radius, h = hole_depth);
        
        translate([-15,0,-1])
            cylinder(r = hole_radius, h = hole_depth);
        translate([-5,0,-1])
            cylinder(r = hole_radius, h = hole_depth);
        translate([5,0,-1])
            cylinder(r = hole_radius, h = hole_depth);
        translate([15,0,-1])
            cylinder(r = hole_radius, h = hole_depth);
        
        translate([0,5,-1])
            cylinder(r = hole_radius, h = hole_depth);
        translate([0,15,-1])
            cylinder(r = hole_radius, h = hole_depth);
        translate([0,-5,-1])
            cylinder(r = hole_radius, h = hole_depth);
        translate([0,-15,-1])
            cylinder(r = hole_radius, h = hole_depth);
        }
    //handle
    difference() {
        translate([0, 0, cylinder2_height+thickness])
            cylinder(h = handle_height+thickness+3, r = handle_radius);
        translate([0, 0, cylinder2_height+thickness-1])
            cylinder(h = handle_height+thickness+5, r = handle_radius-1);
    }
}