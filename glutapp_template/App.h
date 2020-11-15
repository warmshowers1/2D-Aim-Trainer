#ifndef App_h
#define App_h

#include "GlutApp.h"
#include "game.h"

class App: public GlutApp {
    Game* game;
public:
    
    App(int argc, char** argv, int width, int height, const char* title);
    
    void draw();

    void idle();
    void leftMouseDown(float x, float y);
    void keyDown(unsigned char key, float x, float y);
    
    ~App();
    
};

#endif
