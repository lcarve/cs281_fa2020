/******************************************************************************
* CarryIt.h
* CS 281-0798, Fall 2020
*
* CarryIt pure abstract class declaration
*******************************************************************************
*/
#ifndef CARRYIT_H
#define CARRYIT_H

#include "Element.h"

#define TREASURE_CARRYIT    't'
#define WEAPON_CARRYIT      'w'
#define BOGIE_CARRYIT       'b'
#define GENERIC_CARRYIT     'c'

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

    bool setPower(int power);
    int getPower() const;
    int addPower(int morePower);
};

#endif