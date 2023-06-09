#include<bits/stdc++.h>
void help(int i, vector<int>&arr, int n, vector<int>&subset, vector<vector<int>>&powerset, int sum , int target){
        if(sum==target){
            powerset.push_back(subset);
            return;
        }
        if(sum>target) return;
        if(i==n) return;
        subset.push_back(arr[i]);
        sum+=arr[i];
        help(i+1, arr, n, subset, powerset, sum, target);
        subset.pop_back();
        sum-=arr[i];
        while(i<arr.size()-1 && arr[i]==arr[i+1]) i++;
        help(i+1, arr, n, subset, powerset, sum, target);
    }

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	// Write your code here.
        vector<int>subset;
        vector<vector<int>>powerset;
        int sum=0;
        sort(arr.begin(), arr.end());
        help(0,arr, n, subset, powerset, sum, target );
        return powerset;
}
