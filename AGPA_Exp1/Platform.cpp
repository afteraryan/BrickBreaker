#include <iostream>
#include "Platform.h"

void Platform::drawPolygon(Location Loc)
{
	TL.x = Loc.x;
	TL.y = Loc.y + height;
	BR.x = Loc.x + width;
	BR.y = Loc.y;
	//Drawing brick 
	if (canRender)
	{
		glBegin(GL_POLYGON);
		glColor3f(color.R, color.G, color.B);
		glVertex2f(Loc.x, Loc.y);
		glVertex2f(Loc.x, Loc.y + height);
		glVertex2f(Loc.x + width, Loc.y + height);
		glVertex2f(Loc.x + width, Loc.y);
		glEnd();
	}
}

GLfloat Platform::getWidth()
{
	return width;
}

GLfloat Platform::getHeight()
{
	return height;
}

void Platform::setDimentions(GLfloat h, GLfloat w)
{
	height = h;
	width = w;
}

bool Platform::CollisionCheck(Projectile* P)
{
	if (TL.x == BR.x || TL.y == BR.y || P->BR.x == P->TL.x || P->TL.y == P->BR.y)
		return false;
	if (TL.x >= P->BR.x || P->TL.x >= BR.x)
		return false;
	if (BR.y >= P->TL.y || P->BR.y >= TL.y)
		return false;
	return true;
}



Platform::Platform(GLfloat OrgX, GLfloat OrgY)
{
	setTag("Platform");
	setOrigin(OrgX, OrgY);
	setLocation(OrgX, OrgY);
	height = 25;
	width = 100;
}

