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

// local function prototypes
bool interAct(Player* pP, Room* pR, std::vector<std::string>& msgQ);

/******************************************************************************
* grabTreasure()
*
* transfer Treasure from Room to Player
* fill caller's vector with messages for display
*******************************************************************************
*/
bool grabTreasure(Player* pP, Room* pR, std::vector<std::string>& msgQ)
{
    // Bogey present prevents Player from getting Treasure
    if (pR->getBogeyCount() > 0)
    {
        msgQ.push_back("An unfriendly is guarding the treasure!");

        // get current Bogey in Room
        std::vector<Bogey*> bV;
        pR->getBogeyInfo(bV);
        Bogey* pB = bV.back();

        // display Bogey text
        std::string str;
        pB->getText(str);
        msgQ.push_back("The unfriendly yells " + str + " and attacks you!");

        return false;
    }

    Treasure* pT = pR->removeTreasure();
    if (pT == nullptr)
    {
        msgQ.push_back("There's no treasure here.");
        return false;
    }

    pP->addTreasure(pT);

    // build message string with string stream
    std::string str;
    std::stringstream ss;
    ss << "You have a " << pT->getName(str) << " worth "
        << pT->getPoints() << " points";

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
bool dropTreasure(Player* pP, Room* pR, std::vector<std::string>& msgQ)
{
    Treasure* pT = pP->removeTreasure();

    if (pT == nullptr)
    {
        msgQ.push_back("You have no treasure to drop!");
        return false;
    }

    // transfer Treasure from Player to Room
    pR->addTreasure(pT);

    // for queueing display message
    std::string str;
    msgQ.push_back("You dropped a " + pT->getName(str));

    return true;
}

/******************************************************************************
* grabWeapon()
*
* transfer Weapon from Room to Player
* add messages to caller's vector for display
*******************************************************************************
*/
bool grabWeapon(Player* pP, Room* pR, std::vector<std::string>& msgQ)
{
    Weapon* pW = pR->removeWeapon();

    if (pW == nullptr)
    {
        msgQ.push_back("There's no weapon here.");
        return false;
    }

    pP->addWeapon(pW);

    // build message string with string stream
    std::string str;
    std::stringstream ss;
    ss << "You have a " << pW->getName(str) << " worth "
        << pW->getPoints() << " points";

    // copy completed message string to caller's vector
    msgQ.push_back(ss.str());

    return true;
}

/******************************************************************************
* dropWeapon()
*
* transfer Weapon from Player to Room
* fill caller's vector with message strings for display
*******************************************************************************
*/
bool dropWeapon(Player* pP, Room* pR, std::vector<std::string>& msgQ)
{
    Weapon* pW = pP->removeWeapon();

    if (pW == nullptr)
    {
        msgQ.push_back("You have no weapon to drop!");
        return false;
    }

    // transfer Weapon from Player to Room
    pR->addWeapon(pW);

    // for queueing display message
    std::string str;
    msgQ.push_back("You dropped a " + pW->getName(str));

    return true;
}

/******************************************************************************
* defendSelf()
*
* use a Weapon on a Bogey
* add messages to caller's vector for display
* 
* returns 'q' when Player is defeated and all lives are gone, or 'f'
* return value 'q' forces main loop to terminate
*******************************************************************************
*/
char defendSelf(Player* pP, Room* pR, std::vector<std::string>& msgQ)
{
    if (!interAct(pP, pR, msgQ))
    {
        // get Player name
        std::string str;
        msgQ.push_back("Aaahhhhh!! " + pP->getName(str) + ", you are defeated!");

        // check for all Player lives used up
        int nLivesLeft = pP->loseLife();
        if (nLivesLeft <= 0)
        {
            msgQ.push_back("And you're out of lives :-((");

            // force q)uit in main app loop
            return 'q';
        }
        
        std::stringstream ss;
        ss << "You have " << nLivesLeft << "  lives left.";
        msgQ.push_back(ss.str());
    }

    // #TODO return same command to main loop
    return 'f';
}

/******************************************************************************
* interAct()
*
* use a Weapon on a Bogey
* add messages to caller's vector for display
*******************************************************************************
*/
bool interAct(Player * pP, Room * pR, std::vector<std::string> & msgQ)
{
    // check for Bogeys present
    if (pR->getBogeyCount() == 0)
    {
        msgQ.push_back("No unfriendlies here..");
        return true;
    }

    // check for Weapon in Player vector
    if (pP->getWeaponCount() == 0)
    {
        msgQ.push_back("Oh no! You have nothing to defend yourself with!");
        return false;
    }

    // get last Weapon stored in vector
    std::vector<Weapon*> wV;
    pP->getWeaponInfo(wV);
    Weapon* pW = wV.back();
    int wPower = pW->getPower();

    // get last Bogey stored in vector
    std::vector<Bogey*> bV;
    pR->getBogeyInfo(bV);
    Bogey* pB = bV.back();
    int bPower = pB->getPower();

    // get Weapon and Bogey names
    std::string wName, bName;
    msgQ.push_back("You flail at the " + pB->getName(bName) +
                   " with your " + pW->getName(wName) + "!");

    // get text associated with this Weapon
    std::string str;
    msgQ.push_back(pW->getText(str));

    // get text associated with this Bogey
    msgQ.push_back(pB->getText(str));

    // if Weapon more powerful than Bogey award points
    if (wPower >= bPower)
    {
        int bPoints = pB->getPoints();

        std::stringstream ss;
        ss << bPoints << " points for defeating the " << bName << "!";
        msgQ.push_back(ss.str());

        // award points and add Bogey notch to Player's belt
        pP->addPoints(bPoints);
        pR->removeBogey();
        pP->addBogey(pB);

        return true;
    }

    // Weapon weaker than Bogey lives to fight again
    if (wPower > 0)
    {
        msgQ.push_back("\nYou missed the " + bName + "!");
        pB->setPower(bPower - wPower);
        return true;
    }

    return false;

}

/******************************************************************************
* lookAllDirections()
*
* add all direction text in current Room to caller's message vector
*******************************************************************************
*/
bool lookAllDirections(Room* pR, std::vector<std::string>& msgQ)
{
    // utility buffer gets stomped every time through loop
    std::string str;
    msgQ.push_back("You're in " + pR->getName(str) + "\n");

    // add text for all directions to caller's vector
    for (int i = 0; i < ROOM_NDIR; i++)
    {
        // only display text for diretions we're using 
        if (pR->getDirectionText(i, str) != "")
            msgQ.push_back(str);
    }

    // display things in Room
    getInventory(pR, msgQ);

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
        // "You are leaving" current Room
        msgQ.push_back(pR->getExitText(str));

        // update Player's Room visits
        visitRoom(pP, pNextRoom, msgQ);

        // display Room contents
        getInventory(pNextRoom, msgQ);

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
    msgQ.push_back("You're in " + pR->getName(roomName) + ".");
    msgQ.push_back(pR->getEntryText(str));

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

/******************************************************************************
* doMagicWord()
*
* Player uses magic word
* queue messages for display
*******************************************************************************
*/
bool doMagicWord(Player* pP, Room* pR, std::vector<std::string>& msgQ)
{
    
    return true;
}
