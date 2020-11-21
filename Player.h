/******************************************************************************
* Player.h
* CS 281-0798, Fall 2020
*
* Player class declaration
*******************************************************************************
*/
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

#include "Treasure.h"
#include "Weapon.h"
#include "Container.h"

constexpr int PLAYER_LIVES = 3;

//----------------------------------------------------------
// Player class derived from base class for containers
//----------------------------------------------------------
class Player : public Container
{
private:
    static int m_pCount; // how many instances exist in game

    int m_nLives;        // number of lives
    std::vector<Room*> m_pRoomsVisitedV;

public:
    Player();
    Player(const std::string& name, int nLives);
    Player(const std::string& name);
    // players will persist for app lifetime
    // so destructor not needed
    //~Player();

    int getPlayerCount() const;

    int getLives() const;
    int setLives(int n);
    int addLives(int n);
    int loseLife();

    // Room visit tracking support
    int addRoomVisit(Room* pR);
    void clearRoomVisits();
    int getRoomVisits(std::vector<Room*>& pRV);

    int addTreasure(Treasure* pT);
    Treasure* removeTreasure();

    int addWeapon(Weapon* pW);
    Weapon* removeWeapon();
};

#endif