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

#include "Treasure.h"
#include "Weapon.h"
#include "Bogie.h"

#define ROOM_CONTAINER      'R'
#define PLAYER_CONTAINER    'P'
#define GENERIC_CONTAINER   'C'

class Container : public Element
{
protected:
    std::vector<Treasure*> m_pTreasureV;  // accumulated Treasure
    std::vector<Weapon*> m_pWeaponV;      // accumulated Weapons
    std::vector<Bogie*> m_pBogieV;        // accumulated Bogies

public:
    Container();
    // Container instances will persist for app lifetime
    // so destructor not needed
    //~Container();

    // Treasure management
    int addTreasure(Treasure* pT);
    Treasure* removeTreasure();
    Treasure* selectTreasure(const std::string& tName);
    int getTreasureCount() const;
    int getTreasureInfo(std::vector<Treasure*>& pTV);
    bool removeAllTreasure();

    // Weapon management
    int addWeapon(Weapon* pT);
    Weapon* removeWeapon();
    Weapon* selectWeapon(const std::string& wName);
    int getWeaponCount() const;
    int getWeaponInfo(std::vector<Weapon*>& pWV);
    bool removeAllWeapon();

    // Bogie management
    int addBogie(Bogie* pB);
    Bogie* removeBogie();
    Bogie* selectBogie(const std::string& bName);
    int getBogieCount() const;
    int getBogieInfo(std::vector<Bogie*>& pBV);
    bool removeAllBogie();

private:
    template <class I>
    int getItemInfo(std::vector<I*>& pDstIV,
        std::vector<I*>& pSrcIV);

    template <class I>
    int addItem(I* pItem, std::vector<I*>& pIV);

    template <class I>
    I* removeItem(std::vector<I*>& pIV);

    template <class I>
    I* selectItem(const std::string& iName, std::vector<I*>& pIV);

};

#endif
