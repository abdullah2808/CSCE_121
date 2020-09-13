#include<vector>
#include<iostream>

using namespace std;

struct Token{ // defining new type token
	char kind;
	int value;
	Token(char ch) : kind(ch), value(0) {} // constructor with kind and no value
	Token(char ch, int val) : kind(ch) , value(val) {} // constructor for numbers
};

class BadToken{}; // exception bad token

Token get_token() {
	char input;
	cin.clear();
	cin >> input;
	
	switch (input){
		case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':{ // numbers switch input
			double val = input - '0' ;
			return Token('n', val);
		}
		case '(': case ')': case '+': case '-': case '*': case '/': case ';': case 'q': { // ( ) + - * switch input
			return Token(input, 0);
		}
		default: // the default case
			throw BadToken();
	} 
}

double term();
double expression();


double primary(){
	Token t = get_token();
	switch (t.kind) { // if a paranthesis is given
		case '(':{
			double d = expression();
			t = get_token();
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
			Token t = get_token();
			if (t.kind == 'q') break;
			if (t.kind == ';') cout << val << '\n';
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
		Token t = get_token();
		switch (t.kind){
			case '+': left += term(); break;
			case '-': left -= term(); break;
			default: return left;
		}
	}
}
	
double term(){
	double left = primary();

	while(true){
		Token t = get_token();
		switch (t.kind){
			case '*': left *= primary(); break;
			case '/': left /= primary(); break;
			default: return left;
		}
	}
}	

