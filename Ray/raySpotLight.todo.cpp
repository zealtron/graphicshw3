#include <math.h>
#include <GL/glut.h>
#include "rayScene.h"
#include "raySpotLight.h"
#include <iostream>
using namespace std;
////////////////////////
//  Ray-tracing stuff //
////////////////////////
Point3D RaySpotLight::getDiffuse(Point3D cameraPosition,RayIntersectionInfo& iInfo){
	Point3D d = iInfo.iCoordinate - location;	
	if(direction.dot(d.unit()) < cos(cutOffAngle)){
		Point3D I = (color*pow(direction.dot(d.unit()),dropOffRate))/(constAtten + linearAtten*d.length() + quadAtten*pow(d.length(),2));
		double NdotL = max(iInfo.normal.dot(d.unit().negate()),0.0);
		return iInfo.material->diffuse*NdotL*I;
	}else{
		return Point3D();
	}
}
Point3D RaySpotLight::getSpecular(Point3D cameraPosition,RayIntersectionInfo& iInfo){	
	Point3D d = iInfo.iCoordinate - location;	
	if(direction.dot(d.unit()) < cos(cutOffAngle)){	
		Point3D I = (color*pow(direction.dot(d.unit()),dropOffRate))/(constAtten + linearAtten*d.length() + quadAtten*pow(d.length(),2));
		Point3D V = (cameraPosition-iInfo.iCoordinate).unit();	
		Point3D R = (iInfo.normal*-2*(d.unit().dot(iInfo.normal)))+d.unit();
		double VdotR = V.dot(R);
		if(VdotR > 0){
			return iInfo.material->specular*pow(VdotR,iInfo.material->specularFallOff)*I;
		}else{
			return Point3D();
		}
	}else{
		return Point3D();
	}	
}
int RaySpotLight::isInShadow(RayIntersectionInfo& iInfo,RayShape* shape,int& isectCount){
	RayIntersectionInfo info;
	Ray3D ray;
	ray.position = iInfo.iCoordinate;
	ray.direction = (iInfo.iCoordinate - location).unit().negate();	
	double result = shape->intersect(ray, info, 0);
	if(result > 0) return 1;
	return 0;
}
Point3D RaySpotLight::transparency(RayIntersectionInfo& iInfo,RayShape* shape,Point3D cLimit){
	return Point3D(1,1,1);
}

//////////////////
// OpenGL stuff //
//////////////////
void RaySpotLight::drawOpenGL(int index){
}
