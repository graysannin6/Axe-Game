#include "Axe.h"
#include "Circle.h"

const int WIDTH = 800;
const int HEIGHT = 800;
const int ZERO = 0;

bool checkCollision(const Circle& circle, const Axe& axe);

int main()
{
    InitWindow(WIDTH,HEIGHT,"Axe_Game");

    Circle circle = {WIDTH/3, HEIGHT/2, 25, 10};
    Axe axe = {WIDTH/2 - 25 , 0, 50, 50, 10 ,Color{230,41,55,255}};
    

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        if (axe.collision)
        {
            DrawText("Game Over!", WIDTH / 2 - 50, HEIGHT / 2, 20, RED);
        }
        else
        {
            // Update bounds for collision detection
            circle.updateBounds();
            axe.updateBounds();

            // Check for collision
            axe.collision = checkCollision(circle,axe);

            DrawCircle(circle.x, circle.y, circle.radius, BLUE);
            DrawRectangle(axe.posX, axe.posY, axe.width, axe.height, axe.color);

            // Update axe position
            axe.posY += axe.direction;
            if (axe.posY + axe.height > WIDTH || axe.posY < 0)
            {
                axe.direction = -axe.direction;
            }


            // Update circle position based on user input
            if (!axe.collision)
            {
                if (IsKeyDown(KEY_A) && circle.l_circle_x > ZERO) { circle.x -= circle.move_speed; }
                if (IsKeyDown(KEY_D) && circle.r_circle_x < WIDTH) { circle.x += circle.move_speed; }
            }
        }
        EndDrawing();
    }
    CloseWindow();
}

bool checkCollision(const Circle& circle, const Axe& axe)
{
    return (circle.r_circle_x >= axe.l_axe_x)&&
           (circle.l_circle_x <= axe.r_axe_x)&&
           (circle.b_circle_y >= axe.u_axe_y) &&
           (circle.u_circle_y <= axe.b_axe_y);
}

 //if (IsKeyDown(KEY_S) && circle.y + circle.radius < HEIGHT){circle.y += circle.move_speed;}
 //if (IsKeyDown(KEY_W) && circle.y - circle.radius > ZERO  ){circle.y -= circle.move_speed;}