/******************************************************************************
* app.h
* CS 281 - 0798, Fall 2020
*
* Common include file for App code files
*******************************************************************************
*/
#ifndef APP_H
#define APP_H

// classes used
#include "Room.h"
#include "Player.h"
#include "Treasure.h"
#include "Weapon.h"

// app.cpp: global variables
extern Room* g_pNexus;
extern Room* g_pBayOfLune;
extern Room* g_pLakeHoudini;
extern Room* g_pSiliconDesert;
extern Room* g_pMagicMountains;

// app_init_rooms.cpp: custom Room initialization functions
Room* initNexus();
Room* initBayOfLune();
Room* initLakeHoudini();
Room* initSiliconDesert();
Room* initMagicMountains();

// app_init_map.cpp: custom Room map initialization functions
void initRoomMap();

// app_player.cpp: Player initialization and management functions
bool grabTreasure(Player* pPlayer, Room* pRoom, std::vector<std::string>& msgQ);
bool dropTreasure(Player* pPlayer, Room* pRoom, std::vector<std::string>& msgQ);
bool grabWeapon(Player* pPlayer, Room* pRoom, std::vector<std::string>& msgQ);
bool lookAllDirections(Room* pRoom, std::vector<std::string>& msgQ);
Room* movePlayer(Player* pP, Room* pR, int direction, std::vector<std::string>& msgQ);
bool visitRoom(Player* pP, Room* pR, std::vector<std::string>& msgQ);


// app_util.cpp: Room initialization and management functions
int getInventory(Container* pR, std::vector<std::string>& msgQ);
// for app exit message display
bool getInfo(Player* pP, Room* pR, std::vector<std::string>& msgQ);
// for handling I)nfo command
bool getAllInfo(Player* pP, Room* pR, std::vector<std::string>& msgQ);

#endif
