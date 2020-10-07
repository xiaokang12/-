#include "iostream"
#include"ctime"
#include <cassert>
using namespace std;

namespace SortTestHelper{
	//����n��Ԫ�ص�������飬ÿ��Ԫ�ص������Χ

	//��ʾ����
	template <typename T>
	void printArr(T arr[], int n){
		for (int i = 0; i < n; i++){
			cout << arr[i] << " ";
			if (i % 10 == 0 && i >= 10)
				cout << endl;
		}
		cout << endl;
	}

	int* generateRandArray(int n, int rangL, int rangH){
		assert(rangL <= rangH);
		int *arr = new int[n];
		srand(time(NULL));
		for (int i = 0; i < n; i++){
			arr[i] = rand() % (rangH - rangL + 1) + rangL;
		}
		return arr;
	}

	//���������㷨�Ƿ���ȷ
	template <typename T>
	bool IsSort(T arr[], int n){
		for (int i = 0; i < n - 1; i++)
			if (arr[i]>arr[i + 1])
				return false;

		return true;
	}
	//���������㷨������
	template <typename T>
	void testSort(string sortname, void(*sort)(T[], int), T arr[], int n){
		clock_t startTime = clock();
		sort(arr, n);
		clock_t endtime = clock();

		cout << "�Ƿ�����ɹ�" << IsSort(arr, n) << endl;
		cout << sortname << ":" << double(endtime - startTime) / CLOCKS_PER_SEC << endl;
		return;
	}

	template <typename T>
	int* copyArr(T arr[],int n){
		int *arr2 = new int[n];
		for (int i = 0; i < n; i++)
			arr2[i] = arr[i];
		return arr2;
	}


}

