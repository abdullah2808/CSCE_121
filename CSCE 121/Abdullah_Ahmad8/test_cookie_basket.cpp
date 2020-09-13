#include "cookie.cpp"

int main() {
	Basket_Vector cookieBasket;
	Basket_Vector cookieBasket1;
	Basket_Vector cookieBasketV;
	//Basket_Vector cookieBasketV1;
	int t;
	int s;
	ifstream iFile("cookies.txt");
	if (iFile.is_open()) {
		while (!iFile.eof()) {
			iFile >> t >> s;
			Cookie c(t, s);
			cookieBasket.add_cookie(c);
		}
	}
	ifstream iFile2("cookies1.txt");
	if (iFile2.is_open()) {
		while (!iFile2.eof()) {
			iFile2 >> t >> s;
			Cookie c(t, s);
			cookieBasket1.add_cookie(c);
		}
	}
	cout << "Cookes in basket 1: \n";
	cookieBasket.print_cookies();
	cout << "Cookies in basket 2: \n";
	cookieBasket1.print_cookies();
	cookieBasketV.merge_baskets(cookieBasket, cookieBasket1);
	cout << "The merge of baskets 1 and 2 is: \n";
	cookieBasketV.print_cookies();
	cout << "The number of small cookies is: \n" << cookieBasketV.cookie_size_total(CookieSize::medium) << endl;
	cout << "The number of Macadmia Nut Chocolate cookies is: \n" << cookieBasketV.cookie_type_total(CookieType::macadamianutchocolate) << endl;
	cout << "The cookie total is: \n" << cookieBasketV.cookie_total() << endl;
	cout << "Clearing the basket. \n";
	cookieBasketV.clear_basket();
	cookieBasketV.intersect_baskets(cookieBasket, cookieBasket1);
	cout << "The intersect of the baskets is : \n";
	cookieBasketV.print_cookies();
	cout << "Clearing the basket. \n";
	cookieBasketV.clear_basket();
	cookieBasketV.difference_baskets(cookieBasket, cookieBasket1);
	cout << "The difference of the baskets is : \n";
	cookieBasketV.print_cookies();
	return 0;
}