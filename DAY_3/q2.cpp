//program for power function
#include<bits/stdc++.h>
using namespace std;


//Time: O(n)
int recursivePower1(int x, int n)
{
	if( n == 0)
		return 1;

	if(n % 2 == 0)
		return recursivePower1(x, n/2) * recursivePower1(x, n/2);
	else
		return x * recursivePower1(x, n/2) * recursivePower1(x, n/2);
}

//Time: O(log n)
int recursivePower2(int x, int n)
{
	int temp;
	if( n == 0)
		return 1;

	temp = recursivePower2(x, n/2);
	if(n % 2 == 0)
		return temp * temp;
	else
		return x * temp * temp;
}

//Handles negative values of n also
float recursivePower3(float x, int n)
{
	float temp;
	if( n == 0)
		return 1;

	temp = recursivePower3(x, n/2);
	if(n % 2 == 0)
		return temp * temp;
	else
	{
		if(n > 0)
			return x * temp * temp;
		else
			return (temp * temp) / x;
	}
}

//Time: O(log n)
int iterativePower(int x, int n)
{
	int res = 1;
	while(n > 0)
	{
		//if n is odd
		if(n & 1)
			res = res * x;

		n = n >> 1; // n = n/2
		x = x * x;
	}
	return res;
}

int main()
{
	cout<<recursivePower1(3,4)<<endl;
	cout<<recursivePower2(3,4)<<endl;
	cout<<recursivePower3(3,-4)<<endl;
	cout<<iterativePower(3, 4)<<endl;
}