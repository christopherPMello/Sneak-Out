/*********************************************************************
 ** Description: This class contains the information and functions
 within the ParRoom class. ParRoom is a sub class of the room class.
 *********************************************************************/
#include "ParRoom.hpp"
//Sets inital info for the parents room
//
ParRoom::ParRoom(){
    setObjectThere(true);
    setObject("Keys");
    setFace('R');
    setInfo("Parents Room");
}
ParRoom::~ParRoom(){
}

