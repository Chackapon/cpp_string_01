#include <iostream>
#include <string>
#include <algorithm>  
#include "string_01.h"

using std::cout, std::cin, std::endl, std::string;
using namespace string_toys;

auto main()->int{
	string str="tes towy\nstring 1 0 320";
	cout<<"> Str to: "<<str<<endl;
	cout<<"> Odwrocony str to: "<<reverse(str)<<endl;
	cout<<"> Wielka pierwsza litera: "<<first_to_upper(str)<<endl;
	cout<<"> Suma cyfr wystepujacych w str= "<<sum_digits(str)<<endl;
	cout<<"> substring \"ring\" znajduje sie na pozycji "<<search_substr(str,"ring")<<endl;
	string sub = "ring";
	cout<<">to samo ale na wskaznikach: "<<custom_serach(&str[0], &sub[0])<<endl;
	return 0;
}