#include <math.h>
#include <GL/glut.h>
#include "rayScene.h"
#include "raySpotLight.h"


////////////////////////
//  Ray-tracing stuff //
////////////////////////
Point3D RaySpotLight::getDiffuse(Point3D cameraPosition,RayIntersectionInfo& iInfo){
	return Point3D();
}
Point3D RaySpotLight::getSpecular(Point3D cameraPosition,RayIntersectionInfo& iInfo){
	return Point3D();
}
int RaySpotLight::isInShadow(RayIntersectionInfo& iInfo,RayShape* shape,int& isectCount){
	return 0;
}
Point3D RaySpotLight::transparency(RayIntersectionInfo& iInfo,RayShape* shape,Point3D cLimit){
	return Point3D(1,1,1);
}

//////////////////
// OpenGL stuff //
//////////////////
void RaySpotLight::drawOpenGL(int index){
	GLfloat spot_direction[] = {direction.negate().p[0], direction.negate().p[1], direction.negate().p[2], 0.0};
	glLightf(GL_LIGHT0+index, GL_SPOT_CUTOFF, cutOffAngle);
	glLightfv(GL_LIGHT0+index, GL_SPOT_DIRECTION, spot_direction);
	GLfloat diffuse[] = {color.p[0], color.p[1], color.p[2]};
	glLightfv(GL_LIGHT0+index, GL_DIFFUSE, diffuse);
	glLightf(GL_LIGHT0+index, GL_CONSTANT_ATTENUATION, constAtten);
	glLightf(GL_LIGHT0+index, GL_LINEAR_ATTENUATION, linearAtten);
	glLightf(GL_LIGHT0+index, GL_QUADRATIC_ATTENUATION, quadAtten);	
	glEnable(GL_LIGHT0+index);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
}
