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
	double b = (ray.direction*2).dot(ray.position-center);
	double c = (ray.position-center).squareNorm()-pow(radius,2);

	//perform quadratic -b +/- sqrt( b^2 - 4ac)
	double d = pow(b,2)-(4*a*c);
	if(d < 0) return -1;
	double t1 = (-b+sqrt(pow(b,2)-(4*a*c)))/(2*a);
	double t2 = (-b-sqrt(pow(b,2)-(4*a*c)))/(2*a);
	
	if(t1 < 0 && t2 < 0) return -1;
	if(t1 < 0) t1 = 999999;
	if(t2 < 0) t2 = 999999;

	double t = min(t1,t2);

	RayIntersectionInfo& info = iInfo;
	info.material = material;	
	info.iCoordinate = ray.position + ray.direction*t;
	info.normal = (info.iCoordinate-center).unit();
	
	//cout << material->emissive.p[0] << " " << material->emissive.p[1] << " " << material->emissive.p[2] << " ";
	//cout << t << " ";
	return t;
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
