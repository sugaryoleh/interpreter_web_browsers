#include "lib.h"

const char Lib::Operations::arithmetics[5] = { '4', '+', '-', '*', '/' };
const char Lib::Operations::comparisons[4] = { '3', '=', '>', '<' };
const char Lib::Operations::combinations[3] = { '2', '&', '|' };

const std::string Lib::TYPES::RESERVED = "RESERVED";
const string Lib::TYPES::INT = "INT";
const string Lib::TYPES::STR = "STR";
const string Lib::TYPES::BOOL = "BOOL";
const string Lib::TYPES::ID = "ID";
const string Lib::TYPES::NONE = "NONE";
const string Lib::TYPES::BROWSER = "BROWSER";

const int Lib::PLUS_MINUS_prt = 7;
const int Lib::MUL_DIV_prt = 6;
const int Lib::VAR_prt = 5;

const list<Token> Lib::token_expressions = {
    Token(R"([ \n\t]+)",    TYPES::NONE, 0),
        Token(R"(#[^\n]*)", TYPES::NONE, 0),
        Token(R"(\:=)",     TYPES::RESERVED, 10),
        Token(R"(\+)",      TYPES::RESERVED, Lib::PLUS_MINUS_prt),
        Token(R"(-[0-9]+)", TYPES::INT, Lib::VAR_prt),
        Token(R"(-)",       TYPES::RESERVED, Lib::PLUS_MINUS_prt),
        Token(R"(\*)",      TYPES::RESERVED, Lib::MUL_DIV_prt),
        Token(R"(/)",       TYPES::RESERVED, Lib::MUL_DIV_prt),
        Token(R"(<=)",      TYPES::RESERVED, 8), //
        Token(R"(<)",       TYPES::RESERVED, 8),
        Token(R"(>=)",      TYPES::RESERVED, 8), //
        Token(R"(>)",       TYPES::RESERVED, 8),
        Token(R"(=)",       TYPES::RESERVED, 8),
        Token(R"(!=)",      TYPES::RESERVED, 8), //
        Token(R"(\&)",      TYPES::RESERVED, 9),
        Token(R"(\|)",      TYPES::RESERVED, 9),
        Token(R"(!)",       TYPES::RESERVED, 9),
        Token(R"(if)",      TYPES::RESERVED, 12),
        Token(R"(else)",    TYPES::RESERVED, 0),//
        Token(R"(while)",   TYPES::RESERVED, 12),
        Token(R"(end)",     TYPES::RESERVED, 0),
        Token(R"(delete)",  TYPES::RESERVED, Lib::VAR_prt+1),
        Token(R"(help)",    TYPES::RESERVED, 0),
        //browser
        Token(R"(run)",     TYPES::RESERVED, 7),
         Token(R"(quit)",     TYPES::RESERVED, 7),
        Token(R"(open)",    TYPES::RESERVED, 11),
        Token(R"(click)",   TYPES::RESERVED, 11),
        Token(R"(input)",   TYPES::RESERVED, 11),
        Token(R"(clear)",   TYPES::RESERVED, 11),
        Token(R"(id)",      TYPES::RESERVED, 6),
        Token(R"(name)",    TYPES::RESERVED, 6),
        Token(R"(chrome)",  TYPES::RESERVED, 6),
        Token(R"(edge)",    TYPES::RESERVED, 6),
        
        //
        Token(R"([0-9]+)",  TYPES::INT, Lib::VAR_prt),
        Token(R"('[A-Za-z]*[A-Za-z0-9_./]*')",    TYPES::STR, Lib::VAR_prt),
        Token(R"(True)",    TYPES::BOOL, Lib::VAR_prt),
        Token(R"(False)",   TYPES::BOOL, Lib::VAR_prt),
        Token(R"([A-Za-z]+[A-Za-z0-9_]*)",      TYPES::ID, Lib::VAR_prt)
};

const std::string Lib::WEB::BROWSERS::CHROME = "chrome";
const std::string Lib::WEB::BROWSERS::EDGE = "edge";
int Lib::WEB::processCounter = 0;

