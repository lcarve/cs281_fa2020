/******************************************************************************
* Bogey.cpp
* CS 281-0798, Fall 2020
*
* Bogey derived class definition
*******************************************************************************
*/
#include <string>

#include "Bogey.h"

//***********************************************************
// Bogey()
//
// overload constructor 1 of 2
//***********************************************************
Bogey::Bogey(std::string name, int points)
{ 
    m_id = BOGEY_CARRYIT;
    m_name = name;
    m_points = points;
}

//***********************************************************
// Bogey()
//
// overload constructor 2 of 2
//***********************************************************
Bogey::Bogey(std::string name)
{
    m_id = BOGEY_CARRYIT;
    m_name = name;
    m_points = BOGEY_POINTS;
}

//***********************************************************
// Bogey()
//
// constructor
//***********************************************************
Bogey::Bogey() : Bogey("bogie", BOGEY_POINTS) { }
