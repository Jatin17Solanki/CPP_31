/* 
	We are given two sorted array. 
We need to merge these two arrays such that the initial numbers (after complete sorting) 
are in the first array and the remaining numbers are in the second array. 
Extra space allowed is O(1).

 Time Complexity: 
		The worst case time complexity of code/algorithm is O(m*n). 
	The worst case occurs when all elements of ar1[] are greater than all elements of ar2[].

 APPROACH:
		The idea is to begin from last element of ar2[] and search it in ar1[]. 
	If there is a greater element in ar1[], then we move last element of ar1[] to ar2[]. 
	To keep ar1[] and ar2[] sorted, we need to place last element of ar2[] at correct place in ar1[]. 
	We can use Insertion Sort type of insertion for this
*/
#include<bits/stdc++.h>
using namespace std;


//APPROACH 1
void merge(int ar1[], int ar2[], int m, int n)
{
	for(int i= n-1; i >=0; i--)
	{
		 int j, last = ar1[m-1];
		 for(j = m-2; j>=0 && ar1[j] > ar2[i] ; j--)
		 	ar1[j+1] = ar1[j];

		 if(j != m-2 || last > ar2[i])
		 {
		 	ar1[j+1] = ar2[i];
		 	ar2[i] = last;
		 }
		 
	}
}

int nextGap(int n)
{
	if( n <=1 )
		return 0;

	return (n/2 + n%2);
}

//APPROACH 2
	//Time Complexity : O((n+m)log(n+m))
void mergeGap(int ar1[], int ar2[], int n, int m)
{
	int gap = n+m;
	int i,j;
	for(gap = nextGap(gap); gap > 0; gap = nextGap(gap))
	{
		for(i=0; i+gap < n; i++)
			if(ar1[i] > ar1[i+gap])
				swap(ar1[i], ar1[i+gap]);

		for(j = gap > n ? gap-n : 0; i<n && j<m; i++, j++)
			if(ar1[i] > ar2[j])
				swap(ar1[i], ar2[j]);
		if(j<m)
		{
			for(j=0; j+gap < m; j++)
				if(ar2[j] > ar2[j+gap])
					swap(ar2[j], ar2[j+gap]);
		}
	}
}

int main(void) 
{ 
    int ar1[] = {1, 5, 9, 10, 15, 20}; 
    int ar2[] = {2, 3, 8, 13}; 
    int n1 = sizeof(ar1)/sizeof(ar1[0]); 
    int n2 = sizeof(ar2)/sizeof(ar2[0]); 

 //APPROACH 1
    // merge(ar1, ar2, n1, n2); 
  
 //APPROACH 2
    mergeGap(ar1, ar2, n1, n2);

    cout << "After Merging \nFirst Array: "; 
    for (int i=0; i<n1; i++) 
        cout << ar1[i] << " "; 
    cout << "\nSecond Array: "; 
    for (int i=0; i<n2; i++) 
        cout << ar2[i] << " "; 
   return 0; 
} 