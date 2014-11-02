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
	RayIntersectionInfo decoyinfo;
	Ray3D localray = this->getInverseMatrix().mult(ray);	
	localray.direction = localray.direction.unit();
	double dst = 9999;
	double truedst;
	for(int i = 0; i < sNum; i++){
		double result = shapes[i]->intersect(localray, bestinfo, mx);
		if(result > 0){		
			truedst = (ray.position - this->getMatrix().multPosition(bestinfo.iCoordinate)).length();
			if(truedst < dst){
				dst = truedst;
				iInfo = bestinfo;
			}
		}
		/*if(result <= dst && result > 0){
			dst = result;
			iInfo = bestinfo;
		}*/
		//cout << shapes[i] << " ";
	}
	//cout << mx << " ";
	if(dst == 9999 || dst <= 0.0001){
		return -1;
	}else{
		iInfo.iCoordinate = this->getMatrix().multPosition(iInfo.iCoordinate); 
		iInfo.normal = (this->getNormalMatrix()*iInfo.normal.negate()).unit();
		return dst;
	}
}

BoundingBox3D RayGroup::setBoundingBox(void){
	return bBox;
}

int StaticRayGroup::set(void){
	inverseTransform = localTransform.invert();
	normalTransform = localTransform.invert().transpose();
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
