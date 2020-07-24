#pragma once
#include "interprocesscommunicator.h"
#include <string>
#include <list>
#include "exception.h"
using namespace std;
class Process
{
public:
	list<string> buf;
	InterProcessCommunicator* pipc;
	Process(InterProcessCommunicator*);
	string repr()
	{
		string buf;
		for (auto it = this->buf.begin(); it != this->buf.end(); it++)
		{
			buf += *it  + "\n";
		}
		return buf;
	}
};

class ProcessDictionary
{
private:
	list<pair<string, Process*>> processes;
	static ProcessDictionary* pd;
public:
		static ProcessDictionary* getProcessDict();
		void push(const string& name, Process* proc);
		Process* get(const string&);
		const list<pair<string, Process*>>& getProcesses();
		string repr();
		void _delete(const string&);
};


