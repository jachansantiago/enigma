#ifndef ENIGMA_H
#define ENIGMA_H


class Enigma
{
	private:

		int RotorI[26];		//Rotor I
		int RotorII[26];	//Rotor II
		int RotorIII[26];	//Rotor III
		int Reflector[26];	// Reflector list
		char KeyBoardUpper[26];
		char KeyBoardLower[26];
		
		
		int Keyboard_Input (char); 		//Convert a Letter to Number
		char Keyboard_Output (int);		// Covert Number to Letter
		int Encryption_RotorI (int);	// Encrypt with rotorI
		int Encryption_RotorII (int);	// Encrypt with rotorII
		int Encryption_RotorIII (int);	// Encrypt with rotorIII
		int ReflectionPath (int);
		int Reflect_Encryption_RotorI (int);	// Encrypt with rotorI after reflector
		int Reflect_Encryption_RotorII (int);	// Encrypt with rotorII after reflector
		int Reflect_Encryption_RotorIII (int);	// Encrypt with rotorIII after reflector
		void RotorSwap(); 						// Rotate Rotors when key is press
		void R1Swap();							//Swap Rotor1 by 1
		void R2Swap();							//Swap Rotor2 by 1
		void R3Swap();							//Swap Rotor3 by 1
	public:
		Enigma();		//Constructor
		char EncryptedChar (char);				//Encrypt a char
		void SetRotorI(char);					// Set Rotor1
		void SetRotorII(char);					// Set Rotor2
		void SetRotorIII(char);					// Set Rotor3
		char GetRotorI();						// Get Rotor1
		char GetRotorII();						// Get Rotor2
		char GetRotorIII();						// Get Rotor3
		void PlugBoard(char, char);				// Swap letters
		void ResetPlugBoard();
};


#endif