/*********************************************************************
 ** Description: This class contains the information and functions
                 within the Player class. The Player class is a sub class
                 of the Person class which is a sub class of the Space class.
 *********************************************************************/
#include "Player.hpp"
//Set all boolean objects to false
//
Player:: Player(){
    basketball = keys = money = payBrother = placeBasketball = winner = false;
}
Player:: ~Player(){
}
//Determine if location the player is moving too is a room
//
bool Player:: savedInfo(char x){
    if((x == 'K') && ((getLocation()->getUpSpace()->getFace() == 'R') || (getLocation()->getUpSpace()->getFace() == '$'))){
        return true;
    }
    else if((x == 'J') && ((getLocation()->getDownSpace()->getFace() == 'R') || (getLocation()->getDownSpace()->getFace() == '$'))){
        return true;
    }
    else if((x == 'H') && ((getLocation()->getLeftSpace()->getFace() == 'R') || (getLocation()->getLeftSpace()->getFace() == '$'))){
        return true;
    }
    else if((x == 'L') && ((getLocation()->getRightSpace()->getFace() == 'R') || (getLocation()->getRightSpace()->getFace() == '$'))){
        return true;
    }
    else
        return false;
}
//Search the current room for an object and update the object if so
//
void Player:: roomSearch(){
    if((getLocation()->getObject() == "Basketball") && (basketball == false)){
        getLocation()->interactWithObject();
        updateObject("Basketball");
    }
    else if((getLocation()->getObject() == "Keys") && (keys == false)){
        getLocation()->interactWithObject();
        updateObject("Keys");
    }
    else if(getLocation()->getObject() == "Money" && (money == false)){
        getLocation()->interactWithObject();
        updateObject("Money");
    }
    else if((getLocation()->getInfo() == "Your Room") && (basketball == true) && (placeBasketball == false)){
        std:: cout << "You placed the basketball under your blankets!" << std:: endl;
        updateObject("placeBasketball");
    }
    else if((getLocation()->getInfo() == "Siblings Room") && (money == true) && (payBrother == false)){
        std:: cout << "You payed off your sibling!" << std:: endl;
        updateObject("payBrother");
    }
    else if((((money == true) && (basketball == true) && (keys == true) && (payBrother == true) && (placeBasketball == true)) &&(getLocation()->getFace() == '$'))){
        std:: cout << "Awesome job! Have fun a that partaaay!" << std:: endl;
        winner = true;
    }
    else
        getLocation()->interactWithoutObject();
}
//Update the object that was found
//
void Player:: updateObject(std:: string x){
    if(x == "Basketball")
        basketball = true;
    else if(x == "Keys")
        keys = true;
    else if(x == "Money")
        money = true;
    else if(x == "payBrother")
        payBrother = true;
    else if(x == "placeBasketball")
        placeBasketball = true;
}
//Update current inventory depending on what items were found
//
void Player:: inventory(){
if((basketball == false) && (keys == false) && (money == false))
    std:: cout << "You do not have any items yet!" << std:: endl;
else{
    std:: cout << "You currently have: " << std:: endl;
    if((basketball == true) && (placeBasketball == false))
        std:: cout << "- Basketball" << std:: endl;
    if(keys == true)
        std:: cout << "- Keys" << std:: endl;
    if((money == true) && (payBrother == false))
        std:: cout << "- Money" << std:: endl;
}
}
//Show the list of current objects depending on which items were found
//
void Player:: objectives(){
    std:: cout << "Your current objectives are: " << std:: endl;
    if((basketball == false) && (placeBasketball == false))
        std:: cout << "- Find the basketball and place it under your sheets" << std:: endl;
    if((money == false) && (payBrother == false))
        std:: cout << "- Find money to pay your sibling off" << std:: endl;
    if(keys == false)
        std:: cout << "- Find your parents keys" << std:: endl;
    if((basketball == true) && (placeBasketball == false))
        std:: cout << "- Place the baksetball under your sheets" << std:: endl;
    if((money == true) && (payBrother == false))
        std:: cout << "- Pay your sibling off" << std:: endl;
    if((money == true) && (basketball == true) && (keys == true) && (payBrother == true) && (placeBasketball == true))
        std:: cout << "- Head on out to the PARTAAAAYYYY!" << std:: endl;
}
//Get functions
//
void Player:: getAreaInfo(){
    std:: cout << "You are currently in " << getLocation()->getInfo() << std:: endl;
}
bool Player:: getWinner(){
    return winner;
}
