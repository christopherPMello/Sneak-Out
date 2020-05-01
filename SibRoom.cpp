/*********************************************************************
 ** Description: This class contains the information and functions
 within the SibRoom class. SibRoom is a sub class of the room class.
 *********************************************************************/
#include "SibRoom.hpp"
//Sets inital info for the siblings room
//
SibRoom::SibRoom(){
    setObjectThere(true);
    setObject("Nothing of use");
    setFace('R');
    setInfo("Siblings Room");
}
SibRoom::~SibRoom(){
}

