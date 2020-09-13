#include<vector>
#include<iostream>
#include "std_lib_facilities.h"

using namespace std;



class Token {  
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value
    Token(char ch)    // 
        :kind(ch), value(0) { }
    Token(char ch, double val)    
        :kind(ch), value(val) { }
};



class Token_stream {
public:
    Token_stream();   // make a Token_stream that reads from cin
    Token get_token();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
private:
    bool full;        // checks for token in buffer
    Token buffer;     // here is where we keep a token
};



Token_stream::Token_stream()
:full(false), buffer(0) // set buffer 0 and full false     
{}

class BadToken{}; // bad token exception

void Token_stream::putback(Token t) //
{
    if (full) // checks if buffer is full or empty
      error("Can't putback into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer full 
}

// Most of this code I pulled from the quizzes and I wrote the classes above using lots of help from the internet
Token Token_stream::get_token() {
	if (full)
    {   
        full=false;
        return buffer; 
    }
	char input;
	cin.clear();
	cin >> input;
	
	switch (input){
		case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':{
			double val = input - '0' ;
			return Token('n', val);
		}
		case '(': case ')': case '+': case '-': case '*': case '/': case';': case'q':{
			return Token(input, 0);
		}
		default:
			throw BadToken{};
	} 
}

Token_stream ts; 

double term();
double expression();


double primary(){
	Token t = ts.get_token();
	switch (t.kind) { // if a paranthesis is given
		case '(':{
			double d = expression();
			t = ts.get_token();
			if (t.kind != ')') throw BadToken();
			return d;
		}
		case 'n': // if a number is given
			return t.value;
	
		default:
			throw BadToken();
	}
}





int main(){
	double val = 0;
	cout << "Enter q at any point to cancel input and enter ; to finalize entry for calculator \n";
	while (cin){
		try{
			Token t = ts.get_token();
			if (t.kind == 'q') break;
			if (t.kind == ';') cout << val << '\n';
			else {ts.putback(t);}
			val = expression();
		}
		catch(BadToken){
			cout << "Error Bad Token try again \n";
			cin.clear();
		}
		
	}
	
	return 0;
}

double expression(){
	double left = term();
	while(true){
		Token t = ts.get_token();
		switch (t.kind){
			case '+': left += term(); break;
			case '-': left -= term(); break;
			default: ts.putback(t); return left;
		}
	}
}
	
double term(){
	double left = primary();

	while(true){
		Token t = ts.get_token();
		switch (t.kind){
			case '*': left *= primary(); break;
			case '/': left /= primary(); break;
			default: ts.putback(t); return left;
		}
	}
}	
