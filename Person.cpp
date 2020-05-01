/*********************************************************************
 ** Description: This class contains the information and functions
                 within the Person class. The person class is a sub class
                 of the Space class.
 *********************************************************************/
#include "Person.hpp"
void Person:: interactWithObject(){
    return;
}
void Person:: interactWithoutObject(){
    return;
}
//Depending on the current location of the player, move if space is available
//
bool Person:: walking(char x){
    if((x == 'K') && (getLocation()->getUpSpace()->getFace() != ' ')){
       return false;
    }
    else if((x == 'J') && (getLocation()->getDownSpace()->getFace() != ' ')){
        return false;
    }
    else if((x == 'H') && (getLocation()->getLeftSpace()->getFace() != ' ')){
        return false;
    }
    else if((x == 'L') && (getLocation()->getRightSpace()->getFace() != ' ')){
        return false;
    }
    else
        return true;
}
//If the player is next to the automated movers, report found
//
bool Person:: found(){
    if((getLocation()->getUpSpace()->getFace() == 'X') || (getLocation()->getDownSpace()->getFace() == 'X') || (getLocation()->getLeftSpace()->getFace() == 'X') || (getLocation()->getRightSpace()->getFace() == 'X'))
        return true;
    else
        return false;
}
//Set functions
//
void Person:: setLocation(Space* s){
    location = s;
}
void Person:: setBaseFace(char c){
    baseFace = c;
}
//Get functions
//
Space* Person:: getLocation(){
    return location;
}
char Person:: getBaseFace(){
    return baseFace;
}
