#include <bits/stdc++.h>

int zAlgorithm(string s, string p, int n, int m)

{


 

    int count = 0;

 

    for(int i=0;i<n;i++){

        if(s[i]==p[0]){

            if(s.substr(i,m)==p){

                count++;

            }

        }

    }

    return count;

}
