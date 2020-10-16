/******************************************************************************
* app_util.cpp
* CS 281 - 0798, Fall 2020
*
* Utility functions
*******************************************************************************
*/
#include <sstream>
#include <vector>

#include "app.h"

/******************************************************************************
* getInventory()
* 
* fill string buffer with messages
* return total number of things in given Container
*******************************************************************************
*/
int getInventory(Container* pC, std::vector<std::string>& msgQ)
{
    int total = 0;      // return value accumulator
    std::string str;    // message buffer

    // vector to be filled with Treasure names and text
    std::vector<Treasure*>pTreasureV;

    int nTreasure = pC->getTreasureInfo(pTreasureV);
    total += nTreasure;

    // vector to be filled with Weapon names and text
    std::vector<Weapon*>pWeaponV;

    int nWeapon = pC->getWeaponInfo(pWeaponV);
    total += nWeapon;

    // #TODO
    int nBogies = 0;
    total += nBogies;

    // #TODO
    int nMagicWords = 0;
    total += nMagicWords;

    // display Treasure available here
    if (nTreasure > 0)
    {
        // is this Container a Room?
        if (pC->getId() == 'r')
            str = "There is treasure here..";
        else
            str = "You have treasure!";
        msgQ.push_back(str);

        for (Treasure* pT : pTreasureV)
        {
            pT->getName(str);
            msgQ.push_back(str);
        }
    }

    // display weaponry available here
    if (nWeapon > 0)
    {
        // blank line between treasure and weapon lists
        if (nTreasure !=0)
            msgQ.push_back("\n");

        // is this Container a Room?
        if (pC->getId() == 'r')
            str = "There is weaponry here..";
        else
            str = "You have weaponry!";
        msgQ.push_back(str);

        for (Weapon* pW : pWeaponV)
        {
            pW->getName(str);
            msgQ.push_back(str);
        }

        msgQ.push_back("\n");
    }

    return total;
}

/******************************************************************************
* getInfo()
*
* for app exit message display
*******************************************************************************
*/
bool getInfo(Player* pP, Room* pR, std::vector<std::string>& msgQ)
{
    // display Player points
    std::stringstream ss;
    ss << "\nYou have " << pP->getPoints() << " points.\n";

    // display Room carryable items
    getInventory(pR, msgQ);

    // display Player carryable items
    getInventory(pP, msgQ);

    // display Player Rooms visited history
    std::vector<Room*> pRoomVisitsV;
    int nVisits = pP->getRoomVisits(pRoomVisitsV);

    // build visited Room list
    ss << "You have visited " << nVisits;
    if (nVisits > 1) 
        ss << " dimensions:";
    else
        ss << " dimension:";
    msgQ.push_back(ss.str());

    for (Room* pR : pRoomVisitsV)
    {
        std::string str;
        pR->getName(str);
        msgQ.push_back(str);
    }

    return true;
}

/******************************************************************************
* getAllInfo()
* 
* for handling I)nfo command
*******************************************************************************
*/
bool getAllInfo(Player* pP, Room* pR, std::vector<std::string>& msgQ)
{
    // display current Room name
    std::string str;
    pR->getName(str);
    msgQ.push_back("You're in " + str + ".");

    getInfo(pP, pR, msgQ);

    return true;
}
