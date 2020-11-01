#ifndef App_h
#define App_h

#include "GlutApp.h"
#include "Rect.h"

class App: public GlutApp {

    Rect* rect;
public:
    
    App(int argc, char** argv, int width, int height, const char* title);
    
    void draw();
    
    void keyDown(unsigned char key, float x, float y);
    
    ~App();
    
};

#endif
