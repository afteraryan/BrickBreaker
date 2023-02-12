#include "Actor.h"
#include "EngineUtilities.h"
#include <iostream>

Actor::Actor()
{
	//initTransform(&transform);
}

std::string Actor::getTag()
{
	return tag;
}

void Actor::setTag(std::string tagStr)
{
	tag = tagStr;
}

void Actor::Move(Location L)
{
	setLocation(getLocation().x + L.x, getLocation().y + L.y);
}

void Actor::setLocation(GLfloat x, GLfloat y)
{
	transform.location.x = x;
	transform.location.y = y;
}


void Actor::setRotation(GLfloat x, GLfloat y)
{
	transform.rotation.x = x;
	transform.rotation.y = y;
}

void Actor::setScale(GLfloat x, GLfloat y)
{
	transform.scale.x = x;
	transform.scale.y = y;
}

void Actor::setOrigin(GLfloat x, GLfloat y)
{
	Origin.x = x;
	Origin.y = y;
	setLocation(x, y);
}

void Actor::setColor(GLfloat R, GLfloat G, GLfloat B)
{
	color.R = R;
	color.G = G;
	color.B = B;

}

void Actor::setVelocity(GLfloat x, GLfloat y)
{
	velocity.x = x;
	velocity.y = y;
}

Location Actor::getLocation()
{
	return transform.location;
}

Location Actor::getOrigin()
{
	return Origin;
}

Rotation Actor::getRotation()
{
	return transform.rotation;
}

Scale Actor::getScale()
{
	return transform.scale;
}

Velocity Actor::getVelocity()
{
	return velocity;
}


void Actor::drawPolygon(GLfloat OrgX, GLfloat OrgY)
{
}


void Actor::destroy()
{
	canCollide = false;
	canRender = false;
}
