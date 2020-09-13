#include <iostream>
#include <cmath>


using namespace std;


int quadratic(double a, double b, double c, double& x1, double& x2) {

	if (a != 0) {
		double det = 0; 
		det = (pow(b, 2)) - (4 * a * c); // determinant 

		if (det >= 0) { // if its the det is greater than 0
			if (det == 0) {		
				x1 = (-b) / (2 * a); // double root

				return 1; // 1 root

			} else {
				x1 = (-b + sqrt(det)) / (2 * a); // root 1 
				x2 = (-b - sqrt(det)) / (2 * a); // root 2


				return 2; // two real roots
			}
		} else { // two complex roots
			return 4;
		}
	} else if (b != 0) { // linear equation
		x1 = -c/b;

		return 1;
	} else if (c != 0) { // no solutions c is not 0

		return 0;
	} else { // infinite roots

		return 3;
	}

}

int main() {
	
	double a, b, c, x1, x2, realPart, imaginaryPart;
	cout << "Enter a quadratic equation in the form ax^2 + bx + c: \n";
	cin >> a >> b >> c;
	double det = 0;
	det = (pow(b, 2)) - (4 * a * c);
	
	int n = quadratic(a,b,c,x1,x2); // n roots using the return statement for the switch
	
	switch(n){
		
	case 0:
	cout << "There are no roots.";
	break;
	
	case 1:
	cout << "There is one root: " << x1;
	break;
	
	case 2:
	cout << "There are two roots: " << x1 << " and x2: " << x2;
	break;
	
	case 3:
	cout << "There are infinite roots.";
	break;
	
	case 4: // complex roots and how to determine 
    realPart = -b/(2*a);
    imaginaryPart =sqrt(-det)/(2*a);
    cout << "There are complex roots."  << endl;
    cout << "x1 = " << realPart << "+" << imaginaryPart << "i" << endl;
    cout << "x2 = " << realPart << "-" << imaginaryPart << "i" << endl;
	break;
	
	}
	return 0;
	
}