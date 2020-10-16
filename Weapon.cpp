/******************************************************************************
* Weapon.cpp
* CS 281-0798, Fall 2020
*
* Weapon class definition
*******************************************************************************
*/
#include <string>

#include "Weapon.h"

// default Weapon characteristics
#define WEAPON_DEFAULT_USES     3
#define WEAPON_DEFAULT_POWER    5

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
    m_id = static_cast<int>('w');   // 'w' means Weapon
    m_name = wName;
    m_usesRemaining = WEAPON_DEFAULT_USES;
    m_powerRating = WEAPON_DEFAULT_POWER;
}

//***********************************************************
// Weapon()
//
// constructor
//***********************************************************
Weapon::Weapon() : Weapon("weapon of protection")
{ }

//***********************************************************
// setId()
//
// must implement this member function because
// it's declared as pure virtual in base class CarryIt
//
// identify Weapon class or unique Weapon
//
// NOTE: member variable m_id is initialized to (int) 'w'
// in constructor
//
// set m_id to passed value
//***********************************************************
bool Weapon::setId(int id)
{
    m_id = id;
    return true;
}

//***********************************************************
// setUsesRemaining()
//***********************************************************
bool Weapon::setUsesRemaining(int uses)
{
    m_usesRemaining = uses;
    return true;
}

//***********************************************************
// getUsesRemaining()
//
// returns number of uses remaining for this Weapon
//***********************************************************
int Weapon::getUsesRemaining() const { return m_usesRemaining; }

//***********************************************************
// addUsesRemaining()
//
// returns updated number of uses remaining for this Weapon
//***********************************************************
int Weapon::addUsesRemaining(int uses)
{
    m_usesRemaining += uses;
    return m_usesRemaining;
}

//***********************************************************
// setPower()
//
// sets power rating for this Weapon
//***********************************************************
bool Weapon::setPower(int power)
{
    m_powerRating = power;
    return true;
}

//***********************************************************
// getUsesRemaining()
//
// returns number of uses remaining for this Weapon
//***********************************************************
int Weapon::getPower() const { return m_powerRating; }

