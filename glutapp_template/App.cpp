#include <iostream>
#include "App.h"


App::App(int argc, char** argv, int width, int height, const char* title): GlutApp(argc, argv, width, height, title){
     game = new Game(width);
}

void App::draw() {
    game->draw();
}

void App::keyDown(unsigned char key, float x, float y){
    if (key == 27){
        exit(0);
    }
}
void App::leftMouseDown(float x, float y){
    game->check(x,y);
    // std::cout << "Left mouse down" << std::endl; // For testing
}

void App::idle(){
    redraw();
}

App::~App(){
    std::cout << "Exiting..." << std::endl;
    // delete game;
}
