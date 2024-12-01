#include "Player.h"

Player::Player(GameMechs *thisGMRef, Food *thisFoodRef)
{
    mainGameMechsRef = thisGMRef;
    mainFoodRef = thisFoodRef;
    myDir = STOP; // default direction
    // genFood = new Food();

    // more actions to be included

    playerPosList = new objPosArrayList(); // uncomment for iteration 3, and everything below
    objPos initialPos(mainGameMechsRef->getBoardSizeX() / 2, mainGameMechsRef->getBoardSizeY() / 2, '*');
    playerPosList->insertHead(initialPos);

    // playerPos.pos->x = thisGMRef->getBoardSizeX() / 2; // update this after making game mechanics class and player class "talk" to each other (aka adding myGM pointer into myPlayer object!)
    // playerPos.pos->y = thisGMRef->getBoardSizeY() / 2;
    // playerPos.symbol = '@';
}

Player::~Player()
{
    // delete any heap members here
    // no keyword "new" in the constructor
    // leave destructor empty FOR NOW

    delete playerPosList; // for iteration 3
    // delete genFood;
}

// should change this to getPlayerHeadPos
objPos Player::getPlayerHeadPos() const
{
    // return the reference to the playerPos arrray list
    return playerPosList->getHeadElement();
}

// might need to create a getPlayerPosArrayList or smth for printing the snake on the game board

objPosArrayList *Player::getPlayerPosList() const
{
    return playerPosList;
}

void Player::updatePlayerDir()
{
    char input = mainGameMechsRef->getInput();
    // mainGameMechsRef->clearInput();

    // PPA3 input processing logic

    switch (input)
    {
        // case ' ':
        //     exitFlag = 1;
        //     break;

    case 'W': // Up
    case 'w':
        if (myDir != UP && myDir != DOWN)
        {
            myDir = UP;
        }
        break;

    case 'S': // Down
    case 's':
        if (myDir != DOWN && myDir != UP)
        {
            myDir = DOWN;
        }
        break;

    case 'A': // Left
    case 'a':
        if (myDir != LEFT && myDir != RIGHT)
        {
            myDir = LEFT;
        }
        break;

    case 'D': // Right
    case 'd':
        if (myDir != RIGHT && myDir != LEFT)
        {
            myDir = RIGHT;
        }
        break;

        // include increase and decrease speed of player cases here!
        // case '+': // Increase Game Speed
        // if(mainGameMechsRef->getSpeed() >= 1 && mainGameMechsRef->getSpeed() < 5)
        // {
        //     mainGameMechsRef->increaseSpeed();
        // }
        // break;

        // case '-': // Decrease Game Speed
        // if(mainGameMechsRef->getSpeed() > 1 && mainGameMechsRef->getSpeed() <= 5)
        // {
        //     mainGameMechsRef->decreaseSpeed();
        // }
        // break;

    default:
        break;
    }
}

void Player::movePlayer(objPos foodPos)
{
    // iteration 3: should get headPos

    objPos headPos = getPlayerHeadPos();

    int x = headPos.pos->x;
    int y = headPos.pos->y;

    objPos newHeadPos(x, y, '*');

    // PPA3 Finite State Machine logic
    switch (myDir)
    {
    case UP:
        y--;
        if (y == 0)
        {
            y = mainGameMechsRef->getBoardSizeY() - 2;
        }
        break;

    case DOWN:
        y++;
        if (y >= mainGameMechsRef->getBoardSizeY() - 1)
        {
            y = 1;
        }
        break;

    case LEFT:
        x--;
        if (x <= 0)
        {
            x = mainGameMechsRef->getBoardSizeX() - 2;
        }
        break;
    case RIGHT:
        x++;
        if (x >= mainGameMechsRef->getBoardSizeX() - 1)
        {
            x = 1;
        }
        break;
    case STOP:
    default:
        break;
    }

    // need to do the insert new position for head and remove tail thing

    if (headPos.isPosEqual(&foodPos))
    {
        playerPosList->insertHead(newHeadPos);
        mainGameMechsRef->incrementScore();
        // mainFoodRef->generateFood(newHeadPos);
    }

    else
    {
        playerPosList->insertHead(newHeadPos);
        playerPosList->removeTail();
    }
}

// void Player::speedControl()
// {
//     switch(mainGameMechsRef->getSpeed())
//     {
//         case 5:
//         mainGameMechsRef->setDelayAmount(10000);
//         break;

//         case 4:
//         mainGameMechsRef->setDelayAmount(100000);
//         break;

//         case 3:
//         mainGameMechsRef->setDelayAmount(150000);
//         break;

//         case 2:
//         mainGameMechsRef->setDelayAmount(200000);
//         break;

//         case 1:
//         mainGameMechsRef->setDelayAmount(250000);
//         break;
//     }
// }

// // More methods to be added