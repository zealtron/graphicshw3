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
	double b = 2*ray.direction.p*(ray.position.p-center.p);
	double c = pow(abs(ray.position.p-center.p),2)-pow(radius,2);

	//perform quadratic -b +/- sqrt( b^2 - 4ac)
	double t1 = (-b+sqrt(pow(b,2)-(4*a*c)))/(2*a);
	double t2 = (-b-sqrt(pow(b,2)-(4*a*c)))/(2*a);

	//cout << "tx: " << tx1 << " " << tx2 << "\n";
	//cout << "ty: " << ty1 << " " << ty2 << "\n";
	//cout << "tz: " << tz1 << " " << tz2 << "\n";
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
