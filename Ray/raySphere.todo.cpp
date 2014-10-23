#include <math.h>
#include <GL/glut.h>
#include "rayScene.h"
#include "raySphere.h"
#include <iostream>
using namespace std;
////////////////////////
//  Ray-tracing stuff //
////////////////////////
double RaySphere::intersect(Ray3D ray,RayIntersectionInfo& iInfo,double mx){
	//set variables for quadratic formula
	double a = 1;
	// x direction
	double bx = 2*ray.direction.p[0]*(ray.position.p[0]-center.p[0]);
	double cx = pow(abs(ray.position.p[0]-center.p[0]),2)-pow(radius,2);
	// y direction
	double by = 2*ray.direction.p[1]*(ray.position.p[1]-center.p[1]);
	double cy = pow(abs(ray.position.p[1]-center.p[1]),2)-pow(radius,2);
	// z direction
	double bz = 2*ray.direction.p[2]*(ray.position.p[2]-center.p[2]);
	double cz = pow(abs(ray.position.p[2]-center.p[2]),2)-pow(radius,2);

	//perform quadratic -b +/- sqrt( b^2 - 4ac)
	double tx1 = (-bx+sqrt(pow(bx,2)-(4*a*cx)))/(2*a);
	double tx2 = (-bx-sqrt(pow(bx,2)-(4*a*cx)))/(2*a);

	double ty1 = (-by+sqrt(pow(by,2)-(4*a*cy)))/(2*a);
	double ty2 = (-by-sqrt(pow(by,2)-(4*a*cy)))/(2*a);

	double tz1 = (-bz+sqrt(pow(bz,2)-(4*a*cz)))/(2*a);
	double tz2 = (-bz-sqrt(pow(bz,2)-(4*a*cz)))/(2*a);

	cout << "tx: " << tx1 << " " << tx2 << "\n";
	cout << "ty: " << ty1 << " " << ty2 << "\n";
	cout << "tz: " << tz1 << " " << tz2 << "\n";
	return -1;
}
BoundingBox3D RaySphere::setBoundingBox(void){
	return bBox;
}

//////////////////
// OpenGL stuff //
//////////////////
int RaySphere::drawOpenGL(int materialIndex){
	return -1;
}
