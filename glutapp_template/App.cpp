#include <iostream>
#include "App.h"


App::App(int argc, char** argv, int width, int height, const char* title): GlutApp(argc, argv, width, height, title){
    rect = new Rect();
}

void App::draw() {
    rect->draw();
}

void App::keyDown(unsigned char key, float x, float y){
    if (key == 27){
        exit(0);
    }
}

App::~App(){
    std::cout << "Exiting..." << std::endl;
    delete rect;
}
