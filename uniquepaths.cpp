#include <bits/stdc++.h>
int f(int i, int j,vector<vector<int>>&dp){
	 if(i==0 || j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int down=f(i-1, j, dp);
        int right=f(i, j-1, dp);
        return dp[i][j]=down+right;
} 
int uniquePaths(int m, int n) {
	// Write your code here.
	 vector<vector<int>>dp(m, vector<int>(n,-1));
     return f(m-1, n-1,dp);   
}