/*
 * BubbleSort.cpp
 *
 *  Created on: 10/01/2017
 *      Author: Ban
 *
 *  BubbleSort problem by:
 *
 *  https://www.hackerrank.com/challenges/ctci-bubble-sort
 *
 */
#include <iostream>
using namespace std;


int swap(int a[], int i, int j){
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
	return 0;
}

int bubbleSort(int a[], int n){
	int totalSwaps = 0;

	for(int i = 0; i < n; i++){
		int roundSwaps = 0;
		for (int j = 0; j < n - 1; j++){
			if (a[j] > a[j + 1]){
				swap(a, j, j + 1);
				roundSwaps++;
			}
		}

		if (roundSwaps == 0){
			cout << "\nArray sorted: ";
			for(int i = 0; i < n - 1; i++){
				cout << a[i] << ", ";
			}
			cout << a[n - 1];
			return totalSwaps;
		} else {
			totalSwaps += roundSwaps;
		}
	}
	return totalSwaps;
}

int main(){

	int n = 0;
	cout << "Enter number of integers to BubbleSort: ";
	cin >> n;
	int a[n];

	for(int i = 0; i < n; i++){
		cout << "\nPopulate position " << i << "/" << n << ": ";
		cin >> a[i];
	}

	cout << "\nArray before bubble sort: ";
	for(int i = 0; i < n; i++){
		cout << "\nArray[" << i << "]: " << a[i];
	}

	int totalSwaps = bubbleSort(a, n);

	cout << "\nArray sorted in: " << totalSwaps << " swaps." << endl;

	return 0;
}


