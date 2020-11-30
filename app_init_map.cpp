/******************************************************************************
* app_init_map.cpp
* CS 281 - 0798, Fall 2020
*
* Room map initialization functions
* 
* The Room map is an array of Room pointers in each Room.
* Each Room knows which Room can be accessed in each direction.
* There is no overall map of the Rooms.
*******************************************************************************
*/
#include "app.h"

/******************************************************************************
* void initRoomMap()
*******************************************************************************
*/
void initRoomMap()
{
    // #TODO
    // In this example map, the Nexus is at the center of all other Rooms
    // Customize your Room map according to your game design
    g_pNexus->setDirectionPtr(ROOM_NORTH, g_pLakeHoudini);
    g_pNexus->setDirectionPtr(ROOM_SOUTH, g_pSiliconDesert);
    g_pNexus->setDirectionPtr(ROOM_EAST, g_pBayOfLune);
    g_pNexus->setDirectionPtr(ROOM_WEST, g_pMagicMountains);

    g_pLakeHoudini->setDirectionPtr(ROOM_SOUTH, g_pNexus);
    g_pLakeHoudini->setDirectionPtr(ROOM_EAST, g_pBayOfLune);
    g_pLakeHoudini->setDirectionPtr(ROOM_WEST, g_pMagicMountains);

    g_pSiliconDesert->setDirectionPtr(ROOM_NORTH, g_pNexus);
    g_pSiliconDesert->setDirectionPtr(ROOM_EAST, g_pBayOfLune);
    g_pSiliconDesert->setDirectionPtr(ROOM_WEST, g_pMagicMountains);

    g_pBayOfLune->setDirectionPtr(ROOM_WEST, g_pNexus);
    g_pBayOfLune->setDirectionPtr(ROOM_NORTH, g_pLakeHoudini);
    g_pBayOfLune->setDirectionPtr(ROOM_SOUTH, g_pSiliconDesert);

    g_pMagicMountains->setDirectionPtr(ROOM_EAST, g_pNexus);
    g_pMagicMountains->setDirectionPtr(ROOM_NORTH, g_pLakeHoudini);
    g_pMagicMountains->setDirectionPtr(ROOM_SOUTH, g_pSiliconDesert);
}
