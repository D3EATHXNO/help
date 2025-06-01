#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"
#include "level_1.h"

class Player
{
    public:
        bool is_moving_forward; // (impliment)
        bool is_on_ground; // check if player is jumping
        int cellSize; // helps to mae a 40x40 grid 
        Vector2 player_pos; // player position
        Vector2 velocity; // speed 
        

        Player(); // constructor
       ~Player(); //deconstructor

       Camera2D camera;//camera

        void Draw();   //draw the player and rectangle hitbox(kinda)
        void Update(); // update
        void CheckCollisionWithObjects(Rectangle platform); // use a fake instance so no bugs declare real level.platform in main 
        
        
    private:

       Texture2D texture; // player.png implimentation
        const float gravity = 0.4f;  // Slower fall speed
        const float jumpForce = -10.0f;  // Lowered jump force for normal jump height

        Rectangle GetPlayerRect();  // no declaration problem 
        

};
#endif