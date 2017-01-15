/*
 * QuickSort.cpp
 *
 *  Created on: 11/01/2017
 *      Author: Ban
 */
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int NUMBERS_TO_SORT = 10;

void randomlyPopulateArray(int *a);
void printArray(int *a);
void quickSort(int *arr, int left, int right);
void swap(int *arr, int i, int j);
int partition(int *arr, int left, int right, int pivot);

int main(){
	int a[NUMBERS_TO_SORT];
	int low = 0;
	int high = NUMBERS_TO_SORT - 1;

	// So I just learned that in order to get the length of an array
	// in C++ we use this: sizeof(a)/sizeof(a[0]):

	// cout << "Size of the array: " << sizeof(a)/sizeof(a[0]);

	// Move on.
	randomlyPopulateArray(a);
	cout << "Array before QuickSort: ";
	printArray(&a);

	quickSort(&a, low, high);

	cout << "Array after QuickSort: ";
	printArray(&a);

	return 0;
}

void randomlyPopulateArray(int *a){
	int aLength = sizeof(a)/sizeof(a[0]);

	// Initialize randomize
	srand(time(NULL));

	for (int i = 0; i < aLength; i++){
		a[i] = rand() % 10 + 1;
	}
}

void printArray(int *a){
	int aLength = sizeof(a)/sizeof(a[0]);

	for (int i = 0; i < aLength - 1; i++){
		cout << a[i] << ", ";
	}

	cout << a[aLength - 1] << endl;
}

void swap(int *arr, int i, int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int partition(int *arr, int left, int right, int pivot){

	while(left <= right){
		while (arr[left] < pivot){
			left++;
		}
		while (arr[right] > pivot){
			right--;
		}

		if (left <= right){
			swap(arr, left, right);
			left++;
			right--;
		}
	}

	return left;
}

void quickSort(int *arr, int left, int right){
	if (left >= right){
		return;
	}

	int pivot = (left + right) / 2;
	int index = partition(arr, left, right, pivot);
	quickSort(arr, left, index - 1);
	quickSort(arr, index, right);
}


