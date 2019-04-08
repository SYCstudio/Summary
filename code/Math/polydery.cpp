void PolyDery(int *A,int *B,int len){
    for (int i=0;i<len;i++) B[i]=1ll*A[i+1]*(i+1)%Mod;
    B[len]=B[len-1]=0;
    return;
}
