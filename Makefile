worm: worm.o 
	g++ -o worm worm.o   
worm.o: worm.cpp   
	g++ -c -Wall -pedantic -g -std=c++11 worm.cpp
clean: 
	rm worm.o  worm
