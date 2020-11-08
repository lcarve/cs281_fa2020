/******************************************************************************
* Player.cpp
* CS 281-0798, Fall 2020
*
* Player class definition
*******************************************************************************
*/
#include <string>
#include <vector>

#include "Room.h"
#include "Player.h"
#include "Treasure.h"

//***********************************************************
// Player(string name)
//
// overload constructor
//***********************************************************
Player::Player(std::string name, int nLives)
{
    m_id = static_cast<int>(PLAYER_CONTAINER);
    m_name = name;
    m_nLives = nLives;
}

//***********************************************************
// Player()
//
// constructor
//***********************************************************
Player::Player() : Player("player 1", 1) { }

//***********************************************************
// getLives()
//***********************************************************
int Player::getLives() const { return m_nLives; }

//***********************************************************
// setLives()
//***********************************************************
int Player::setLives(int n) { m_nLives = n; return n; }

//***********************************************************
// addLives()
//***********************************************************
int Player::addLives(int n) { m_nLives += n; return m_nLives; }

//***********************************************************
// loseLife()
//***********************************************************
int Player::loseLife() { m_nLives--;  return m_nLives; }

//***********************************************************
// addRoomVisit()
//
// adds Room pointer to Player's Room visit history
//***********************************************************
int Player::addRoomVisit(Room* pR)
{
    m_pRoomsVisitedV.push_back(pR);
    return m_pRoomsVisitedV.size();
}

//***********************************************************
// clearRoomVisits()
//
// clears Player's Room visit history
//***********************************************************
bool Player::clearRoomVisits()
{
    m_pRoomsVisitedV.clear();
    return true;
}

//***********************************************************
// getRoomVisits()
//
// returns the Player's number of Room visits
//***********************************************************
int Player::getRoomVisits(std::vector<Room*>& pRV)
{
    pRV.clear();
    for (Room* pR : m_pRoomsVisitedV)
    {
        pRV.push_back(pR);
    }
    return m_pRoomsVisitedV.size(); 
}

//***********************************************************
// addTreasure()
//
// adds a Treasure instance pointer to the container's
// vector of Treasure instance pointers
//
// returns the number of treasures in the vector
//***********************************************************
int Player::addTreasure(Treasure* pT)
{
    int n = Container::addTreasure(pT);

    // update Player points
    m_points += pT->getPoints();

    return n;
}

//***********************************************************
// removeTreasure()
//
// if the Treasure vector is not empty,
//  1) get the last Treasure in the vector
//  2) remove one Treasure from vector
//  3) take away Player Treasure points
//  4) return pointer to Treasure taken from Player or nullptr
//***********************************************************
Treasure* Player::removeTreasure()
{
    Treasure* pT = Container::removeTreasure();

    // update Player points
    if (pT != nullptr)
        m_points -= pT->getPoints();

    return pT;
}

//***********************************************************
// addWeapon()
//
// adds a Weapon instance pointer to the Player's
// vector of Weapon instance pointers
//
// returns the number of Weapons in the vector
//***********************************************************
int Player::addWeapon(Weapon* pW)
{
    int n = Container::addWeapon(pW);

    // update Player points
    m_points += pW->getPoints();

    return n;
}

//***********************************************************
// removeWeapon()
//
// if the Weapon vector is not empty,
//  1) get the last Weapon in the vector
//  2) remove one Weapon from vector
//  3) take away Player Weapon points
//  4) return pointer to Weapon taken from Player or nullptr
//***********************************************************
Weapon* Player::removeWeapon()
{
    Weapon* pW = Container::removeWeapon();

    // update Player points
    if (pW != nullptr)
        m_points -= pW->getPoints();

    return pW;
}




