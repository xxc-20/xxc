#include <iostream>

//交换两个数
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//快速排序
void quickSort(int *arr, int left, int right) {
	if (left >= right) return;
	int i = left, j = right;
	int key = left; //选择第一个元素作为基准
	while (left < right) {
		while (left < right && arr[right] >=arr[key]) right--;
		while (left < right && arr[left] <= arr[key]) left++;
		swap(&arr[left], &arr[right]); //交换两个元素
	}
	int pos = left;
	swap(&arr[key], &arr[pos]); //将基准元素放到正确的位置
	quickSort(arr, i, pos - 1);
	quickSort(arr, pos + 1, j);
}

int main() {
	int arr[] = { 5, 2, 4, 6, 1, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	std::cout << n << std::endl;
	quickSort(arr, 0, n - 1);
	for (int num : arr) {
		std::cout << num << " ";
	}
}