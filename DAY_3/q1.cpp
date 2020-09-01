#include<bits/stdc++.h>
using namespace std;
int titleToNumber(string s)
{
	int n = s.length();
	int result = 0;
	int power = 1;
	for(int i = n-1; i >= 0 ; i--)
	{
		result += (s[i] - 'A' + 1) * power;
		power = power*26;
	}
	return result;
}
int main()
{
	string str = "AA";
	cout<<titleToNumber(str);
}