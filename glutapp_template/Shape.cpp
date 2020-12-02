//polymorphism with rect/square circle?? and triangle //f@#king NOPE!!!
#include<iostream>
#include <math.h>
#include "Shape.h"

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

using namespace std;

Shape::Shape(){
	x = 0;
	y = 0.1;
	red = 1;
	green = 0;
	blue = 0;
    radius = .1;

	w = 0.2;
	h = 0.2;

	selected = false;
	shape = 0;
}

Shape::Shape(float x, float y, float r, float g, float b, float rad){
    this->x = x;
    this->y = y;
    red = r;
    green = g;
    blue = b;
    radius = rad;
    w = 2 * rad / sqrt(2);
    h = 2 * rad / sqrt(2);
    selected = false;
	shape = 2;
}

Shape::Shape(float x, float y, float r, float g, float b, float w, float h){
    this->x = x;
    this->y = y;
    red = r;
    green = g;
    blue = b;
    this->w = w;
    this->h = h;
    selected = false;
	shape = 0;
}

Shape::Shape(float x, float y, float r, float g, float b, float w, float h, float rad){
    this->x = x;
    this->y = y;
    red = r;
    green = g;
    blue = b;
    this->w = w;
    this->h = h;
    radius = rad;
    selected = false;
	shape = 0;
}

Shape::~Shape(){
	// There is nothing to do here for now...
}

bool Shape::contains(float x, float y) const {
    if(shape == 1){ // Triangle
        float tx[3] = {this->x, this->x + w, this->x + (w/2)};
        float ty[3] = {this->y, this->y, this->y - h};
        float a = ((ty[1] - ty[2]) * (x - tx[2]) + (tx[2] - tx[1]) * (y - ty[2])) / ((ty[1] - ty[2]) * (tx[0] - tx[2]) + (tx[2] - tx[1]) * (ty[0] - ty[2]));
        float b = ((ty[2] - ty[0]) * (x - tx[2]) + (tx[0] - tx[2]) * (y - ty[2])) / ((ty[1] - ty[2]) * (tx[0] - tx[2]) + (tx[2] - tx[1]) * (ty[0] - ty[2]));
        float c = 1 - a - b;
        return (0 <= a && a <= 1) && (0 <= b && b <= 1) && (0 <= c && c <= 1);
    }
    else if(shape == 2){ // Circle
        if((pow((x - this->x), 2) + pow((y - this->y), 2)) > pow(radius, 2))
            return false;
        return true;
    }
    else // Square or other
	    return (x > this->x) && (x < this->x + this->w) && (y < this->y) && (y > this->y - this->h);
}

void Shape::select(){
	selected = true;
}

void Shape::deselect(){
	selected = false;
}

void Shape::drawTri(){
    shape = 1;
	glColor3f(red, green, blue);
	
	glBegin(GL_LINES);

	glVertex2f(x, y);
	glVertex2f(x+w, y);

	glVertex2f(x+w, y);
	glVertex2f(x+w/2, y-h);

    glVertex2f(x+w/2, y-h);
    glVertex2f(x, y);
	glEnd();
	
}

void Shape::drawRect(){
    shape = 0;
	glColor3f(red, green, blue);
	
	glBegin(GL_LINES);

	glVertex2f(x, y);
	glVertex2f(x+w, y);

	glVertex2f(x+w, y);
	glVertex2f(x+w, y-h);
	
	glVertex2f(x+w, y-h);
	glVertex2f(x, y-h);
	
	glVertex2f(x, y-h);
	glVertex2f(x, y);

	glEnd();
	
}

void Shape::drawCirc(){
    shape = 2;
	GLfloat twicePi = 2.0f * 3.141592;
	glColor3f(red, green, blue);
	glBegin(GL_LINE_LOOP);
		for(int i = 0; i <= 100;i++) { 
			glVertex2f(
			    x + (radius * cos(i * twicePi / 100)), 
			    y + (radius * sin(i * twicePi / 100))
			);
		}
	glEnd();
}

float Shape::getX() const {
	return x;
}

float Shape::getY() const {
	return y;
}

float Shape::getW() const {
	return w;
}

float Shape::getH() const {
	return h;
}

bool Shape::getSel() const {
	return selected;
}

float Shape::getR() const {
	return red;
}

float Shape::getG() const {
	return green;
}

float Shape::getB() const {
	return blue;
}

void Shape::setX(float x){
	this->x = x;
}

void Shape::setY(float y){
	this->y = y;
}

void Shape::setW(float w){
	this->w = w;
}

void Shape::setH(float h){
	this->h = h;
}

void Shape::setRad(float r){
    this->radius = r;
}

void Shape::setCol(float r, float g, float b){
    this->red=r;
    this->green=g;
    this->blue=b;
}

void Shape::setSh(int s){
    this->shape=s;
}

int Shape::getSh() const{
    return shape;
}
