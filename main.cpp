//============================================================================
// Name        : main.cpp
// Author      : Steven Theck & Ryan Epstein
// Description : Day of week calculator for user's birthdate
//============================================================================

#include "stdafx.h"
using namespace std;

int main() {

	int day, month, year;	// Integers for user input
	char * weekday;	// String for day of week
	char * zodiacSign; // String for zodiac sign

	cout << "Enter your date of birth (MM/DD/YYYY): ";
	cin >> month;	// User input for month of birth
	if (cin.get() != '/') {
		cout << "Expected /\n";
		return 1;
	}
	cin >> day;		// User input for day of birth
	if (cin.get() != '/') {
		cout << "Expected /\n";
		return 1;
	}
	cin >> year;	// User input for year of birth

	weekday = getWeekday(year, month, day);	// Call getWeekday function
	zodiacSign = getZodiacSign(year, month, day); // Call getZodiacSign function

	if (weekday != NULL) {
		cout << "\nYou were born on a " << weekday << ".\n";
		cout << "\nYour zodiac sign is " << zodiacSign << ".\n\n";
	}

	system("PAUSE");
	return 0;
}
