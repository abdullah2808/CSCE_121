#include<vector>
#include<iostream>

using namespace std;

struct Token{ // defining new type token
	char kind;
	int value;
	Token(char ch) : kind(ch), value(0) {} // constructor with kind and no value
	Token(char ch, int val) : kind(ch) , value(val) {} // constructor for numbers
};



Token get_token() {
	char input;
	cin.clear();
	cin >> input;
	
	switch (input){
		case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':{ // numbers switch input
			double val = input - '0' ;
			return Token('n', val);
		}
		case '(': case ')': case '+': case '-': case '*': case '/': case ';': { // ( ) + - * switch input
			return Token(input, 0);
		}
		default: // the default case
			return Token(input, 0);
	} 
}

void vecprint(vector<int> v, vector<char> vc){ // prints vector of type int
	for (int i = 0; i < v.size(); i++){

		cout << "Kind: " <<vc.at(i) << endl;
		cout << "Value: " <<v.at(i) << endl;		
	}
}



int main(){
	vector<int> v; // int vecor for holding int values
	vector<char> vc; // char vector for holding char values
	cout << "Enter q at any point to cancel input and enter ; to finalize entry for calculator \n";
	while (cin){
		Token t = get_token();
		if (t.kind == 'q'){
			vecprint(v, vc);
			cout << endl;
		break;			
		}	 // breaks if q and prints the expression
		if (t.value == 0){ // if the t vvalue is 0 which means its a () - * + it pushes it to the vc vector
			vc.push_back(t.kind);
		}
		else { // the numbers get pushed to this vector and the kinds are also pushed 
			v.push_back(t.value);
			vc.push_back(t.kind);
		}
		
	}
	return 0;
}

		

