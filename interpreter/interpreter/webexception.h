#pragma once
#include <exception>
#include <string>
#include <map>
using namespace std;

class WebException : public exception 
{
    string ex;
    int code;
    static map<int, string> exceptions;
public:
    static void init();
    WebException(const int&);

    virtual const char* what() const throw()
    {
        return ex.c_str();
    }
};

