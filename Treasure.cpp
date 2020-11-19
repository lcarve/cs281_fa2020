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

