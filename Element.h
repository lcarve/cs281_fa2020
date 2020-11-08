/******************************************************************************
* Element.h
* CS 281-0798, Fall 2020
*
* Element pure abstract class declaration
*******************************************************************************
*/
#ifndef ELEMENT_H
#define ELEMENT_H

//----------------------------------------------------------
// Element class:
//      base class for all other classes
//----------------------------------------------------------
class Element
{
protected:
    int m_id;              // set in constructor for internal use
    std::string m_name;    // element name
    std::string m_text;    // descriptive text
    int m_points;          // accumulated points

public:
    int getId() const;
    
    bool setName(const std::string& name);
    bool getName(std::string& name) const;
    
    int addPoints(int points);
    bool setPoints(int points);
    int getPoints() const;

    bool setText(const std::string& text);
    bool getText(std::string& text) const;
};

#endif