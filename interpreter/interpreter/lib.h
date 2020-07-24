#pragma once
#include <string>
#include <list>
#include "token.h"
//#include "ast.h"
using namespace std;

class Lib
{
public:
    static const int VAR_prt;
    static const int MUL_DIV_prt;
    static const int PLUS_MINUS_prt;
    static const list<Token> token_expressions;
    class Operations
    {
    public:
        static const char arithmetics[5];
        static const char comparisons[4];
        static const char combinations[3];
    };
    class TYPES
    {
    public:
        static const std::string RESERVED;
        static const std::string INT;
        static const std::string STR;
        static const std::string BOOL;
        static const std::string ID;
        static const std::string NONE;
        static const std::string BROWSER;
    };
    class WEB
    {
       public:
       static int processCounter;
       class BROWSERS
       {
        public:
            static const std::string CHROME;
            static const std::string EDGE;
       };
    };
    
};