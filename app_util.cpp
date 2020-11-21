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
    int total = 0;              // return value accumulator
    std::string str;            // message buffers
    char cType = pC->getId();   // ROOM_CONTAINER or PLAYER_CONTAINER

    // vector to be filled with Bogey names and text
    std::vector<Bogey*> pBogeyV;
    int nBogey = pC->getBogeyInfo(pBogeyV);
    total += nBogey;

    // display Bogeys present
    if (nBogey > 0)
    {
        std::stringstream ss;

        ss << "\n";

        // is this Container a Room?
        if (cType == ROOM_CONTAINER)
            ss << "There is an unfriendly here..\n";
        else if (nBogey > 1)
            ss << "You've defeated " << nBogey << " unfriendlies!\n";
        else
            ss << "You've defeated an unfriendly!\n";

        // display Bogey name and power
        for (Bogey* pB : pBogeyV)
        {
            pB->getName(str);
            ss << str << " [" << pB->getPower()
                << "] (" << pB->getPoints() << ")\n";
        }

        msgQ.push_back(ss.str());
    }

    // vector to be filled with Weapon names and text
    std::vector<Weapon*> pWeaponV;
    int nWeapon = pC->getWeaponInfo(pWeaponV);
    total += nWeapon;

    // display weaponry available here
    if (nWeapon > 0)
    {
        std::stringstream ss;

        // is this Container a Room?
        if (cType == ROOM_CONTAINER)
            ss << "There is weaponry here..\n";
        else
            ss << "You have weaponry!\n";

        // display Weapon name, power, and points
        for (Weapon* pW : pWeaponV)
        {
            pW->getName(str);
            ss << str << " [" << pW->getPower() 
                << "] (" << pW->getPoints() << ")\n";
        }

        msgQ.push_back(ss.str());
    }

    // vector to be filled with Treasure names and text
    std::vector<Treasure*>pTreasureV;
    int nTreasure = pC->getTreasureInfo(pTreasureV);
    total += nTreasure;

    // display Treasure available here
    if (nTreasure > 0)
    {
        std::stringstream ss;

        // is this Container a Room?
        if (cType == ROOM_CONTAINER)
            ss << "There is treasure here..\n";
        else
            ss << "You have treasure!\n";

        // display Treasure name only
        for (Treasure* pT : pTreasureV)
            ss << pT->getName(str) << " (" << pT->getPoints() << ")\n";

        msgQ.push_back(ss.str());
    }

    // #TODO
    int nMagicWord = 0;
    total += nMagicWord;

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
    // display Player points and number of lives left
    std::stringstream ss;
    ss << "You have " << pP->getPoints() << " points.\n";
    ss << "You have " << pP->getLives() << " lives left.\n\n";

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
        ss << " dimensions:\n";
    else
        ss << " dimension:\n";
    msgQ.push_back(ss.str());

    for (Room* pR : pRoomVisitsV)
    {
        std::string str;
        ss << pR->getName(str) << "\n";
    }

    // display count of each class instance
    ss << "\n";
    ss << "Total players: " << pP->getPlayerCount() << "\n";
    ss << "Total dimensions: " << pR->getRoomCount() << "\n";
    Treasure t;
    ss << "Total treasures: " << t.getTreasureCount() << "\n";
    Weapon w;
    ss << "Total weapons: " << w.getWeaponCount() << "\n";
    Bogey b;
    ss << "Total unfriendlies: " << b.getBogeyCount() << "\n";
    msgQ.push_back(ss.str());

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
