all: enigmaMachine

enigmaMachine: enigma.o client.o 
	g++ -o enigma Enigma.o client.o 
	make clean
proto: enigma.o proto.o
	g++ -o proto Enigma.o proto.o
	make clean

enigma.o: Enigma.cpp Enigma.h
	g++ -c Enigma.cpp

client.o: client.cpp
	g++ -c client.cpp

proto.o:
	g++ -c proto.cpp
clean:
	rm *.o 