#include "Validator.h"

int main(void) {
	CreditCardValidation myValidator;
	 
	for (unsigned int i = 0; i < sizeof(testCard) / sizeof(testCard[0]); i++) {

		if (myValidator.validatecardNumber(testCard[i]) && myValidator.digitValidation(testCard[i])) {
			cout << " Card : " << testCard[i].c_str() << " is valid" << endl;
		}

		else if (myValidator.digitValidation(testCard[i]) == false) {
			cout << endl;
		}

		else{
			cout << " Card : " << testCard[i].c_str() << " is Invalid" << endl;
		}
	}
	return 0;
}





