#include <iostream>
#include<math.h>
#include "Shape.h"

#if defined WIN32
#include<freeglut.h>
#elif defined __APPLE__
#include<GLUT/glut.h>
#else
#include<GL/freeglut.h>
#endif

#define PI 3.141592653

Shape::Shape(){
    x = 0;
    y = 0;
    
    red = 1;
    green = 1;
    blue = 0;

    r = 0.05;
}

void Shape::draw() {
    glColor3f(red, green, blue);

    glBegin(GL_POLYGON);

    // Make hexagon
    float angle, dx, dy;
    int edges = 6; // Keep this, for testing
    for(int i = 0; i < edges; i++){
        angle = 2.0f * PI * float(i) / float(edges);
        dx = this->r * cosf(angle);
        dy = this->r * sinf(angle);
        glVertex2f(this->x + dx, this->y + dy);
    }
    glEnd();
}

Shape::~Shape(){
}
