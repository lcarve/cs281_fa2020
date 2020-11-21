/******************************************************************************
* Weapon.cpp
* CS 281-0798, Fall 2020
*
* Weapon class definition
*******************************************************************************
*/
#include <string>

#include "Weapon.h"

// initialize static class instance count
int Weapon::m_wCount = 0;


//***********************************************************
// Weapon(string wName)
//
// overload constructor
//
// wName is a call by value string parameter
// to allow passing string literals
//***********************************************************
Weapon::Weapon(const std::string& wName, int points)
{
    // track instance count
    m_wCount++;

    m_id = WEAPON_CARRYIT;
    m_name = wName;
    m_points = points;
}

//***********************************************************
// Weapon()
//
// constructor
//***********************************************************
Weapon::Weapon() : Weapon("weapon of protection", WEAPON_POINTS)
{ }

//***********************************************************
// getWeaponCount() : return static instance count 
//***********************************************************
int Weapon::getWeaponCount() const { return m_wCount; }


//***********************************************************
// setUsesRemaining()
//***********************************************************
int Weapon::setUsesRemaining(int uses)
{
    return m_usesRemaining = uses;
}

//***********************************************************
// getUsesRemaining()
//***********************************************************
int Weapon::getUsesRemaining() const
{
    return m_usesRemaining;
}

//***********************************************************
// addUsesRemaining()
//***********************************************************
int Weapon::addUsesRemaining(int uses)
{
    return m_usesRemaining += uses;
}
