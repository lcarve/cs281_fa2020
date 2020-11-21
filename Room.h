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
int constexpr ROOM_NDIR = 16;
//int constexpr ROOM_NDIR = 6; // north south east west up down

int constexpr ROOM_POINTS = 150;

// each Room direction
int constexpr ROOM_NORTH = 0;
int constexpr ROOM_SOUTH = 1;
int constexpr ROOM_EAST  = 2;
int constexpr ROOM_WEST  = 3;
int constexpr ROOM_UP    = 4;
int constexpr ROOM_DOWN  = 5;
// custom directions
int constexpr ROOM_UX1 =  6;
int constexpr ROOM_UX2 =  7;
int constexpr ROOM_UX3 =  8;
int constexpr ROOM_UX4 =  9;
int constexpr ROOM_UX5 = 10;
int constexpr ROOM_UX6 = 11;
int constexpr ROOM_UX7 = 12;
int constexpr ROOM_UX8 = 13;
int constexpr ROOM_UX9 = 14;
int constexpr ROOM_UXX = 15;

//------------------------------------------------------------
// class definition error codes
//------------------------------------------------------------

// feature not yet implemented
int constexpr ROOM_TODO = -1;
// user's command is not a direction move
int constexpr ROOM_DEAD_END = -2;
// something's went wrong in callee function
int constexpr ROOM_ERROR = -3;

//------------------------------------------------------------
// Room class
//------------------------------------------------------------
class Room : public Container
{
private:
    // how many instances exist in game
    static int m_rCount;

    // text to display for each direction in Room
    std::array <std::string, ROOM_NDIR> m_roomTextArray;

    // each Room* gives next Room in the given direction
    std::array<Room*, ROOM_NDIR> m_nextRoomPtrArray;

    // messages for display on Player entry and exit
    std::string m_entryText;
    std::string m_exitText;

public:
    Room();
    Room(const std::string& name, int points);
    // rooms will persist for app lifetime
    // so destructor not needed
    //~Room();

    int getRoomCount() const;

    void setEntryText(const std::string& str);
    std::string& getEntryText(std::string& str) const;
    
    void setExitText(const std::string& str);
    std::string& getExitText(std::string& str) const;

    // see direction constants above!
    void setDirectionText(int direction, const std::string& str);
    std::string& getDirectionText(int direction, std::string& str) const;

    // see direction constants above!
    void setDirectionPtr(int direction, Room* pRoom);
    Room* getDirectionPtr(int direction) const;
};

#endif