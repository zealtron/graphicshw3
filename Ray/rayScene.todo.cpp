#include "rayScene.h"
#include <GL/glut.h>
#include <math.h>
#include <iostream>

using namespace std;

///////////////////////
// Ray-tracing stuff //
///////////////////////

Point3D RayScene::Reflect(Point3D v,Point3D n){
	return (n*-2*(v.unit().dot(n)))+v.unit();
}

int RayScene::Refract(Point3D v,Point3D n,double ir,Point3D& refract){
	return 0;
}

Ray3D RayScene::GetRay(RayCamera* camera,int i,int j,int width,int height){
	Ray3D r;
	r.position = camera->position;
	Point3D p;
	//cout << camera->direction.p[0] << " " << camera->direction.p[1] << " " << camera->direction.p[2] << " "; 
	
	//Y-axis, d=1
	Point3D py1 = r.position + camera->direction - camera->up*tan(camera->heightAngle);
	Point3D py2 = r.position + camera->direction + camera->up*tan(camera->heightAngle);

	//X-axis, d=1
	Point3D px1 = r.position + camera->direction - camera->right*tan(camera->heightAngle*camera->aspectRatio);
	Point3D px2 = r.position + camera->direction + camera->right*tan(camera->heightAngle*camera->aspectRatio);
	
	Point3D px = px1 + (px2-px1)*((i+0.5)/width) - r.position;
	Point3D py = py1 + (py2-py1)*((j+0.5)/height) - r.position;
	p = px + py;

	r.direction = p.unit();	
	//cout << "Position: " << camera->position.p[0] << " " << camera->position.p[1] << " " << camera->position.p[2] << "\n";
	//cout << p[0] << " " << p[1] << " " << p[2] << " ";
	
	return r;
}

Point3D RayScene::GetColor(Ray3D ray,int rDepth,Point3D cLimit){
	RayIntersectionInfo iInfo;
	double result = group->intersect(ray, iInfo, 0);
	//cout << result << " ";
	if(result > 0){
		//cout << result << " ";
		Point3D diffuse;
		Point3D specular;
		int isectcount;
		for(int i = 0; i < lightNum; i++){
			int shadow = lights[i]->isInShadow(iInfo, group, isectcount);
			if(shadow == 0){
				diffuse = diffuse + lights[i]->getDiffuse(ray.position, iInfo);	
				specular = specular + lights[i]->getSpecular(ray.position, iInfo);
			}	
		}
		Point3D color = iInfo.material->ambient + iInfo.material->emissive + diffuse + specular;
		return color;
	}else{ 
		return background;
	}
}

//////////////////
// OpenGL stuff //
//////////////////
void RayMaterial::drawOpenGL(void){
}
void RayTexture::setUpOpenGL(void){
}
