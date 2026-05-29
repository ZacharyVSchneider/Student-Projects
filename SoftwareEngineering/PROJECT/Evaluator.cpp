#include <iostream>
#include <list>
#include <string>
using namespace std;

//Using an enum instead of isinstance for eval
enum Instance{literal =1,binary,unary,group};

// Expr: Base Struct for any Expression, built with instance for eval
struct Expr{enum Instance instance;};

//Simple Class for T,F 
struct Literal: Expr {
	instance = literal;
	int value;
	};

//Binary: for all binary operations. (AND,OR, NAND XOR)
struct Binary: Expr {
	Expr left;
	enum TokenType op;
	Expr right;
	instance = binary;
};

//Unary: for prefix operations (NOT)
struct Unary: Expr {
	enum TokenType op;
	Expr right;
	instance = unary;
};

//Group: Grouped expressions
struct Group: Expr {
	Expr expression;
	instance = group;
};

//Pointer to current token
int current;

//getting the previous token
Token prev_tkn(list<Token>& Tokens){
	
	//pointer made to iterate through list, begins at list's 0 index
	list<Token>::iterator ptr = Tokens.begin();

	//Makes sure current is legit
	if (current <= Tokens.size())
		{
		//ptr is moved along the List by current - 1 to the given index,
		advance(ptr,current-1);

		//then returns it!
		return *ptr;
		}
	//returns error if not
	else{
		throw SyntaxError("prev_tkn given invalid Array Place.");}
}

Token curr_tkn(list<Token>& Tokens){
	//pointer made to iterate through list
	list<Token>::iterator ptr = Tokens.begin();

	//ensures current is legit
	if (current <= Tokens.size())
		{
		//ptr is moved along the List by current to the given index,
		advance(ptr,current)

		//then returns it!
		return *ptr;
		}
	//returns error if not
	else:
		throw SyntaxError("curr_tkn given invalid place");
}

Expr primary(list<Token>& Tokens){
	//nabs current tkn for Parsing
	Token tkn = curr_tkn(Tokens);

	//Parses Vals as literals
	if (tkn == TokenType.VAL)
		{
		current++;
		return Literal(tkn.value)
		}
	//Checks to ensure Every Paren is connected, returns group if so
	if (tkn == TokenType.LPAREN)
		{
		current++;
		Expr expr = xor(Tokens);
		if (curr_tkn(tokens).typ != TokenType.RPAREN)
			{ 
			throw SyntaxError("Missing right Paren.");
			}
		current++;
		return Group(expr);
		}
	current = 0;
	//returns error if no literals nor groups are found
	Token err_tkn = curr_tkn(Tokens);
	string err = format("Found an unexpected token {}", err_tkn.lexeme);
	throw SyntaxError(err);

	}

Expr unary(list<Token>& Tokens){
	//creates Unary Classes (NOTS)
	if (curr_tkn(Tokens).type == TokenType.Not)
		{

		current++;
		int op = prev_tkn(Tokens).type;
		Expr right = unary(Tokens);
		return Unary(op, right);

		}

	return primary(tokens);
	}

//Return ANDS
Expr _and(list<Token>& Tokens){

	Expr expr = unaray(Tokens);

	while(curr_tkn(Tokens) == TokenType.AND){
		
		current++;
		enum TokenType op = prev_tkn(Tokens).type;
		Expr right = unaray(tokens);
		expr = Binary(expr,op,right);
		}
	
	return expr;
	}

//Returns ORS
Expr _or(list<Token>& Tokens){
	
	Expr expr = _and(Tokens);

	while (curr_tkn(Tokens) == TokenType.OR){

		current++;
		op = prev_tkn(Tokens).type;
		right = _and(Tokens);
		expr = Binary(expr,op,right);
		}

	return expr;
	}

//Returns NANDS
Expr nand(list<Token>& Tokens){

	Expr expr = _or(tokens);

	while (curr_tkn(Tokens) == TokenType.NAND){

		current++;
		op = prev_tkn(Tokens).type;
		right = _or(Tokens);
		expr = Binary(expr,op,right);
		}

	return expr;
	}

//Returns XORS
Expr xor(list<Token>& Tokens){

	Expr expr = _or(tokens);

	while (curr_tkn(Tokens) == TokenType.NAND){

		current++;
		op = prev_tkn(Tokens).type;
		right = nand(Tokens);
		expr = Binary(expr,op,right);
		}

	return expr;
	}

//Parses the Ast out, 
Expr parse(list<Token>& Tokens, string line){
	list<Token>::iterator ptr = Tokens.begin();
	Expr ast = xor(Tokens);

	//returns error if there are leftover tokens
	if (current != Tokens.size()){
		advance(ptr,current-1);
		Token err_tkn = *ptr;
		string err = format("Error at Token {} : ",err_tkn.lexeme);
		current = 0;
		throw SyntaxError(err+line);
		}
	current = 0
	return ast;
	}

bool evalUnary(Unary node){
	int right = eval(nod.right);
	return not(right);
	}

bool evalBinary(Binary node){
	bool left = eval(node.left);
	bool right = eval(node.right);
	
	//despite the fact that Literals are ints, the evals return bools, so this still works
	switch(node.op){
		case TokenType.AND: return right && left;
			break;
		case TokenType.OR: return right || left;
			break;
		case TokenType.XOR: return right != left;
			break;
		case TokenType.NAND: return !(left && right);
			break;

		throw RuntimeError("Invalid AST Node found.");
		}
	}
//eval effectively turns the ints from the literals into bools for use in the other functions
bool eval(Expr node){
	if (node.instance == 1){
		if (node.value == 1){
		return true;
		}
		if (node.value == 0){
		return false;
		}
		if (node.value == -1){
		throw ValueError("Operator is being used as a value!");
		}

	}
	if (node.instance == 2){
		return evalBinary(node)}
	if (node.instance == 3){
		return evalUnary(node)}
	if (node.instance == 4){
		return eval(node.expression)}
	}
	throw RuntimeError("Invalid AST Node Found");
		
	}	

	

	





