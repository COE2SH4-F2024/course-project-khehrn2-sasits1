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

void Food::generateFood(objPosArrayList *snakeBody)
{

    // Only need to block off the player position for now
    // Upgrade this in Iteration 3, when single player is replaced with player list
    int xVal, yVal, symbol;
    bool isElement; // valid random element position
    do
    {
        xVal = (rand() % (20 - 2)) + 1;   // Assuming board size X is 20
        yVal = (rand() % (10 - 2)) + 1;   // Assuming board size Y is 10
        food->setObjPos(xVal, yVal, 'o'); // Set new position for food

        isElement = false;

        for (int i = 0; i < snakeBody->getSize(); i++)
        {
            objPos thisSegment = snakeBody->getElement(i);
            if (thisSegment.pos->x == xVal && thisSegment.pos->y == yVal)
            {
                isElement = true; // overlap of element and snake body!
                break;
            }
            else
            {
                isElement = false;
            }
        }
    } while (isElement);
}

objPos Food::getFoodPos() const
{
    return *food;
}

void Food::clearInput()
{
    input = 0;
}