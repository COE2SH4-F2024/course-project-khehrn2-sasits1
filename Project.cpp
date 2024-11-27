#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

#include "Player.h"
#include "GameMechs.h"

using namespace std;

#define DELAY_CONST 100000
// #define HEIGHT 10
// #define WIDTH 20

Player *myPlayer; // Global pointer meant to instantiate a player object on the heap
GameMechs *myGM;

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
    MacUILib_printf("Before Intialize\n"); // check
    Initialize();
    MacUILib_printf("After Initialize\n"); // check
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
    MacUILib_printf("Initialize()\n");
    MacUILib_init();
    MacUILib_clearScreen();

    myGM = new GameMechs(myGM->getBoardSizeX(), myGM->getBoardSizeY());
    myPlayer = new Player(myGM); // created a player object on the heap, myPlayer keeps track of the pointer myGM to the instance of the GameMechs object
    // myArrayList = new objPosArrayList(); // will use this in future iterations

    // exitFlag = false; don't need this bc GameMechs class alr initializes it to false!
}

void GetInput(void)
{
    MacUILib_printf("GetInput()\n");
    char input = myGM->getInput();
}

void RunLogic(void)
{
    char input = myGM->getInput();
    MacUILib_printf("RunLogic()\n");
    if (input == ' ')
    {
        myGM->setExitTrue(); // Exit if space is pressed
    }

    else if (input == 'i') // debug key? for increment
    {
        myGM->incrementScore();
        MacUILib_printf("Score is incremented by one. Current score: %d \n", myGM->getScore());
    }

    else if (input == '/')
    { // debug key for lose flag
        myGM->setLoseFlag();
    }

    myGM->clearInput();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    MacUILib_printf("DrawScreen()\n");
    objPos playerPos = myPlayer->getPlayerPos();

    int boardWidth = myGM->getBoardSizeX();
    int boardHeight = myGM->getBoardSizeY();

    // MacUILib_printf("Checkpoint 1!\n");
    MacUILib_printf("Player [x, y, sym] = [%d, %d, %c]\n", playerPos.pos->x, playerPos.pos->y, playerPos.symbol);

    for (int j = 0; j < boardHeight; j++) // // when j is between index 0 and 8, print "#"when i is between index 0 and 19, print "#"
    {
        for (int i = 0; i < boardWidth; i++) // when i is between index 0 and 19, print "#"
        {
            // int item = 0;
            // MacUILib_printf("Checkpoint 2!\n");
            if (j == 0 || j == boardHeight - 1 || i == 0 || i == boardWidth - 1)
            {
                MacUILib_printf("%c", '#');
            }

            else if (i == playerPos.pos->x && j == playerPos.pos->y)
            {
                MacUILib_printf("%c", playerPos.symbol);
                // item = 1;
                // continue;
            }
            // int k;
            // for(k = 0; k < 5; k++) // prints out the symbol for the random items on the board
            // {
            //     if(j == itemBin[k].y && i == itemBin[k].x)
            //     {
            //         MacUILib_printf("%c", itemBin[k].symbol);
            //         item = 1;
            //         break;
            //     }
            // }
            // if(!item){

            else
            {
                MacUILib_printf("%c", ' ');
            }
            //}
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
    MacUILib_clearScreen();

    delete myPlayer;
    delete myGM;

    MacUILib_uninit();
}
