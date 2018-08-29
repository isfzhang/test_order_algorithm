#include <cstdlib>
#include <cstdio>

#include  "test.h"
#include  "order.h"

#define ARR_SIZE 10000

int main()
{
	SortTestHelper::test(ARR_SIZE);

	//int* arr = SortTestHelper::generateRandomArray(ARR_SIZE, 0, ARR_SIZE);
	//SortTestHelper::printArray(arr, ARR_SIZE);
	//BubbleSort(arr, ARR_SIZE);
	//SortTestHelper::printArray(arr, ARR_SIZE);
	//delete[] arr;

	printf("OK \n");
	getchar();

	return 0;
}