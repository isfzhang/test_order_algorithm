#include <cstdlib>
#include <ctime>

#include "test.h"
#include "order.h"

/*
*  作者：吴与伦
*  链接：https ://juejin.im/post/5b7e353051882542db3bdc33
*  来源：掘金
*  著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

int *SortTestHelper::generateRandomArray(const int n, int rangeL, int rangeR) {
	int *arr = new int[n];
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
	}
	return arr;
}

void testSelectionSort(int n) {
	int* arr = SortTestHelper::generateRandomArray(n, 0, n);
	SortTestHelper::testSort("selectionSort", selectionSort<int>, arr, n);
	delete[] arr;
}

void testinsertionSort(int n) {
	int* arr = SortTestHelper::generateRandomArray(n, 0, n);
	SortTestHelper::testSort("insertionSort", insertionSort<int>, arr, n);
	delete[] arr;
}

void testinsertionSort_optimization(int n) {
	int* arr = SortTestHelper::generateRandomArray(n, 0, n);
	SortTestHelper::testSort("insertionSort_optimization", insertionSort_optimization<int>, arr, n);
	delete[] arr;
}

void testBubbleSort(int n) {
	int* arr = SortTestHelper::generateRandomArray(n, 0, n);
	SortTestHelper::testSort("BubbleSort", BubbleSort<int>, arr, n);
	delete[] arr;
}

void testmergeSort(int n) {
	int* arr = SortTestHelper::generateRandomArray(n, 0, n);
	SortTestHelper::testSort("mergeSort", mergeSort<int>, arr, n);
	delete[] arr;
}

void  SortTestHelper::test(int length) {
	testSelectionSort(length);
	testinsertionSort(length);
	testinsertionSort_optimization(length);
	testBubbleSort(length);
	testmergeSort(length);
}


