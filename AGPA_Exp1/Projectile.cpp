#include "Projectile.h"



Projectile::Projectile(GLfloat OrgX, GLfloat OrgY)
{
	setTag("Projectile");
	setLocation(OrgX, OrgY);
	setOrigin(OrgX, OrgY);
	height = 25;
	width = 25;
}

void Projectile::drawPolygon(Location Loc)
{
	TL.x = Loc.x;
	TL.y = Loc.y + height;
	BR.x = Loc.x + width;
	BR.y = Loc.y;
	//Drawing brick 
	if (canRender)
	{
		glBegin(GL_POLYGON);
		glColor3f(0.9, 1, 0.2);
		glVertex2f(Loc.x, Loc.y);
		glVertex2f(Loc.x, Loc.y + height);
		glVertex2f(Loc.x + width, Loc.y + height);
		glVertex2f(Loc.x + width, Loc.y);
		glEnd();
	}
}

GLfloat Projectile::getWidth()
{
	return width;
}

GLfloat Projectile::getHeight()
{
	return height;
}
