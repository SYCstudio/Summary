void PolySqrt(int *A,int *B,int len){
    if (len==1){
        B[0]=sqrt(A[0]);return;//注意这里常数项的计算，这里的 sqrt 函数应该是求模意义下的二次剩余
    }
    PolySqrt(A,B,len>>1);
    PolyInv(B,P4,len);
    int N,L=0;
    for (N=1;N<=len<<1;N<<=1) ++L;
    for (int i=0;i<N;++i) Rader[i]=(Rader[i>>1]>>1)|((i&1)<<(L-1));
    for (int i=0;i<len;++i) P3[i]=A[i];
    NTT(P3,N,1);NTT(P4,N,1);
    for (int i=0;i<N;++i) P3[i]=1ll*P3[i]*P4[i]%Mod;
    NTT(P3,N,-1);
    for (int i=0;i<len;++i) B[i]=1ll*(B[i]+P3[i])%Mod*inv2%Mod;
    return;
}
