#include <iostream>
#include <math.h>
using namespace std;

class InvalidMonth{};
class InvalidDay{};
class InvalidYear{};


int adder(int x){ // simple function to add digits of a number together
	int m;
	int sum = 0;
	while(x>0)    {
	
	m=x%10;    
	sum=sum+m;    
	x=x/10;    
	}
	return sum;
}
int sumDigits(int month, int day, int year){ // returns the su mof the added dagits
	int tsum;
	int msum;
	int dsum;
	int ysum;
	msum = adder(month); // will never return an int above 9 already because max value of month is 12
	dsum = adder(day);
	ysum = adder(year);
	
	while (dsum >= 10){ // makes sure the sum of dsum is under 10
	dsum = adder(dsum);	
	}
	while (ysum >= 10){ // makes sure the year sum is under 10
	ysum = adder(ysum);
	}

	tsum = msum + dsum + ysum;
	
	while (tsum >= 10){ // makes sure the total sum is under 10
	tsum = adder(tsum);	
	}
	return tsum;
	
}

int main(){
	int month;
	int day;
	int year;
	int caseNum; 
	int checker; // is 0 until the correct format is entered

	while (checker != 1){ // takes in input and checks if it is in the correct format
	try{
	cout << "Please enter your birthdate in the format format, month day year, e.g. 9 21 1985: \n";
	
	cin >> month >> day >> year;
	int yearc = log10(year); // just a variable to make sure year is in the correct format

	if (month <= 0 || month > 12){
	throw InvalidMonth();	
	}
	
	if (day <= 0 || day > 31) {
	throw InvalidDay();
	}
	
	if (yearc != 3) {  // if format is not matched
	throw InvalidYear();
	}
	
	else{
		checker = 1;
	}
	}
	
	catch (InvalidMonth){ // catches the exception of an invalid month
			cout << "You have entered an invalid month. \n";
			cin.clear(); 
		}
	catch (InvalidDay){ // catches the exception of an invalid day
			cout << "You have entered an invalid day. \n";
			cin.clear(); 
		}
	catch (InvalidYear){ // catches the excepion of an invalid month 
			cout << "You have entered an invalid year. \n";
			cin.clear(); 
		}
	}
	

	
	
	caseNum = sumDigits(month,day,year);
	
	switch(caseNum){ // different case numbers correspond to different nums
	case 1:
	cout << "Your Lucky Number is 1" << endl;
	cout << "You Personality Type is The Leader and your characteristics are: \n";
	cout << "Strategic\nStrong-Willed \nSelf Confidant \nCharismatic \n";
	break;	
	case 2:
	cout << "Your Lucky Number is 2" << endl;
	cout << "You Personality Type is The Mediator and your characteristics are: \n";
	cout << "Idealistic \nOpen-Minded \nFlexible \nVery Creative \n";
	break;	
	case 3:
	cout << "Your Lucky Number is 3" << endl;
	cout << "You Personality Type is The Communicator and your characteristics are: \n";
	cout << "Knowledgeable \nOriginal \nSelf Confidant \nEnergetic \n";	
	break;	
	case 4:
	cout << "Your Lucky Number is 4" << endl;
	cout << "You Personality Type is The Teacher and your characteristics are: \n";
	cout << "Very Loyal \nSensitive \nGood at Connecting with others \nNurturing \n";	
	break;	
	case 5:
	cout << "Your Lucky Number is 5" << endl;
	cout << "You Personality Type is The Freedom Seeker and your characteristics are: \n";
	cout << "Imaginative \nCharming \nCurious \nRisk-taker \n";
	break;	
	case 6:
	cout << "Your Lucky Number is 6" << endl;
	cout << "You Personality Type is The Nurturer and your characteristics are: \n";
	cout << "Supportive \nReliable \nPatient \nLoyal \n";
	break;	
	case 7:
	cout << "Your Lucky Number is 7" << endl;
	cout << "You Personality Type is The Seeker and your characteristics are: \n";
	cout << "Obsevant \nCharismatic \nPopular \nKnowledge-hungry \n";
	break;
	case 8:
	cout << "Your Lucky Number is 8" << endl;
	cout << "You Personality Type is The Power House and your characteristics are: \n";
	cout << "Authorative \nStrong-Willed \nEfficient \nConfidant \n";
	break;	
	case 9:
	cout << "Your Lucky Number is 9" << endl;
	cout << "You Personality Type is The Humanitarian and your characteristics are: \n";
	cout << "Charitable \nTolerant \nAltruistic \nNatural Leaders\n";	
	break;	
	}	
		
 return 0;	
}