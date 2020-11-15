#ifndef GAME_H
#define GAME_H
#include "Shape.h" //<- include the object
#include "text.h"
#include <deque>
#include <time.h>


class Game {
    bool start;
    Text* text;
    Shape* test;

    Shape* st;

    std::deque<Shape*> shapes;
    std::deque<Shape*> diff;
    std::deque<Shape*> col;
    
    time_t begin;
    time_t click;
    long seed;
    short int hits;
    short int clicks;

public:
	Game();
    Game(float);

	~Game();

	void draw();
    void shoot();
    void check(float x, float y);
};




#endif
