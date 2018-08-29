#ifndef TEST_H
#define TEST_H

#include <cassert>
#include <ctime>

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class SortTestHelper{
public:

	static int *generateRandomArray(const int n, int rangeL, int rangeR);
	static void test(int);

	template <typename S>
	static bool isSorted(S arr[], int const n) {
		for (int i = 0; i < n - 1; i++) {
			if (arr[i + 1] < arr[i]) {
				return false;
			}
		}
		return true;
	}

	template <typename T, typename S>
	static void testSort(string sortName, void(*sort)(T arr[], const int i), S arr[], const int i) {
		clock_t startTime = clock();
		sort(arr, i);
		clock_t endTime = clock();
		assert(isSorted(arr, i));
		cout << sortName << ":" << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	}

	template <typename Z>
	static void printArray(Z arr[], const int n)
	{
		for (int i = 0; i < n; ++i)
			cout << arr[i] << " ";
		cout << endl;
	}

};

#endif // !TEST_H

