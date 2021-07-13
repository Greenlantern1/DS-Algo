
/*Array ADT*/
#include <iostream>
using namespace std;

struct Array
{
	int *A;
	int size;
	int length;
	void Append(int x)
	{
		this->A[this->length] = x;
		this->length++;
	}
	void DisplayElements()
	{
		cout << "The Elements in the array " << endl;
		for (int j = 0; j < (this->length);j++)
		{
			cout << this->A[j] << endl;
		}
	}
	void Insert(int index, int x)
	{
		for (int i = this->length; i > index; i--)
		{
			this->A[i] = this->A[i - 1];
		}
		this->A[index] = x;
		cout << "Inserted successfully" << endl;
	}
	
	
};

/*Array append(Array a,int x) {
	a.A[a.length] = x;
	a.length++;
	return a;
}*/
//Recursive way to find the sum
int Rsum(int a[], int n)
{
	int sum = 0;
    if(n < 0)
	{
		return 0;
	}
	sum = Rsum(a, n - 1) + a[n];
	return sum;
}
//Finding the sum
int Sum(Array a)
{
	int S = 0;
	for (int i = 0;i < a.length;i++)
	{
		S += a.A[i];
	}
	return S;
}
//Returns The  max
int Max(Array a)
{
	int max = a.A[0];
	for (int i = 1;i < a.length;i++)
	{
		if (a.A[i] > max)
		{
			max = a.A[i];
		}
	}
	return max;
}
void swap(int *a,int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
void Append(Array a)
{
	int x;
	cin >> x;
	a.Append(x);
}
void Insert(Array a)
{
	int index, e;
	cout << "enter the Index and the element to be inserted" << endl;
	cin >> index >> e;
	a.Insert(index, e);
}
//Linear Search()
void LinearSearch(Array a)
{
	int x;
	cout << "Enter the element to be searched" << endl;
	cin >> x;
	for (int i = 0;i < a.length;i++)
	{
		if (a.A[i] == x)
		{
			cout << "Array found at " << i + 1 << endl;
			swap(&a.A[i], &a.A[i - 1]);
			/* In C we dont pass the array by address by default but in C++ array are alwyas passed as addresses*/
		}
		
		//Transposition is also implemented here if you kind of pay a little attention you will know;

	}
	cout << "Not found " << endl;
	
} 
//Binary Search() only applicable to 
//the sorted array so we need to check if the list is sorted or not
int BinarySearch(Array a)
{
	int x;
	cout << "Enter the Element to be found" << endl;
	cin >> x;
	int s = 0;
	int e = (a.length-1);
	int m;
	while (s<=e)
	{
		m = s + (e - s) / 2;
		if (a.A[m] == x)
		{
			 cout << "Found at " << m + 1 << endl;
			 return m + 1;
		}
		else if (x > a.A[m])
		{
			s = m + 1;
		}
		else if (x < a.A[m])
		{
			e = m - 1;
		}
		cout << "Not Found" << endl;
	}
} // Implemented using the recursive way:)
//Recursiv Implementation
int BinaryRecursiveSearch(int s, int e, Array a , int x)
{
	if (s > e)
	{
		return -1;
	}
	else {
		int m = s + (e - s) / 2;
		if (a.A[m] == x)
		{
			return m+1;
		}
		else if (a.A[m] > x)
		{
			BinaryRecursiveSearch(s, m - 1, a, x);
		}
		else if (a.A[m]<x)
		{
			BinaryRecursiveSearch(m+1,e, a, x);
		}
	}
}
//Call to the binaryRevursion:(
void Search(Array a)
{
	int x;
	cout << "Enter the element to be inserted " << endl;
	cin >> x;
	if (BinaryRecursiveSearch(0, (a.length - 1), a, x) == -1)
	{
		cout << "Element Not Found" << endl;
	}
	else {
		cout << "Found at " << BinaryRecursiveSearch(0, (a.length - 1), a, x) << endl;
	}
}
void Reverse(int a[],int n)
{
	
	int *aux = new int[n];
	
	for (int i = 0;i < n;i++)
	{
		aux[i] = a[i];
	}
	for (int j = n - 1;j >= 0;j--)
	{
		a[n-j-1] = aux[j];
	}
}
//function to check if the array is sorted in an ascending order
void isSortedAsending(Array a)
{
	int i = a.length - 1;
	while (i--)
	{
		if (a.A[i] > a.A[i + 1])
		{
			cout << "Not sorted" << endl;
			return;
	  }
		
    }
	cout << "Sorted" << endl;
}

int main()
{  
	//Initialization and stuff:)
	int n;                 
	struct Array arr;
	cout << "Enter the size of the Array" << endl;
	cin >> arr.size;
	arr.A = new int[arr.size];

    //arr.A=(int*)malloc(arr.size*sizeof(int)) in C

	cout << "Enter the no. of elements to be entered" << endl;
	cin >> n;
	arr.length = n;
	cout << "Enter the" << n << "elements now" << endl;
	for (int i = 0;i < n;i++)
	{
		cin>>arr.A[i];
	}
	
	//DisplayElements(arr);
	arr.DisplayElements();
	int option;
	do
	{
		cout << " You can Perform these things" << endl;
		cout << "1. Appending " << endl;
		cout << "2. Inserting" << endl;
		cout << "3. Deleting" << endl;
		cout << "4. Search" << endl;
		cout << "5. Display Elements" << endl;
		cout << "6. Find the Max" << endl;
		cout << "7. Find the Sum" << endl;
		cout << "8. Reverse the array" << endl;
		cout << "9.Check if the array is sorted" << endl;
		cout << "0. End the program" << endl;
		cout << "Press respective serial Number :" << endl;
		cin >> option;
		switch (option)
		{
		case 1: Append(arr);
			    break;
		case 2: Insert(arr);
			    break;
		case 4: LinearSearch(arr);
				break;	
		case 5: arr.DisplayElements();
			    break;
		case 6: cout << "Max element in the array:" << Max(arr) << endl;
			    break;
		case 7:cout << "Sum of all elements " << Rsum(arr.A,arr.length-1) << endl;
			    break;
		case 8: Reverse(arr.A,arr.length);
			    break;
		case 9: isSortedAsending(arr);
			    break;
		case 0: break;
		default:
			cout << "Invalid Input TRY AGAIN" << endl;

		}

	} while (option);
	
	delete(arr.A);

	return 0;
}


