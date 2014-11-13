#include "rayScene.h"
#include <GL/glut.h>
#include <math.h>


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
	return Ray3D();
}

Point3D RayScene::GetColor(Ray3D ray,int rDepth,Point3D cLimit){
	return Point3D();
}

//////////////////
// OpenGL stuff //
//////////////////
void RayMaterial::drawOpenGL(void){
	float amb [3] = {ambient.p[0], ambient.p[1], ambient.p[2]};
	glMaterialfv(GL_FRONT, GL_AMBIENT, amb);
	float dif [3] = {diffuse.p[0], diffuse.p[1], diffuse.p[2]};
	glMaterialfv(GL_FRONT, GL_DIFFUSE, dif);
	float em [3] = {emissive.p[0], emissive.p[1], emissive.p[2]};
	glMaterialfv(GL_FRONT, GL_EMISSION, em);
	float spec [3] = {specular.p[0], specular.p[1], specular.p[2]};
	glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
	float shin [1] = {specularFallOff};
	glMaterialfv(GL_FRONT, GL_SHININESS, shin);
}
void RayTexture::setUpOpenGL(void){
}
