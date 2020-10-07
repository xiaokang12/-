// ����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "on2�����㷨.h"
#include"nlogn����.h"
using namespace std;

class Student{
public:
	string m_name;
	int m_score;
	Student();
	Student(string name, int score){
		this->m_score = score;
		this->m_name = name;
	}
	bool operator<(const Student &s2){
		return this->m_score < s2.m_score;
	}

	friend ostream& operator<<(ostream &os, const Student &s){
		os << "Student:" << s.m_name << " " << s.m_score << endl;
		return os;
	}
};


int main( )
{
	/*
	//ѡ������
	int n = 20;
	int *arr = SortTestHelper::generateRandArray(n, 0, 30);
	SortTestHelper::printArr(arr, n);
	cout << endl; cout << endl;
	selectSort(arr, n);
	SortTestHelper::printArr(arr, n);
	delete[] arr;

	//�ַ�������
	string arrs[5] = { "a","k","d","j","g" };
	selectSort(arrs, 5);
	SortTestHelper::printArr(arrs, 5);

	//�Զ�����������
	Student s[4] = { {"C",85}, {"A",90}, {"D",77}, {"B",91} };
	selectSort(s,4);
	for (int i = 0; i < 4; i++){
		cout << s[i];
	}


	//����ѡ�������㷨
	int *arr_t = SortTestHelper::generateRandArray(100000, 0, 5000);
	SortTestHelper::testSort("ѡ������", selectSort, arr_t, 100000);
	*/


	/*
	//��������
	int n = 5;
	int *arr_insert = SortTestHelper::generateRandArray(n, 0, 20);
	SortTestHelper::printArr(arr_insert, n);
	//insertSort(arr_insert, n);
	insertSortOpt(arr_insert, n);
	SortTestHelper::printArr(arr_insert, n);
	delete[] arr_insert;

	//�ַ�����������
   string arrs[5] = { "a", "k", "d", "j", "g" };
	insertSort(arrs, 5);
	SortTestHelper::printArr(arrs, 5);

	//�Զ�������
	Student s[4] = { { "C", 85 }, { "A", 90 }, { "D", 77 }, { "B", 91 } };
	insertSort(s, 4);
	for (int i = 0; i < 4; i++){
		cout << s[i];
	}
	*/


	//��������
    int n = 50000;
	int *arr_test = SortTestHelper::generateRandArray(n, 0, n);
	int *arr_test2 = SortTestHelper::copyArr(arr_test, n);
	int *arr_test3 = SortTestHelper::copyArr(arr_test, n);
	int *arr_test4 = SortTestHelper::copyArr(arr_test, n);
	int *arr_test5 = SortTestHelper::copyArr(arr_test, n);
	//SortTestHelper::testSort("ѡ������", selectSort, arr_test, n);
	SortTestHelper::testSort("��������", insertSortOpt, arr_test2, n);
	SortTestHelper::testSort("shell����", shellSort, arr_test3, n);
	SortTestHelper::testSort("�鲢����", MergeSort, arr_test4, n);
	SortTestHelper::testSort("�Ե����¹鲢����", MergeSortBU, arr_test5, n);
	//SortTestHelper::printArr(arr_test3, n);
	delete[] arr_test;
	delete[] arr_test2;
	delete[] arr_test3;
	delete[] arr_test4;

	//�鲢����
	n = 10;
	int *arr_merge = SortTestHelper::generateRandArray(n, 0, n);
	//insertSort(arr_merge, n);
	MergeSortBU(arr_merge, n);
	SortTestHelper::printArr(arr_merge, n);


	system("pause");
	return 0;
}
