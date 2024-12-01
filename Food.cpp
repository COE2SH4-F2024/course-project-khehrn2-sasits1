#include "Food.h"

Food::Food()
{
    food->setObjPos(-10, -10, 'o'); // initialize the food object outside the gameboard
    // xVal = 0;
    // yVal = 0;

    srand(time(nullptr)); // seeding the random number generation
}

Food::Food(GameMechs *myGMRef)
{
    mainGameMechsRef = myGMRef;
    food = new objPos;
    food->setObjPos(-10, -10, 'o'); // initialize the food object outside the gameboard
    // xVal = 0;
    // yVal = 0;

    srand(time(nullptr)); // seeding the random number generation
}

Food::~Food()
{
    delete food;
    // can be empty
}

void Food::generateFood(objPos blockOff)
{

    // Only need to block off the player position for now
    // Upgrade this in Iteration 3, when single player is replaced with player list
    int xVal, yVal, symbol;
    do
    {
        xVal = (rand() % (20 - 2)) + 1; // Assuming board size X is 20
        yVal = (rand() % (10 - 2)) + 1; // Assuming board size Y is 10
    }

    while (xVal == blockOff.pos->x && yVal == blockOff.pos->y);

    food->setObjPos(xVal, yVal, 'o'); // Set new position for food
}

objPos Food::getFoodPos() const
{
    return *food;
}

void Food::clearInput()
{
    input = 0;
}