#include <iostream>
#include "App.h"


App::App(int argc, char** argv, int width, int height, const char* title): GlutApp(argc, argv, width, height, title){
    sh = new Circle(0.5, 0, 0.05, 1, 0, 0);
    ap = new Triangle(0.5, 0.5, 0.05, 0, 1, 0);
    e = new Square(0, 0.5, 0.05, 0, 0, 1);
}

void App::draw() {
    sh->draw();
    ap->draw();
    e->draw();
}

void App::keyDown(unsigned char key, float x, float y){
    if (key == 27){
        exit(0);
    }
}

App::~App(){
    std::cout << "Exiting..." << std::endl;
    delete sh;
    delete ap;
    delete e;
}
