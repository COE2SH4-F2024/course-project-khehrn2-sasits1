#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

#include "Player.h"

using namespace std;

#define DELAY_CONST 100000
#define HEIGHT 10
#define WIDTH 20

Player *myPlayer; // Global pointer meant to instantiate a player object on the heap

bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(exitFlag == false)  
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
    MacUILib_init();
    MacUILib_clearScreen();

    // need to pass myGM pointer where nullptr is in myPlayer object!
    myPlayer = new Player(nullptr); // created a player object on the heap
    
    exitFlag = false;
}

void GetInput(void)
{
   
}

void RunLogic(void)
{
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();

    objPos playerPos = myPlayer->getPlayerPos();
   
    MacUILib_printf("Player [x, y, sym] = [%d, %d, %c]\n", playerPos.pos->x, playerPos.pos->y, playerPos.symbol); 

    for(int j = 0; j < HEIGHT; j++) // // when j is between index 0 and 8, print "#"when i is between index 0 and 19, print "#"
    {
        for(int i = 0; i < WIDTH; i++) // when i is between index 0 and 19, print "#"
        {
            //int item = 0;
            if(i == playerPos.pos->x && j == playerPos.pos->y)
            {
                MacUILib_printf("%c", playerPos.symbol);
                //item = 1;
                //continue;
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
            //if(!item)
            {
                if(j == 0 || j == HEIGHT - 1 || i == 0 || i == WIDTH - 1) 
                {
                    MacUILib_printf("%c",'#');
                }
                else
                {
                    MacUILib_printf("%c",' ');
                }
            }
        }
        MacUILib_printf("%c",'\n');
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

    MacUILib_uninit();
}
