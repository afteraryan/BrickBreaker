#pragma once
#include<gl/glut.h>

struct Location
{
	GLfloat x, y;
};

struct Scale
{
	GLfloat x, y;
};

struct Rotation
{
	GLfloat x, y;
};

struct Transform
{
	Location location;
	Scale scale;
	Rotation rotation;
};

struct Color
{
	GLfloat R, G, B;
};

struct Velocity
{
	GLfloat x, y;
};

/*void initTransform(Transform* t)
{
	t->location.x = 0;
	t->location.y = 0;
	t->rotation.x = 0;
	t->rotation.y = 0;
	t->scale.x = 1;
	t->scale.y = 1;
}*/


class EngineUtilities
{
	
};

