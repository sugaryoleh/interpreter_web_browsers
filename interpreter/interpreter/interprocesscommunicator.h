#pragma once
#include "windows.h"
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#include <iostream>
#include "webexception.h"
#include <list>
#define BUF_SIZE 10000

using namespace std;


class InterProcessCommunicator
{
private:
	HANDLE hMapFile;
	LPCTSTR pBuf;
	const wchar_t* GetWC(const char*);
	void help();
	string fmo;
public:
	int init(const string&);
	int run(istream &);
	int run(const list<string>&);
};

