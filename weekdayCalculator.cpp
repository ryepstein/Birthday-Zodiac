/*
 * weekdayCalculator.cpp
 *
 *  Created on: Jul 29, 2015
 *      Author: Steven Theck & Ryan Epstein
 */

#include "stdafx.h"

using namespace std;

int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // Number of days in each month

char * getWeekday(int year, int month, int day) {

	// Base date: July 26, 2015

	char * weekdayArray[] = { "Sunday", "Monday", "Tuesday", "Wednesday",
			"Thursday", "Friday", "Saturday" };	// Array of weekdays
	int count = 0; // Count variable for time between user-defined date and base date

	if (month < 1 || month > 12) {
		cout << "Invalid month\n";
		return NULL;
	}
	if (day < 1 || day > daysInMonth[month-1]) {
		if (month == 2) {
			if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) { //Calculate if the year is a leap year
				if (day > 29) {
					cout << "Invalid day\n";
					return NULL;
				}
			}
			else {
				cout << "Invalid day\n";
				return NULL;
			}
		}
		else {
			cout << "Invalid day\n";
			return NULL;
		}
	}

	count += day - 26; // Calculate difference in days; base day is 26

	if (month < 7)	// Calculate difference in months; base month is 7
		for (int i = 7; i > month; i--)
			count -= daysInMonth[i - 2];
	else
		for (int i = 7; i < month; i++)
			count += daysInMonth[i - 1];

	if (year < 2015) {	// Calculate difference in years; base year is 2015
		for (int i = 2015; i > year; i--) {
			if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))
				count -= 366;
			else
				count -= 365;
		}
		if ((((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) && (month < 3))
			count -= 1;	// Subtract one day if user-defined year is a leap year
	} else {
		for (int i = 2015; i < year; i++) {
			if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))
				count += 366;
			else
				count += 365;
		}
		if ((((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) && (month > 2))
			count += 1;	// Add one day if user-defined year is a leap year
	}

	count %= 7;	// Get integer value for day of the week

	if (count < 0)
		count += 7;	// Change from negative to positive if user-defined date is prior to base date

	return weekdayArray[count]; // Return day of week string
}

char * getZodiacSign(int year, int month, int day) {
	char * zodiacSignArray[] = { "Aquarius", "Pisces", "Aries", "Taurus", "Gemini", "Cancer", "Leo", "Virgo", "Libra", "Scorpio", "Sagittarius", "Capricorn" };	// Array of zodiac signs

	int count = 0;
	bool leapYear = false;
	
	for (int i = 0; i < month - 1; i++)
		count += daysInMonth[i];
	count += day;
	if (month > 2) {
		if ((((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) && (month > 2)) {
			count += 1;	// Add one day if user-defined year is a leap year
			leapYear = true;
		}
	}

	if (count > 19 && count <= 49)
		return zodiacSignArray[0];
	else if (count > 49 && (count <= 79 || (count <= 80 && leapYear)))
		return zodiacSignArray[1];
	else if ((count > 79 || (count > 80 && leapYear)) && (count <= 109 || (count <= 110 && leapYear)))
		return zodiacSignArray[2];
	else if ((count > 109 || (count > 110 && leapYear)) && (count <= 140 || (count <= 141 && leapYear)))
		return zodiacSignArray[3];
	else if ((count > 140 || (count > 141 && leapYear)) && (count <= 171 || (count <= 172 && leapYear)))
		return zodiacSignArray[4];
	else if ((count > 171 || (count > 172 && leapYear)) && (count <= 204 || (count <= 205 && leapYear)))
		return zodiacSignArray[5];
	else if ((count > 204 || (count > 205 && leapYear)) && (count <= 235 || (count <= 236 && leapYear)))
		return zodiacSignArray[6];
	else if ((count > 235 || (count > 236 && leapYear)) && (count <= 265 || (count <= 266 && leapYear)))
		return zodiacSignArray[7];
	else if ((count > 265 || (count > 266 && leapYear)) && (count <= 295 || (count <= 296 && leapYear)))
		return zodiacSignArray[8];
	else if ((count > 295 || (count > 296 && leapYear)) && (count <= 325 || (count <= 326 && leapYear)))
		return zodiacSignArray[9];
	else if ((count > 325 || (count > 326 && leapYear)) && (count <= 356 || (count <= 357 && leapYear)))
		return zodiacSignArray[10];
	else if (count <= 19 || count > 356)
		return zodiacSignArray[11];
}
