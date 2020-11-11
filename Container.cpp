/******************************************************************************
* Container.cpp
* CS 281-0798, Fall 2020
*
* Container abstract class definition
*******************************************************************************
*/
#include <string>
#include <vector>

#include "Container.h"

//***********************************************************
// Container(string name)
//
// constructor
//***********************************************************
Container::Container()
{
    m_id = static_cast<int>(GENERIC_CONTAINER);
    m_name = "container";
}

//***********************************************************
// addTreasure()
//
// adds a Treasure instance pointer to the container's
// vector of Treasure instance pointers
//
// returns the number of treasures in the vector
//***********************************************************
int Container::addTreasure(Treasure* pT)
{
    m_pTreasureV.push_back(pT);
    return m_pTreasureV.size();
}

//***********************************************************
// removeTreasure()
//
// if the Treasure vector is not empty,
//  1) get the last Treasure in the vector
//  2) remove one Treasure from vector
//  3) return pointer to Treasure removed or nullptr
//***********************************************************
Treasure* Container::removeTreasure()
{
    return removeItem(m_pTreasureV);
}

//***********************************************************
// selectTreasure()
//
// if the Treasure vector is not empty,
//      get the Treasure that matches the passed name string
//***********************************************************
Treasure* Container::selectTreasure(const std::string& tName)
{
    return selectItem(tName, m_pTreasureV);
}

//***********************************************************
// getTreasureCount()
//
// return number of treasures in this Room
//***********************************************************
int Container::getTreasureCount() const
{
    return m_pTreasureV.size();
}

//***********************************************************
// getTreasureInfo()
//
// copy Treasure vector elements to passed vector
//
// return number of Treasure elements 
//***********************************************************
int Container::getTreasureInfo(std::vector<Treasure*>& tV)
{
    return getItemInfo(tV, m_pTreasureV);
}

//***********************************************************
// removeAllTreasure()
//***********************************************************
bool Container::removeAllTreasure()
{
    m_pTreasureV.clear();
    return true;
}

//***********************************************************
// addWeapon()
//
// adds a Weapon instance pointer to the container's
// vector of Weapon instance pointers
//
// returns the number of Weapons in the vector
//***********************************************************
int Container::addWeapon(Weapon* pW)
{
    m_pWeaponV.push_back(pW);
    return m_pWeaponV.size();
}

//***********************************************************
// removeWeapon()
//
// if the Weapon vector is not empty,
//  1) get the last Weapon in the vector
//  2) remove one Weapon from vector
//  3) return pointer to Weapon removed or nullptr
//***********************************************************
Weapon* Container::removeWeapon()
{
    return removeItem(m_pWeaponV);
}

//***********************************************************
// selectWeapon()
//
// if the Weapon vector is not empty,
//      get the Weapon that matches the passed name string
//***********************************************************
Weapon* Container::selectWeapon(const std::string& wName)
{
    return selectItem(wName, m_pWeaponV);
}

//***********************************************************
// getWeaponCount()
//
// return number of weapons in this Room
//***********************************************************
int Container::getWeaponCount() const
{
    return m_pWeaponV.size();
}

//***********************************************************
// getWeaponInfo()
//
// copy Weapon vector elements to passed vector
//
// return number of Weapon elements 
//***********************************************************
int Container::getWeaponInfo(std::vector<Weapon*>& wV)
{
    return getItemInfo(wV, m_pWeaponV);
}

//***********************************************************
// removeAllWeapon()
//***********************************************************
bool Container::removeAllWeapon()
{
    m_pWeaponV.clear();
    return true;
}

//***********************************************************
// addBogie()
//
// adds a Bogie instance pointer to the container's
// vector of Bogie instance pointers
//
// returns the number of Weapons in the vector
//***********************************************************
int Container::addBogie(Bogie* pB)
{
    m_pBogieV.push_back(pB);
    return m_pBogieV.size();
}

//***********************************************************
// removeBogie()
//
// if the Bogie vector is not empty,
//  1) get the last Bogie in the vector
//  2) remove one Bogie from vector
//  3) return pointer to Bogie removed or nullptr
//***********************************************************
Bogie* Container::removeBogie()
{
    return removeItem(m_pBogieV);
}

//***********************************************************
// selectBogie()
//
// if the Bogie vector is not empty,
//      get the Bogie that matches the passed name string
//***********************************************************
Bogie* Container::selectBogie(const std::string& bName)
{
    return selectItem(bName, m_pBogieV);
}

//***********************************************************
// getBogieCount()
//
// return number of Bogies in this Container
//***********************************************************
int Container::getBogieCount() const
{
    return m_pBogieV.size();
}

//***********************************************************
// getBogieInfo()
//
// copy Bogie vector elements to passed vector
//
// return number of Bogie elements 
//***********************************************************
int Container::getBogieInfo(std::vector<Bogie*>& bV)
{
    return getItemInfo(bV, m_pBogieV);
}

//***********************************************************
// removeAllBogie()
//***********************************************************
bool Container::removeAllBogie()
{
    m_pBogieV.clear();
    return true;
}

//***********************************************************
// getItemInfo() : function template
//
// copy item's vector elements to passed vector
//
// return number of vector elements 
//***********************************************************
template <class I> 
int Container::getItemInfo(std::vector<I*>& pDstIV,
                           std::vector<I*>& pSrcIV)
{
    if (pSrcIV.size() == 0)
        return 0;

    // copy values - prevent direct access to Container's vector
    for (I* item : pSrcIV)
        pDstIV.push_back(item);

    return pDstIV.size();
}

//***********************************************************
// addItem() : function template
//***********************************************************
template <class I>
int Container::addItem(I* pItem, std::vector<I*>& pIV)
{
    pIV.push_back(pItem);
    return pIV.size();
}

//***********************************************************
// removeItem() : function template
//
// if the item vector is not empty,
//  1) get the last item in the vector
//  2) remove one item from vector
//  3) return pointer to item removed or nullptr
//***********************************************************
template <class I>
I* Container::removeItem(std::vector<I*>& pIV)
{
    if (pIV.size() == 0)
        return nullptr;

    I* pItem = pIV.back();
    pIV.pop_back();

    return pItem;
}

//***********************************************************
// selectItem() : function template
//
// if the passed item vector is not empty,
//      return the item that matches the passed name string
//***********************************************************
template <class I>
I* Container::selectItem(const std::string& iName,
                         std::vector<I*>& pIV)
{
    std::string str;

    for (auto pI : pIV)
    {
        // check for matching item name
        pI->getName(str);
        if (iName.compare(str))
            return pI;
    }

    return nullptr;
}

