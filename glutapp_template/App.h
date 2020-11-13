#ifndef App_h
#define App_h

#include "GlutApp.h"
#include "Rect.h"
#include "Circle.h"
#include "Triangle.h"

class App: public GlutApp {

    Rect* rect;
    Circle* circ;
    Triangle* tri;
public:
    
    App(int argc, char** argv, int width, int height, const char* title);
    
    void draw();
    
    void keyDown(unsigned char key, float x, float y);
    
    ~App();
    
};

#endif
