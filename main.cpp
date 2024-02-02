#include <iostream>

#include <raylib.h>
#include <cmath>

#include "OrbitalCamera.h"
#include "Utils.h"
#include "Q1.h"
#include "Q2.h"

int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(750, 750, "a");
    SetTargetFPS(60);

    //Q1();
    Q2a();
    //Q2b();
    //Q2c();

    CloseWindow();
    return 0;
}
