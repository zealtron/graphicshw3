#include <GL/glut.h>
#include <math.h>
#include "rayCamera.h"



//////////////////
// OpenGL stuff //
//////////////////
void RayCamera::drawOpenGL(void){
	gluLookAt(position.p[0], position.p[1], position.p[2], direction.p[0], direction.p[1], direction.p[2], up.p[0], up.p[1], up.p[2]);
}
void RayCamera::rotateUp(Point3D center,float angle){
	Point3D k = (center-position).unit();
	direction = direction*cos(angle*PI/180) + (k.crossProduct(direction))*sin(angle*PI/180) + k*(k.dot(direction))*(1-cos(angle*PI/180));	
}
void RayCamera::rotateRight(Point3D center,float angle){	
	Point3D k = (center-position).unit();	
	up = up*cos(angle*PI/180) + (k.crossProduct(up))*sin(angle*PI/180) + k*(k.dot(up))*(1-cos(angle*PI/180));	
}
void RayCamera::moveForward(float dist){
}
void RayCamera::moveRight(float dist){
}
void RayCamera::moveUp(float dist){
}
