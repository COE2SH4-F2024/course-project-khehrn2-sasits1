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
    GameMechs *mainGameMechsRef;

    int xVal;
    int yVal;
    char input;

public:
    Food();
    Food(GameMechs *myGMRef);
    ~Food();

    void generateFood(objPos blockoff);
    void clearInput();

    objPos getFoodPos() const;
};

#endif
