void PolyInv(int *A,int *B,int len){
    if (len==1){
        B[0]=QPow(A[0],Mod-2);return;
    }
    PolyInv(A,B,len>>1);
    int N,L=0;
    for (N=1;N<=len<<1;N<<=1) ++L;
    for (int i=0;i<N;++i) Rader[i]=(Rader[i>>1]>>1)|((i&1)<<(L-1)),P1[i]=P2[i]=0;
    for (int i=0;i<len;++i) P1[i]=A[i],P2[i]=B[i];
    NTT(P1,N,1);NTT(P2,N,1);
    for (int i=0;i<N;++i) P1[i]=1ll*P1[i]*P2[i]%Mod*P2[i]%Mod;
    NTT(P1,N,-1);
    for (int i=0;i<=len<<1;++i) B[i]=((2ll*B[i]%Mod-P1[i])%Mod+Mod)%Mod;
    return;
}
