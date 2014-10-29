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
	double NdotL = max(iInfo.normal.negate().dot(direction),0.0);
	return iInfo.material->diffuse*NdotL*color;
}
Point3D RayDirectionalLight::getSpecular(Point3D cameraPosition,RayIntersectionInfo& iInfo){
	return Point3D();
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
