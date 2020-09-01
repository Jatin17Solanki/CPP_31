/* 
Q: Inversion Count for an array indicates – how far (or close) the array is from being sorted. 
If array is already sorted then inversion count is 0. If array is sorted in reverse order that 
inversion count is the maximum.
Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j

Link:  https://www.youtube.com/watch?time_continue=327&v=k9RQh21KrH8&feature=emb_logo

Algorithm:
The idea is similar to merge sort, divide the array into two equal or almost equal halves in each step until the base case is reached.
Create a function merge that counts the number of inversions when two halves of the array are merged, create two indices i and j, i is the index for first half and j is an index of the second half. if a[i] is greater than a[j], then there are (mid – i) inversions. because left and right subarrays are sorted, so all the remaining elements in left-subarray (a[i+1], a[i+2] … a[mid]) will be greater than a[j].
Create a recursive function to divide the array into halves and find the answer by summing the number of inversions is the first half, number of inversion in the second half and the number of inversions by merging the two.
The base case of recursion is when there is only one element in the given half.
Time: O(n logn)
Space: O(n)

*/
#include<bits/stdc++.h>
using namespace std;

int merge(int arr[], int l, int m, int r)
{
	int i, j, k, inv_count=0;
	int n1 = m+1-l;
	int n2 = r-m;

	int L[n1], R[n2];
	for(i=0; i<n1; i++)
		L[i] = arr[l+i];
	for(j=0; j<n2; j++)
		R[j] = arr[m+1+j];

	i=0;
	j=0;
	k=l;
	while(i < n1 && j < n2)
	{
		if(L[i] < R[j])
			arr[k++] = L[i++];
		else
		{
			arr[k++] = R[j++];
			//inv_count = start index of right - i
			inv_count += (m+1) - i;
		}
	}

	while(i < n1)
		arr[k++] = L[i++];
	while(j < n2)
		arr[k++] = R[j++];

	return inv_count;
}

int mergeSort(int arr[], int left, int right)
{
	int mid, inv_count = 0;

	if(left < right)
	{
		mid = (left+right)/2;

		inv_count += mergeSort(arr, left, mid);
		inv_count += mergeSort(arr, mid+1, right);

		inv_count += merge(arr, left, mid, right);
	}
	return inv_count;
}

void printArray(int A[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 

int main()
{
 	int arr[] = { 12, 11, 13, 5, 6, 7 }; 
    int arr_size = sizeof(arr) / sizeof(arr[0]); 
  
    int inv_count = mergeSort(arr, 0, arr_size - 1); 
  
    printf("\nSorted array is \n"); 
    printArray(arr, arr_size);
    cout<<"\nInversion count: "<<inv_count;
}