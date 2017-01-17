/*
 * MergeSort.cpp
 *
 *  Created on: 16/01/2017
 *      Author: Ban
 */

#include <iostream>

void mergeSort(int arr[]);
void mergeSort(int arr[], int temp[], int low, int high);
void mergeHalves(int arr[], int temp[], int leftStart, int rightEnd);

void mergeSort(int arr[]){
	int aLength = sizeof(arr) / sizeof(arr[0]);
	mergeSort(arr, new int[aLength], 0, aLength - 1);
}

void mergeSort(int arr[], int temp[], int low, int high){
	if (low >= high) return;
	int mid = low + ((high - low) / 2);

	mergeSort(arr, temp, low, mid);
	mergeSort(arr, temp, mid + 1, high);
	mergeHalves(arr, temp, low, high);
}

void mergeHalves(int arr[], int temp[], int leftStart, int rightEnd){
	int left = leftStart;
	int leftEnd = leftStart + ((rightEnd - leftStart) / 2);
	int rightStart = leftEnd + 1;
	int right = rightStart;
	int index = leftStart;
	int size = (rightEnd - leftStart) + 1;

	while (left <= leftEnd && right <= rightEnd){
		if (arr[left] >= arr[right]){
			temp[index++] = arr[right++];
		} else {
			temp[index++] = arr[left++];
		}
	}

	while (left < leftEnd){
		temp[index++] = arr[left++];
	}
	while (right < rightEnd){
		temp[index++] = arr[right++];
	}

	for (int i = left; i < right; i++){
		arr[i] = temp[i];
	}
}

int main(){
	int arr[] = { 5, 1, 2, 4, 6, 9 };
	int aLength = sizeof(arr) / sizeof(arr[0]);

	for(int i = 0; i < aLength - 1; i++){
		std::cout << arr[i] << ", ";
	}
	std::cout << arr[aLength - 1] << std::endl;

	std::cout << "Calling MergeSort." << std::endl;

	mergeSort(arr);

	for(int i = 0; i < aLength - 1; i++){
		std::cout << arr[i] << ", ";
	}
	std::cout << arr[aLength - 1] << std::endl;

}


