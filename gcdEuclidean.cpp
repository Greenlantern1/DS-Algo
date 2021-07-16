#include<iostream.h>
int gcd(int x, int y )
{
	if (y == 0)
	{
		return x;
	}
	else
	{
		gcd(y, x%y);    //Euclidean Algorithm to find the gcd of two numbers :)
	}
}

void main()
{   
	int x, y;
	cout << "Enter the numbers" << endl;
	cin >> x >> y;
	cout << "GCD" << gcd(x, y) << endl;

}
