#include "Brick.h"
#include "EngineUtilities.h"

void Brick::drawPolygon(Location Loc)
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

GLfloat Brick::getWidth()
{
	return width;
}

GLfloat Brick::getHeight()
{
	return height;
}

void Brick::setDimentions(GLfloat h, GLfloat w)
{
	height = h;
	width = w;
}

bool Brick::CollisionCheck(Projectile *P)
{
	if (canCollide)
	{
		if (TL.x == BR.x || TL.y == BR.y || P->BR.x == P->TL.x || P->TL.y == P->BR.y)
			return false;
		if (TL.x > P->BR.x || P->TL.x > BR.x)
			return false;
		if (BR.y > P->TL.y || P->BR.y > TL.y)
			return false;
		return true;
	}
	else
		return false;
}

void Brick::ability(Platform* P)
{
	switch (BrickType)
	{
		case '1':
		{
			P->setDimentions(P->getHeight(), P->getWidth());
			break;
		}
		case '2':
		{
			P->setDimentions(P->getHeight(), P->getWidth());
			break;
		}
		case '3':
		{
			P->setDimentions(P->getHeight(), P->getWidth());
			break;
		}
		case '4':
		{
			P->setDimentions(P->getHeight(), P->getWidth()*2);
			break;
		}
		case '5':
		{
			P->setDimentions(P->getHeight(), P->getWidth()/2);
			break;
		}
		default:
			break;
	}
}

Brick::Brick(GLfloat OrgX, GLfloat OrgY, char c)
{
	setTag("Brick");
	setOrigin(OrgX, OrgY);
	setLocation(OrgX, OrgY);
	BrickType = c;
	height = 50;
	width = 75;
}
