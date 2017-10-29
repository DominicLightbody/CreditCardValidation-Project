#pragma once

#include <iostream>
#include <string>

using namespace std;

const string testCard[] = { "4686006570307405",
"4686006570307407",
"4093650457937474",
"4340423439668810",
"1234567812345670",
"5509415774265347",
"X234567812345670",
"4539281167952835",
"4532528637398511",
"4653549906803760" };

class CreditCardValidation {
private:
	static int convertChartoInt(const char digit);
public:
	static bool validatecardNumber(const string cardNumber);
	bool digitValidation(string cardNumber);
};


