#ifndef App_h
#define App_h

#include "GlutApp.h"
#include "Shape.h"
// #include "Rect.h"
#include "Circle.h"
#include "Triangle.h"
#include "Square.h"

class App: public GlutApp {
    Shape* sh;
    Shape* ap;
    Shape* e;
public:
    
    App(int argc, char** argv, int width, int height, const char* title);
    
    void draw();
    
    void keyDown(unsigned char key, float x, float y);
    
    ~App();
    
};

#endif
