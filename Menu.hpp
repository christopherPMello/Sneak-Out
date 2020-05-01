#ifndef MENU_HPP
#define MENU_HPP
#include <iostream>
#include <iomanip>
#include <limits>
using std:: endl;
using std:: cout;
using std:: cin;
class Menu{
private:
    int steps;
public:
    char move(int);
    void info(int);
    void mainInfo();
    int restart();
    void inputValidator(int&);
    void inputCharValidator(char&);
};
#endif
