/*********************************************************************
 ** Description: This class contains the information and functions
                 within the Board class. The board class contains
                 the majority of the interactions and movement witin the
                 game as well as creating and destroying the board. 
 *********************************************************************/
#include "Board.hpp"
Board:: ~Board(){
    clear();
}
Board:: Board(){
    create();
}
//Creates the board for the map
//
void Board:: create(){
    end = false;
//Randomly generates numbers to be in the array of strings
    randomRoom();
//Creates the board
    board = new Space**[BOARD_SIZE];
    for(int i = 0; i < BOARD_SIZE; i++)
        board[i] = new Space*[BOARD_SIZE];
//Adds boarders to the board
    Boarders();
    for(int i = 1; i < BOARD_SIZE - 1; i++){
        for(int j = 1; j < BOARD_SIZE - 1; j++){
//Set the front door
            if(i == 1 && j == 1){
                board[i][j] = new Room;
                assign(board[i][j], true, "", '$');
                board[i][j]->setInfo("Front Door");
            }
//Creates a room
            else if(i == 1 && j == 4){
                roomMaker(i, j, vec.at(0));
            }
//Creates another room
            else if(i == 1 && j == 7){
                roomMaker(i, j, vec.at(1));
            }
//Creates another room
            else if(i == 3 && j == 1){
                roomMaker(i, j, vec.at(2));
            }
//Creates another room
            else if(i == 6 && j == 1){
                roomMaker(i, j, vec.at(3));
            }
//Creates another room
            else if(i == 7 && j == 7){
                board[i][j] = new Room;
                assign(board[i][j], false, "", 'R');
                board[i][j]->setInfo("Your Room");
            }
//All other spaces are empty rooms
            else
                board[i][j] = new Room;
        }
    }
//Obtain pointers and set location pointer to moving objects
    D = new Person;
    D->setLocation((board[4][4]));
    assign(D, true, "**Ruff**",'A');
    faces(D, 'A');
    
    P = new Person;
    P->setLocation((board[2][3]));
    assign(P, true, "**I'm not angry, I'm just dissapointed**", 'P');
    P->getLocation()->setFace('P');
    faces(P, 'P');
    
    M = new Person;
    M->setLocation((board[2][5]));
    assign(M, true, "**I'm not angry, I'm just dissapointed**", 'P');
    M->getLocation()->setFace('P');
    faces(M, 'P');
    
    C = new Person;
    C->setLocation((board[5][3]));
    assign(C, true, "**Meow**", 'A');
    C->getLocation()->setFace('A');
    faces(C, 'A');
    
    X = new Player;
    X->setLocation((board[7][6]));
    assign(X, true, "", 'X');
    X->getLocation()->setFace('X');
    faces(X, 'X');
}
//Deletes and sets all pointers to nullptr
//
void Board:: clear(){
//Delete all moving person objects
    delete D;
    D = nullptr;
    delete P;
    P = nullptr;
    delete M;
    M = nullptr;
    delete C;
    C = nullptr;
    delete X;
    X = nullptr;
    
//Delete board
    for(int i = 0; i < BOARD_SIZE; i++){
        for(int j = 0; j < BOARD_SIZE; j++){
            delete board[i][j];
            board[i][j] = nullptr;
        }
        delete []board[i];
        board[i] = nullptr;
    }
    delete []board;
    board = nullptr;
}
//Print board with faces
//
void Board::printBoard(){
    for(int i = 0; i < BOARD_SIZE; i++){
        std:: cout << std:: endl << std:: endl;
        for(int j = 0; j < BOARD_SIZE; j++){
            std:: cout << std:: setw(3);
            std:: cout << board[i][j]->getFace() << "  ";
        }
    }
    std:: cout << std:: endl << std:: endl;
}
//Create boarders around the board
//
void Board:: Boarders(){
    for(int i = 0; i < BOARD_SIZE; i++){
        board[0][i] = new Room;
        board[0][i]->setFace('*');
        board[BOARD_SIZE - 1][i] = new Room;
        board[BOARD_SIZE - 1][i]->setFace('*');
    }
    for(int i = 1; i < BOARD_SIZE - 1; i++){
        board[i][0] = new Room;
        board[i][0]->setFace('*');
        board[i][BOARD_SIZE - 1] = new Room;
        board[i][BOARD_SIZE - 1]->setFace('*');
    }
}
//Returns random numbers between 1 and the max range input
//
int Board:: random_in_range(int max){
    thread_local static std::mt19937 mt(std::random_device{}());
    thread_local static std::uniform_int_distribution<int> pick;
    return pick(mt, decltype(pick)::param_type{1, max});
}
//Returns coorisponding letter to the random number generated
//
char Board:: randomChar(int p){
    if(p == 1)
        return 'K';
    else if(p == 2)
        return 'J';
    else if(p == 3)
        return 'H';
    else
        return 'L';
}
//Assigns face, object, and presence of object within space class
//
void Board:: assign(Space* sp, const bool& b, const std:: string& s, const char& c){
    sp->setObjectThere(b);
    sp->setObject(s);
    sp->setFace(c);
}
//Sets the face of the board and person pointer
//
void Board:: faces(Person* s, const char& c){
    s->getLocation()->setFace(c);
    s->setBaseFace(c);
}
//Links all the boards together using four pointers
//
void Board:: linker(){
    for(int i = 1; i < BOARD_SIZE - 1; i++)
        for(int j = 1; j < BOARD_SIZE - 1; j++){
            board[i][j]->setUpSpace(board[i - 1][j]);
            board[i][j]->setDownSpace(board[i + 1][j]);
            board[i][j]->setLeftSpace(board[i][j - 1]);
            board[i][j]->setRightSpace(board[i][j + 1]);
        }
}
//Passing in the coordinates to create new locations
//
void Board::roomMaker(const int i, const int j, const int r){
    if(r == 1)
        board[i][j] = new SibRoom;
    else if(r == 2)
        board[i][j] = new ParRoom;
    else if(r == 3)
        board[i][j] = new Garage;
    else if(r == 4)
        board[i][j] = new ParOffice;
}
//Randomly places 4 numbers in a vector to be later used for the randomized location of the rooms
//
void Board:: randomRoom(){
    std:: map<int, int> map;
    int i = 0;
    while (vec.size() < 4){
        int r = random_in_range(4);
        auto p = map.find(r);
        if(p == map.end()){
            vec.push_back(r);
            map.insert(std:: pair<int, int> (r, i));
            i++;
        }
        else
            r = random_in_range(4);
    }
}
//Moves the main player depending on their starting location
//
void Board:: actuallyMove(Person* s, char r, bool a){
    {
        if(r == 'K'){
            if(a == false)
            s->getLocation()->setFace(' ');
            s->setLocation(s->getLocation()->getUpSpace());
            if(a == true)
            s->getLocation()->setFace(s->getBaseFace());
        }
        else if(r == 'J'){
            if(a == false)
            s->getLocation()->setFace(' ');
            s->setLocation(s->getLocation()->getDownSpace());
            if(a == true)
            s->getLocation()->setFace(s->getBaseFace());
        }
        else if(r == 'H'){
            if(a == false)
            s->getLocation()->setFace(' ');
            s->setLocation(s->getLocation()->getLeftSpace());
            if (a == true)
            s->getLocation()->setFace(s->getBaseFace());
        }
        else if(r == 'L'){
            if(a == false)
            s->getLocation()->setFace(' ');
            s->setLocation(s->getLocation()->getRightSpace());
            if(a == true)
            s->getLocation()->setFace(s->getBaseFace());
        }
    }
}
//Moves the parents and animals to open spaces randomly
//
void Board:: actuallyMoveRandom(Person* s, char r){
    {
        if(r == 'K'){
            s->getLocation()->setFace(' ');
            s->setLocation(s->getLocation()->getUpSpace());
            s->getLocation()->setFace(s->getBaseFace());
        }
        else if(r == 'J'){
            s->getLocation()->setFace(' ');
            s->setLocation(s->getLocation()->getDownSpace());
            s->getLocation()->setFace(s->getBaseFace());
        }
        else if(r == 'H'){
            s->getLocation()->setFace(' ');
            s->setLocation(s->getLocation()->getLeftSpace());
            s->getLocation()->setFace(s->getBaseFace());
        }
        else if(r == 'L'){
            s->getLocation()->setFace(' ');
            s->setLocation(s->getLocation()->getRightSpace());
            s->getLocation()->setFace(s->getBaseFace());
        }
    }
}
//Takes a random number and moves the player accordingly
//
void Board:: walk(Person* s){
    char r = randomChar(random_in_range(4));
    if (s->walking(r) == false){
        return;
    }
else
    actuallyMoveRandom(s, r);
}
//Moves the automatic player each term
//
void Board:: movement(){
    walk(D);
    walk(P);
    walk(M);
    walk(C);
}
//Moves the player depending on the inputed char
//
void Board:: playerMove(char c){
    bool b = true;
//If the user enters one of the movement options, decrement steps and move the player
    if((c == 'K') || (c == 'J') || (c == 'L') || (c == 'H')){
        steps--;
        if(X->savedInfo(c) == true){
            b = false;
            actuallyMove(X, c, b);
        }
        else if(((X->getLocation()->getFace() == 'R') || (X->getLocation()->getFace() == '$')) && ((X->walking(c) == true)))
            actuallyMove(X, c, b);
        
        else if(X->walking(c) == true)
            actuallyMoveRandom(X, c);
    }
    else if(c == 'I'){
    steps--;
    return;
    }
//If the player does not enter a movement option, do not decrement spaces
else if(c == 'C')
    X->inventory();
else if(c == 'X')
    X->objectives();
else if(c == 'V')
    X->roomSearch();
else if(c == 'Z')
    X->getAreaInfo();
else if(c == 'Q'){
    clear();
    exit(0);
}
else
    return;
}
//Determine if the player was caught or lost
//
bool Board:: getEnd(){
//If the automatic players found the human player
    if((D->found() == true) || (P->found() == true) || (M->found() == true) || (C->found() == true)){
        std:: cout << endl;
        if(D->found() == true)
            std:: cout << "*'OH NO! Shhhhh! Mr. Wiskers!'*   " << std:: endl << C->getObject() << std:: endl;
        else if(P->found() == true)
            std:: cout << "*'OH NO! PLEASE, I CAN EXPLAIN!'* " << std:: endl << P->getObject() << std:: endl;
        else if(M->found() == true)
            std:: cout << "*'OH NO! PLEASE, I CAN EXPLAIN!'* " << std:: endl << M->getObject() << std:: endl;
        else if(C->found() == true)
            std:: cout << "*'OH NO! Shhhh! Calm down Sparky'*" << std:: endl << D->getObject() << std:: endl;
        
        return true;
}
    else if (getSteps() < 1){
        std:: cout <<"*OH NO! You took too long! You missed the party*" << std:: endl;
        return true;
    }
//If the player wins
    else if(X->getWinner() == true){
        return true;
    }
    else
        return false;
}
//Get and set methods
//
void Board:: setSteps(int x){
    steps = x;
}
int Board:: getSteps(){
    return steps;
}
