/******************************************************************************
* app_init_rooms.cpp
* CS 281 - 0798, Fall 2020
*
* Room initialization functions
*   - set Room entry text, exit text, direction text
*   - install Treasures in Room Treasure vector or in Room mixed vector
*   - install Weapons in Room Weapon vector or in Room mixed vector
* #TODO
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
    // create Room and set name and point value
    Room* pRoom = new Room("the Nexus", 100);

    // set Room text for entry, exit, and every direction
    pRoom->setEntryText("The Nexus is a portal to other dimensions.");
    pRoom->setExitText("You are leaving the Nexus.");
    pRoom->setDirectionText(ROOM_NORTH, "Lake Houdini to the North");
    pRoom->setDirectionText(ROOM_SOUTH, "Silicon Desert to the South");
    pRoom->setDirectionText(ROOM_EAST, "Bay of Lune to the East");
    pRoom->setDirectionText(ROOM_WEST, "Magic Mountains to the West");
    pRoom->setDirectionText(ROOM_UP, "Blue skies above");
    pRoom->setDirectionText(ROOM_DOWN, "A carpet of wildflowers below");

    // create and initialize Treasure instance
    Treasure* pTreasure = new Treasure("heart of gold", 100);

    // install Treasure pointer in Room's Treasure vector
    pRoom->addTreasure(pTreasure);

    // create and initialize Weapon instance
    Weapon* pWeapon = new Weapon("boring PowerPoint", 100);
    pWeapon->setText("Clunk!");

    // install Weapon pointer in Room's Weapon vector
    pRoom->addWeapon(pWeapon);

    // create and initialize Bogey instance
    Bogey* pBogey = new Bogey("swarthy, sweaty orc", 200);
    pBogey->setText("Heeeyyaahhh!!");

    // install Bogey pointer in Room's Bogey vector
    pRoom->addBogey(pBogey);

    return pRoom;
}

/******************************************************************************
* Room* initBayOfLune()
*******************************************************************************
*/
Room* initBayOfLune()
{
    // create Room and set name and point value
    Room* pRoom = new Room("the Bay of Lune", 150);

    // set Room text for entry, exit, and every direction
    pRoom->setEntryText("You are swimming in the clear, cold Bay of Lune.");
    pRoom->setExitText("You are emerging from the Bay of Lune.");
    pRoom->setDirectionText(ROOM_NORTH, "Lake Houdini to the North");
    pRoom->setDirectionText(ROOM_SOUTH, "Silicon Desert to the South");
    pRoom->setDirectionText(ROOM_EAST, "Moonscape Isle to the East");
    pRoom->setDirectionText(ROOM_WEST, "The Nexus to the West");
    pRoom->setDirectionText(ROOM_UP, "Cloudy skies above");
    pRoom->setDirectionText(ROOM_DOWN, "Coarse sand beneath clear water below");

    // create and initialize Treasure instance
    Treasure* pTreasure = new Treasure("chunk of glowing pink quartz", 100);

    // install Treasure pointer in Room's Treasure vector
    pRoom->addTreasure(pTreasure);

    // create and initialize Weapon instance
    Weapon* pWeapon = new Weapon("pink plastic fly swatter", 100);
    pWeapon->setText("WhhhhffffffTTT!!");

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
    // create Room and set name and point value
    Room* pRoom = new Room("Lake Houdini", 150);

    // set Room text for entry, exit, and every direction
    pRoom->setEntryText("Lake Houdini's cool tourmaline water laps your bare toes.");
    pRoom->setExitText("You turn away from Lake Houdini.");
    pRoom->setDirectionText(ROOM_NORTH, "Coco Tar Pit to the North");
    pRoom->setDirectionText(ROOM_SOUTH, "The Nexus to the South");
    pRoom->setDirectionText(ROOM_EAST, "Bay of Lune to the East");
    pRoom->setDirectionText(ROOM_WEST, "Magic Mountains to the West");
    pRoom->setDirectionText(ROOM_UP, "Cloudy skies above");
    pRoom->setDirectionText(ROOM_DOWN, "Little fishes and pollywogs in clear water below");

    // create and initialize Treasure instance
    Treasure* pTreasure = new Treasure("diamond in the rough", 100);

    // install Treasure pointer in Room's Treasure vector
    pRoom->addTreasure(pTreasure);

    // create and initialize Weapon instance
    Weapon* pWeapon = new Weapon("Nerf gun", 100);
    pWeapon->setText("FFFOOOMMMM!!");

    // install Treasure pointer in Room's Treasure vector
    pRoom->addWeapon(pWeapon);

    return pRoom;
}

/******************************************************************************
* Room* initSiliconDesert()
*******************************************************************************
*/
Room* initSiliconDesert()
{
    // create Room and set name and point value
    Room* pRoom = new Room("the shimmering Silicon Desert", 150);

    // set Room text for entry, exit, and every direction
    pRoom->setEntryText("Old circuit boards crowd the desert landscape.");
    pRoom->setExitText("You turn away from the Silicon Desert's crunchy mess of E-waste");
    pRoom->setDirectionText(ROOM_NORTH, "The Nexus to the North");
    pRoom->setDirectionText(ROOM_SOUTH, "You see nothing but E-waste and a hazy horizon to the South");
    pRoom->setDirectionText(ROOM_EAST, "E-waste all the way to the Bay of Lune to the East");
    pRoom->setDirectionText(ROOM_WEST, "Magic Mountains to the West");
    pRoom->setDirectionText(ROOM_UP, "Cloudy skies above");
    pRoom->setDirectionText(ROOM_DOWN, "Plenty of salvage opportunities at your feet!");

    return pRoom;
}

/******************************************************************************
* Room* initMagicMountains()
*******************************************************************************
*/
Room* initMagicMountains()
{
    // create Room and set name and point value
    Room* pRoom = new Room("a high pass in the Magic Mountains", 150);

    // set Room text for entry, exit, and every direction
    pRoom->setEntryText("the view is fantastic!");
    pRoom->setExitText("You gingerly descend from your perch high in the Magic Mountains.");
    pRoom->setDirectionText(ROOM_NORTH, "Lake Houdini just visible on the North horizon");
    pRoom->setDirectionText(ROOM_SOUTH, "Silicon Desert E-wasteland to the South");
    pRoom->setDirectionText(ROOM_EAST, "The Nexus to the East");
    pRoom->setDirectionText(ROOM_WEST, "Sunset to the West");
    pRoom->setDirectionText(ROOM_UP, "Cloudy skies above");
    pRoom->setDirectionText(ROOM_DOWN, "You're up high, don't look down!");

    // create and initialize Bogey instance
    Bogey* pBogey = new Bogey("big ugly fly", 100);
    pBogey->setText("Shplatt!!");

    // install Bogey pointer in Room's Bogey vector
    pRoom->addBogey(pBogey);

    return pRoom;
}

