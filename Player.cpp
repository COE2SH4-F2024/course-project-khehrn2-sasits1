#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.pos->x = 5; // update this after making game mechanics class and player class "talk" to each other (aka adding myGM pointer into myPlayer object!)
    playerPos.pos->y = 5;
    playerPos.symbol = '@';
}


Player::~Player()
{
    // delete any heap members here
    // no keyword "new" in the constructor
    // leave destructor empty FOR NOW
}

objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPos;
}

// void Player::updatePlayerDir()
// {
//         if(input != 0)  // if not null character
//         {
//             switch(input)
//             {
//                 // case ' ':
//                 //     exitFlag = 1;
//                 //     break;

//                 case 'W': // Up
//                 case 'w':
//                 if(myDir != UP && myDir != DOWN)
//                 {
//                     myDir = UP;
//                 }
//                 break;

//                 case 'S': // Down
//                 case 's':
//                 if(myDir != DOWN && myDir != UP)
//                 {
//                     myDir = DOWN;
//                 }
//                 break;

//                 case 'A': // Left
//                 case 'a':
//                 if(myDir != LEFT && myDir != RIGHT)
//                 {
//                     myDir = LEFT;
//                 }
//                 break;

//                 case 'D': // Right
//                 case 'd':
//                 if(myDir != RIGHT && myDir != LEFT)
//                 {
//                     myDir = RIGHT;
//                 }
//                 break;

//                 default:
//                     break;
//             }
//         // input = 0; //reset input
//         }

//         // PPA3 input processing logic          
// }

// void Player::movePlayer()
// {
//     // PPA3 Finite State Machine logic
// }

// // More methods to be added