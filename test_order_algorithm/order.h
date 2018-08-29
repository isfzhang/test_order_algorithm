#ifndef ORDER_H
#define ORDER_H

#include <cstdbool>

#include <algorithm>

template <typename T>
void selectionSort(T arr[], int n) {
	int min_index = 0;
	//T value;
	for (int order = 0; order < n; ++order) {
		min_index = order;
		for (int unorder = order + 1; unorder < n; ++unorder) {
			if (arr[unorder] < arr[min_index])
				min_index = unorder;
		}
		//value = arr[order];
		//arr[order] = arr[min_index];
		//arr[min_index] = value;
		std::swap(arr[order], arr[min_index]);
	}
}

template <class T>
void insertionSort(T arr[], int n) {
	for (int i = 1; i < n; ++i) {
		for (int j = i; j > 0; --j) {
			if (arr[j - 1] > arr[j])
				std::swap(arr[j - 1], arr[j]);
			else
				break;
		}
	}
}

template <class T>
void insertionSort_optimization(T arr[], int n) {
	T value;
	int j;
	for (int i = 1; i < n; ++i) {
		value = arr[i];
		for (j = i; j > 0; --j) {
			if (value < arr[j - 1])
				arr[j] = arr[j - 1];
			else
				break;
		}
		arr[j] = value;
	}
}

template <typename T>
void BubbleSort(T arr[], int n) {
	bool finish = true;
	
	for (int i = n; i > 1; --i) {
		finish = true;
		for (int j = 0; j < i - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
				finish = false;
			}
		}

		if (finish)
			break;
	}
}

template <typename T>
void __merge(T arr[], int l, int mid, int r) {
	// 创建一个临时空间  栈上开辟报错 堆上开辟记得释放
	T* temArr = new T[r - l + 1];
	for (int i = l; i <= r; i++) {
		temArr[i - l] = arr[i];
	}

	int i = l, j = mid + 1;
	for (int k = l; k <= r; k++) {

		if (i>mid) {
			arr[k] = temArr[j - l];
			j++;
		}
		else if (j>r) {
			arr[k] = temArr[i - l];
			i++;
		}
		else if (temArr[i - l] < temArr[j - l]) {
			arr[k] = temArr[i - l];
			i++;
		}
		else {
			arr[k] = temArr[j - l];
			j++;
		}
	}

	delete[] temArr;
}

template <typename T>
void __mergeSort(T arr[], int left, int right) {
	//数组假定左闭右闭
	if (left >= right)
		return;

	int mid = (left + right) / 2;

	__mergeSort(arr, left, mid);
	__mergeSort(arr, mid + 1, right);
	__merge(arr, left, mid, right);
}

template <typename T>
void mergeSort(T arr[], int n) {
	__mergeSort(arr, 0, n - 1);
}

#endif // !ORDER_H

