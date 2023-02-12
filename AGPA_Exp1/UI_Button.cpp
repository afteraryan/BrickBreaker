#include "UI_Button.h"
#include <iostream>

bool UI_Button::isClicked(int x, int y, Location O)
{
	//std::cout << O.x<<","<<O.y<<" "<<x<<","<<y << std::endl;
	if ((x >= O.x && x <= O.x + width) && (y >= O.y && y <= O.y + height))
        return true;
    return false;
}

void UI_Button::setDimentions(GLfloat h, GLfloat w)
{
    height = h;
    width = w;
}

void UI_Button::drawPolygon(Location Loc)
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

std::string UI_Button::getName()
{
	return Name;
}

UI_Button::UI_Button(GLfloat OrgX, GLfloat OrgY, GLfloat h, GLfloat w, std::string n)
{
	Name = n;
    setTag("Button");
    setOrigin(OrgX, OrgY);
    setLocation(OrgX, OrgY);
    height = h;
	width = w;
}