int calculateMinPatforms(int at[], int dt[], int n) {
    //sort the times
    sort(at, at+n);
    sort(dt, dt+n);
    int i=1, j=0;
    //the first arrival will happen anyway
    //we will need at-least 1 platform anyway
    int maxP = 1, cnt = 1;

    while(i<n && j<n){
        //if arrival of next train requires new platform
        if(at[i]<=dt[j]){
            cnt++;
            i++;
        }
        else{
            cnt--;
            j++;
        }
        maxP = max(maxP, cnt);
    }
    return maxP;
}