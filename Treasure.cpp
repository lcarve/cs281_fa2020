/******************************************************************************
* Treasure.cpp
* CS 281-0798, Fall 2020
*
* Treasure class definition
*******************************************************************************
*/
#include <string>

#include "CarryIt.h"
#include "Treasure.h"

// initialize static class instance count
int Treasure::m_tCount = 0;


//***********************************************************
// Treasure(string tName)
//
// overload constructor
//
// tName is a call by value string parameter
// to allow passing string literals
//***********************************************************
Treasure::Treasure(const std::string& tName, int points)
{
    // track instance count
    m_tCount++;

    m_id = TREASURE_CARRYIT;
    m_name = tName;
    m_points = points;
}

//***********************************************************
// Treasure()
//
// constructor
//***********************************************************
Treasure::Treasure() : Treasure("untold treasure", TREASURE_POINTS)
{ }


//***********************************************************
// getTreasureCount() : return static instance count 
//***********************************************************
int Treasure::getTreasureCount() const { return m_tCount; }



