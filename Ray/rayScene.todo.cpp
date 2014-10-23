#include "rayScene.h"
#include <GL/glut.h>
#include <math.h>
#include <iostream>

using namespace std;

///////////////////////
// Ray-tracing stuff //
///////////////////////

Point3D RayScene::Reflect(Point3D v,Point3D n){
	return Point3D();
}

int RayScene::Refract(Point3D v,Point3D n,double ir,Point3D& refract){
	return 0;
}

Ray3D RayScene::GetRay(RayCamera* camera,int i,int j,int width,int height){
	Ray3D r;
	r.position = camera->position;
	Point3D p;
	//cout << camera->direction.p[0] << " " << camera->direction.p[1] << " " << camera->direction.p[2] << " "; 
	
	//Y-axis, d=100
	double py1 = r.position.p[1] + 100*camera->direction.p[1] - 100*tan(camera->heightAngle)*camera->up.p[1];
	double py2 = r.position.p[1] + 100*camera->direction.p[1] + 100*tan(camera->heightAngle)*camera->up.p[1];
	
	p[1] = py1 + ((j+0.5)/height)*(py2-py1);

	//X-axis, d=100
	double px1 = r.position.p[0] + 100*camera->direction.p[0] - 100*tan(camera->heightAngle)*camera->right.p[0];
	double px2 = r.position.p[0] + 100*camera->direction.p[0] + 100*tan(camera->heightAngle)*camera->right.p[0];

	p[0] = px1 + ((i+0.5)/width)*(px2-px1);
	
	p[2] = 100;	

	//cout << p[0] << " " << p[1] << " " << p[2] << " ";
	
	return r;
}

Point3D RayScene::GetColor(Ray3D ray,int rDepth,Point3D cLimit){
	return Point3D();
}

//////////////////
// OpenGL stuff //
//////////////////
void RayMaterial::drawOpenGL(void){
}
void RayTexture::setUpOpenGL(void){
}
