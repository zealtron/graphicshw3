#include <math.h>
#include <GL/glut.h>
#include "rayPointLight.h"
#include "rayScene.h"

////////////////////////
//  Ray-tracing stuff //
////////////////////////
Point3D RayPointLight::getDiffuse(Point3D cameraPosition,RayIntersectionInfo& iInfo){
	return Point3D();
}
Point3D RayPointLight::getSpecular(Point3D cameraPosition,RayIntersectionInfo& iInfo){
	return Point3D();
}
int RayPointLight::isInShadow(RayIntersectionInfo& iInfo,RayShape* shape,int& isectCount){
	return 0;
}
Point3D RayPointLight::transparency(RayIntersectionInfo& iInfo,RayShape* shape,Point3D cLimit){
	return Point3D(1,1,1);
}


//////////////////
// OpenGL stuff //
//////////////////
void RayPointLight::drawOpenGL(int index){
	GLfloat light_position[] = {location[0], location[1], location[2], 1};	
	glLightfv(GL_LIGHT0+index, GL_POSITION, light_position);
	GLfloat diffuse[] = {color.p[0], color.p[1], color.p[2]};
	glLightfv(GL_LIGHT0+index, GL_DIFFUSE, diffuse);
	glLightf(GL_LIGHT0+index, GL_CONSTANT_ATTENUATION, constAtten);
	glLightf(GL_LIGHT0+index, GL_LINEAR_ATTENUATION, linearAtten);
	glLightf(GL_LIGHT0+index, GL_QUADRATIC_ATTENUATION, quadAtten);	
	glEnable(GL_LIGHT0+index);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
}
