#include <math.h>
#include "Triangle.h"

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

Triangle::Triangle(){
	x = -0.1;
	y = 0.1;

	red = 1;
	green = 0;
	blue = 0;

    s = 0.1;
}

Triangle::Triangle(float x, float y, float s){
	this->x = x;
	this->y = y;

	red = 1;
	green = 0;
	blue = 0;

    this->s = s;
}

Triangle::Triangle(float x, float y, float s, float red, float green, float blue){
	this->x = x;
	this->y = y;

	this->red = red;
	this->green = green;
	this->blue = blue;

    this->s = s;
}

Triangle::Triangle(const Triangle& other){
	x = other.x;
	y = other.y;

	red = other.red;
	green = other.green;
	blue = other.blue;

    s = other.s;
}

bool Triangle::operator== (const Triangle& other){
	return 	x == other.x && 
			y == other.y && 
			red == other.red && 
			green == other.green && 
			blue == other.blue;
            s == other.s;
}

Triangle::~Triangle(){
	// There is nothing to do here
}

bool Triangle::contains(float x, float y) const { // Edit this for triangles
    if((x > (this->x + s)) || (x < this->x) || (y > this->y) 
        || (y < this->y - (s * (sqrt(3)/2))))
        return false;
    else if(x < this->x + (s/2)){
        float dy = (-1 * sqrt(3)) * (x + (1 - this->x)) + this->y;
        if(y < dy)
            return false;
    }
    else if(x > this->x + (s/2)){
        float dy = sqrt(3) * (x - (this->x + 1)) + this->y;
        if(y < dy)
            return false;
    }
    return true;
}

// Edit to do triangles
void Triangle::draw(){
	glColor3f(red, green, blue);
	
	glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + s, y);
    glVertex2f(x + (s/2), y - (s * (sqrt(3)/2)));
	glEnd();
}

float Triangle::getX() const {
	return x;
}

float Triangle::getY() const {
	return y;
}

float Triangle::getR() const {
	return red;
}

float Triangle::getG() const {
	return green;
}

float Triangle::getB() const {
	return blue;
}

void Triangle::setX(float x){
	this->x = x;
}

void Triangle::setY(float y){
	this->y = y;
}

void Triangle::setS(float s){
	this->s = s;
}
