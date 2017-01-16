/*
 * QuickSort.cpp
 *
 *  Created on: 11/01/2017
 *      Author: Ban
 */
#include <iostream>
#include <stdlib.h>
#include <time.h>

// Avoid Namespace pollution: https://gcc.gnu.org/ml/libstdc++/2000-09/msg00067.html
// using namespace std;

const int NUMBERS_TO_SORT = 10;

void randomlyPopulateArray(int *a, int size);
void printArray(int *a, int size);
void quickSort(int *arr, int left, int right);
int partition(int *arr, const int left, const int right, const int pivot);

int main(){
	int a[NUMBERS_TO_SORT];
	int low = 0;
	int high = NUMBERS_TO_SORT - 1;

	// So I just learned that in order to get the length of an array
	// in C++ we use this: sizeof(a)/sizeof(a[0]):

	// cout << "Size of the array: " << sizeof(a)/sizeof(a[0]);

	// Move on.
	randomlyPopulateArray(a, NUMBERS_TO_SORT);
	std::cout << "Array before QuickSort: ";
	printArray(a, NUMBERS_TO_SORT);

	quickSort(a, low, high);

	std::cout << "Array after QuickSort: ";
	printArray(a, NUMBERS_TO_SORT);

	return 0;
}

void randomlyPopulateArray(int *a, int size){

	// Initialize randomize
	srand(time(NULL));

	int i = 0;
	while (i < size) {
		a[i] = rand() % 10 + 1;
		i++;
	}
}

void printArray(int *a, int size){
	int i = 0;
	while (i < size - 1) {
		std::cout << a[i] << ", ";
		i++;
	}

	std::cout << a[size - 1] << std::endl;
}

int partition(int *arr, int left, int right, int pivot){

	while(left <= right){
		while (left <= right && arr[left] <= pivot){
			left++;
		}
		while (left <= right && arr[right] > pivot){
			right--;
		}

		if (left < right){
			std::swap(arr[left], arr[right]);
			left++;
			right--;
		}
	}

	return left;
}

void quickSort(int *arr, const int left, const int right){
	if (left >= right){
		return;
	}

	// This is a bug:
	// https://research.googleblog.com/2006/06/extra-extra-read-all-about-it-nearly.html
	// int pivot = (left + right) / 2;

    // Use this instead:
	int pivot = left + ((right - left) / 2);
	std::cout << "Pivot: " << pivot << std::endl;
	int index = partition(arr, left, right, pivot);
	quickSort(arr, left, index - 1);
	quickSort(arr, index, right);
}


