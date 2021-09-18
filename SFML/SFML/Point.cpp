#include "Point.h"

Point::Point(Vector2f position, float radius, Color color)
{
	_shape = CircleShape(radius);
	position.x -= radius / 2;
	position.y -= radius / 2;
	_shape.setPosition(position);
	_shape.setFillColor(color);
	isCreated = true;
}

Vector2f Point::getPosition()
{
	return _shape.getPosition();
}

void Point::draw(RenderWindow& window)
{
	if (isCreated)
		window.draw(_shape);
}
