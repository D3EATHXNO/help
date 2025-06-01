#pragma once
#include "raylib.h"
#include <deque>
#define MAX_SPIKES 100


class Spike {
public:

    Rectangle hitbox;
    Spike(int x , int y);
    ~Spike();
    int  cellsize;
    Vector2 pos;
    void Draw();

private:
    float width,height;
    Texture2D SPIKE;
};
