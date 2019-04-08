int GetK(int k){
    int sum=0,ret=0;
    for (int i=20;i>=0;i--){
        ret=ret+(1<<i);
        if ((ret>n)||(sum+BIT[ret]>=k)) ret-=(1<<i);
        else sum+=BIT[ret];
    }
    return ret+1;
}
