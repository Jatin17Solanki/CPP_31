/* 
Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction 
(i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
Note that you cannot sell a stock before you buy one.

Time: O(n)
Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;

int mProfit(vector<int> prices, int *buy, int* sell)
{
	int minPrice = INT_MAX;	//buying price
	int maxProfit = 0;
	int B = -1;		//Buy index
	int S = -1;		//Sell index
	for(int i =0; i < prices.size(); i++)
	{
		if( prices[i] < minPrice)
		{
			minPrice = prices[i];
			B = i;
		}
		else if( prices[i] - minPrice > maxProfit)
		{
			maxProfit = prices[i] - minPrice;
			S = i;
		}
	}
	*buy= B;
	*sell = S;
	return maxProfit;

}

int main()
{
	vector<int> prices = { 9,3,7,5,8,6,1,2 };
	int B, S;
	int profit = mProfit(prices, &B, &S);
	cout<<"Maximum profit: "<<profit<<endl;
	if(profit > 0)
		cout<<"Buy on Day: "<<B<<"\tSell on Day: "<<S;
}