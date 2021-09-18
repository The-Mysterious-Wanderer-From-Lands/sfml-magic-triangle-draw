#include "Simulator.h"
mutex mtx;
void renderPoints(vector<Point>& pointers, list<Point>& points,
	Point& lastPoint,bool& isUpdate) {
	while (isUpdate) {
		Point current = pointers[rand() % pointers.size()];
		float x = current.getPosition().x; float y = current.getPosition().y;
		float newX = (x + lastPoint.getPosition().x) / 2;
		float newY = (y + lastPoint.getPosition().y) / 2;
		Point newPoint(Vector2f(newX, newY));
		points.push_back(newPoint);
		lastPoint = newPoint;
		this_thread::sleep_for(chrono::milliseconds(5));
	}
}

void simulate(RenderWindow& window, vector<Point> pointers)
{
	srand(time(NULL));
	bool isUpdate = true;
	list<Point> points;
	Point lastPoint = pointers[0];

	thread thr(renderPoints, ref(pointers), ref(points),
		ref(lastPoint), ref(isUpdate));
	while (isUpdate) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				isUpdate = false;
			if (event.type == Event::KeyPressed)
				if (event.key.code == Keyboard::Escape)
					isUpdate = false;
		}
		window.clear();
		for (Point p : pointers)
			p.draw(window);
		for (Point p : points)
			p.draw(window);
		window.display();
	}
	thr.join();
}
