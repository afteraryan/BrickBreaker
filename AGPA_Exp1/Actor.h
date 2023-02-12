#pragma once
#include<gl/glut.h>
#include <string>
#include "EngineUtilities.h"
#include <vector>

class Actor
{	
	//Identity
	std::string tag;
	std::string getTag();
	std::vector<GLfloat> vertices;
	Velocity velocity = {0,0};
	Location minBounds;
	Location maxBounds;
public:
	bool canRender = true;
	bool canCollide = true;
	Color color;
	Actor();

	

	//Collision
	Actor *collidingActor;

	
	//Transform
	Transform transform;
	Location Origin;
	void setLocation(GLfloat x, GLfloat y);
	void setRotation(GLfloat x, GLfloat y);
	void setScale(GLfloat x, GLfloat y);
	void setOrigin(GLfloat x, GLfloat y);
	void setTag(std::string tagStr);
	void setColor(GLfloat R, GLfloat G, GLfloat B);
	void Move(Location);
	void setVelocity(GLfloat, GLfloat);
	Location getLocation();
	Location getOrigin();
	Rotation getRotation();
	Scale getScale();
	Velocity getVelocity();

	//Rendering
	virtual void drawPolygon(GLfloat, GLfloat);

	

	//Self-Fucntions
	void destroy();

};

