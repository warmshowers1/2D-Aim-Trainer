#include "App.h"

int main(int argc, char** argv) {
    GlutApp* app = new App(argc, argv, 640, 640, "Aim Trainer");

    app->run();
}
