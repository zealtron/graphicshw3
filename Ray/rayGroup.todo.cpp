#include <stdlib.h>
#ifdef __APPLE__
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif
#include "rayGroup.h"

using namespace std;
////////////////////////
//  Ray-tracing stuff //
////////////////////////
double RayGroup::intersect(Ray3D ray,RayIntersectionInfo& iInfo,double mx){
	double minDistance = mx;

	for (int i = 0; i < sNum; i++) {
		double distance = shapes[i]->intersect(ray, iInfo, minDistance);
		if (distance >= 0) {
			minDistance = distance;
		}
	}

	return minDistance;
}

BoundingBox3D RayGroup::setBoundingBox(void){
	Point3D* pList;
	BoundingBox3D tBBox;
	pList=new Point3D[sNum*2];
	for(int i=0;i<sNum;i++){
		tBBox=shapes[i]->setBoundingBox();
		pList[2*i  ]=tBBox.p[0];
		pList[2*i+1]=tBBox.p[1];
	}
	tBBox=BoundingBox3D(pList,sNum*2);

	delete[] pList;
	bBox=tBBox.transform(getMatrix());
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
	glMatrixMode(GL_MODELVIEW);	
	Matrix4D m = getMatrix();
	GLdouble matrix[16] = {
		m(0,0), m(0,1), m(0,2), m(0,3),
		m(1,0), m(1,1), m(1,2), m(1,3),
		m(2,0), m(2,1), m(2,2), m(2,3),
		m(3,0), m(3,1), m(3,2), m(3,3)
	};
	glPushMatrix();
	glMultMatrixd(matrix);
	for (int i = 0; i < sNum; i++) {
		int distance = shapes[i]->drawOpenGL(materialIndex);
	}
	glPopMatrix();
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
