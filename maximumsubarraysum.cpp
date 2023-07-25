#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
   long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

    for (int i = 0; i < n; i++) {

        sum += arr[i];
        
        if (sum < 0) {
            sum = 0;
        }
        maxi=max(maxi, sum);
    }

    return maxi;
}
