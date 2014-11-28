#include <math.h>
#include <GL/glut.h>
#include "rayDirectionalLight.h"
#include "rayScene.h"

////////////////////////
//  Ray-tracing stuff //
////////////////////////
Point3D RayDirectionalLight::getDiffuse(Point3D cameraPosition,RayIntersectionInfo& iInfo){
	return Point3D();
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
	GLfloat light_position[] = {direction.negate().p[0], direction.negate().p[1], direction.negate().p[2], 0.0};
	glLightfv(GL_LIGHT0+index, GL_POSITION, light_position);
	//GLfloat ambient[] = {ambient.p[0], ambient.p[1], ambient.p[2]};
	//glLightfv(GL_LIGHT0+index, GL_AMBIENT, ambient);
	GLfloat diffuse[] = {color.p[0], color.p[1], color.p[2]};
	glLightfv(GL_LIGHT0+index, GL_DIFFUSE, diffuse);
	glEnable(GL_LIGHT0+index);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
}
