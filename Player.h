#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

public:
    enum Dir
    {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        STOP
    }; // This is the direction state

    Player(GameMechs *thisGMRef, Food *thisFood); // GameMechs class is passed by reference as pointer into the Player class
    ~Player();                                    // destructor, deletes heap members to prevent memory leakage.

    // objPos getPlayerPos() const; // Upgrade this in iteration 3.

    objPos getPlayerHeadPos() const; // updated: uncomment after triple-checking objPosArrayList
    objPosArrayList *getPlayerPosList() const;
    void updatePlayerDir();
    void movePlayer(objPos foodPos);
    void speedControl();

    // More methods to be added here

private:
    // objPos playerPos; // Upgrade this in iteration 3.

    objPosArrayList *playerPosList; // Iteration 3 Update
    enum Dir myDir;
    // Food *genFood;

    // Need a reference to the Main Game Mechanisms
    GameMechs *mainGameMechsRef;
    Food *mainFoodRef;

    objPos *foodPos;
};

#endif