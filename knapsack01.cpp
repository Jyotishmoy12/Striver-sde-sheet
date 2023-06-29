
#include<bits/stdc++.h>
int f(int ind,int w, vector<int>&wt, vector<int>&val, vector<vector<int>>&dp){
	if(ind==0){
		if(wt[0]<=w) return val[0];
		else return 0;
	}
	if(dp[ind][w]!=-1) return dp[ind][w];
	int notsteal=0+f(ind-1, w, wt, val, dp);
	int steal=INT_MIN;
	if(wt[ind]<=w){
		steal=val[ind]+f(ind-1, w-wt[ind], wt, val, dp);

	}
	return dp[ind][w]=max(steal, notsteal);
}


int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<vector<int>>dp(n, vector<int>(w+1, -1));
	return f(n-1, w, weights, values, dp);

}
