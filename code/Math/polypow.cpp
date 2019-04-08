void PolyPow(int *A,int *B,int len,int k){
    PolyLn(A,P1,len);
    for (int i=0;i<len;i++) P1[i]=1ll*P1[i]*k%Mod;
    PolyExp(P1,B,len);
    for (int i=0;i<len;i++) P1[i]=0;
    return;
}
