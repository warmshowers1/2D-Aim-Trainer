#ifndef App_h
#define App_h

#include "GlutApp.h"
#include "Rect.h"
#include "Circle.h"

class App: public GlutApp {

    Rect* rect;
    Circle* circ;
public:
    
    App(int argc, char** argv, int width, int height, const char* title);
    
    void draw();
    
    void keyDown(unsigned char key, float x, float y);
    
    ~App();
    
};

#endif
