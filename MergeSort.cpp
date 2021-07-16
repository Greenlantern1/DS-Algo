// MergeSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*This Program is the implementation of MergeSort on Arrays*/

#include <iostream>
using namespace std;
void Merge(int arr[],int s , int m ,int e)
{
	
	int temp[100];
	int i = s;
	int j = m + 1;
	int k = 0;
	while (i <= m && j <= e)
	{
		if (arr[i] <= arr[j])
		{
			temp[k] = arr[i];
			i++;
			k++;
		}
		else if (arr[i] > arr[j])
		{
			temp[k] = arr[j];
			j++;
			k++;
		}
	}
	if (i < m)
	{
		while (i <= m)
		{
			temp[k] = arr[i];
			i++;
			k++;
		}
	}
	if (j < e)
	{
		while (j <= e)
		{
			temp[k] = arr[i];
			i++;
			k++;
		}
	}
	//Copying into the original array;
	for (int d = 0;d < e + 1;d++)
	{
		arr[d] = temp[d];
	}

}
void MergeSort(int arr[],int s,int e)
{
	if (s<e)
	{
		int m = (s+e)/ 2;
		MergeSort(arr, s, m);
		MergeSort(arr, m + 1, e);
		Merge(arr, s, m, e);
	}
}

int main()
{
	int n;
	cout << "Enter the size of the array" << endl;
	cin >> n;
	int* A = new int[n];
	for (int i = 0;i < n;i++)
	{
		cin >> A[i];
	}
	MergeSort(A, 0, n - 1);
	//Merging is complete
	cout << "Sorted Array:" << endl;
	for (int i = 0;i < n;i++)
	{
		cout << A[i] << endl;
	}
}



