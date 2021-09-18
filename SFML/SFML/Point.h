#pragma once
#ifndef POINT_H
#define POINT_H
#include <SFML/Graphics.hpp>
using namespace sf;
class Point
{
public:
	Point(Vector2f position, float radius = 1.f, Color color = Color::Red);
	Vector2f getPosition();
	void draw(RenderWindow& window);
private:
	CircleShape _shape;
	bool isCreated = false;
};
#endif // !POINT_H

