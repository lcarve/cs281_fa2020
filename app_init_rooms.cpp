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
    Room* pRoom = new Room();

    // set Room name and point value
    pRoom->setPoints(100);
    pRoom->setName("the Nexus");

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
    Treasure* pTreasure = new Treasure();
    pTreasure->setName("heart of gold");
    pTreasure->setPoints(100);

    // install Treasure pointer in Room's Treasure vector
    pRoom->addTreasure(pTreasure);

    // create and initialize Weapon instance
    Weapon* pWeapon = new Weapon();
    pWeapon->setName("boring PowerPoint");
    pWeapon->setText("Clunk!");
    pWeapon->setPoints(100);

    // install Weapon pointer in Room's Weapon vector
    pRoom->addWeapon(pWeapon);

    // create and initialize Bogie instance
    Bogie* pBogie = new Bogie();
    pBogie->setName("swarthy, sweaty, bandy-legged orc");
    pBogie->setText("Heeeyyaahhh!!");
    pBogie->setPoints(200);

    // install Bogie pointer in Room's Bogie vector
    pRoom->addBogie(pBogie);

    return pRoom;
}

/******************************************************************************
* Room* initBayOfLune()
*******************************************************************************
*/
Room* initBayOfLune()
{
    Room* pRoom = new Room();

    // set Room name and point value
    pRoom->setName("the Bay of Lune");
    pRoom->setPoints(150);

    // set Room text for entry, exit, and every direction
    pRoom->setEntryText("You are swimming in the clear, cold Bay of Lune.");
    pRoom->setExitText("You are emerging from the Bay of Lune.");
    pRoom->setDirectionText(ROOM_NORTH, "Too hazy to see North");
    pRoom->setDirectionText(ROOM_SOUTH, "Coco Tar Pit to the South");
    pRoom->setDirectionText(ROOM_EAST, "Moonscape Isle to the East");
    pRoom->setDirectionText(ROOM_WEST, "The Nexus to the West");
    pRoom->setDirectionText(ROOM_UP, "Cloudy skies above");
    pRoom->setDirectionText(ROOM_DOWN, "Coarse sand beneath clear water below");

    // create and initialize Treasure instance
    Treasure* pTreasure = new Treasure();
    pTreasure->setName("chunk of glowing pink quartz");
    pTreasure->setPoints(100);

    // install Treasure pointer in Room's Treasure vector
    pRoom->addTreasure(pTreasure);

    // create and initialize Weapon instance
    Weapon* pWeapon = new Weapon();
    pWeapon->setName("fly swatter");
    pWeapon->setText("WhhhhffffffTTT!!");
    pWeapon->setPoints(100);

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

    // set Room name and point value
    pRoom->setPoints(150);
    pRoom->setName("Lake Houdini");

    // set Room text for entry, exit, and every direction
    pRoom->setEntryText("Lake Houdini's cool tourmaline water laps your bare toes.");
    pRoom->setExitText("You turn away from Lake Houdini.");
    pRoom->setDirectionText(ROOM_NORTH, "Coco Tar Pit to the North");
    pRoom->setDirectionText(ROOM_SOUTH, "The Nexus to the South");
    pRoom->setDirectionText(ROOM_EAST, "Moonscape Isle to the East");
    pRoom->setDirectionText(ROOM_WEST, "Swampy Marsh to the West");
    pRoom->setDirectionText(ROOM_UP, "Cloudy skies above");
    pRoom->setDirectionText(ROOM_DOWN, "Little fishes and pollywogs in clear water below");

    // create and initialize Treasure instance
    Treasure* pTreasure = new Treasure();
    pTreasure->setName("diamond in the rough");
    pTreasure->setPoints(100);

    // install Treasure pointer in Room's Treasure vector
    pRoom->addTreasure(pTreasure);

    // create and initialize Weapon instance
    Weapon* pWeapon = new Weapon();
    pWeapon->setName("Nerf gun");
    pWeapon->setText("FFFOOOMMMM!!");
    pWeapon->setPoints(100);

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
    Room* pRoom = new Room();

    // set Room name and point value
    pRoom->setPoints(150);
    pRoom->setName("the shimmering Silicon Desert");

    // set Room text for entry, exit, and every direction
    pRoom->setEntryText("Old circuit boards crowd the desert landscape.");
    pRoom->setExitText("You turn away from the Silicon Desert's crunchy mess of E-waste");
    pRoom->setDirectionText(ROOM_NORTH, "The Nexus to the North");
    pRoom->setDirectionText(ROOM_SOUTH, "You see nothing but E-waste and a hazy horizon to the South");
    pRoom->setDirectionText(ROOM_EAST, "Circuit boards all the way to the thunderheads on the horizon to the East");
    pRoom->setDirectionText(ROOM_WEST, "A stand of Joshua trees rises above the littered desert floor to the West");
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
    Room* pRoom = new Room();

    // set Room name and point value
    pRoom->setPoints(150);
    pRoom->setName("a high pass in the Magic Mountains");

    // set Room text for entry, exit, and every direction
    pRoom->setEntryText("the view is fantastic!");
    pRoom->setExitText("You gingerly descend from your perch high in the Magic Mountains.");
    pRoom->setDirectionText(ROOM_NORTH, "Hundreds of acres of pine forest extending to the North horizon");
    pRoom->setDirectionText(ROOM_SOUTH, "Dark rain clouds are rolling in from the South");
    pRoom->setDirectionText(ROOM_EAST, "The Nexus to the East");
    pRoom->setDirectionText(ROOM_WEST, "The Nexus to the East");
    pRoom->setDirectionText(ROOM_UP, "Cloudy skies above");
    pRoom->setDirectionText(ROOM_DOWN, "You're up high, don't look down!");

    // create and initialize Bogie instance
    Bogie* pBogie = new Bogie();
    pBogie->setName("big ugly fly");
    pBogie->setText("Shplatt!!");
    pBogie->setPoints(100);

    // install Bogie pointer in Room's Bogie vector
    pRoom->addBogie(pBogie);

    return pRoom;
}

