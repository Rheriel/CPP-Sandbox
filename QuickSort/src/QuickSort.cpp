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

void randomlyPopulateArray(int *a, const int size);
void printArray(int *a, const int size);
void quickSort(int *arr, const int left, const int right);
int partition(int *arr, const int left, const int right);

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

void randomlyPopulateArray(int *a, const int size){

	// Initialize randomize
	srand(time(NULL));

	int i = 0;
	while (i < size) {
		a[i] = rand() % 10 + 1;
		i++;
	}
}

void printArray(int *a, const int size){
	int i = 0;
	while (i < size - 1) {
		std::cout << a[i] << ", ";
		i++;
	}

	std::cout << a[size - 1] << std::endl;
}

int partition(int *arr, const int left, const int right){

	// This is a bug:
	// https://research.googleblog.com/2006/06/extra-extra-read-all-about-it-nearly.html
	// const int pivot = (left + right) / 2;

    // Use this instead:
    const int mid = left + ((right - left) / 2);
    const int pivot = arr[mid];

    std::cout << "Pivot: " << pivot << std::endl;

    // We move the pivot to the front.
    std::swap(arr[mid], arr[left]);

	int i = left + 1; // The pivot is now the first element.
	int j = right;

	while(i <= j){
		while (i <= j && arr[i] <= pivot){
			i++;
		}
		while (i <= j && arr[j] > pivot){
			j--;
		}

		if (i < j){
			std::swap(arr[i], arr[j]);
		}
	}

	// We move the pivot to its final position.
	std::swap(arr[i - 1], arr[left]);

	return i - 1;
}

void quickSort(int *arr, const int left, const int right){
	if (left >= right){
		return;
	}

	int index = partition(arr, left, right);
	quickSort(arr, left, index - 1);
	quickSort(arr, index + 1, right);
}


