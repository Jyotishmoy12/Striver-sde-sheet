string kthPermutation(int n, int k) {
    int fact=1;
    vector<int>numbers;
    for(int i=1;i<n;i++){
        fact=fact*i;
        numbers.push_back(i); // storing all the numbers in the array
    }
    numbers.push_back(n);
    string ans="";
    k=k-1; // coz of 0-based indexing
    while(true){
       ans+=to_string(numbers[k/fact]);
       numbers.erase(numbers.begin()+k/fact);
       if(numbers.size()==0){
           break;
       }
       k=k%fact;
       fact=fact/numbers.size(); 
    }
    return ans;

}
