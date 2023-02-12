#include "Actor.h"
#include "Projectile.h"
#include "Platform.h"
#include "EngineUtilities.h"
#pragma once
class Brick : public Actor
{
	GLfloat height, width;
	struct Vertex
	{
		GLfloat x, y;
	};
	char BrickType;
public:
	Vertex TL, BR;
	void drawPolygon(Location);
	GLfloat getWidth();
	GLfloat getHeight();

	void setDimentions(GLfloat h, GLfloat w);
	bool CollisionCheck(Projectile *P);
	void ability(Platform* P);
	Brick(GLfloat, GLfloat, char);
};

