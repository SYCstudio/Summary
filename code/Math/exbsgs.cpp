void BSGS(int x,int z,int k){
    if (z==1){
        printf("0\n");return;
    }
    int cnt=0,D=1;
    do{
        int d=gcd(x,z);if (d==1) break;
        if (k%d){
            printf("No Solution\n");return;
        }
        k/=d;z/=d;cnt++;D=1ll*D*(x/d)%z;
        if (D==k){
            printf("%d\n",cnt);return;
        }
    }
    while (1);
    M.clear();
    int m=ceil(sqrt(z));
    int now=k,T=1;M[k]=0;
    for (int i=1;i<=m;i++){
        now=1ll*now*x%z;T=1ll*T*x%z;
        M[now]=i;
    }
    now=D;
    for (int i=1;i<=m;i++){
        now=1ll*now*T%z;
        if (M.count(now)){
            printf("%d\n",i*m-M[now]+cnt);return;
        }
    }
    printf("No Solution\n");return;
}
