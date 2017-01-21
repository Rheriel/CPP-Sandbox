/*
 * MergeSort.cpp
 *
 *  Created on: 16/01/2017
 *      Author: Ban
 */

#include <iostream>

void mergeSort(int *arr);
void mergeSort(int *arr, int *temp, int low, int high);
void mergeHalves(int *arr, int *temp, int leftStart, int rightEnd);

int ARRAY_SIZE = 10;

void mergeSort(int *arr){
	mergeSort(arr, new int[ARRAY_SIZE], 0, ARRAY_SIZE - 1);
}

void mergeSort(int *arr, int *temp, int low, int high){
	if (low >= high) return;

	int mid = low + ((high - low) / 2);

	mergeSort(arr, temp, low, mid);
	mergeSort(arr, temp, mid + 1, high);
	mergeHalves(arr, temp, low, high);
}

void mergeHalves(int *arr, int *temp, int leftStart, int rightEnd){
	int left = leftStart;
	int leftEnd = leftStart + ((rightEnd - leftStart) / 2);
	int rightStart = leftEnd + 1;
	int right = rightStart;
	int index = leftStart;

	while (left <= leftEnd && right <= rightEnd){
		if (arr[left] > arr[right]){
			temp[index++] = arr[right++];
		} else {
			temp[index++] = arr[left++];
		}
	}

	while (left <= leftEnd){
		temp[index++] = arr[left++];
	}
	while (right <= rightEnd){
		temp[index++] = arr[right++];
	}

	for (int i = leftStart; i <= rightEnd; i++){
		arr[i] = temp[i];
	}
}

int main(){
	int arr[] = { 5, 1, 2, 4, 6, 9, 3, 8, 7, 0 };

	for(int i = 0; i < ARRAY_SIZE - 1; i++){
		std::cout << arr[i] << ", ";
	}
	std::cout << arr[ARRAY_SIZE - 1] << std::endl;

	std::cout << "Calling MergeSort." << std::endl;

	mergeSort(arr);

	for(int i = 0; i < ARRAY_SIZE - 1; i++){
		std::cout << arr[i] << ", ";
	}
	std::cout << arr[ARRAY_SIZE - 1] << std::endl;

}


