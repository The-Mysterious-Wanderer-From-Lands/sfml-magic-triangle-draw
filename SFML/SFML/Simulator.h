#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <time.h>
#include <mutex>
#include <list>
#include "Point.h"

using namespace std;
using namespace sf;

void simulate(RenderWindow& window, vector<Point> pointers);