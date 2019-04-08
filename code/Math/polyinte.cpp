void PolyInte(int *A,int *B,int len){
    for (int i=1;i<len;i++) B[i]=1ll*A[i-1]*Inv[i]%Mod;
    B[0]=0;return;
}
