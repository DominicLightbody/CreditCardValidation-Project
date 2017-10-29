#include "Validator.h"

int CreditCardValidation::convertChartoInt(const char digit)
{
	int numericalDigit = digit - '0';

	if (numericalDigit < 0 || numericalDigit > 9) {
		throw(0);
	}
	return(numericalDigit);
}

bool CreditCardValidation::validatecardNumber(const string cardNumber) {
	
	int calculatedCheckDigit = -1,  // -1 to remove the last didgit from the array 
		checkDigit, sumofValues = 0;
	
	int reversedNumbers[15];

	bool cardStatus = false;

	try {

		checkDigit = convertChartoInt(cardNumber.at(15));

		for (int i = 14; i >= 0; i--) {
			reversedNumbers[14-i] = convertChartoInt(cardNumber.at(i));
		}

		for (int i = 0; i <= 14; i =  i + 2) {
				reversedNumbers[i] = reversedNumbers[i] * 2;	
			}
		
		for (int i = 0; i <= 14; i = i+2) {
			if (reversedNumbers[i] > 9) {
				reversedNumbers[i] = reversedNumbers[i] - 9;
			}
		}
		 
		
		for (int i = 0; i <= 14; i++) {
				sumofValues += reversedNumbers[i];
		}

		calculatedCheckDigit = sumofValues % 10;
			
		cardStatus = (calculatedCheckDigit == checkDigit);
		}
	catch (...) {
		cardStatus = false;
	}
	return(cardStatus);
}

bool CreditCardValidation::digitValidation(string cardNumber) {

	for (int i = 0; i <= 15; i++) {
		char check = cardNumber.at(i);
		if (isalpha(check)) {
			cout << " Card invalid due to letter '" << cardNumber.at(i) << "' being present";
			return false;
		}
		else {
			return true;
		}
	}
}


//chose to use the array "reversedNumbers[]" for all calulations as it was more dynamic than using the oddCount and evenCount variables. The array allowed for all calculations to take place on the one variable.