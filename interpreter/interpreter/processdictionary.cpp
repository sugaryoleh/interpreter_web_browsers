#include "processdictionary.h"

ProcessDictionary* ProcessDictionary::pd = nullptr;

ProcessDictionary* ProcessDictionary::getProcessDict()
{
	if (ProcessDictionary::pd == nullptr)
		ProcessDictionary::pd = new ProcessDictionary();
	return ProcessDictionary::pd;
}

void ProcessDictionary::push(const string& name, Process* proc)
{
	bool prec = false;
	for (auto it = this->processes.begin(); it != this->processes.end(); it++)
		if (it->first == name)
		{
			delete it->second;
			it->second = proc;
			prec = true;
			break;
		}
	if (!prec)
	{
		this->processes.push_back({ name, proc });
	}
}
Process* ProcessDictionary::get(const string& name)
{
	for (auto it = this->processes.begin(); it != this->processes.end(); it++)
		if (it->first == name)
		{
			return it->second;
		}
	throw Exception("No process with handle " + name);
	return nullptr;
}

const list<pair<string, Process*>>& ProcessDictionary::getProcesses()
{
	return this->processes;
}

string ProcessDictionary::repr()
{
	string buf;
	buf += "processes:\nstart\n";
	for (auto it = this->processes.begin(); it != this->processes.end(); it++)
	{
		buf += "handle:\t" + it->first + "\n\t" + it->second->repr();
	}
	buf += "end\n";
	return buf;
}

void ProcessDictionary::_delete(const string& name)
{
	auto it = this->processes.begin();
	for (it; it != this->processes.end(); it++)
	{
		if (it->first == name)
		{
			it->second->buf.push_back("exit");
		}
	}
	throw Exception("No process with handle " + it->first);
}

Process::Process(InterProcessCommunicator* pipc)
{
	this->pipc = pipc;
}
