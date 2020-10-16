/******************************************************************************
* app_init_rooms.cpp
* CS 281 - 0798, Fall 2020
*
* Room initialization functions
*   - set Room entry text, exit text, direction text
*   - install Treasures in Room Treasure vector or in Room mixed vector
*   - install Weapons in Room Weapon vector or in Room mixed vector
* #TODO
*   - install bogies in Room Bogie vector
*   - install magic words in Room MagicWord vector
*******************************************************************************
*/
#include "app.h"

/******************************************************************************
* Room* initNexus()
*******************************************************************************
*/
Room* initNexus()
{
    Room* pRoom = new Room();

    // set Room point value
    pRoom->setPoints(100);

    std::string str = "the Nexus";
    pRoom->setName(str);

    str = "The Nexus is a portal to other dimensions.";
    pRoom->setEntryText(str);

    str = "You are leaving the Nexus.";
    pRoom->setExitText(str);

    str = "Lake Houdini to the north";
    pRoom->setDirectionText(ROOM_NORTH, str);

    str = "Silicon Desert to the south";
    pRoom->setDirectionText(ROOM_SOUTH, str);

    str = "Bay of Lune to the east";
    pRoom->setDirectionText(ROOM_EAST, str);

    str = "Magic Mountains to the west";
    pRoom->setDirectionText(ROOM_WEST, str);

    str = "Blue skies above";
    pRoom->setDirectionText(ROOM_UP, str);

    str = "A carpet of wildflowers below";
    pRoom->setDirectionText(ROOM_DOWN, str);

    // create and initialize Treasure instance
    Treasure* pTreasure = new Treasure();
    str = "heart of gold";
    pTreasure->setName(str);
    pTreasure->setPoints(100);

    // install Treasure pointer in Room's Treasure vector
    pRoom->addTreasure(pTreasure);

    return pRoom;
}

/******************************************************************************
* Room* initBayOfLune()
*******************************************************************************
*/
Room* initBayOfLune()
{
    Room* pRoom = new Room();

    // set Room point value
    pRoom->setPoints(150);

    std::string str = "the Bay of Lune";
    pRoom->setName(str);

    str = "You are swimming in the clear, cold Bay of Lune.";
    pRoom->setEntryText(str);

    str = "You are emerging from the Bay of Lune.";
    pRoom->setExitText(str);

    str = "Too hazy to see to the north";
    pRoom->setDirectionText(ROOM_NORTH, str);

    str = "Coco Tar Pit to the south";
    pRoom->setDirectionText(ROOM_SOUTH, str);

    str = "Moonscape Isle to the east";
    pRoom->setDirectionText(ROOM_EAST, str);

    str = "Swampy Marsh to the west";
    pRoom->setDirectionText(ROOM_WEST, str);

    str = "Cloudy skies above";
    pRoom->setDirectionText(ROOM_UP, str);

    str = "You see coarse sand through the clear water below";
    pRoom->setDirectionText(ROOM_DOWN, str);

    // create and initialize Treasure instance
    Treasure* pTreasure = new Treasure();
    str = "fist-sized chunk of glowing pink quartz";
    pTreasure->setName(str);
    pTreasure->setPoints(100);

    // install Treasure pointer in Room's Treasure vector
    pRoom->addTreasure(pTreasure);

    // create and initialize Weapon instance
    Weapon* pWeapon = new Weapon();
    str = "fly swatter";
    pWeapon->setName(str);
    pWeapon->setPoints(200);

    // install Weapon pointer in Room's Weapon vector
    pRoom->addWeapon(pWeapon);

    return pRoom;
}

/******************************************************************************
* Room* initLakeHoudini()
*******************************************************************************
*/
Room* initLakeHoudini()
{
    Room* pRoom = new Room();

    // set Room point value
    pRoom->setPoints(150);

    std::string str = "Lake Houdini";
    pRoom->setName(str);

    str = "Lake Houdini's cool tourmaline water laps your bare toes.";
    pRoom->setEntryText(str);

    str = "You turn away from Lake Houdini.";
    pRoom->setExitText(str);

    str = "Coco Tar Pit to the north";
    pRoom->setDirectionText(ROOM_NORTH, str);

    str = "The Nexus to the south";
    pRoom->setDirectionText(ROOM_SOUTH, str);

    str = "Moonscape Isle to the east";
    pRoom->setDirectionText(ROOM_EAST, str);

    str = "Swampy Marsh to the west";
    pRoom->setDirectionText(ROOM_WEST, str);

    str = "Cloudy skies above";
    pRoom->setDirectionText(ROOM_UP, str);

    str = "Little fishes and pollywogs in clear water below";
    pRoom->setDirectionText(ROOM_DOWN, str);

    // create and initialize Treasure instance
    Treasure* pTreasure = new Treasure();
    str = "huge diamond in the rough";
    pTreasure->setName(str);
    pTreasure->setPoints(100);

    // install Treasure pointer in Room's Treasure vector
    pRoom->addTreasure(pTreasure);

    return pRoom;
}

/******************************************************************************
* Room* initSiliconDesert()
*******************************************************************************
*/
Room* initSiliconDesert()
{
    Room* pRoom = new Room();

    // set Room point value
    pRoom->setPoints(150);

    std::string str = "the shimmering Silicon Desert";
    pRoom->setName(str);

    str = "Old circuit boards crowd the desert landscape.";
    pRoom->setEntryText(str);

    str = "You turn away from the Silicon Desert's crunchy mess of E-waste";
    pRoom->setExitText(str);

    str = "You see nothing but E-waste and a hazy horizon to the north";
    pRoom->setDirectionText(ROOM_NORTH, str);

    str = "The Nexus to the south";
    pRoom->setDirectionText(ROOM_SOUTH, str);

    str = "Nothing but circuit boards and thunderheads on the horizon to the east";
    pRoom->setDirectionText(ROOM_EAST, str);

    str = "A stand of Joshua trees rises above the littered desert floor to the west";
    pRoom->setDirectionText(ROOM_WEST, str);

    str = "Cloudy skies above";
    pRoom->setDirectionText(ROOM_UP, str);

    str = "You see plenty of salvage opportunities at your feet!";
    pRoom->setDirectionText(ROOM_DOWN, str);

    return pRoom;
}

/******************************************************************************
* Room* initMagicMountains()
*******************************************************************************
*/
Room* initMagicMountains()
{
    Room* pRoom = new Room();

    // set Room point value
    pRoom->setPoints(150);

    std::string str = "a high pass in the Magic Mountains";
    pRoom->setName(str);

    str = "the view is fantastic!";
    pRoom->setEntryText(str);

    str = "You gingerly descend from your perch high in the Magic Mountains.";
    pRoom->setExitText(str);

    str = "Hundreds of acres of pine forest extending to the north horizon";
    pRoom->setDirectionText(ROOM_NORTH, str);

    str = "Dark rain clouds are rolling in from the south";
    pRoom->setDirectionText(ROOM_SOUTH, str);

    str = "The Nexus to the east";
    pRoom->setDirectionText(ROOM_EAST, str);

    str = "Smoke rises from a mountain cabin's tin chimney";
    pRoom->setDirectionText(ROOM_WEST, str);

    str = "Cloudy skies above";
    pRoom->setDirectionText(ROOM_UP, str);

    str = "You're up high, don't look down!";
    pRoom->setDirectionText(ROOM_DOWN, str);

    return pRoom;
}

