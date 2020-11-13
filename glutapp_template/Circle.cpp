#include <math.h>
#include "Circle.h"

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#define PI 3.141592653

Circle::Circle(){
	x = -0.1;
	y = 0.1;

	red = 1;
	green = 0;
	blue = 0;

    r = 0.1; // Radius
}

Circle::Circle(float x, float y, float r){
	this->x = x;
	this->y = y;

	red = 1;
	green = 0;
	blue = 0;

    this->r = r;
}

Circle::Circle(float x, float y, float r, float red, float green, float blue){
	this->x = x;
	this->y = y;

	this->red = red;
	this->green = green;
	this->blue = blue;

	this->r = r;
}

Circle::Circle(const Circle& other){
	x = other.x;
	y = other.y;

	red = other.red;
	green = other.green;
	blue = other.blue;

	r = other.r;
}

bool Circle::operator== (const Circle& other){
	return 	x == other.x && 
			y == other.y && 
			r == other.r && 
			red == other.red && 
			green == other.green && 
			blue == other.blue;
}

Circle::~Circle(){
	// There is nothing to do here
}

bool Circle::contains(float x, float y) const { // Edit this for circles
    if((x > (this->x + r)) || (x < (-1 * (this->x + r))) || (y > (this->y + r)) || (y < (-1 * (this->y + r))))
        return false;
    else{
        float dy = r * sinf(acosf((x - this->x)/r)) + this->y; // Should be the upper/lower y coordinate
        if((y > dy) || (y < (-1 * dy)))
            return false;
    }
    return true;
}

// Edit to do circles
void Circle::draw(){
	glColor3f(red, green, blue);
	
	glBegin(GL_POLYGON);

    float angle, dx, dy;
    int edges = 30;
    for(int i = 0; i < edges; i++){
        angle = 2.0f * PI * float(i) / float(edges);
        dx = this->r * cosf(angle);
        dy = this->r * sinf(angle);
        glVertex2f(this->x + dx, this->y + dy);
    }
	glEnd();
}

float Circle::getX() const {
	return x;
}

float Circle::getY() const {
	return y;
}

float Circle::getR() const {
	return red;
}

float Circle::getG() const {
	return green;
}

float Circle::getB() const {
	return blue;
}

void Circle::setX(float x){
	this->x = x;
}

void Circle::setY(float y){
	this->y = y;
}

void Circle::setR(float r){
	this->r = r;
}
