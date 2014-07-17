#ifndef UTILS_H
#define UTILS_H

#include "Utils.h"

string toString(int n) {
/* Converts an integer to string */
	string result;

	while (n) {
		result = static_cast<char>('0' + (n % 10)) + result;
		n /= 10;
	}

	return result;
}

#endif
