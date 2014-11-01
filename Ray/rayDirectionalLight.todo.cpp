#include <math.h>
#include <GL/glut.h>
#include "rayDirectionalLight.h"
#include "rayScene.h"
#include <iostream>
using namespace std;
////////////////////////
//  Ray-tracing stuff //
////////////////////////
Point3D RayDirectionalLight::getDiffuse(Point3D cameraPosition,RayIntersectionInfo& iInfo){	
	double NdotL = max(iInfo.normal.dot(direction.negate()),0.0);
	return iInfo.material->diffuse*NdotL*color;
}
Point3D RayDirectionalLight::getSpecular(Point3D cameraPosition,RayIntersectionInfo& iInfo){
	Point3D V = (cameraPosition-iInfo.iCoordinate).unit();	
	Point3D R = (iInfo.normal*-2*(direction.unit().dot(iInfo.normal)))+direction.unit();
	double VdotR = V.dot(R);
	if(VdotR > 0){
		return iInfo.material->specular*pow(VdotR,iInfo.material->specularFallOff)*color;
	}else{
		return Point3D();
	}
}
int RayDirectionalLight::isInShadow(RayIntersectionInfo& iInfo,RayShape* shape,int& isectCount){
	RayIntersectionInfo info;
	Ray3D ray;
	ray.position = iInfo.iCoordinate;
	ray.direction = direction.negate();
	double result = shape->intersect(ray, info, 0);
	if(result > 0) return 1;
	return 0;
}
Point3D RayDirectionalLight::transparency(RayIntersectionInfo& iInfo,RayShape* shape,Point3D cLimit){
	return Point3D(1,1,1);
}

//////////////////
// OpenGL stuff //
//////////////////
void RayDirectionalLight::drawOpenGL(int index){
}
