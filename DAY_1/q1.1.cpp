/* 
	Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
	prove that at least one duplicate number must exist. Assume that there is only one duplicate number, 
	find the duplicate one.
*/
#include<bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> arr)
{
	if( arr.size() > 1)
	{
		int slow = arr[0];
		int fast = arr[0];

		do
		{
			slow = arr[slow];
			fast = arr[arr[fast]];
		} while(slow != fast);

		fast = arr[0];
		while(fast != slow)
		{
			fast = arr[fast];
			slow = arr[slow];
		}
		return slow;
	}
	return -999;
}

int main() 
{ 
      
    vector<int> num = { 1, 2, 3, 4, 5, 2, 6}; 
    int result = findDuplicate(num);
    cout<<"Duplicate : ";
    result != -999 ? cout<<result : cout<<"No duplicates!";
} 