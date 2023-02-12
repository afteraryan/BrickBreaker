#include "Actor.h"
#include "EngineUtilities.h"
#pragma once
class UI_Button : public Actor
{
	struct Vertex
	{
		GLfloat x, y;
	};
	GLfloat height, width;
	Vertex TL, BR;
	std::string Name;
	

public:
	//Functions
	bool isClicked( int x,int y, Location);
	void setDimentions(GLfloat h, GLfloat w);
	void drawPolygon(Location);
	std::string getName();
	UI_Button(GLfloat OrgX, GLfloat OrgY, GLfloat h, GLfloat w, std::string n);

};

