/******************************************************************************
* Weapon.cpp
* CS 281-0798, Fall 2020
*
* Weapon class definition
*******************************************************************************
*/
#include <string>

#include "Weapon.h"

//***********************************************************
// Weapon(string wName)
//
// overload constructor
//
// wName is a call by value string parameter
// to allow passing string literals
//***********************************************************
Weapon::Weapon(std::string wName)
{
    m_id = static_cast<int>(WEAPON_CARRYIT);
    m_name = wName;
}

//***********************************************************
// Weapon()
//
// constructor
//***********************************************************
Weapon::Weapon() : Weapon("weapon of protection")
{ }

