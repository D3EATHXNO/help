#include <iostream>
#include "raylib.h"
#include "raymath.h"
#include "src/player.h"
#include "src/level_1.h"
#include "src/spike.h"

int main()
{
    //INIT
    
    const float scr_height = 600.00f;
    const float scr_width = 800.00f;
    SetTargetFPS(60);
    InitWindow(scr_width,scr_height,"Geometery Dach");
    
    Player player = Player();
    Level level = Level();

    //loop
    while(!WindowShouldClose())
    {
        //UPDATE

        //DRAW
        BeginDrawing();        
        ClearBackground(RAYWHITE);
  
       
        // Camera target follows player
        

        BeginMode2D(player.camera);
        
         player.Draw();
         level.DrawLevel();
         level.DrawSpikes();

        EndMode2D();

        player.CheckCollisionWithObjects(level.platform);
        player.Update();


        EndDrawing();
    }


    //denit

    CloseWindow();


    return 0;
}