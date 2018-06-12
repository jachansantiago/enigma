all: commandLine

enigmaMachine: enigma.o client.o 
	g++ -o enigma enigma.o client.o 
	make clean
commandLine: enigma.o cmdLine.o
	g++ -o enigma enigma.o cmdLine.o
	make clean

enigma.o: enigma.cpp enigma.h
	g++ -c enigma.cpp

client.o: client.cpp
	g++ -c client.cpp

cmdLine.o:
	g++ -c cmdLine.cpp
clean:
	rm *.o 