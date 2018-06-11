all: commandLine

enigmaMachine: enigma.o client.o 
	g++ -o enigma Enigma.o client.o 
	make clean
commandLine: enigma.o cmdLine.o
	g++ -o enigma Enigma.o cmdLine.o
	make clean

enigma.o: Enigma.cpp Enigma.h
	g++ -c Enigma.cpp

client.o: client.cpp
	g++ -c client.cpp

cmdLine.o:
	g++ -c cmdLine.cpp
clean:
	rm *.o 