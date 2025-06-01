#ifndef LEVEL_1_H
#define LEVEL_1_H
#include "raylib.h"
#include "spike.h"
#include <vector>

class Level
{
public:
    Spike spike;
    std::vector<Spike> spikes;
    Rectangle platform;
    void DrawLevel();
    void DrawSpikes();
    
private:
    int cellsize = 40;
};

#endif