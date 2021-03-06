// lower_upper_bound_test.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

vector<int>::iterator lowerBound(vector<int> &vec, int num)
{
	if (vec.empty())
		return vec.end();
	vector<int>::iterator left = vec.begin(), right = vec.end();
	vector<int>::iterator mid = left + (right - left) / 2;
	while (left < right) {
		if (*mid < num) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
		mid = left + (right - left) / 2;
	}
	return left;
}

vector<int>::iterator upperBound(vector<int> &vec, int num)
{
	if (vec.empty())
		return vec.end();
	vector<int>::iterator left = vec.begin(), right = vec.end();
	vector<int>::iterator mid = left + (right - left) / 2;
	while (left < right) {
		if (*mid <= num) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
		mid = left + (right - left) / 2;
	}
	return left;
}

int main()
{
	vector<int> vec = { 1,2,3,4,4,4,5,6,7 };
	vector<int>::iterator it = lowerBound(vec, 4);
	cout << it - vec.begin() << endl;

	it = upperBound(vec, 8);
	cout << it - vec.begin() << endl;

	system("PAUSE");
    return 0;
}

