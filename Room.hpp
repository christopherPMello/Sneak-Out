#ifndef ROOM_HPP
#define ROOM_HPP
#include "Space.hpp"
class Room : public Space{
private:
public:
    void interactWithObject() override;
    void interactWithoutObject() override;
    bool interact();
};
#endif

