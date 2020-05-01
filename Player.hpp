#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Person.hpp"
class Player : public Person{
private:
    bool basketball, keys, money, payBrother, placeBasketball, winner;
    
public:
    Player();
    ~Player();
    void updateObject(std:: string);
    bool savedInfo(char x);
    void roomSearch();
    void inventory();
    void objectives();
    void getAreaInfo();
    bool getWinner();
};
#endif
