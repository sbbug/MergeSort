/*
C++ʵ�ֹ鲢����
*/
#include<iostream>
using namespace std;

/*
�鲢��������
�����鲢�������������Ϊһ����������

�����һ����arr[l...m]
����ڶ�����arr[m+l...r]
*/
void merge(int arr[], int l, int m, int r){

	int i, j, k;
	//�����һ���ֳ���
	int n1 = m - l + 1;
	//����ڶ����ֳ���
	int n2 = r - m;
	//����������ʱ����,�ڴ涯̬����
	int *Left = new int[n1];
	int *Right = new int[n2];

	//��arr�������ݿ�������ʱ������
	for (i = 0; i < n1; i++)
		Left[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		Right[j] = arr[m + 1 + j];

	//Ȼ���ڽ���������Left,Right�ϲ���arr��
	//������ʼ��
	i = 0;
	j = 0;
	k = l;

	while (i < n1 && j < n2){
		//��left,right�н�С���ȹ鲢��һ��������
		if (Left[i] <= Right[j])
			arr[k] = Left[i++];
		else
			arr[k] = Right[j++];

		k++;
    }
	//���Left��������ʣ���Ԫ�ؿ���ֱ��copy��ȥ
	while (i < n1)
		arr[k++] = Left[i++];
	//���Right��������ʣ��Ԫ��ֱ��copy��ȥ
	while (j < n2)
		arr[k++] = Right[j++];
	
	delete Left;
	delete Right;

}
/*
�±�l������arr����Ҫ����Ԫ�ص����±�
�±�rʶ����arr����Ҫ����Ԫ�ص����±�
*/
void mergeSort(int arr[], int l, int r){
	
	    if (l >= r) return;

		//���㻮���е�
		int m = (r + l) / 2;
	
		//��ʼ�鲢����
		mergeSort(arr,l,m);
		mergeSort(arr, m + 1, r);
      	merge(arr,l,m,r);

	
}
//�����ӡ����
void printArray(int A[], int size){
	int i;
	for (i = 0; i < size; i++)
		cout << A[i] << '\t';
	cout << endl;
}
int main(){
	//��������
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int arr_size = sizeof(arr)/sizeof(arr[0]);

	cout << "ԭ����\n";
	printArray(arr,arr_size);

	mergeSort(arr,0,arr_size-1);

	cout << "����������\n";
	printArray(arr,arr_size);

	getchar();
	system("pasue");
	return 0;
}