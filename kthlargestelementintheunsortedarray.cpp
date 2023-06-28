#include <bits/stdc++.h> 
int kthLargest(vector<int>& nums, int size, int k)
{
	priority_queue<int, vector<int>, greater<int>>q;
		for(int i=0; i<nums.size(); i++){
			q.push(nums[i]);
			while(q.size()>k){
                q.pop();
            }
		}
		return q.top();
}
