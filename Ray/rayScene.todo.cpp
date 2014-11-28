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
	return Ray3D();
}

Point3D RayScene::GetColor(Ray3D ray,int rDepth,Point3D cLimit){
	return Point3D();
}

//////////////////
// OpenGL stuff //
//////////////////
static GLuint texName;

void RayMaterial::drawOpenGL(void){		
	GLfloat amb[] = {ambient.p[0], ambient.p[1], ambient.p[2]};
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, amb);	
	GLfloat dif[] = {diffuse.p[0], diffuse.p[1], diffuse.p[2]};
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, dif);
	GLfloat em[] = {emissive.p[0], emissive.p[1], emissive.p[2]};
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, em);
	GLfloat spec[] = {specular.p[0], specular.p[1], specular.p[2]};
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec);
	GLfloat shin[] = {specularFallOff};
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shin);	
	//cout << diffuse.p[0] << " " << diffuse.p[1] << " " << diffuse.p[2] << "\n";
}
void RayTexture::setUpOpenGL(void){
	glGenTextures(1, &openGLHandle);
	glBindTexture(GL_TEXTURE_2D, openGLHandle);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);	
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);	
	GLvoid *image = (GLvoid *)(&img->pixel(0,0));
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img->width(), img->height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
}
