#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr) {    int ele1 = 0;    int ele2 = 0;    int count1 = 0;    int count2 = 0;    int n = arr.size();

   vector<int> ans;        for(auto x: arr){        if(ele1 == x){            count1++;        }else if(ele2 == x){            count2++;        }else if(count1 ==0){            ele1 = x;            count1 =1;        }else if(count2 ==0){            ele2 =x;            count2=1;        }else{            count2--;            count1--;        }    }        count1 =0;    count2=0;        for(auto x: arr){        if(x==ele2){            count2++;        }        if(x==ele1){            count1++;        }    }

   if(count1 > n/3){        ans.push_back(ele1);    }        if(count2>n/3){        ans.push_back(ele2);    }        return ans;

}
