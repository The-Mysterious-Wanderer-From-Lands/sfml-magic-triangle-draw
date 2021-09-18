#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <vector>
#include <list>
#include "Point.h"
#include "Simulator.h"

using namespace std;
using namespace sf;

int main() {
	RenderWindow window(VideoMode(1000,700),"Magic Triangle");

	Font font;
	font.loadFromFile("Data/font.otf");
	Text infoText("Press S to start or C to clear points\n\tClick somewhere to place point", font, 30);
	infoText.setFillColor(Color::Red);
	infoText.setPosition(300, 50);
	Text errorText("Some error", font, 20);
	errorText.setFillColor(Color::Red);
	errorText.setStyle(Text::Bold);
	errorText.setPosition(600, 650);

	vector<Point> pointers;
	while (window.isOpen()) {
		Event event;

		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::Escape)
					window.close();
				if (event.key.code == Keyboard::C) 
					pointers.clear();
				if (event.key.code == Keyboard::S) {
					if (pointers.size() < 3) {
						errorText.setString("points must be 3 or more");
						continue;
					}
					errorText.setString("");
					simulate(window, pointers);
					pointers.clear();
				}
			}
			if (event.type == Event::MouseButtonPressed) {
				if (event.key.code == Mouse::Left) {
					errorText.setString("");
					Vector2f position = (Vector2f)Mouse::getPosition(window);
					pointers.push_back(Point(position, 5, Color::Green));
				}
			}
		}
		window.clear();
		window.draw(infoText);
		window.draw(errorText);
		for (Point p : pointers) {
			p.draw(window);
		}
		window.display();
	}
	return 0;
}