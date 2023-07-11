int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    sort(at, at+n);
    sort(dt, dt+n);
    int plat_needed=1, res=1;
    int i=1, j=0;
    while(i<n && j<n){
        if(at[i]<=dt[j]){
            plat_needed++;
            i++;
        }
        else if(at[i]>dt[j]){
            plat_needed--;
            j++;
        }
        if(plat_needed>res){
            res=plat_needed;
        }
    }
    return res;
}
