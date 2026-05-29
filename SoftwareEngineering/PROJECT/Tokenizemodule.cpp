#include <iostream>
#include <list>
#include <string>
using namespace std;

//Utilizing an gobal enum var for ease
enum TokenType{LPAR =-2, RPAR = -1, VAL = 0, XOR, NAND, OR, AND, NOT, UNDEF = -99};

//using a struct for Token class
struct Token {
    enum TokenType type; // Type of token (programmatically), is a enum value
    int pos;    // Character position
    string lexeme; // The literal character
    int value; 	// The literal value (T = 1, F = 0, All others = -1)
}

//Created a global list, type Token, to pass in and out of functions.
list<Token> Tokens;


//Function to convert every possible character given to the program into something it can work with, utilizes a string operator (haven't worked with these before so be mindful of it)

void Tokenize(string line;list<Token>& Tokens){
	//place starts at -1 so it can be 0 when on first char
	int place = -1;
	for (string::iterator chara = str.begin(); chara != str.end(); chara++; place++){
		//pretty normal switch case
		switch(char){
			case '(': 
				Tokens.append(Token(TokenType = LPAR, place, chara,-1));
				break;
			case ')': 
				Tokens.append(Token(TokenType = RPAR, place, chara,-1));
				break;
			case '!': 
				Tokens.append(Token(TokenType = NOT, place, chara,-1));
				break;
			case '&': 
				Tokens.append(Token(TokenType = AND, place, chara,-1));
				break;
			case '|': 
				Tokens.append(Token(TokenType = OR, place, chara,-1));
				break;
			case '@': 
				Tokens.append(Token(TokenType = NAND, place, chara,-1));
				break;
			case '$': 
				Tokens.append(Token(TokenType = XOR, place, chara,-1));
				break;
			case 'T': 
				Tokens.append(Token(TokenType = LPAR, place, chara,1));
				break;
			case 'F': 
				Tokens.append(Token(TokenType = LPAR, place, chara,0));
				break;
            		case '\t' | '\r' | '\n' | ' ':
				break;
            		case _:
				throw SyntaxError("Invalid token %s found.",char);
		}
	}