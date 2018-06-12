#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include "enigma.h"

using namespace std;

bool validPlug(string);
void help();


int main(int argc, char * const argv[])
{
	char c;
	string buff;
	string ROTOR_CONF = "QWE";
	string PLUG_CONFIG = "";
	string MESSAGE = "";
	bool fromFile = false;
	bool outputFile = false;
	bool plugBoard = false;
	bool fromMessage = false;
	bool space = true;
	bool skip_endl = true;
	string FILE = "";
	string input;
	ofstream outFile;
	string OUT_FILE;
	Enigma Machine;

	while( (c = getopt(argc, argv, "h:f:r:p:w:m:o:")) != EOF){
		switch(c){
			case 'h':
				help();
				return 0;
			case 'r':
				ROTOR_CONF = optarg;
				if(ROTOR_CONF.length() != 3){
					cerr << "Invalid Rotor Configuration (only 3 letters)" << endl;
					return 1;
				}
				break;
			case 'f':
				fromFile = true;
				FILE = optarg;
				break;
			case 'p':
				plugBoard = true;
				PLUG_CONFIG = optarg;
				if(!validPlug(PLUG_CONFIG)){
					cerr << "Invalid PlugBoard Configuration" << endl;
					return 1;
 				}
 				break;
 			case 'm':
 				fromMessage = true;
 				MESSAGE = optarg;
 				break;
 			case 'w':
 				if (optarg[0] == '0'){
 					space = false;
 				}
 				break;
 			case 'o':
 				outputFile = true;
 				OUT_FILE = optarg;
 				break;
 			case '?':
 				return 1;
			default:
				cerr << "Unknown Option"<< endl;
				return 1;
		}
	}

	// Enigma Machine ROTOR Configuration
	Machine.SetRotorI(ROTOR_CONF[0]);
	Machine.SetRotorII(ROTOR_CONF[1]);
	Machine.SetRotorIII(ROTOR_CONF[2]);

	// Enigma PlugBoard Configuration
	for(int i = 0; i < PLUG_CONFIG.length(); i +=2 ){
		Machine.PlugBoard(PLUG_CONFIG[i],PLUG_CONFIG[i+1]);
	}
	

	if(outputFile)
    	outFile.open(OUT_FILE);

	// Select output FILE | STANDARD OUTPUT
	ostream & outStream = (outputFile ? outFile : cout);

	if(fromFile){
		ifstream inFile(FILE);
		if(inFile.is_open()){

			while(getline(inFile, buff)){

				// Skip first endl
				if(!skip_endl && space){
					outStream << endl;
				}else{
					skip_endl = false;
				}

				for (int i = 0; i < buff.length(); i++){
					if(isalpha(buff[i])){
						outStream << Machine.EncryptedChar(buff[i]);
					}else{

						if(space){
							outStream << buff[i];
						}
						else if(!isspace(buff[i])){
							outStream << buff[i];
						}
					}
				}

			}

			inFile.close();
		}else{
			cerr << "Unable to open file" << endl;
			return 1;
		}

	}else if(fromMessage){
		buff = MESSAGE;
		for (int i = 0; i < buff.length(); i++){

			if(isalpha(buff[i])){
				outStream << Machine.EncryptedChar(buff[i]);
			}else{
				if(space){
					outStream << buff[i];
				}
				else if(!isspace(buff[i])){
					outStream << buff[i];
				}
			}
			
		}

	}
	
	outStream << endl;

	if(outputFile)
    	outFile.close();
	
	return 0;
}


bool validPlug(string pconfig)
{
	// Check if are pairs
	if(pconfig.length() % 2 != 0){
		return false;
	}

	// Check if a letter repeats.
	for(int i = 0; i < pconfig.length(); i++){
		for(int j = i + 1; j < pconfig.length(); j++){
			if(pconfig[i] == pconfig[j])
				return false;
		}
	}

	return true;
}

void help(){
	cout << "TODO:// Print Help...." << endl;
	return;
}
