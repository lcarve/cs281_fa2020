/******************************************************************************
* Bogie.h
* CS 281-0798, Fall 2020
*
* Bogie class declaration
*******************************************************************************
*/
#ifndef BOGIE_H
#define BOGIE_H

#include <string>

#include "Element.h"
#include "CarryIt.h"

//----------------------------------------------------------
// Bogie class: derived from CarryIt and Container classes
//----------------------------------------------------------
class Bogie : public CarryIt
{
public:
    Bogie();
    Bogie(std::string name);
    // Bogie instances will persist for app lifetime
    // so destructor not needed
    //~Bogie();

};

#endif