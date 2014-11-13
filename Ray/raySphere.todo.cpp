#include <math.h>
#include <GL/glut.h>
#include "rayScene.h"
#include "raySphere.h"

////////////////////////
//  Ray-tracing stuff //
////////////////////////
double RaySphere::intersect(Ray3D ray,RayIntersectionInfo& iInfo,double mx){
	return -1;
}
BoundingBox3D RaySphere::setBoundingBox(void){
	Point3D p=Point3D(radius,radius,radius);
	bBox=BoundingBox3D(center+p,center-p);
	return bBox;
}

//////////////////
// OpenGL stuff //
//////////////////
int RaySphere::drawOpenGL(int materialIndex){
	GLUquadricObj *obj = gluNewQuadric();
	gluSphere(obj, radius, openGLComplexity, openGLComplexity);
	glTranslatef(center.p[0], center.p[1], center.p[2]);
	material->drawOpenGL();
	return -1;
}
