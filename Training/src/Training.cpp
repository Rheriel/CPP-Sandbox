//============================================================================
// Name        : Training.cpp
// Author      : Jorge Perez
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void passByValue(int val);
void passByReference(int *val);

int main() {
	cout << "Hello, World!" << endl; // prints Hello, World!

	int value = 10;
	int reference = 10;

	passByValue(value);
	passByReference(&reference);

	cout << "Value after function: "<< value << endl;
	cout << "Reference after function: "<< reference << endl;

	return 0;
}

void passByValue(int val){
	val = 20;
}

void passByReference(int *val){
	*val = 20;
}
