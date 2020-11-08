/******************************************************************************
* Container.cpp
* CS 281-0798, Fall 2020
*
* Container abstract class definition
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
    m_id = static_cast<int>(GENERIC_CONTAINER);
    m_name = "container";
}

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
int Container::getTreasureInfo(std::vector<Treasure*>& tV)
{
    if (m_pTreasureV.size() == 0)
        return 0;

    // copy values - prevent direct access to Container's vector
    for (Treasure* t : m_pTreasureV)
        tV.push_back(t);

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
//  3) return pointer to Weapon removed or nullptr
//***********************************************************
Weapon* Container::removeWeapon()
{
    if (m_pWeaponV.size() == 0)
        return nullptr;

    Weapon* pW = m_pWeaponV.back();
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
int Container::getWeaponInfo(std::vector<Weapon*>& wV)
{
    if (m_pWeaponV.size() == 0)
        return 0;

    // copy values - prevent direct access to Container's vector
    for (Weapon* w : m_pWeaponV)
        wV.push_back(w);

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

//***********************************************************
// addBogie()
//
// adds a Bogie instance pointer to the container's
// vector of Bogie instance pointers
//
// returns the number of Weapons in the vector
//***********************************************************
int Container::addBogie(Bogie* pB)
{
    m_pBogieV.push_back(pB);
    return m_pBogieV.size();
}

//***********************************************************
// removeBogie()
//
// if the Bogie vector is not empty,
//  1) get the last Bogie in the vector
//  2) remove one Bogie from vector
//  3) return pointer to Bogie removed or nullptr
//***********************************************************
Bogie* Container::removeBogie()
{
    if (m_pBogieV.size() == 0)
        return nullptr;

    Bogie* pB = m_pBogieV.back();
    m_pBogieV.pop_back();

    return pB;
}

//***********************************************************
// getBogieCount()
//
// return number of Bogies in this Container
//***********************************************************
int Container::getBogieCount() const
{
    return m_pBogieV.size();
}

//***********************************************************
// getBogieInfo()
//
// copy Bogie vector elements to passed vector
//
// return number of Bogie elements 
//***********************************************************
int Container::getBogieInfo(std::vector<Bogie*>& bV)
{
    if (m_pBogieV.size() == 0)
        return 0;

    // copy values - prevent direct access to Container's vector
    for (Bogie* b : m_pBogieV)
        bV.push_back(b);

    return bV.size();
}

//***********************************************************
// removeAllBogie()
//***********************************************************
bool Container::removeAllBogie()
{
    m_pBogieV.clear();
    return true;
}

