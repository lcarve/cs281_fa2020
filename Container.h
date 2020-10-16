/******************************************************************************
* Container.h
* CS 281-0798, Fall 2020
*
* Container pure abstract class declaration
*******************************************************************************
*/
#ifndef CONTAINER_H
#define CONTAINER_H

#include <string>
#include <vector>

#include "CarryIt.h"
#include "Treasure.h"
#include "Weapon.h"

class Container
{
protected:
    int m_id;                             // internal use
    std::string m_name;                   // user supplied name
    int m_points;                         // accumulated points
    std::vector<Treasure*> m_pTreasureV;  // accumulated Treasure
    std::vector<Weapon*> m_pWeaponV;      // accumulated Weapons

    // mixed type carryable items vector for optional use
    std::vector<CarryIt*> m_pCarryItV;

public:
    Container();
    // Container instances will persist for app lifetime
    // so destructor not needed
    //~Container();

    // derived classes must implement this member function
    virtual bool setId(int id) = 0;

    int getId() const;

    bool setName(std::string& name);
    bool getName(std::string& str) const;

    int addPoints(int points);
    bool setPoints(int points);
    int getPoints() const;

    // Treasure management support
    int addTreasure(Treasure* pT);
    Treasure* removeTreasure();
    int getTreasureCount() const;
    int getTreasureInfo(std::vector<Treasure*>& pTV) const;
    bool removeAllTreasure();

    // Weapon management support
    int addWeapon(Weapon* pT);
    Weapon* removeWeapon();
    int getWeaponCount() const;
    int getWeaponInfo(std::vector<Weapon*>& pWV) const;
    bool removeAllWeapon();

};

#endif
