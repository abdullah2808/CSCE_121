#include <iostream>
using namespace std;
#include <cstdlib>



int minimal(int a, int b){ // checks which integar comes first

	if (a < b){ // checks if first number is less than b
		return a;

	}
	else if (a == b){ // checks if they are equal
		return a;

	}
	else{ // if second number is greater
		return b;
		
	}


}


char lexographical(char a, char b){ // checks lexographically which one comes first


	if (a < b){ // checks if first letter is less than second letter
		return a;

	}
	else if (a == b){ // checks if they are equal
		return a;

	}
	else{ // if 2nd letter is greater prints c
		return b;
		
	}

	
}

template <typename myType>
myType numeric(myType first, myType second){

	if (first < second){ // checks if first number is less than b
		return first;

	}
	else if (first == second){ // checks if they are equal
		return first;

	}
	else{ // if second number is greater
		return second;
		
	}

	
	
}


int main(){
	cout << "If the numbers or characters are equal will return a 0 or a blank space \n";
	
	cout << minimal(5,10) << endl;
	cout << minimal(-5,-15) << endl;
	cout << minimal(200,10) << endl;
	cout << minimal(10,10) << endl;
	cout << minimal(11,-11) << endl;
	
	cout << lexographical('A', 'B') << endl;
	cout << lexographical('A', 'A') << endl;
	cout << lexographical('Z', 'A') << endl;
	cout << lexographical('a', 'A') << endl;
	cout << lexographical('d', 'a') << endl;
					
	
	cout << numeric('D', 'D') << endl;
	cout << numeric('A', 'a') << endl;
	cout << numeric('C', 'c') << endl;
	cout << numeric(5, 5) << endl;
	cout << numeric(5, 10) << endl;
					


	return 0;
}		