#include "Game.h"
#include<iostream>
#include<fstream>
#include <math.h>
#include <deque>
#include <time.h>
#include <stdlib.h>

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

using namespace std;

Game::Game(float width){
    start = false;
    text = new Text(width);
    test = new Shape();

    st = new Shape(-.45, .8, 1, 0, 0, .1, .1, 0.05);

    shapes.push_back(new Shape(-.45, .3, 1, 1, 1, .1, .1)); //sq
    shapes.push_back(new Shape(-.2, .3, 1, 1, 1, .1, .1)); //tri
    shapes.push_back(new Shape(.1, .26, 1, 1, 1, .05)); //circ

    col.push_back(new Shape(-.45, 0, 1, 0, 0, .1, .1));
    col.push_back(new Shape(-.2, 0, 0, 1, 0, .1, .1));
    col.push_back(new Shape(.05, 0, 0, 1, 1, .1, .1));

    diff.push_back(new Shape(-.43, -.32, 1, 1, 1, .1, .1));
    diff.push_back(new Shape(-.18, -.32, 0, 0, 0, .1, .1));
    diff.push_back(new Shape(.07, -.32, 0, 0, 0, .1, .1));

    seed = time(NULL);
}

void Game::draw(){
    // In menu
    if(!start){
        if (test->getSh() == 0)      // 0 = Square
          st->drawRect();
        else if (test->getSh() == 1) // 1 = Triangle
          st->drawTri();
        else                         // 2 = Circle
          st->drawCirc();
        

        shapes[0]->drawRect();
        shapes[1]->drawTri();
        shapes[2]->drawCirc();

        for (int i = 0; i < diff.size(); i++) { // Not ideal, but more efficient
            col[i]->drawRect();
            diff[i]->drawRect();
        }
        
        text->setColor(1,0,0);
        text->renderText(-.8, .7, "Start");
        text->renderText(-.8, .2, "Shape");
        text->renderText(-.8, -.1, "Color");
        text->renderText(-.8, -.4, "Difficulty");

        text->renderText(-.4, -.4, "1");
        text->renderText(-.15, -.4, "2");
        text->renderText(.1, -.4, "3");
    }
    // Start button clicked
    else{
        text->setColor(1,1,1);
        text->renderText(-0.95, 0.9, "Time: " + to_string(int(difftime(time(NULL), begin))));
        // If user takes too long, move target
        if(difftime(time(NULL), click) > 1){
            test->setX(float((rand() % 190) - 100) / 100); // Fix these later
            test->setY(float((rand() % 190) - 90) / 100);
            click = time(NULL);
        }
        if(difftime(time(NULL), begin) > 29){ // 30 seconds
        // When game ends
        // if(difftime(time(NULL), begin) > 9){ // 10 seconds for testing
            start = false;
            ofstream result;
            result.open("result.csv", fstream::app);
            // Check shape and put in csv
            switch(st->getSh()){
            case 0:
                result << "Square, ";
                break;
            case 1:
                result << "Triangle, ";
                break;
            case 2:
                result << "Circle, ";
                break;
            default:
                result << "[Shape], "; // Something went wrong
            }
            
            // Check color and put in csv
            if(st->getR() == 1) // If red at all
                result << "Red, ";
            else if(st->getB() == 0) // If not blue, green
                result << "Green, ";
            else if(st->getB() == 1) // Must be blue
                result << "Blue, ";
            else
                result << "[Color], "; // Something went wrong
            
            // Check difficulty and put in csv
            if(test->getW() >= 0.2) // If red at all
                result << "1, ";
            else if(test->getW() >= 0.1) // If not blue, green
              result << "2, ";
            else if(test->getW() >= 0.05) // Must be blue
              result << "3, ";
            else
              result << "[Level], "; // Something went wrong
            
            result << to_string(hits) << ", " << to_string(clicks) << ", " << to_string(float(hits) / clicks * 100) << "%, \n";
            
            result.close();
        }
        // cout << "Target coords: (" + 
        if(hits < 10)
            text->renderText(0.75, 0.9, "Hits: " + to_string(hits));
        else
            text->renderText(0.72, 0.9, "Hits: " + to_string(hits));
        if (test->getSh() == 0){
            test->drawRect();
        } else if (test->getSh() == 1){
            test->drawTri();
        } else{
            test->drawCirc();
        }
    }
}

void Game::check(float x, float y){ //Runs for every click
    srand(seed++);// Set seed
    // If the game started
    clicks++;
    if(st->contains(x,y)){
        hits = 0;
        clicks = 0;
        start = true;
        begin = time(NULL);
    }
    // If we're in the middle of the game
    else if(start && test->contains(x,y)){
        ++hits;
        click = time(NULL);
        test->setX(float((rand() % 190) - 100) / 100); // Fix these later
        test->setY(float((rand() % 190) - 90) / 100);
        // cout << "Mouse coords: (" + x + "," + y + ")" << endl;
    }
    // If we're still in the menu
    else if(!start){
        for(deque<Shape*>::iterator i = col.begin(); i != col.end(); i++){
            if((*i)->contains(x, y)){
                for(deque<Shape*>::iterator j = col.begin(); j != col.end(); j++)
                    (*j)->deselect();
                (*i)->select();
                break;
            }
        }

        for(deque<Shape*>::iterator i = diff.begin(); i != diff.end(); i++){
            if((*i)->contains(x, y)){
                for(deque<Shape*>::iterator j = diff.begin(); j != diff.end(); j++){
                    (*j)->setCol(0,0,0);
                    (*j)->deselect();
                }
                (*i)->setCol(1,1,1);
                (*i)->select();
                break;
            }
        }

        for(deque<Shape*>::iterator i = shapes.begin(); i != shapes.end(); i++){
            if((*i)->contains(x, y)){
                for(deque<Shape*>::iterator j = shapes.begin(); j != shapes.end(); j++)
                    (*j)->deselect();
                (*i)->select();
                break;
            }
        }

        if(shapes[0] -> getSel()){
            test->setSh(0);
        } else if (shapes[1] -> getSel()){
            test->setSh(1);
        } else if (shapes[2] -> getSel()) {
            test->setSh(2);
        }
        
        if(col[0]->getSel()){
            test->setCol(1,0,0);
            st->setCol(1,0,0);
        } else if(col[1]->getSel()){
            test->setCol(0,1,0);
            st->setCol(0,1,0);
        } else if(col[2]->getSel()) {
            test->setCol(0,1,1);
            st->setCol(0,1,1);
        }

        // Depending on difficulty, the size will change
        if(diff[0]->getSel() && test->getW() != 0.2){
            test->setW(0.2);
            test->setH(0.2);
            test->setRad(0.1);
        } else if(diff[1]->getSel() && test->getW() != 0.1){
            test->setW(0.1);
            test->setH(0.1);
            test->setRad(0.07);
        } else if(diff[2]->getSel() && test->getW() != 0.05){
            test->setW(0.05);
            test->setH(0.05);
            test->setRad(0.04);
        }
    }
}
