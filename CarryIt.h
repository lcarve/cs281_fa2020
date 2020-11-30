/******************************************************************************
* CarryIt.h
* CS 281-0798, Fall 2020
*
* CarryIt pure abstract class declaration
*******************************************************************************
*/
#ifndef CARRYIT_H
#define CARRYIT_H

// needed for overloading insertion operator <<
#include <iostream>

#include "Element.h"

int constexpr TREASURE_CARRYIT = 't';
int constexpr WEAPON_CARRYIT   = 'w';
int constexpr BOGEY_CARRYIT    = 'b';
int constexpr GENERIC_CARRYIT  = 'c';

//----------------------------------------------------------
// CarryIt class: abstract base class for carried items
//----------------------------------------------------------
class CarryIt : public Element
{
protected:
    int m_power;
    int m_roomInfo;
    int m_playerInfo;

public:
    CarryIt();
    // CarryIt instances will persist for app lifetime
    // so destructor not needed
    //~CarryIt();

    void setPower(int power);
    int getPower() const;
    int addPower(int morePower);

    // insertion operator overloading function must either
    //      1) be declared as a friend, or
    //      2) be defined inside the class

    friend std::ostream& operator<< (std::ostream& os, const CarryIt &item);
};

#endif