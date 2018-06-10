#include <iostream>
#include "Enigma.h"
using namespace std;

int main()
{
	Enigma Machine;
	char l;
	char e;
	char p1, p2;
	//char r1, r2, r3;
	int cant;

	cout << " Enigma Machine Simulator  by Jeffrey Chan " << endl;
	

	while(l != '0')
	{

		if( l == '2')
		{
			Machine.ResetPlugBoard();
			cout << " Setting PlugBoard :" << endl;
			cout << "How many plug wire do you want? (0 - 13) -> ";
			cin >> cant;

			for(int i = 0; i < cant; i++)
			{

				cout << " Wire #" << i+1 << endl;
				cout << " First letter -> ";
				cin >> p1;
				cout << " Second letter -> ";
				cin >> p2;
			
				Machine.PlugBoard(p1,p2);

			}

			l = '3';
		}

	if(l != '3')
	{

	cout << " Please set Rotor I, II and III with letter A-Z [English Keyboard] " << endl; 
	cout << "Set RotorI -> ";
	cin >> l;
	Machine.SetRotorI(l);
	cout << "Set RotorII -> ";
	cin >> l;
	Machine.SetRotorII(l);
	cout << "Set RotorIII -> ";
	cin >> l;
	Machine.SetRotorIII(l);

	}
	cout << endl << " Enigma Machine Only allows enter letter A-Z [English Keyboard] No numbers." 
		<< endl <<	" Press [0] to exit. " << endl 
		<<	" Press [1] to set rotors again. " << endl 
		<<  " Press [2] to set plugboard."
		<< endl << " Message : ";
	
	while(l != '0' && l != '1' && l != '2')
	{
		cin >> l;
		e = Machine.EncryptedChar(l);

		cout << e ;
	}


	}

	return 0;
}