/******************************************************************************
* Container.cpp
* CS 281-0798, Fall 2020
*
* Container pure abstract class definition
*******************************************************************************
*/
#include <string>
#include <vector>

#include "Container.h"

//***********************************************************
// Container(string name)
//
// constructor
//***********************************************************
Container::Container()
{
    m_id = -1;
    m_name = "container";
    m_points = 0;               // accumulated points
}

//***********************************************************
// setId() declared as pure virtual
//***********************************************************

//***********************************************************
// getId()
//***********************************************************
int Container::getId() const
{
    return m_id;
}

//***********************************************************
// setName()
//
// copies passed string into member string 
//***********************************************************
bool Container::setName(std::string& name)
{
    m_name = name;
    return true;
}

//***********************************************************
// getName()
//
// copies member string into caller's string    
//***********************************************************
bool Container::getName(std::string& str) const
{
    str = m_name;
    return true;
}

//***********************************************************
// addPoints()
//
// adds passed value to container's points
//***********************************************************
int Container::addPoints(int points) 
{
    m_points += points;
    return true;
}

//***********************************************************
// setPoints()
//
// sets container's points to passed value
//***********************************************************
bool Container::setPoints(int points)
{
    m_points = points;
    return true;
}

//***********************************************************
// getPoints()
//
// returns how many points the container has
//***********************************************************
int Container::getPoints() const { return m_points; }

//***********************************************************
// addTreasure()
//
// adds a Treasure instance pointer to the container's
// vector of Treasure instance pointers
//
// returns the number of treasures in the vector
//***********************************************************
int Container::addTreasure(Treasure* pT)
{
    m_pTreasureV.push_back(pT);
    return m_pTreasureV.size();
}

//***********************************************************
// removeTreasure()
//
// if the Treasure vector is not empty,
//  1) get the last Treasure in the vector
//  2) remove one Treasure from vector
//  3) return pointer to Treasure removed or nullptr
//***********************************************************
Treasure* Container::removeTreasure()
{
    if (m_pTreasureV.size() == 0)
        return nullptr;

    Treasure* pT = m_pTreasureV.back();
    // remove Treasure from vector
    m_pTreasureV.pop_back();

    return pT;
}

//***********************************************************
// getTreasureCount()
//
// return number of treasures in this Room
//***********************************************************
int Container::getTreasureCount() const
{
    return m_pTreasureV.size();
}

//***********************************************************
// getTreasureInfo()
//
// copy Treasure vector elements to passed vector
//
// return number of Treasure elements 
//***********************************************************
int Container::getTreasureInfo(std::vector<Treasure*>& tV) const
{
    if (m_pTreasureV.size() == 0)
        return 0;

    // copy values - prevent direct access to Container's vector
    for (Treasure* t : m_pTreasureV)
    {
        tV.push_back(t);
    }

    return tV.size();
}

//***********************************************************
// removeAllTreasure()
//***********************************************************
bool Container::removeAllTreasure()
{
    m_pTreasureV.clear();
    return true;
}

//***********************************************************
// addWeapon()
//
// adds a Weapon instance pointer to the container's
// vector of Weapon instance pointers
//
// returns the number of Weapons in the vector
//***********************************************************
int Container::addWeapon(Weapon* pW)
{
    m_pWeaponV.push_back(pW);
    return m_pWeaponV.size();
}

//***********************************************************
// removeWeapon()
//
// if the Weapon vector is not empty,
//  1) get the last Weapon in the vector
//  2) remove one Weapon from vector
//  3) return pointer to Treasure removed or nullptr
//***********************************************************
Weapon* Container::removeWeapon()
{
    if (m_pWeaponV.size() == 0)
        return nullptr;

    Weapon* pW = m_pWeaponV.back();
    // remove Treasure from vector
    m_pWeaponV.pop_back();

    return pW;
}

//***********************************************************
// getWeaponCount()
//
// return number of weapons in this Room
//***********************************************************
int Container::getWeaponCount() const
{
    return m_pWeaponV.size();
}

//***********************************************************
// getWeaponInfo()
//
// copy Weapon vector elements to passed vector
//
// return number of Weapon elements 
//***********************************************************
int Container::getWeaponInfo(std::vector<Weapon*>& wV) const
{
    if (m_pWeaponV.size() == 0)
        return 0;

    // copy values - prevent direct access to Container's vector
    for (Weapon* w : m_pWeaponV)
    {
        wV.push_back(w);
    }

    return wV.size();
}

//***********************************************************
// removeAllWeapon()
//***********************************************************
bool Container::removeAllWeapon()
{
    m_pWeaponV.clear();
    return true;
}

