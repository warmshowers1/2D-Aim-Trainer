#include <iostream>
#include "App.h"


App::App(int argc, char** argv, int width, int height, const char* title): GlutApp(argc, argv, width, height, title){
    circ = new Circle(0.5, 0, 0.05, 1, 0, 0);
    tri = new Triangle(-0.5, 0, 0.05, 1, 0, 0);
}

void App::draw() {
    tri->draw();
    circ->draw();
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
