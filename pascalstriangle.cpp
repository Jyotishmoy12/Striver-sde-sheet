#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
  vector<vector<long long int>>res;
  for(int i=0;i<n;i++){
    vector<long long int>v(i+1,1);
    for(int j=1;j<i;j++){
      v[j]=res[i-1][j-1]+res[i-1][j];
    }
    res.push_back(v);
  }
  return res;
}
