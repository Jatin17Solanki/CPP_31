//Given an integer n, write a function that returns count of trailing zeroes in n! in log n time

/* 
Approach:
	A trailing zero is always produced by prime factors 2 and 5.
We can easily observe that the number of 2s in prime factors is always more than or equal 
to the number of 5s. So if we count 5s in prime factors, we are done.	

Trailing 0s in n! = Count of 5s in prime factors of n!
                  = floor(n/5) + floor(n/25) + floor(n/125) + ....
*/
#include<bits/stdc++.h>
using namespace std;

int findTrailingZeros(int n)
{
	int factor = 5;
	int count = 0;
	while( factor <= n)
	{
		count += n/factor;
		factor *= 5;
	}
	return count;
}

int main()
{
	int n = 100; 
    cout << "Count of trailing 0s in " << 100 
         << "! is " << findTrailingZeros(n);
}