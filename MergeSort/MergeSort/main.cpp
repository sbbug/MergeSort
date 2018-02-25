/*
C++实现归并排序
*/
#include<iostream>
using namespace std;

/*
归并方法定义
用来归并两个有序数组成为一个有序数组

数组第一部分arr[l...m]
数组第二部分arr[m+l...r]
*/
void merge(int arr[], int l, int m, int r){

	int i, j, k;
	//数组第一部分长度
	int n1 = m - l + 1;
	//数组第二部分长度
	int n2 = r - m;
	//创建两个临时数组,内存动态分配
	int *Left = new int[n1];
	int *Right = new int[n2];

	//将arr数组数据拷贝到临时数组里
	for (i = 0; i < n1; i++)
		Left[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		Right[j] = arr[m + 1 + j];

	//然后在将两个数组Left,Right合并到arr里
	//变量初始化
	i = 0;
	j = 0;
	k = l;

	while (i < n1 && j < n2){
		//将left,right中较小的先归并到一个数组里
		if (Left[i] <= Right[j])
			arr[k] = Left[i++];
		else
			arr[k] = Right[j++];

		k++;
    }
	//如果Left数组里有剩余的元素可以直接copy进去
	while (i < n1)
		arr[k++] = Left[i++];
	//如果Right数组里有剩余元素直接copy进去
	while (j < n2)
		arr[k++] = Right[j++];
	
	delete Left;
	delete Right;

}
/*
下标l是数组arr里需要排序元素的左下标
下标r识数组arr里需要排序元素的右下标
*/
void mergeSort(int arr[], int l, int r){
	
	    if (l >= r) return;

		//计算划分中点
		int m = (r + l) / 2;
	
		//开始归并排序
		mergeSort(arr,l,m);
		mergeSort(arr, m + 1, r);
      	merge(arr,l,m,r);

	
}
//定义打印方法
void printArray(int A[], int size){
	int i;
	for (i = 0; i < size; i++)
		cout << A[i] << '\t';
	cout << endl;
}
int main(){
	//测试数据
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int arr_size = sizeof(arr)/sizeof(arr[0]);

	cout << "原数组\n";
	printArray(arr,arr_size);

	mergeSort(arr,0,arr_size-1);

	cout << "排序后的数组\n";
	printArray(arr,arr_size);

	getchar();
	system("pasue");
	return 0;
}