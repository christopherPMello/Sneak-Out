/*********************************************************************
 ** Description: This class contains the information and functions
 within the Garage class. Garage is a sub class of the room class.
 *********************************************************************/
#include "Garage.hpp"
//Sets inital info for the parents office
//
Garage::Garage(){
    setObjectThere(true);
    setObject("Basketball");
    setFace('R');
    setInfo("Garage");
}
Garage::~Garage(){
}

