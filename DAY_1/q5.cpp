/* 
 Using kadane's Algo :
	Write an efficient program to find the sum of contiguous subarray within a one-dimensional 
	 array of numbers which has the largest sum.

 Time Complexity: O(n)
 Space Complexity: O(1)
 
 LINK: https://www.youtube.com/watch?v=86CQq3pKSUw
*/

#include<bits/stdc++.h>
using namespace std;

int maxSubArraySum(int arr[], int n)
{
	int currentMax = arr[0];
	int globalMax = arr[0];

	for(int i = 1; i < n; i++)
	{
		currentMax = max(arr[i], arr[i]+currentMax);
		globalMax = max(currentMax, globalMax);
	}
	return globalMax;
}

int main() 
{ 
   int a[] =  {-2, -3, 4, -1, -2, 1, 5, -3}; 
   int n = sizeof(a)/sizeof(a[0]); 
   int max_sum = maxSubArraySum(a, n); 
   cout << "Maximum contiguous sum is " << max_sum; 
   return 0; 
} 