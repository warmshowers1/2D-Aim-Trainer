#include <math.h>
#include "text.h"

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif
//This really doesnt need to be an object (but this was made before the game class existed)
Text::Text(){
	x = 0;
	y = 0;
	red = 1;
	green = 0;
	blue = 0;
    text = ' ';
    font = GLUT_BITMAP_TIMES_ROMAN_24;
    width = 1;
}

Text::Text(float w){
	x = 0;
	y = 0;
	red = 1;
	green = 0;
	blue = 0;
    text = ' ';
    font = GLUT_BITMAP_TIMES_ROMAN_24;
    width = w;
}

Text::~Text(){
	// There is nothing to do here for now...
}

void Text::renderText(float x, float y, std::string words){
    this->text = words;
    glColor3f(red, green, blue);
    float offset = 0;
    for (int i = 0; i < text.length(); i++) {
        glRasterPos2f(x+offset, y);
        glutBitmapCharacter(font, text[i]);
        int w = glutBitmapWidth(font, text[i]);
        offset += ((float)w / width)*2;
    }
}
void Text::setW(float w){
    this->width = w;
}

void Text::setColor(float r, float g, float b){
    this->red = r;
    this->green = g;
    this->blue = b;
}

void Text::Lose(){
    this->text = "Lose";
}

void Text::Win(){
    this->text = "Win";
}
