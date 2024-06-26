#pragma once

#include "raylib.h"

struct Axe
{
    int posX;
    int posY;
    int width;
    int height;
    int direction;
    Color color;
    bool collision{false};

    //bounds
    int l_axe_x;
    int r_axe_x;
    int u_axe_y;
    int b_axe_y;

    void updateBounds()
    {
         l_axe_x = posX;
         r_axe_x = posX + width;
         u_axe_y = posY;
         b_axe_y = posY + height;
    }
    
    
};