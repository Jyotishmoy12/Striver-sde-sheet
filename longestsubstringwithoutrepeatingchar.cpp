#include <bits/stdc++.h> 
int uniqueSubstrings(string s)
{
   if(s=="") return 0;
   int n=s.length();
   int maxi=INT_MIN;
   int i=0,j=0;
   unordered_set<char>st;
   while(j<n){
       while(st.find(s[j])!=st.end()){
           st.erase(s[i]);
           i++;
       }
       maxi=max(maxi, j-i+1);
       st.insert(s[j]);
       j++;
   }
return maxi;
}
