#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

#include "Player.h"
#include "GameMechs.h"
#include "Food.h"

using namespace std;

#define DELAY_CONST 100000
// #define HEIGHT 10
// #define WIDTH 20

Player *myPlayer; // Global pointer meant to instantiate a player object on the heap
GameMechs *myGM;

Food *myFood;

// objPosArrayList *myArrayList; // will use in future iterations

// bool exitFlag; will not need this bc of GameMechs class!

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

int main(void)
{
    // MacUILib_printf("Before Intialize\n"); // check
    Initialize();
    // MacUILib_printf("After Initialize\n"); // check
    while (myGM->getExitFlagStatus() == false)
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();
}

void Initialize(void)
{
    // MacUILib_printf("Initialize()\n");
    MacUILib_init();
    MacUILib_clearScreen();

    myGM = new GameMechs(20, 10);
    myPlayer = new Player(myGM); // created a player object on the heap, myPlayer keeps track of the pointer myGM to the instance of the GameMechs object
    myFood = new Food(myGM);

    myFood->generateFood(myPlayer->getPlayerPos());
    // myArrayList = new objPosArrayList(); // will use this in future iterations

    // exitFlag = false; don't need this bc GameMechs class alr initializes it to false!
}

void GetInput(void)
{
    // MacUILib_printf("GetInput()\n");
    char input = myGM->getInput();
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();
    // myPlayer->speedControl();

    char input = myGM->getInput();
    // MacUILib_printf("RunLogic()\n");
    if (input == ' ')
    {
        myGM->setExitTrue(); // Exit if space is pressed
    }

    else if (input == 'i') // debug key? for increment
    {
        myGM->incrementScore();
        // MacUILib_printf("Score is incremented by one. Current score: %d \n", myGM->getScore());
    }

    else if (input == 'f')
    {
        myFood->generateFood(myPlayer->getPlayerPos());
    }

    else if (input == '/')
    { // debug key for lose flag
        myGM->setLoseFlag();
    }

    myGM->clearInput();
    myFood->clearInput();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    // MacUILib_printf("DrawScreen()\n");
    objPos playerPos = myPlayer->getPlayerPos();
    objPos foodPos = myFood->getFoodPos();

    int boardX = myGM->getBoardSizeX();
    int boardY = myGM->getBoardSizeY();

    // MacUILib_printf("Checkpoint 1!\n");
    MacUILib_printf("Player [x, y, sym] = [%d, %d, %c]\n", playerPos.pos->x, playerPos.pos->y, playerPos.symbol);
    MacUILib_printf("Food Position: [%d, %d, %c]\n", foodPos.pos->x, foodPos.pos->y, foodPos.symbol);
    // j is row, i is column
    for (int j = 0; j < boardY; j++) // // when j is between index 0 and 8, print "#"when i is between index 0 and 19, print "#"
    {
        for (int i = 0; i < boardX; i++) // when i is between index 0 and 19, print "#"
        {
            // int item = 0;
            // MacUILib_printf("Checkpoint 2!\n");
            if (j == 0 || j == boardY - 1 || i == 0 || i == boardX - 1)
            {
                MacUILib_printf("%c", '#');
            }

            else if (i == playerPos.pos->x && j == playerPos.pos->y)
            {
                MacUILib_printf("%c", playerPos.symbol);
                // item = 1;
                // continue;
            }

            else if (j == foodPos.pos->y && i == foodPos.pos->x)
            { // Draw Food Character
                MacUILib_printf("%c", foodPos.symbol);
            }
            else
            {
                MacUILib_printf("%c", ' ');
            }
        }
        MacUILib_printf("%c", '\n');
    }
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}

void CleanUp(void)
{
    // MacUILib_clearScreen();

    delete myPlayer;
    delete myGM;
    delete myFood;

    MacUILib_uninit();
}
