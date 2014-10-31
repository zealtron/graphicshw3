#include <stdlib.h>
#include <GL/glut.h>
#include "rayGroup.h"
#include <iostream>
using namespace std;
////////////////////////
//  Ray-tracing stuff //
////////////////////////
double RayGroup::intersect(Ray3D ray,RayIntersectionInfo& iInfo,double mx){	
	RayIntersectionInfo bestinfo;
	double dst = 9999;
	for(int i = 0; i < sNum; i++){
		double result = shapes[i]->intersect(ray, bestinfo, mx);	
		if(result < dst && result > 0){
			dst = result;
			iInfo = bestinfo;
		}
		//cout << shapes[i] << " ";
	}
	//cout << mx << " ";
	if(dst == 9999 || dst <= 0.0001){
		return -1;
	}else{
		return dst;
	}
}

BoundingBox3D RayGroup::setBoundingBox(void){
	return bBox;
}

int StaticRayGroup::set(void){
	return 1;
}
//////////////////
// OpenGL stuff //
//////////////////
int RayGroup::getOpenGLCallList(void){
	return 0;
}

int RayGroup::drawOpenGL(int materialIndex){
	return -1;
}

/////////////////////
// Animation Stuff //
/////////////////////
Matrix4D ParametrizedEulerAnglesAndTranslation::getMatrix(void){
	return Matrix4D::IdentityMatrix();
}
Matrix4D ParametrizedClosestRotationAndTranslation::getMatrix(void){
	return Matrix4D::IdentityMatrix();
}
Matrix4D ParametrizedRotationLogarithmAndTranslation::getMatrix(void){
	return Matrix4D::IdentityMatrix();
}
Matrix4D ParametrizedQuaternionAndTranslation::getMatrix(void){
	return Matrix4D::IdentityMatrix();
}
