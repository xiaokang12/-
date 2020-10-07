#pragma once


#include "on2�����㷨.h"

//��arr[l...mid]��arr[mid+1...r]�����ֽ��й鲢
template <typename T>
void __merge(T arr[], int l, int mid, int r){
	int   *aux=new int[r-l+1];

	for (int i = l; i <= r; i++){
		aux[i - l] = arr[i];
	}

	int i = l, j = mid + 1;
	for (int k = l; k <= r; k++)
	{
		if (i > mid){
			arr[k]= aux[j - l];
			j++;
		}
		else if (j > r){
			arr[k] = aux[i - l];
			i++;
		}
		else if (aux[i - l]<aux[j-l]){
			arr[k] = aux[i - l];
			i++;
		}
		else {
			arr[k] = aux[j - l];
			j++;
		}
	}
	delete[] aux;
}

//�ݹ�ʹ�ù鲢���򣬶�arr[l,...r]�ķ�Χ��������
template <typename T>
void __mergeSort(T arr[], int l, int r){
	if (l >=r)
		return;


	int mid = (l + r) / 2;
	__mergeSort(arr, l, mid);
	__mergeSort(arr, mid + 1, r);
	if (arr[mid]>arr[mid+1])
	   __merge(arr, l, mid, r);
}

template <typename T>
void MergeSort(T *arr, int n){
	__mergeSort(arr, 0, n - 1);
}

//�Ե����ϵĹ鲢����***************************************//
template <typename T>
void MergeSortBU(T *arr, int n){
	for (int sz = 1; sz < n; sz += sz){  //�鲢����ĸ���
		for(int i= 0; i +sz< n; i += sz + sz ){  //�鲢����ʼλ��
			//��arr[i...i+sz-1]��arr[i+sz...i+2*sz-1]
			__merge(arr, i, i + sz - 1, min(i + 2 * sz - 1, n - 1));
		}
	}
}