/******************************************************************************
* CarryIt.cpp
* CS 281-0798, Fall 2020
*
* CarryIt abstract class definition
*******************************************************************************
*/
#include <string>
#include <cstdlib>

#include "CarryIt.h"

// default carryable element characteristics
#define MAX_POWER    5
#define MIN_POWER    3

//***********************************************************
// CarryIt()
//
// constructor
//***********************************************************
CarryIt::CarryIt()
{
    m_id = static_cast<int>(GENERIC_CARRYIT);
    m_name = "carry me";

    m_power = rand() % MAX_POWER + MIN_POWER;
    m_roomInfo = 0;
    m_playerInfo = 0;
}

//***********************************************************
// setPower()
//***********************************************************
bool CarryIt::setPower(int power)
{
    m_power = power;
    return true;
}

//***********************************************************
// getPower()
//***********************************************************
int CarryIt::getPower() const
{
    return m_power;
}

//***********************************************************
// addPower()
//
// returns updated power setting
//***********************************************************
int CarryIt::addPower(int morePower)
{
    m_power += morePower;
    return m_power;
}
