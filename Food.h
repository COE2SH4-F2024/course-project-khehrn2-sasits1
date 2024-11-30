#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"

class Food
{
private:
    objPos *food;
    // GameMechs *mainGameMechsRef; idk if we actually need this

    int xVal;
    int yVal;

public:
    Food();
    Food(int boardSizeX, int boardSizeY);
    ~Food();

    void generateFood(objPos blockoff);

    objPos getFoodPos() const;
};

#endif
