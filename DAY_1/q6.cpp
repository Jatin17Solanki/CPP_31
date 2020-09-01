/*
	Given a set of time intervals in any order, merge all overlapping intervals into one and output the result 
	which should have only mutually exclusive intervals. Let the intervals be represented as pairs of integers 
	for simplicity.
	For example, let the given set of intervals be {{1,3}, {2,4}, {5,7}, {6,8} }. 
	The intervals {1,3} and {2,4} overlap with each other, so they should be merged and become {1, 4}. 
	Similarly {5, 7} and {6, 8} should be merged and become {5, 8}

*/
#include<bits/stdc++.h>
using namespace std;
struct Interval
{
	int start;
	int end;
};

bool compareInterval(Interval i1, Interval i2)
{
	return (i1.start < i2.start) ;
}


/* 
APPROACH 1
	Time: O(nlogn)
	Space: O(n)
*/
void mergeIntervals(Interval arr[], int n)
{
	if(n <= 0)
		return;

	sort(arr, arr+n, compareInterval);

	stack<Interval> s;

	s.push(arr[0]);

	for(int i=1;i<n;i++)
	{
		Interval top = s.top();

		if( top.end < arr[i].start)
			s.push(arr[i]);
		else if(top.end < arr[i].end)
		{
			top.end = arr[i].end;
			s.pop();
			s.push(top);
		}
	}

	cout<<"Merged intervals are: \n";
	while(s.empty() == false)
	{
		Interval t = s.top();
		cout<<"["<<t.start<<","<<t.end<<"] ";
		s.pop();
	}
	return;
}


/*
	APPROACH 2.1
		Time: O(nlogn)
		Space: O(1)
*/
void merge(Interval arr[], int n)
{
	if(n <= 0)
		return;

	sort(arr, arr+n, compareInterval);

	Interval prev = arr[0];

	for(int i = 1; i < n; i++)
	{
		if(prev.end < arr[i].start)
		{
			cout<<"["<<prev.start<<","<<prev.end<<"] ";
			prev = arr[i];
		}
		else if(prev.end < arr[i].end)
			prev.end = arr[i].end;
	}
	cout<<"["<<prev.start<<","<<prev.end<<"] ";
}

/*
	APPROACH 2.2
		Time: O(nlogn)
		Space: O(1)
*/
void merge2(Interval arr[], int n)
{
	// Sort Intervals in increasing order of 
    // start time 
    sort(arr, arr+n, compareInterval);  
  
    int index = 0; // Stores index of last element  
    // in output array (modified arr[])  
  
    // Traverse all input Intervals  
    for (int i=1; i<n; i++)  
    {  
        // If this is not first Interval and overlaps  
        // with the previous one  
        if (arr[index].end >=  arr[i].start)  
        {  
               // Merge previous and current Intervals  
            arr[index].end = max(arr[index].end, arr[i].end);  
            arr[index].start = min(arr[index].start, arr[i].start);  
        }  
        else { 
        	index++;
            arr[index] = arr[i];  
        }     
    }  
  
    // Now arr[0..index-1] stores the merged Intervals  
    cout << "\n The Merged Intervals are: ";  
    for (int i = 0; i <= index; i++)  
        cout << "[" << arr[i].start << ", " << arr[i].end << "] ";
}

int main()
{
	Interval arr[] =  { {6,8}, {1,9}, {2,4}, {4,7}, {12,14} ,{14,16}, {18,19}}; 
	int size = sizeof(arr)/sizeof(arr[0]);
//APPROACH 1
	// mergeIntervals(arr, size);

//APPROACH 2.1
	// merge(arr, size);

//APPROACH 2.2
	merge2(arr, size);
}