// Sort an array of 0’s 1’s 2’s without using extra space or sorting algo
#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sort(int arr[], int n)
{
	int L = 0;
	int M = 0;
	int H = n-1;

	//unknown = arr[M ... H]
	while(M <= H)
	{
		switch(arr[M])
		{
			case 0 : swap(arr[M++], arr[L++]);
					 break;
			case 1 : M++;
					 break;
			case 2 : swap(arr[M], arr[H--]);
					 break;
		}
	}
}

int main() 
{ 
    int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    sort(arr, n); 
  
    cout << "array after segregation "; 
  
    printArray(arr, n); 
  
    return 0; 
} 