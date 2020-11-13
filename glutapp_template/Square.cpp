#include <math.h>
#include "Square.h"

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

Square::Square(){
	x = -0.1;
	y = 0.1;
	red = 1;
	green = 1;
	blue = 1;

    s = 0.1;
}

Square::Square(float x, float y, float s){
	this->x = x;
	this->y = y;

	red = 1;
	green = 1;
	blue = 1;

	this->s = s;
}

Square::Square(float x, float y, float s, float red, float green, float blue){
	this->x = x;
	this->y = y;

	this->red = red;
	this->green = green;
	this->blue = blue;

	this->s = s;
}

Square::Square(const Square& other){
	x = other.x;
	y = other.y;

	red = other.red;
	green = other.green;
	blue = other.blue;

	s = other.s;
}

bool Square::operator== (const Square& other){
	return 	x == other.x && 
			y == other.y && 
			s == other.s && 
			red == other.red && 
			green == other.green && 
			blue == other.blue;
}

Square::~Square(){
	// There is nothing to do here for now...
}

bool Square::contains(float x, float y) const {
	return (x > this->x) && (x < (this->x + this->s)) && (y < this->y) && (y > (this->y - this->s));
}


void Square::draw(){

	glColor3f(red, green, blue);
	
	glBegin(GL_POLYGON);

	glVertex2f(x, y);
	glVertex2f(x+s, y);
	glVertex2f(x+s, y-s);
	glVertex2f(x, y-s);
	
	glEnd();
	
}

float Square::getX() const {
	return x;
}

float Square::getY() const {
	return y;
}

float Square::getS() const {
	return s;
}

float Square::getR() const {
	return red;
}

float Square::getG() const {
	return green;
}

float Square::getB() const {
	return blue;
}

void Square::setX(float x){
	this->x = x;
}

void Square::setY(float y){
	this->y = y;
}

void Square::setS(float s){
	this->s = s;
}
