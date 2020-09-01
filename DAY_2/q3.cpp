/* 
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation 
of numbers.If such arrangement is not possible, it must rearrange it as the lowest possible order 
(ie, sorted in ascending order).  
The replacement must be in-place and use only constant extra memory.
*/
#include<bits/stdc++.h>
using namespace std;

void swap(char *a, char *b)
{
	if(*a == *b)
		 return;

	char temp = *a;
	*a = *b;
	*b = temp;
}

void rev(string& s, int l, int r)
{
	while(l < r)
		swap(&s[l++], &s[r--]);
}

//without using stl
//Time: O(n) Space: O(1)
void nextPermutation(string& s)
{
	int i = s.length()-2;
	while(i>=0 && s[i] >= s[i+1])
		i--;

	if(i >= 0)
	{
		int j = s.length()-1;
		while(j >= 0 && s[j] <= s[i])
			j--;

		swap(&s[i], &s[j]);
	}
	rev(s, i+1, s.length() -1);
}

//using stl for an integer array
void nextPermutation_2(vector<int>& s)
{
	int i = s.size()-2;
	while(i>=0 && s[i] >= s[i+1])
		i--;

	if(i >= 0)
	{
		int j = s.size()-1;
		while(j >= 0 && s[j] <= s[i])
			j--;

		swap(s[i], s[j]);
	}
	reverse(s.begin() + i + 1, s.end());
}

int main()
{
	string s = "54321";
	nextPermutation(s);
	cout<<"Next permutation(string): "<<s;

	vector<int> arr = {1,4,3,2};
	nextPermutation_2(arr);

	cout<<"\n\nNext permutation(int array): ";
	for(int i=0; i < arr.size(); i++)
		cout<<arr[i]<<" ";
}