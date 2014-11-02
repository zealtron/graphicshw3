#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "rayTriangle.h"
#include <iostream>
using namespace std;
////////////////////////
//  Ray-tracing stuff //
////////////////////////
Plane3D plane;

void RayTriangle::initialize(void){
	plane = Plane3D(v[0]->position,v[1]->position,v[2]->position);
}
double RayTriangle::intersect(Ray3D ray,RayIntersectionInfo& iInfo,double mx){
	//solve for t= -(p0 dot n + d) / (v dot n)
	double t = -(ray.position.dot(plane.normal) + plane.distance)/(ray.direction.dot(plane.normal));
	
	//set values for points for checking
	Point3D p = ray.position + ray.direction*t;
	Point3D v0 = v[0]->position - ray.position;
	Point3D v1 = v[1]->position - ray.position;
	Point3D v2 = v[2]->position - ray.position;

	//check side 0,1
	Point3D n01 = v1.crossProduct(v0);
	if((p - ray.position).dot(n01) < 0) return -1;
	//check side 0,2
	Point3D n02 = v0.crossProduct(v2);
	if((p - ray.position).dot(n02) < 0) return -1;
	//check side 1,2
	Point3D n12 = v2.crossProduct(v1);
	if((p - ray.position).dot(n12) < 0) return -1;
	
	RayIntersectionInfo& info = iInfo;
	info.iCoordinate = ray.position + ray.direction*t;
	info.normal = plane.normal.negate();
	info.material = material;
	
	return t;
}
BoundingBox3D RayTriangle::setBoundingBox(void){
	return bBox;
}

//////////////////
// OpenGL stuff //
//////////////////
int RayTriangle::drawOpenGL(int materialIndex){
	return -1;
}
