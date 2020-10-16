/******************************************************************************
* app_player.cpp
* CS 281 - 0798, Fall 2020
*
* Player initialization and management functions
*******************************************************************************
*/
#include <sstream>
#include <vector>

#include "app.h"

/******************************************************************************
* grabTreasure()
*
* transfer Treasure from Room to Player
* fill caller's vector with messages for display
*******************************************************************************
*/
bool grabTreasure(Player* pPlayer, Room* pRoom, std::vector<std::string>& msgQ)
{
    Treasure* pTreasure = pRoom->removeTreasure();

    if (pTreasure == nullptr)
    {
        msgQ.push_back("There's no treasure here.");
        return false;
    }

    pPlayer->addTreasure(pTreasure);
    std::string str;
    pTreasure->getName(str);

    // build message string with string stream
    std::stringstream ss;
    ss << "you have a " << str << " worth "
        << pTreasure->getPoints() << " points";

    // add completed message string to caller's vector
    msgQ.push_back(ss.str());

    return true;
}

/******************************************************************************
* dropTreasure()
*
* transfer Treasure from Player to Room
* fill caller's vector with message strings for display
*******************************************************************************
*/
bool dropTreasure(Player* pPlayer, Room* pRoom, std::vector<std::string>& msgQ)
{
    Treasure* pTreasure = pPlayer->removeTreasure();

    if (pTreasure == nullptr)
    {
        msgQ.push_back("Your pockets are empty!");
        return false;
    }

    // transfer Treasure from Player to Room
    pRoom->addTreasure(pTreasure);

    // for queueing display message
    std::string str;
    pTreasure->getName(str);

    msgQ.push_back("You dropped a " + str);

    return true;
}

/******************************************************************************
* grabWeapon()
*
* transfer Weapon from Room to Player
* add messages to caller's vector for display
*******************************************************************************
*/
bool grabWeapon(Player* pPlayer, Room* pRoom, std::vector<std::string>& msgQ)
{
    Weapon* pWeapon = pRoom->removeWeapon();

    if (pWeapon == nullptr)
    {
        msgQ.push_back("There's no weapon here.");
        return false;
    }

    pPlayer->addWeapon(pWeapon);
    std::string str;
    pWeapon->getName(str);

    // build message string with string stream
    std::stringstream ss;
    ss << "you have a " << str << " worth "
        << pWeapon->getPoints() << " points";

    // copy completed message string to caller's vector
    msgQ.push_back(ss.str());

    return true;
}

/******************************************************************************
* lookAllDirections()
*
* add all direction text in current Room to caller's message vector
*******************************************************************************
*/
bool lookAllDirections(Room* pRoom, std::vector<std::string>& msgQ)
{
    // utility buffer gets stomped every time through loop
    std::string str;

    // add text for all directions to caller's vector
    for (int i = 0; i < ROOM_NDIR; i++)
    {
        pRoom->getDirectionText(i, str);

        // only display text for diretions we're using 
        if (str != "")
            msgQ.push_back(str);
    }

    // display things in Room
    getInventory(pRoom, msgQ);

    return true;
}

/******************************************************************************
* movePlayer()
*
* look up pointer to next Room in given direction
* if there's a Room in that direction,
* display exit text in current Room
*
* return pointer to the new Room,
* or pointer to same Room if no Room in that direction
*
*******************************************************************************
*/
Room* movePlayer(Player* pP, Room* pR, int direction, std::vector<std::string>& msgQ)
{
    std::string str = "Dead end.";

    Room* pNextRoom = pR->getDirectionPtr(direction);
    if (pNextRoom != nullptr)
    {
        // "you are leaving" current Room
        pR->getExitText(str);

        visitRoom(pP, pNextRoom, msgQ);

        return pNextRoom;
    }

    // nowhere to go in this direction, stay in current Room
    return pR;
}

/******************************************************************************
* visitRoom()
*
* award Room points to Player
* update Player's Rooms visited history
* queue messages for display
*******************************************************************************
*/
bool visitRoom(Player* pP, Room* pR, std::vector<std::string>& msgQ)
{
    // award Room points to Player
    int points = pR->getPoints();
    pP->addPoints(points);

    // update Player Room visit history
    pP->addRoomVisit(pR);

    // build greeting messages and queue for display
    std::string str, roomName;
    pR->getName(roomName);

    msgQ.push_back("You're in " + roomName + ".");

    pR->getEntryText(str);
    msgQ.push_back(str);

    // only award points for initial visit to each Room
    if (pR->getPoints() > 0)
    {
        std::stringstream ss;
        ss << points << " points for " << roomName << "!\n";

        msgQ.push_back(ss.str());
        pR->setPoints(0);
    }

    return true;
}
