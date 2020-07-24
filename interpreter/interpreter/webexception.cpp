#include "webexception.h"

map<int, string> WebException::exceptions;

void WebException::init()
{
	WebException::exceptions.insert({ 2, "No driver for such browser name" });
	WebException::exceptions.insert({ 3, "Driver is already initialized" });
	WebException::exceptions.insert({ 4, "Element is npt interactable" });
	WebException::exceptions.insert({ 5, "No such element" });
	WebException::exceptions.insert({ 6, "Element is unreadable" });
	WebException::exceptions.insert({ 7, "Wrong parameters combination" });
}

WebException::WebException(const int& code)
{
	if (exceptions.find(code) != exceptions.end())
	{
		this->ex = exceptions[code];
	}
	else ex = "Undefined exception in web-manager process";
}
