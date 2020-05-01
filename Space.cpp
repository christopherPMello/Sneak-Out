/*********************************************************************
 ** Description: This class contains the information and functions
                 within the Space class. The Space class is the base
                 class for the other room and nonroom classes.
 *********************************************************************/
#include "Space.hpp"
Space::Space(){
    setObjectThere(false);
    setObject("");
    setFace(' ');
    setInfo("the hallway");
}
Space::~Space(){
}
//set functions
void Space:: setUpSpace(Space* s){
    up = s;
}
void Space::setDownSpace(Space* s){
    down = s;
}
void Space::setLeftSpace(Space* s){
    left = s;
}
void Space::setRightSpace(Space* s){
    right = s;
}
void Space:: setObject(std:: string name){
    object = name;
}
void Space:: setObjectThere(bool x){
    ifObjectThere = x;
}
void Space:: setFace(char x){
    face = x;
}
void Space:: setInfo(std:: string s){
    info = s;
}
//Get functions
std:: string Space:: getType(){
    return object;
}
char Space:: getFace(){
    return face;
}
std:: string Space:: getObject(){
    return object;
}
bool Space:: getObjectThere(){
    return ifObjectThere;
}
Space* Space::getUpSpace(){
    return up;
}
Space* Space::getDownSpace(){
    return down;
}
Space* Space::getLeftSpace(){
    return left;
}
Space* Space::getRightSpace(){
    return right;
}
std:: string Space::getInfo(){
    return info;
}
