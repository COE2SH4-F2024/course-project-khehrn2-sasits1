#include "Player.h"

Player::Player(GameMechs *thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP; // default direction

    // more actions to be included

    // playerPosList = new objPosArrayList(); //uncomment for iteration 3, and everything below
    // objPos initialPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '@')
    // playerPosList->insertHead(initialPos);

    playerPos.pos->x = thisGMRef->getBoardSizeX() / 2; // update this after making game mechanics class and player class "talk" to each other (aka adding myGM pointer into myPlayer object!)
    playerPos.pos->y = thisGMRef->getBoardSizeY() / 2;
    playerPos.symbol = '@';
}

Player::~Player()
{
    // delete any heap members here
    // no keyword "new" in the constructor
    // leave destructor empty FOR NOW

    // delete playerPosList; //for iteration 3
}

// should change this to getPlayerHeadPos
objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPos;
}

// might need to create a getPlayerPosArrayList or smth for printing the snake on the game board

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

void Player::movePlayer()
{

    // iteration 3: should get headPos

    // PPA3 Finite State Machine logic
    switch (myDir)
    {
    case UP:
        playerPos.pos->y--;
        if (playerPos.pos->y == 0)
        {
            playerPos.pos->y = mainGameMechsRef->getBoardSizeY() - 2;
        }
        break;

    case DOWN:
        playerPos.pos->y++;
        if (playerPos.pos->y >= mainGameMechsRef->getBoardSizeY() - 1)
        {
            playerPos.pos->y = 1;
        }
        break;

    case LEFT:
        playerPos.pos->x--;
        if (playerPos.pos->x <= 0)
        {
            playerPos.pos->x = mainGameMechsRef->getBoardSizeX() - 2;
        }
        break;
    case RIGHT:
        playerPos.pos->x++;
        if (playerPos.pos->x >= mainGameMechsRef->getBoardSizeX() - 1)
        {
            playerPos.pos->x = 1;
        }
        break;
    default:
        break;
    }

    // need to do the insert new position for head and remove tail thing
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