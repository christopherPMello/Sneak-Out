###
### @file - Sneak Out makefile
### @author - Christopher Mello
### @description - Makefile for Sneak Out
###

#
# Sneak Out
#

output: main.o Menu.o Board.o Space.o Garage.o ParOffice.o ParRoom.o SibRoom.o Room.o Person.o Player.o
	g++ main.o Menu.o Board.o Space.o Garage.o ParOffice.o ParRoom.o SibRoom.o Room.o Person.o Player.o -std=c++11 -o output

main.o: main.cpp
	g++ -c main.cpp -std=c++11

Menu.o: Menu.cpp
	g++ -c Menu.cpp -std=c++11

Board.o: Board.cpp
	g++ -c Board.cpp -std=c++11

Space.o: Space.cpp
	g++ -c Space.cpp -std=c++11

Garage.o: Garage.cpp
	g++ -c Garage.cpp -std=c++11

ParOffice.o: ParOffice.cpp
	g++ -c ParOffice.cpp -std=c++11

ParRoom.o: ParRoom.cpp
	g++ -c ParRoom.cpp -std=c++11

SibRoom.o: SibRoom.cpp
	g++ -c SibRoom.cpp -std=c++11

Room.o: Room.cpp
	g++ -c Room.cpp -std=c++11

Person.o: Person.cpp
	g++ -c Person.cpp -std=c++11

Player.o: Player.cpp
	g++ -c Player.cpp -std=c++11

clean:
	rm *.o output

