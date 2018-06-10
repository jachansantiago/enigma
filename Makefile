all: enigmaMachine

enigmaMachine: enigma.o client.o 
	g++ -o enigma Enigma.o client.o 

enigma.o: Enigma.cpp Enigma.h
	gcc -c Enigma.cpp

client.o: client.cpp
	gcc -c client.cpp

clean:
	rm *.o 