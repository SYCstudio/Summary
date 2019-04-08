void PolyLn(int *A,int *B,int len){
    mem(L1,0);mem(L2,0);
    PolyDery(A,L1,len);
    PolyInv(A,L2,len);
    NTT(L1,len<<1,1);NTT(L2,len<<1,1);
    for (int i=0;i<(len<<1);i++) L1[i]=1ll*L1[i]*L2[i]%Mod;
    NTT(L1,len<<1,-1);
    PolyInte(L1,B,len);
    for (int i=0;i<(len<<1);i++) L1[i]=L2[i]=0;
    return;
}
