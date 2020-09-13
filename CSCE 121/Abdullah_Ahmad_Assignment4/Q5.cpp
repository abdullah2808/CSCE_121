#include <iostream>
using namespace std;
#include <vector>


	
void vectorswap(vector <int> a, vector <int>& b){ // vector b is dereferenced 

	for (int i = 0; i < (b.size()); i++){ // the iteration starts at the size - 1 which would be the last number of vector a and then goes down to 0 pushing the values into b
		b.at(i) = a[a.size() - 1 - i]; 
	}
	
	return;
	}
	
void vectorprint(vector <int> v){ // prints out the values of desired vector from the functions thing we did in class pretty much 
		for (int i = 0; i < v.size(); i++) {
        cout << v.at(i) << endl;
	}
}

void recursswap(vector <int>& a, int i = 0){
	
	if (i < a.size() / 2 ){ // only runs half the size of the vector because it replaces the first and last element using a temp variable
		int temp;
		temp = a.at(i);
		a[i] = a[a.size() - i - 1];
		a[a.size() - i - 1] = temp; 
		recursswap(a,i+1); // recursive calls the function so it'll run again until every element has been swapped
	}
	
	else{
		return;
	}
}
	
	


int main(){
	vector <int> a(10); // a vector of size 10
	vector <int> b(10); // vector b to be returned too 
	
	for (int i = 0; i < a.size() ; i++) { // fills A with numbers 0 through 9 
        a.at(i) = i;
	}
	
	cout << "The initial vector known as vector a: \n";
	vectorprint(a);
	
	vectorswap(a,b); // prints out value of B as a test
	cout << "Vector B using the First Swap function: \n";	
	vectorprint(b); // prints out vector b 

	recursswap(a);
	cout << "Vector A using the recursive swap function: \n";
	vectorprint(a);
	
	return 0;
}