#ifndef BOARD_HPP
#define BOARD_HPP
#include "Player.hpp"
#include "SibRoom.hpp"
#include "ParRoom.hpp"
#include "Garage.hpp"
#include "ParOffice.hpp"
#include "Menu.hpp"
#include <iomanip>
#include <random>
class Board{
private:
    const int BOARD_SIZE = 9;
    int steps;
    Space*** board;
    std:: vector<int> vec;
    bool end;
    Person* M;
    Person* D;
    Person* P;
    Person* C;
    Player* X;
public:
    Board();
    ~Board();
    void clear();
    void create();
    void printBoard();
    void assign(Space* space, const bool&, const std:: string&, const char&);
    void faces(Person*, const char&);
    void randomRoom();
    char randomChar(int);
    void Boarders();
    void linker();
    void walk(Person* s);
    void actuallyMove(Person*, char, bool);
    void actuallyMoveRandom(Person*, char);
    void movement();
    int random_in_range(int);
    void playerMove(char);
    void roomMaker(int, int, int);
    
    int getRandomRoom(int);
    bool getEnd();
    void setSteps(int);
    int getSteps();
};
#endif
