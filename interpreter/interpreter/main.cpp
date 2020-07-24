#include <iostream>
#include <string>
#include "interpreter.h"
#include "exception.h"
using namespace std;


int main()
{
	try 
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 6);
		cout << "Interpreter by Oleh Sakharchuk c All rights reserved" << endl;
		Interpreter* pInterpreter = Interpreter::getInterpreter();
		cout << "Interactive mode - 1" << endl <<"Usual mode - 2" << endl;
		int ch;
		cin >> ch;
		if (ch == 1)
		{
			pInterpreter->runInteractive();
		}
		else if (ch == 2)
		{
			string file;
			cout << "File path" << endl;
			cin >> file;
			pInterpreter->runUsual(file);
		}		
	}
	catch (Exception ex)
	{
		cout << ex._what();
	}
	return 0;
}