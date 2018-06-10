#include <iostream>
#include <unistd.h>

using namespace std;

bool validPlug(string);

int main(int argc, char * const argv[])
{
	char c;
	string ROTOR_CONF = "QWE";
	string PLUG_CONFIG = "";
	string MESSAGE = "";
	bool fromFile = false;
	bool plugBoard = false;
	bool fromMessage = false;
	bool space = true;
	string FILE = "";

	while( (c = getopt(argc, argv, "f:r:p:w:m:")) != EOF){
		switch(c){
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
 				if (optarg == "0"){
 					space = false;
 				}
 				break;
			default:
				cerr << "Unknown Option: " << string(optarg) << endl;
				return 1;
		}
	}

	argc -= optind;
	argv += optind;

	
	return 0;
}


bool validPlug(string pconfig)
{
	// CHeck if are pairs
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
