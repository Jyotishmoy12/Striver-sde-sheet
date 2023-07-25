#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    
    sort(arr.begin(), arr.end());
    int i=0; int j=1;
    int count=1;
    int maxCount=1;
    while(i<n && j<n){
        if(arr[j]-arr[i] ==1){
            count++;
            maxCount= max(count, maxCount);
            i++;
            j++;
        }
        else if(arr[j]-arr[i]==0){
            i++;
            j++;
        }
        else{
            count=1;
            i++;
            j++;
        }
    }
    return maxCount;
}
