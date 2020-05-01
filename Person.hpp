#ifndef PERSON_HPP
#define PERSON_HPP
#include "Space.hpp"
class Person : public Space{
private:
    char baseFace;
    Space* location;
public:
    void interactWithObject() override;
    void interactWithoutObject() override;
    bool walking(char);
    bool found();
    
    void setLocation(Space*);
    Space* getLocation();
    void setBaseFace(char);
    char getBaseFace();
};
#endif
