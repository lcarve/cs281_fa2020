/******************************************************************************
* Bogey.h
* CS 281-0798, Fall 2020
*
* Bogey class declaration
*******************************************************************************
*/
#ifndef BOGEY_H
#define BOGEY_H

#include <string>

#include "Element.h"
#include "CarryIt.h"

int constexpr BOGEY_POINTS = 100;

//----------------------------------------------------------
// Bogey class: derived from CarryIt and Container classes
//----------------------------------------------------------
class Bogey : public CarryIt
{
private:
    static int m_bCount;

public:
    Bogey();
    Bogey(std::string name);
    Bogey(std::string name, int points);
    // Bogey instances will persist for app lifetime
    // so destructor not needed
    //~Bogey();

    int getBogeyCount() const;
};

#endif