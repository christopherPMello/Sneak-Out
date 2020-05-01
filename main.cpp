/*********************************************************************
 ** Author:      Christopher Mello
 ** Date:        December 4, 2018
 ** Description: This program displays and runs a text based game for the user.
                 The user is given a theme, objectives, and a step limit,
                 in order to complete the game. The objective of the game is
                 to leave the house without being caught and there are several
                 randomly moving objects in the way of your goal.
 *********************************************************************/
#include "Board.hpp"
int main (){
    bool b = false;
    char c;
//Create board and initalize variables
    Board board;
    board.linker();
    board.setSteps(75);
//Create menu and present information to the user
    Menu menu;
    menu.mainInfo();
    menu.info(board.getSteps());
//Continue loop until game is over
    while(b == false){
        board.printBoard();
        c = menu.move(board.getSteps());
        board.playerMove(c);
        
//Move player if the player has chosen a variable
        if((c != 'V') && (c != 'Z') && (c != 'C') && (c != 'X') && (c != 'A'))
        board.movement();
        b = board.getEnd();
        
//If the game is over reset variables and run game again
        if(b == true){
        int again = 0;
        board.printBoard();
        again = menu.restart();
            if(again == 1){
                board.clear();
                board.create();
                board.linker();
                board.setSteps(75);
                b = false;
            }
            else{
                board.clear();
                exit(0);
            }
        }
    }
}
