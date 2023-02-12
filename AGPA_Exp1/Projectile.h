#include "Actor.h"
#pragma once


class Projectile: public Actor
{
	GLfloat height, width;
	struct Vertex
	{
		GLfloat x, y;
	};

public:
	Vertex TL, BR;

	Projectile(GLfloat, GLfloat);
	void drawPolygon(Location);

	GLfloat getWidth();
	GLfloat getHeight();

};

