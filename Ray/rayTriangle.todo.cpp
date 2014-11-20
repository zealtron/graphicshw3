#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "rayTriangle.h"

////////////////////////
//  Ray-tracing stuff //
////////////////////////
void RayTriangle::initialize(void){		
}
double RayTriangle::intersect(Ray3D ray,RayIntersectionInfo& iInfo,double mx){
	return -1;
}
BoundingBox3D RayTriangle::setBoundingBox(void){
	Point3D pList[3];
	pList[0]=v[0]->position;
	pList[1]=v[1]->position;
	pList[2]=v[2]->position;
	bBox=BoundingBox3D(pList,3);
	for(int i=0;i<3;i++){
		bBox.p[0][i]-=RAYEPS;
		bBox.p[1][i]+=RAYEPS;
	}
	return bBox;
}

//////////////////
// OpenGL stuff //
//////////////////
int RayTriangle::drawOpenGL(int materialIndex){	
	material->drawOpenGL(); 
	glBegin(GL_TRIANGLES);	
		glVertex3f(v[0]->position.p[0], v[0]->position.p[1], v[0]->position.p[2]);		
		glVertex3f(v[1]->position.p[0], v[1]->position.p[1], v[1]->position.p[2]);	
		glVertex3f(v[2]->position.p[0], v[2]->position.p[1], v[2]->position.p[2]);	
	glEnd();
	return -1;
}
