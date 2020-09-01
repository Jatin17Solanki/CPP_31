//Pascal Triangle
#include<bits/stdc++.h>
using namespace std;


//Time: O(R)  Space: O(1)
int nCr(int n, int r)
{
	if(r > n-r)
		r = n-r;

	int res = 1;
	for(int i=0; i< r; i++)
	{
		res *= n-i;
		res /= (i+1);
	}
	return res;
}

//Time: O(n^3)  Space: O(1)
void printPascal_1(int n)
{
	cout<<endl;
	for(int line = 0; line < n; line++)
	{
		for(int j =0; j <= line; j++)
			cout<<nCr(line, j)<<" ";
		cout<<endl;
	}
}

//Time: O(n^2)  Space: O(n^2)
void printPascal_2(int n)
{
	int arr[n][n];

	cout<<endl;
	for(int line = 0; line < n; line++)
	{
		for(int j = 0; j <= line; j++)
		{
			if(line == j || j == 0)
				arr[line][j] = 1;
			else
				arr[line][j] = arr[line-1][j-1] + arr[line-1][j];
			cout<<arr[line][j]<<" ";
		}
		cout<<endl;
	}
}

/*
Time: O(n^2)  Space: O(1)

C(line, i)   = line! / ( (line-i)! * i! )
C(line, i+1) = line! / ( (line - i - 1)! * (i+1)! )
We can derive following expression from above two expressions.
C(line, i+1) = C(line, i) * (line - i ) / (i+1)

So C(line, i+1) can be calculated from C(line, i) in O(1) time
*/
void printPascal_3(int n)
{
	cout<<endl;
	for(int line = 0; line < n; line++)
	{
		int c = 1;
		for(int i = 0; i <= line; i++)
		{
			cout<<c<<" ";
			c = c * (line - i) / (i+1);
		}
		cout<<endl;
	}
}

int main()
{
	printPascal_3(5);
}