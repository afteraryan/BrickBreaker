#include "Actor.h"
#include "Projectile.h"
#pragma once
class Platform: public Actor
{
	GLfloat height, width;
	struct Vertex
	{
		GLfloat x, y;
	};

public:
	typedef Actor super;
	Vertex TL, BR;
	Platform(GLfloat, GLfloat);
	void drawPolygon(Location);
	GLfloat getWidth();
	GLfloat getHeight();

	void setDimentions(GLfloat h, GLfloat w);
	bool CollisionCheck(Projectile* P);
};

