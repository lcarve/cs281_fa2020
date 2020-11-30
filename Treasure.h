/******************************************************************************
* Treasure.h
* CS 281-0798, Fall 2020
*
* Treasure class declaration
*******************************************************************************
*/
#ifndef TREASURE_H
#define TREASURE_H

#include <string>

// base class declaration
#include "CarryIt.h"

int constexpr TREASURE_POINTS = 100;

//----------------------------------------------------------
// Treasure class derived from base class for carried items
//----------------------------------------------------------
class Treasure : public CarryIt
{
private:
    static int m_tCount; // how many instances exist in game

public:
    Treasure();
    Treasure(const std::string& tName, int points);
    // Treasure persists for app lifetime
    // so destructor not needed
    //~Treasure();

    int getTreasureCount() const;
};

#endif
