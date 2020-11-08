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

class Player : public Container
{
private:
    int m_nLives;   // number of lives
    std::vector<Room*> m_pRoomsVisitedV;

public:
    Player();
    Player(std::string name, int nLives);
    // players will persist for app lifetime
    // so destructor not needed
    //~Player();

    int getLives() const;
    int setLives(int n);
    int addLives(int n);
    int loseLife();

    // Room visit tracking support
    int addRoomVisit(Room* pR);
    bool clearRoomVisits();
    int getRoomVisits(std::vector<Room*>& pRV);

    int addTreasure(Treasure* pT);
    Treasure* removeTreasure();

    int addWeapon(Weapon* pW);
    Weapon* removeWeapon();
};

#endif