#include "stdafx.h"
#include <iostream>
using namespace std;

void print(int arr[], int len)
{
	for (int i = 0; i < len; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void bubble_sort(int arr[], int len)
{
	int temp;
	for (int i = 1; i < len; ++i) {
		for (int j = 0; j < len - i; ++j) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int partition(int arr[], int left, int right)
{
	int pivot = arr[left];
	while (left < right) {
		while (left < right && arr[right] >= pivot)
			right--;
		if (left < right)
			arr[left++] = arr[right];
		while (left < right && arr[left] <= pivot)
			left++;
		if (left < right)
			arr[right--] = arr[left];
	}
	arr[left] = pivot;
	return left;
}

void quick_sort(int arr[], int left, int right)
{
	if (left < right) {
		int mid = partition(arr, left, right);
		quick_sort(arr, left, mid - 1);
		quick_sort(arr, mid + 1, right);
	}
}

void insert_sort(int arr[], int len)
{
	int pos, cur;
	for (int i = 1; i < len; ++i) {
		pos = i - 1;
		cur = arr[i];
		while (pos >= 0 && arr[pos] > cur) {
			arr[pos + 1] = arr[pos];
			pos--;
		}
		arr[pos + 1] = cur;
	}
}

void shell_sort(int arr[], int len)
{
	int gap = len / 2, pos, cur;
	while (gap) {
		for (int i = gap; i < len; ++i) {
			pos = i - gap;
			cur = arr[i];
			while (pos >= 0 && arr[pos] > cur) {
				arr[pos + gap] = arr[pos];
				pos -= gap;
			}
			arr[pos + gap] = cur;
		}
		gap /= 2;
	}
}

void select_sort(int arr[], int len)
{
	int i, j, k, tmp;
	for (int i = 0; i < len-1; ++i) {
		k = i;
		for (int j = i+1; j < len; ++j) {
			if (arr[j] < arr[k]) {
				k = j;
			}
		}
		if (k != i) {
			tmp = arr[i];
			arr[i] = arr[k];
			arr[k] = tmp;
		}
	}
}

int main()
{
	const int len = 10;
	int arr[len];
/*	for (int i = 0; i < len; ++i) {
		cin >> arr[i];
	}
	quick_sort(arr, 0, 9);
	print(arr, len);

	for (int i = 0; i < len; ++i) {
		cin >> arr[i];
	}
	bubble_sort(arr, len);
	print(arr, len);

	for (int i = 0; i < len; ++i) {
		cin >> arr[i];
	}
	insert_sort(arr, len);
	print(arr, len);

	for (int i = 0; i < len; ++i) {
		cin >> arr[i];
	}
	shell_sort(arr, len);
	print(arr, len);*/

	for (int i = 0; i < len; ++i) {
		cin >> arr[i];
	}
	select_sort(arr, len);
	print(arr, len);
	return 0;
}
