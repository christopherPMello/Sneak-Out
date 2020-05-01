/*********************************************************************
 ** Description: This class contains the information and functions
                 within the Menu class. Menu is the class that obtains
                 and presents the majority of the information to the user
 *********************************************************************/
#include "Menu.hpp"
//Obtains user input and determins the movement
//
char Menu:: move(int x){
    char choice;
    cout << "Action: ";
    cin.clear();
    cin >> choice;
    choice = toupper(choice);
    
//checks the input
    inputCharValidator(choice);
    
//Checks if choice was A before passing to the board
    if(choice == 'A')
        info(x);
    
    return choice;
}
//Shows current options for user movement
//
void Menu:: info(int x){
    cout << "Press one of the coorisponding keys: " << endl;
    cout << "H: Move Left" << "                  " << "L: Move Right" << endl;
    cout << "J: Move Down" << "                  " << "K: Move Up" << endl;
    cout << "I: Don't Move" << "                 " << "V: Interact" << endl;
    cout << "Z: Get Area Info" << "              " << "C: Show Carry list" << endl;
    cout << "X: Show Objectives" << "            " << "Q: Quit" << endl;
    cout << "A: To see the controlls" << endl;
    cout << "Steps remaining: " << x << endl;
}
//Presents inital info to the user
//
void Menu:: mainInfo(){
    cout << "*******************************************" << endl;
    cout << "                 SNEAK OUT " << endl;
    cout << "*******************************************" << endl;
    cout << "It's friday night. You're 16. You're an adult...meh..." << endl;
    cout << "There's a party and all the cool kids are going to be there." << endl;
    cout << "SO ARE YOU." << endl;
    cout << "There's just one problem. Your parents wont let you go." << endl;
    cout << "They just don't understand...." << endl;
    cout << "Are we gonna stay in and be lame? HECK NO! " << endl;
    cout << "WERE SNEAKING OUT!" << endl << endl;
    cout << "-------------------------------------------" << endl;
    cout << "               RULES & OBJECTIVES" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "Be careful of your parents (P) as well as your cat and dog (A), if you get" << endl;
    cout << "one space away, you'll get caught!" << endl;
    cout << "If they get too close, hide in a room (R), they cant see you in there." << endl;
    cout << "In order to blow this pop stand we need to do the following:" << endl;
    cout << "- Get the basketball from your garage (R) to place under the sheets " << endl;
    cout << "  in your room (R), they'll never know your gone." << endl;
    cout << "- Steal money from your parents office (R) to pay off your sibling, they knows" << endl;
    cout << "  your going and they'll blow your cover without a bribe." << endl;
    cout << "- Grab your parents keys from they're room (R), you're taking the car." << endl;
    cout << "Once we have everything, head to the front door ($)." << endl;
    cout << "-------------------------------------------" << endl;
    cout << "               IMPORTANT INFO" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "We only have 100 steps to make it to the party before we run out of time!" << endl;
    cout << "**At any time press 'A', to view the controls to move and interact with the board**" << endl;
    cout << "LETS GET TO IT!" << endl << endl;
}
//Asks if the user would play again after winning or loosing
//
int Menu:: restart(){
    int again = 0;
    cout << "Play Again!? " << endl;
    cout << "1) Yes" << endl;
    cout << "2) No" << endl;
    cin >> again;
    inputValidator(again);
    return again;
}
//Verify's user input for integers
//
void Menu:: inputValidator(int& c){
    while(!c || (c != 1 && c != 2)){
        cout << "Please enter a number between 1 and 2" << std:: endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std:: cin >> c;
    }
}
//verify's user input for characters
//
void Menu:: inputCharValidator(char& c){
    while(((c != 'Q')&&(c != 'C')&&(c != 'V'))&&(c != 'K')&&(c != 'L')&&(c != 'A')&&(c != 'X')&&(c != 'Z')&&(c != 'I')&&(c != 'J')&&(c != 'H')){
        cout << "Please enter a valid character" << std:: endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> c;
        c = toupper(c);
    }
}
