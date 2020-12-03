/******************************************************************************
* Weapon.h
* CS 281-0798, Fall 2020
*
* Weapon class declaration
*******************************************************************************
*/
#ifndef WEAPON_H
#define WEAPON_H

#include <string>

// base class declaration
#include "CarryIt.h"

int constexpr WEAPON_POINTS = 100;
int constexpr WEAPON_USES = 1;

//----------------------------------------------------------
// Weapon class derived from base class for carried items
//----------------------------------------------------------
class Weapon : public CarryIt
{
private:
    int m_usesRemaining;

    static int m_wCount; // how many instances exist in game

public:
    Weapon();
    Weapon(const std::string& wName, int points);
    // Weapon persists for app lifetime
    // so destructor not needed
    //~Weapon();

    // static member function allows call without a class instance
    static int getWeaponCount();

    int setUsesRemaining(int uses);
    int getUsesRemaining() const;
    int addUsesRemaining(int uses);
};

#endif
