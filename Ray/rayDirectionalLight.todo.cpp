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
	Point3D R = (iInfo.normal*2*(iInfo.normal.dot(direction)))-direction;
	double VdotR = pow((V.dot(R)),iInfo.material->specularFallOff);
	return iInfo.material->specular*VdotR*color;
}
int RayDirectionalLight::isInShadow(RayIntersectionInfo& iInfo,RayShape* shape,int& isectCount){
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
