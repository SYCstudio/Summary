void PolyExp(int *A,int *B,int len){
    if (len==1){B[0]=1;return;}
    PolyExp(A,B,len>>1);
    PolyLn(B,E1,len);
    for (int i=0;i<len;i++) E1[i]=((Mod-E1[i]+A[i])%Mod+Mod)%Mod,E2[i]=B[i];
    E1[0]=(E1[0]+1)%Mod;
    NTT(E1,len<<1,1);NTT(E2,len<<1,1);
    for (int i=0;i<(len<<1);i++) E1[i]=1ll*E1[i]*E2[i]%Mod;
    NTT(E1,len<<1,-1);
    for (int i=0;i<len;i++) B[i]=E1[i];
    for (int i=0;i<(len<<1);i++) E1[i]=E2[i]=0;
    return;
}
