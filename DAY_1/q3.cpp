/* Given an unsorted array of size n. Array elements are in the range from 1 to n. 
	One number from set {1, 2, …n} is missing and one number occurs twice in the array. 
	Find these two numbers.
*/

#include<bits/stdc++.h>
using namespace std;
void printArray(int arr[], int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

/* 
	APPROACH 1(Modifiying input array)
	N = size+1 as n is included.(otherwise (n%n -1) = -1, which does not exist)
	Time : O(n)
	Space: O(1)
*/
void printAns(int nums[], int size)
{
	int N = size+1;
	for(int i=0;i < size; i++)
        {
            nums[(nums[i] % N) -1] = nums[(nums[i] % N) -1] + N;
            printArray(nums, size);
        }
        
        for(int i=0;i<size;i++)
        { 
        	if( nums[i] < N+1)
             {
             	cout<<"Missing no : "<<i+1<<endl;
             }   
             if( nums[i] > 2*N)
             	cout<<"Repeating no : "<<i+1<<endl; 
        }
}

/*
	APPROACH 2 (USING BIT MANIPULATION) NOTE: array is not modified here

		We know that a^b^a = b. Using this logic the algo is defined!
		Time : O(n)
		Space: O(1)
*/
void getTwoElements(int arr[], int n, int *repeating, int *missing)
{
	int x = 0;
	int y = 0;
	int xor1 = 0;

	/* Get the xor of all array elements */
    for (int i =0; i < n; i++) 
        xor1 = xor1 ^ arr[i]; 
  
    /* XOR the previous result with numbers  
    from 1 to n*/
    for (int i = 1; i <= n; i++) 
        xor1 = xor1 ^ i; 

	/* Get the rightmost set bit in set_bit_no */
	int set_bit_no = xor1 & ~(xor1 -1);

	for(int i=0; i<n; i++)
		if( arr[i] & set_bit_no)
			x = x ^ arr[i];
		else
			y = y ^ arr[i];

	for(int i =1; i<=n; i++)
		if(i & set_bit_no)
			x = x ^ i;
		else
			y = y ^ i;

	for(int i=0; i< n; i++)
	{
		if(x == arr[i])
		{
			*repeating = x;
			*missing = y;
			return;
		}
	}

	*missing = x;
	*repeating = y;

}

/*
	APPROACH 3 (Two variables - Two equations)
		Note: this approach can lead to arithmetic overflow
		Time : O(n)
		Space: O(1)
*/
void getSolution(int arr[], int n)
{
	long long SumOfN = (n * (n + 1))/2;
	long long SumOfSquares = (n*(n+1)*(2*n + 1))/6;
	long long arraySum = 0;
	long long arraySumSquare = 0;

	for(int i=0; i< n;i++)
	{
		arraySum += arr[i];
		arraySumSquare += arr[i]*arr[i];
	}

	long long x;	//REPEATING
	long long y;	//MISSING

	// x - y = arraySum - SumOfN
	long long a = arraySum -  SumOfN;

	// x*x - y*y = arraySumSquare - SumOfSquares
	long long b = arraySumSquare - SumOfSquares;

	x = a/2 + b/(2*a);
	y = x - a;

	cout<<"Repeating: "<<x<<endl;
    cout<<"Missing: "<<y<<endl;

}


int main() 
{ 
    int arr[] = { 1, 2, 3, 3, 5, 6, 7 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 

//APPROACH 1
    // printAns(arr, n); 
    // cout<<endl;

//APPROACH 2
    // int *repeating = (int*)malloc(sizeof(int));
    // int *missing = (int*)malloc(sizeof(int));
    // getTwoElements(arr, n, repeating, missing);
    // cout<<"Repeating : "<<*repeating<<endl;
    // cout<<"Missing : "<<*missing<<endl;

//APPROACH 3
    getSolution(arr, n);
} 