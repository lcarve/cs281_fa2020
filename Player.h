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
    std::vector<Room*> m_pRoomsVisitedV;

public:
    Player();
    Player(std::string name);
    // players will persist for app lifetime
    // so destructor not needed
    //~Player();

    // code hooks for multiplayer support
    bool setId(int id);

    // Room visit tracking support
    int addRoomVisit(Room* pR);
    bool clearRoomVisits();
    int getRoomVisits(std::vector<Room*>& pRV);

    int addTreasure(Treasure* pT);
    Treasure* removeTreasure();

    int addWeapon(Weapon* pW);
    Weapon* removeWeapon();
    int useWeapon(Weapon* pW);
};

#endif