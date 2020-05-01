/*********************************************************************
 ** Description: This class contains the information and functions
 within the ParOffice class. ParOffice is a sub class of the room class.
 *********************************************************************/
#include "ParOffice.hpp"
//Sets inital info for the parents office
//
ParOffice::ParOffice(){
    setObjectThere(true);
    setObject("Money");
    setFace('R');
    setInfo("Parents Office");
}
ParOffice::~ParOffice(){
}
