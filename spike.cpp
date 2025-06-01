#include "spike.h"

Spike::Spike(int x, int y)
{
    SPIKE = LoadTexture("assets/spike.png");
    width = 30;
    height = 30;
    hitbox = { (float) x  ,  (float) y , width , height};  
    pos.x = x;
    pos.y = y;
}

Spike::~Spike()
{
    UnloadTexture(SPIKE);
}

void Spike::Draw()
{
    DrawRectangle(pos.x,pos.y,width,height,RED);
    DrawTextureV(SPIKE , pos , WHITE);
}