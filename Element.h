/******************************************************************************
* Element.h
* CS 281-0798, Fall 2020
*
* Element base class declaration
* All classes for this game are derived from Element
*******************************************************************************
*/
#ifndef ELEMENT_H
#define ELEMENT_H

int constexpr GENERIC_ELEMENT = 'e';

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
    Element();

    int getId() const;
    
    void setName(const std::string& name);
    std::string& getName(std::string& name) const;
    
    int addPoints(int points);
    void setPoints(int points);
    int getPoints() const;

    void setText(const std::string& text);
    std::string& getText(std::string& text) const;
};

#endif