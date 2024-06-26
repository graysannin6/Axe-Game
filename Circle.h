#pragma once

struct Circle
{
    int x;
    int y;
    int radius;
    int move_speed;

    //bounds
    int l_circle_x;
    int r_circle_x;
    int u_circle_y;
    int b_circle_y;

    void updateBounds()
    {
        l_circle_x = x - radius;
        r_circle_x = x + radius;
        u_circle_y = y - radius;
        b_circle_y = y + radius;
    }
};