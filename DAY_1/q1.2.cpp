//Find the duplicate in an array of N integers(0 to n-1)
#include <bits/stdc++.h> 
using namespace std; 
  

/* APPROACH 1 :
	1. Traverse the given array from start to end.
	2. For every element in the array increment the arr[i]%n‘th element by n.
	3. Now traverse the array again and print all those indexes i for which arr[i]/n is greater than 1. 
			Which guarantees that the number n has been added to that index
	4. This approach works because all elements are in the range from 0 to n-1 and arr[i] would be greater 
			than n only if a value “i” has appeared more than once.


	
	Complexity Anlaysis:
		Time Complexity: O(n).
		Only two traversals are needed. So the time complexity is O(n).

		Auxiliary Space: O(1).
		No extra space is needed, so the space complexity is constant.
*/
int main() 
{ 
      
    int num[] = { 1, 7, 7, 4, 3, 2, 7, 8, 2, 3, 1}; 
    int size = sizeof(num) / sizeof(num[0]);  

    for(int i=0; i< size; i++)
    	num[num[i] % size] = num[num[i] % size] + size;

    cout<<"repeating elements are: "<<endl;
    for(int i=0; i< size;i++)
    {
    	if(num[i] >= 2*size)
    		cout<<i<<" ";
    }
    return 0; 
} 