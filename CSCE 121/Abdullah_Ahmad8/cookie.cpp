#include <iostream>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <list>
#include <fstream>
using namespace std;


enum class CookieType { // enum class that can contain these certain values 
	macadamianutchocolate, walnutchocolatechunk, blackberrygalettes, whitechocolateraspberry };

enum class CookieSize // enum class that can contain these certain values 
{
	small, medium, large };


class Cookie
{
	private:
	CookieSize size;
	CookieType type;
	public:
	Cookie(CookieType ty, CookieSize sz): type(ty), size(sz) {} //default constructor 
	Cookie(int t, int s) : type(CookieType(t)), size(CookieSize(s)) {} // constructor for reading cookies 
	CookieType get_type() const; // get type function
	CookieSize get_size() const; // get size function 
	bool operator==(const Cookie& cook)const; // operator overloading 
	bool operator!=(const Cookie& cook)const; // operator overloading 
	friend ostream& operator<<(ostream& os, Cookie& cook); // operator overloading for <<
	bool operator < (const Cookie& cook); /// for sorting as per size

	
};

inline CookieSize Cookie::get_size() const // returns size 
{
	return size;
} 



inline CookieType Cookie::get_type() const // returns type 
{
	return type;
}

inline bool Cookie::operator==(const Cookie& cook)const // operator == overloading 
{
	return(size == cook.size && type == cook.type);; // compares size to type 
}

inline bool Cookie::operator!=(const Cookie& cook)const // operator == overloading 
{
	return(size != cook.size && type != cook.type);; // compares size to type 
}

inline bool Cookie::operator<(const Cookie& cook)
{
	return size < cook.size;
}




inline ostream& operator<<(ostream& os, Cookie& cookie) // operator overloading <<
{
	switch(cookie.Cookie::get_type()){ // switch statement to get the type and then printing the right thing
	case CookieType::macadamianutchocolate:
		os << "Macadamia Nut Chocolate, ";
		break;
	case CookieType::walnutchocolatechunk:
		os << "Walnut Chocolate Chunk, ";
		break;
	case CookieType::blackberrygalettes:
		os << "Blackberry Galettes, ";
		break;
	case CookieType::whitechocolateraspberry:
		os << "White Chocolate Raspberry, ";
		break;
}

	switch (cookie.Cookie::get_size()) // using a switch statement to get the size and then printing the coresponding statement
	{
	case CookieSize::small:
		os << "Small; ";
		break;
	case CookieSize::medium:
		os << "Medium; ";
		break;
	case CookieSize::large:
		os << "Large; ";
		break;
}
    return os;
}

class Basket{ // basket class with all virtual functions 

	public:
		virtual void add_cookie(const Cookie& c) = 0;
		virtual bool is_in_basket(const Cookie& c)const = 0;
		virtual Cookie remove_any_cookie() = 0;
		virtual void remove_cookie(const Cookie& c) = 0;
		virtual void clear_basket() = 0;
		virtual bool is_basket_empty() const = 0;
		virtual int cookie_total() const = 0;
		virtual int cookie_size_total(CookieSize s) const = 0;
		virtual int cookie_type_total(CookieType t)const = 0;
		virtual void print_cookies() const = 0;
		virtual void copy_basket(const Basket& basket) = 0;
		virtual void merge_baskets(const Basket& basket1, const Basket& basket2) = 0;
		virtual void intersect_baskets(const Basket& basket1, const Basket& basket2) = 0;		virtual void difference_baskets(const Basket& basket1, const Basket& basket2) = 0;
		virtual vector<Cookie> getbv() const = 0;
		virtual list<Cookie> getbl() const = 0;
};

class Basket_Vector:public Basket{

	private:
		vector <Cookie> cookie_basket;
		list <Cookie> cookie_basket1;
	public:
		virtual void add_cookie(const Cookie& c);
		bool is_in_basket(const Cookie& c)const;
		Cookie remove_any_cookie();
		void remove_cookie(const Cookie& c);
		void clear_basket();
		bool is_basket_empty() const;
		int cookie_total() const;
		int cookie_size_total(CookieSize s)const;
		int cookie_type_total(CookieType t)const;
		void print_cookies()const;
		void copy_basket(const Basket& basket);
		void merge_baskets(const Basket& basket1, const Basket& basket2);
		void intersect_baskets(const Basket& basket1, const Basket& basket2);		void difference_baskets(const Basket& basket1, const Basket& basket2) ;
		vector<Cookie> getbv() const {
			return cookie_basket;
		}
		list<Cookie> getbl() const {
			return cookie_basket1;
		}
};

// add a cookie function 
inline void Basket_Vector::add_cookie(const Cookie& c){
	cookie_basket.push_back(c);
}


//checks if it is in the basket
inline bool Basket_Vector::is_in_basket(const Cookie& c)const{

	vector<Cookie>::const_iterator i; ///iterator
	for(i = cookie_basket.begin() ; i != cookie_basket.end() ; i++ ) // iterates through the vector 
	{ 
		if(i->get_size() == c.get_size() && i->get_type() == c.get_type()){ // checks if type are same
			return true; // returns true if the cookie is in the basket
		}
	}
	return false;
}

// remove random cookie 
inline Cookie Basket_Vector::remove_any_cookie(){
	int k =rand() % cookie_basket.size();
	Cookie c = cookie_basket[k]; // sets place to random cookie 
	vector<Cookie>:: iterator i = cookie_basket.begin(); // iterator at beginning
	i = i + k; // moves iterator to cookie posistion
	cookie_basket.erase(i); ///remove that cookie from basket
	return c; // return that cookie
}

// removing a cookie from basket 
inline void Basket_Vector::remove_cookie(const Cookie& c){
	vector<Cookie>:: iterator i = cookie_basket.begin(); // iterator at beginning 
	for( ; i != cookie_basket.end() ;i++){ // going through the basket 
		if(i->get_size() == c.get_size() && i->get_type() == c.get_type()){ // if same size and type
			cookie_basket.erase(i); //removes  cookie
			break;
		}
	}
}

//function to remove all cookies from basket
inline void Basket_Vector::clear_basket(){
	cookie_basket.clear();
}

// checks if basket is empty 
inline bool Basket_Vector::is_basket_empty() const{
	return cookie_basket.size() == 0;
}

// function to get total size 
inline int Basket_Vector::cookie_total() const{
	return cookie_basket.size();
}


// returns number of cooking have the same siz e
inline int Basket_Vector::cookie_size_total(CookieSize s)const{
	int count = 0;
	vector<Cookie>:: const_iterator i = cookie_basket.begin(); // starts iterator at start 
	for( ; i != cookie_basket.end() ; i++){ // going through the basket 
		if(i->get_size() == s ){ // if size matches 
		count++;
		}
	}
return count; // returns amount of cookies having a certain size 
}

// returns number of cookie of certain type
inline int Basket_Vector::cookie_type_total(CookieType t)const{
	int count=0;
	vector<Cookie>:: const_iterator i = cookie_basket.begin(); /// iterator at first position
	for( ; i != cookie_basket.end() ;i++){ /// iterate through basket
		if(i->get_type() == t ){/// if type matches then increment cnt
			count++;
		}
	}
return count; ///return count of cookies having type t
}

inline void Basket_Vector::print_cookies() const{


	vector <Cookie> temp = cookie_basket; // copy vector 
	sort(temp.begin(),temp.end()); // sorts the temp vector 
	for(size_t i=0;i<temp.size();i++){
		cout << temp[i] << endl; // prints all the cookie sorted by size 
}
}

inline void Basket_Vector::copy_basket(const Basket& basket) {
	vector<Cookie> temp = basket.getbv();
	for (int i = 0; i < temp.size(); i++) {
		cookie_basket.push_back(temp[i]);
	}
}

inline void Basket_Vector::merge_baskets(const Basket& basket1, const Basket& basket2) {
	vector<Cookie> temp = basket1.getbv();
	vector<Cookie> temp2 = basket2.getbv();
	for (int i = 0; i < temp.size(); i++) {
		cookie_basket.push_back(temp[i]);
	}
	for (int j = 0; j < temp2.size(); j++) {
		cookie_basket.push_back(temp2[j]);
	}
}

inline void Basket_Vector::intersect_baskets(const Basket& basket1, const Basket& basket2) {
	vector<Cookie> temp = basket1.getbv();
	vector<Cookie> temp2 = basket2.getbv();
	for (int i = 0; i < temp.size(); i++) {
			if (basket2.is_in_basket(temp[i]))
			{
				cookie_basket.push_back(temp[i]);
			}
		}
	
}

inline void Basket_Vector::difference_baskets(const Basket& basket1, const Basket& basket2) {
	vector<Cookie> temp = basket1.getbv();
	vector<Cookie> temp2 = basket2.getbv();
	for (int i = 0; i < temp.size(); i++) {
		if (basket2.is_in_basket(temp[i]))
		{
			continue;
		}
		else cookie_basket.push_back(temp[i]);
	}

}

class Basket_LinkedList :public Basket {

private:
	vector <Cookie> cookie_basket1;
	list <Cookie> cookie_basket;
public:
	virtual void add_cookie(const Cookie& c);
	bool is_in_basket(const Cookie& c)const;
	Cookie remove_any_cookie();
	void remove_cookie(const Cookie& c);
	void clear_basket();
	bool is_basket_empty() const;
	int cookie_total() const;
	int cookie_size_total(CookieSize s)const;
	int cookie_type_total(CookieType t)const;
	void print_cookies()const;
	void copy_basket(const Basket& basket);
	void merge_baskets(const Basket& basket1, const Basket& basket2);
	void intersect_baskets(const Basket& basket1, const Basket& basket2);	void difference_baskets(const Basket& basket1, const Basket& basket2);
	list<Cookie> getbl() const {
		return cookie_basket;
	}
	vector<Cookie> getbv() const {
		return cookie_basket1;
	}
};

inline void Basket_LinkedList::add_cookie(const Cookie& c) {
	cookie_basket.push_front(c);
}

inline bool Basket_LinkedList::is_in_basket(const Cookie& c)const {

	list<Cookie>::const_iterator i; ///iterator
	for (i = cookie_basket.begin(); i != cookie_basket.end(); i++) // iterates through the vector 
	{
		if (*i == c) { // checks if type are same
			return true; // returns true if the cookie is in the basket
		}
	}
	return false;
}

// remove random cookie 
inline Cookie Basket_LinkedList::remove_any_cookie() {
	int k = rand() % cookie_basket.size();
	list<Cookie>::iterator i = cookie_basket.begin(); // iterator at beginning
	advance(i, k); // advancing I to a random place 
	Cookie c = *i; // to save the value of i 
	cookie_basket.erase(i); ///remove that cookie from basket
	return c; // return that cookie
}

// removing a cookie from basket 
inline void Basket_LinkedList::remove_cookie(const Cookie& c) {
	list<Cookie>::iterator i = cookie_basket.begin(); // iterator at beginning 
	for (; i != cookie_basket.end(); i++) { // going through the basket 
		if (i->get_size() == c.get_size() && i->get_type() == c.get_type()) { // if same size and type
			cookie_basket.erase(i); //removes  cookie
			break;
		}
	}
}

//function to remove all cookies from basket
inline void Basket_LinkedList::clear_basket() {
	cookie_basket.clear();
}

// checks if basket is empty 
inline  bool Basket_LinkedList::is_basket_empty() const {
	return cookie_basket.size() == 0;
}

// function to get total size 
inline int Basket_LinkedList::cookie_total() const {
	return cookie_basket.size();
}


// returns number of cooking have the same siz e
inline int Basket_LinkedList::cookie_size_total(CookieSize s)const {
	int count = 0;
	list<Cookie>::const_iterator i = cookie_basket.begin(); // starts iterator at start 
	for (; i != cookie_basket.end(); i++) { // going through the basket 
		if (i->get_size() == s) { // if size matches 
			count++;
		}
	}
	return count; // returns amount of cookies having a certain size 
}

// returns number of cookie of certain type
inline int Basket_LinkedList::cookie_type_total(CookieType t)const {
	int count = 0;
	list<Cookie>::const_iterator i = cookie_basket.begin(); /// iterator at first position
	for (; i != cookie_basket.end(); i++) { /// iterate through basket
		if (i->get_type() == t) {/// if type matches then increment cnt
			count++;
		}
	}
	return count; ///return count of cookies having type t
}

inline void Basket_LinkedList::print_cookies() const {
	for (auto cookie : cookie_basket){
		cout << cookie << endl;
	}
	return;
	
}

inline void Basket_LinkedList::copy_basket(const Basket& basket) {
	list<Cookie> temp = basket.getbl();
	for (auto cookie : temp) {
		cookie_basket.push_back(cookie);
	}
}

inline void Basket_LinkedList::merge_baskets(const Basket& basket1, const Basket& basket2) {
	list<Cookie> temp = basket1.getbl();
	list<Cookie> temp2 = basket2.getbl();
	for (auto cookie : temp) {
		cookie_basket.push_back(cookie);
	}
	for (auto cookie1 : temp2) {
		cookie_basket.push_back(cookie1);
	}
}

inline void Basket_LinkedList::intersect_baskets(const Basket& basket1, const Basket& basket2) {
	list<Cookie> temp = basket1.getbl();
	list<Cookie> temp2 = basket2.getbl();
	for (auto cookie : temp) {
			if (basket2.is_in_basket(cookie))
			{
				cookie_basket.push_back(cookie);
			}
	}
}

inline void Basket_LinkedList::difference_baskets(const Basket& basket1, const Basket& basket2) {
	list<Cookie> temp = basket1.getbl();
	list<Cookie> temp2 = basket2.getbl();
	for (auto cookie : temp) {
		if (basket2.is_in_basket(cookie))
		{
			continue;
		}
		else cookie_basket.push_back(cookie);
		
	}

}
/*
int main() {
	 TESTING CODE
	Cookie c1(CookieType::macadamianutchocolate, CookieSize::medium);
	Cookie c2(CookieType::macadamianutchocolate, CookieSize::medium);
	Cookie c3(CookieType::whitechocolateraspberry, CookieSize::large);
	cout << c1 << endl;
	cout << (c1 == c2) << endl;
	cout << (c1 == c3) << endl;
	cout << c3;
	
	
	Basket_LinkedList cookieBasket;
	Basket_LinkedList cookieBasket2;
	Basket_LinkedList cookieBasket1;
	Basket_LinkedList cookieBasket3;
	Basket_LinkedList cookieBasket4;
	Basket_LinkedList cookieBasket5;
	if (cookieBasket.is_basket_empty()) {
		cout << "Basket is empty " << endl; // checking for the empty basket function 
	}

	cout << "Adding Cookies; " << endl;


	cookieBasket.add_cookie(Cookie(CookieType::macadamianutchocolate, CookieSize::medium));
	cookieBasket.add_cookie(Cookie(CookieType::macadamianutchocolate, CookieSize::medium));
	cookieBasket.add_cookie(Cookie(CookieType::whitechocolateraspberry, CookieSize::large)); // testing the adding function adding 3 cookies
	cookieBasket.add_cookie(Cookie(CookieType::blackberrygalettes, CookieSize::small));
	cookieBasket1.add_cookie(Cookie(CookieType::whitechocolateraspberry, CookieSize::large)); // testing the adding function adding 3 cookies
	cookieBasket1.add_cookie(Cookie(CookieType::blackberrygalettes, CookieSize::small));
	cout << "The Current basket is: " << endl;
	cookieBasket.print_cookies(); // printing the cookies sorted by size

	cout << "The amount of cookies in the basket: " << cookieBasket.cookie_total() << endl;
	cout << "The amount of medium cookies in the basket: " << cookieBasket.cookie_size_total(CookieSize::medium) << endl;
	cout << "The amount of macadamia nut chocolate cookies in the basket: " << cookieBasket.cookie_type_total(CookieType::macadamianutchocolate) << endl;
	
	cout << "Removing a random cookie; " << endl;
	Cookie c = cookieBasket.remove_any_cookie();
	cout << "The removed cookie is: ";
	cout << c << endl; // printing the removed cookie
	
	cout << "The basket after removing the cookie: " << endl;
	cookieBasket.print_cookies(); // checking what cookie removed

	cout << "Checks to see if a cookie of blackberry galletes small is in the basket: ";
	if (cookieBasket.is_in_basket(Cookie(CookieType::blackberrygalettes, CookieSize::small))) { // checking if a certain cookie is in basket
		cout << "Is here" << endl;
	}
	else {
	cout << "Is not here" << endl;
}
	
	//cout << "Clearing the basket: " << endl;
	//cookieBasket.clear_basket(); // clears basket 

	//cout << "Cookies in basket: " << cookieBasket.cookie_total();

	cout << "Basket Copy" << endl;
	cookieBasket2.copy_basket(cookieBasket);
	cookieBasket2.print_cookies();
	cout << "Basket Merge" << endl;
	cookieBasket3.merge_baskets(cookieBasket, cookieBasket1);
	cookieBasket3.print_cookies();
	cout << "Basket Intersect" << endl;
	cookieBasket4.intersect_baskets(cookieBasket, cookieBasket1);
	cookieBasket4.print_cookies();
	cout << "Basket Difference" << endl;
	cookieBasket5.difference_baskets(cookieBasket, cookieBasket1);
	cookieBasket5.print_cookies();
	
	return 0;
}

*/


