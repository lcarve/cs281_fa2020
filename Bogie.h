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

#include "CarryIt.h"
#include "Container.h"

//----------------------------------------------------------
// Bogie class: derived from CarryIt and Container classes
//----------------------------------------------------------
class Bogie : public CarryIt, public Container
{
private:
    int m_id;               // to resolve compile time ambiguity
    std::string m_name;     // to resolve compile time ambiguity

public:
    Bogie();
    Bogie(std::string name);
    // Bogie instances will persist for app lifetime
    // so destructor not needed
    //~Bogie();

    // derived classes must implement this member function
    bool setId(int id);
};

#endif