#include "level_1.h"

int x , y;
int cellsize = 40;
void Level::DrawLevel()
{
    platform = 
    {
        0,    //x
        7*40,    //y
        9999999,    //width
        40      //height
    }; 
    DrawRectangleRec(platform,DARKGRAY);
    
}

void Level::DrawSpikes()
{
    spikes.push_back(Spike(0 , 250));
    spikes.push_back(Spike(cellsize*0.5 , 250));
    spikes.push_back(Spike(cellsize*1 , 250));

    for(Spike& spike : spikes )
    {
        spike.Draw();
    }
}
