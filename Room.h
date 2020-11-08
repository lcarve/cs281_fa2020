/******************************************************************************
* Room.h
* CS 281-0798, Fall 2020
*
* Room class declaration
*******************************************************************************
*/
#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <array>
#include <vector>

#include "Container.h"
#include "Treasure.h"
#include "Weapon.h"

//------------------------------------------------------------
// direction constants
// use these to exercise Room class!
//------------------------------------------------------------

// number of Room directions plus custom directions
#define ROOM_NDIR   16
//#define ROOM_NDIR   6

// each Room direction
#define ROOM_NORTH  0
#define ROOM_SOUTH  1
#define ROOM_EAST   2
#define ROOM_WEST   3
#define ROOM_UP     4
#define ROOM_DOWN   5
// custom directions
#define ROOM_UX1    6
#define ROOM_UX2    7
#define ROOM_UX3    8
#define ROOM_UX4    9
#define ROOM_UX5   10
#define ROOM_UX6   11
#define ROOM_UX7   12
#define ROOM_UX8   13
#define ROOM_UX9   14
#define ROOM_UXX   15

//------------------------------------------------------------
// class definition error codes
//------------------------------------------------------------

// feature not yet implemented
#define ROOM_TODO       -1
// user's command is not a direction move
#define ROOM_DEAD_END   -2
// something's went wrong in callee function
#define ROOM_ERROR      -3

//------------------------------------------------------------
// Room class
//------------------------------------------------------------
class Room : public Container
{
private:
    // text to display for each direction in Room
    std::array <std::string, ROOM_NDIR> m_roomTextArray;

    // each Room* gives next Room in the given direction
    std::array<Room*, ROOM_NDIR> m_nextRoomPtrArray;

    // messages for display on Player entry and exit
    std::string m_entryText;
    std::string m_exitText;

public:
    Room();
    // name is a call by value string parameter
    // to allow passing string literals
    // and using initialization list
    Room(std::string name);
    // rooms will persist for app lifetime
    // so destructor not needed
    //~Room();

    bool setEntryText(const std::string& str);
    bool getEntryText(std::string& str) const;
    
    bool setExitText(const std::string& str);
    bool getExitText(std::string& str) const;

    // see direction constants above!
    bool setDirectionText(int direction, const std::string& str);
    bool getDirectionText(int direction, std::string& str) const;

    // see direction constants above!
    bool setDirectionPtr(int direction, Room* pRoom);
    Room* getDirectionPtr(int direction) const;
};

#endif