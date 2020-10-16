/******************************************************************************
* Room.cpp
* CS 281-0798, Fall 2020
*
* Room class definition
*******************************************************************************
*/
#include <string>
#include <vector>

#include "Room.h"
#include "Treasure.h"
#include "Weapon.h"

//***********************************************************
// Room(string name)
//
// overload constructor
// 
// name is a call by value parameter
// to allow passing string literals
//***********************************************************
Room::Room(std::string name)
{
    m_id = static_cast<int>('r');   // 'r' for Room
    m_name = name;
    m_entryText = "entering the " + m_name;
    m_exitText = "exiting the " + m_name;

    // initialize Room text to known values
    m_roomTextArray[ROOM_NORTH] = "looking north";
    m_roomTextArray[ROOM_SOUTH] = "looking south";
    m_roomTextArray[ROOM_EAST] = "looking east";
    m_roomTextArray[ROOM_WEST] = "looking west";
    m_roomTextArray[ROOM_UP] = "looking up";
    m_roomTextArray[ROOM_DOWN] = "looking down";

    // initialize custom direction text to "" to
    // simplify client (app) code display logic
    m_roomTextArray[ROOM_UX1] = "";
    m_roomTextArray[ROOM_UX2] = "";
    m_roomTextArray[ROOM_UX3] = "";
    m_roomTextArray[ROOM_UX4] = "";
    m_roomTextArray[ROOM_UX5] = "";
    m_roomTextArray[ROOM_UX6] = "";
    m_roomTextArray[ROOM_UX7] = "";
    m_roomTextArray[ROOM_UX8] = "";
    m_roomTextArray[ROOM_UX9] = "";
    m_roomTextArray[ROOM_UXX] = "";

    // initialize Room pointers
    m_nextRoomPtrArray[ROOM_NORTH] = nullptr;
    m_nextRoomPtrArray[ROOM_SOUTH] = nullptr;
    m_nextRoomPtrArray[ROOM_EAST]  = nullptr;
    m_nextRoomPtrArray[ROOM_WEST]  = nullptr;
    m_nextRoomPtrArray[ROOM_UP]    = nullptr;
    m_nextRoomPtrArray[ROOM_DOWN]  = nullptr;

    // support for user defined directions
    // client code should add global const (before main())
    // like this: const int ROOM_YOUR_CUSTOM_DIRECTION = ROOM_UX1;

    m_nextRoomPtrArray[ROOM_UX1] = nullptr;
    m_nextRoomPtrArray[ROOM_UX2] = nullptr;
    m_nextRoomPtrArray[ROOM_UX3] = nullptr;
    m_nextRoomPtrArray[ROOM_UX4] = nullptr;
    m_nextRoomPtrArray[ROOM_UX5] = nullptr;
    m_nextRoomPtrArray[ROOM_UX6] = nullptr;
    m_nextRoomPtrArray[ROOM_UX7] = nullptr;
    m_nextRoomPtrArray[ROOM_UX8] = nullptr;
    m_nextRoomPtrArray[ROOM_UX9] = nullptr;
    m_nextRoomPtrArray[ROOM_UXX] = nullptr;
}

//***********************************************************
// Room()
//
// constructor
//***********************************************************
Room::Room() : Room("room") {}

//***********************************************************
// setId()
//***********************************************************
bool Room::setId(int id) { m_id = id; return true; }

//***********************************************************
// setEntryText()
//***********************************************************
bool Room::setEntryText(std::string& entryText)
{
    m_entryText = entryText;
    return true;
}

//***********************************************************
// getEntryText()
//***********************************************************
bool Room::getEntryText(std::string& str) const
{
    str = m_entryText;
    return true;
}

//***********************************************************
// setExitText()
//***********************************************************
bool Room::setExitText(std::string& exitText)
{
    m_exitText = exitText;
    return true;
}

//***********************************************************
// getExitText()
//***********************************************************
bool Room::getExitText(std::string& str) const
{
    str = m_exitText;
    return true;
}

//***********************************************************
// setDirectionText()
//***********************************************************
bool Room::setDirectionText(int direction, std::string& str)
{
    m_roomTextArray[direction] = str;
    return true;
}

//***********************************************************
// getRoomDirectionText()
//***********************************************************
 bool Room::getDirectionText(int direction, std::string& str) const
{
     str = m_roomTextArray[direction];
     return true;
 }

//***********************************************************
// setDirectionPtr()
//
// set the pointer to the next Room in this direction
//***********************************************************
bool Room::setDirectionPtr(int direction, Room* pRoom)
{
    m_nextRoomPtrArray[direction] = pRoom;
    return true;
}

//***********************************************************
// getDirectionPtr()
//
// return pointer to the next Room in given direction
//***********************************************************
Room* Room::getDirectionPtr(int direction) const 
{ 
    return m_nextRoomPtrArray[direction];
}

