/******************************************************************************
* CarryIt.h
* CS 281-0798, Fall 2020
*
* CarryIt pure abstract class declaration
*******************************************************************************
*/
#ifndef CARRYIT_H
#define CARRYIT_H

//----------------------------------------------------------
// CarryIt class: pure abstract base class for carried items
//----------------------------------------------------------
class CarryIt
{
protected:
    int m_id;
    std::string m_name;
    std::string m_text;
    int m_points;
    int m_roomNow;
    int m_playerNow;

public:
    CarryIt();
    // CarryIt instances will persist for app lifetime
    // so destructor not needed
    //~CarryIt();

    // derived classes must implement this member function
    virtual bool setId(int id) = 0;

    int getId() const;

    bool setName(std::string& name);
    bool getName(std::string& name) const;

    bool setPoints(int points);
    int getPoints() const;

    bool setText(std::string& text);
    bool getText(std::string& text) const;

};

#endif