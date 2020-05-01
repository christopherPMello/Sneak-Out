/*********************************************************************
 ** Description: This class contains the base information for all the rooms
                 in the game. The room class is a subclass of the space class.
 *********************************************************************/
#include "Room.hpp"
//Sets inital info for the all rooms
//
void Room:: interactWithObject(){
    std:: cout << "O boy! You found the " << getObject() << std:: endl;
}
void Room::interactWithoutObject(){
    std:: cout << "There seems to be nothing here" << std:: endl;
}
//interact with objects depending on their current status
//
bool Room:: interact(){
    if (getObjectThere() == true){
        interactWithObject();
        return true;
    }
    else{
        interactWithoutObject();
        return false;
    }
}
