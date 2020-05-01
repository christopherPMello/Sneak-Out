#ifndef SPACE_HPP
#define SPACE_HPP
#include <iostream>
#include <string>
#include <map>
#include <vector>
class Space{
private:
//Space pointers
    Space* up;
    Space* down;
    Space* left;
    Space* right;
    
    std:: string object, info;
    bool ifObjectThere, gone, obj;
    char face;
    
public:
    Space();
    virtual ~Space();
    virtual void interactWithObject() = 0;
    virtual void interactWithoutObject() = 0;
    
//Get and Set functions
    void setUpSpace(Space*);
    void setDownSpace(Space*);
    void setLeftSpace(Space*);
    void setRightSpace(Space*);
    void setObjectThere(bool);
    void setFace(char);
    void setObject(std:: string name);
    void setInfo(std:: string);
    
    Space* getUpSpace();
    Space* getDownSpace();
    Space* getLeftSpace();
    Space* getRightSpace();
    bool getObjectThere();
    std:: string getType();
    char getFace();
    std:: string getObject();
    std:: string getInfo();
};
#endif
