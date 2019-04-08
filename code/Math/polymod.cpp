void PolyMod(vector<int> A,vector<int> B,vector<int> &R){
    int n=A.size()-1,m=B.size()-1,p=n-m;
    for (int i=0;i<n-i;i++) swap(A[i],A[n-i]);
    for (int i=0;i<m-i;i++) swap(B[i],B[m-i]);
    
    int N=1;while (N<=m) N<<=1;
    B.resize(N);M1.resize(N);
    PolyInv(B,M1,N);B.resize(m+1);M1.resize(p+1);
    
    Mul(M1,A);
    for (int i=0;i<p-i;i++) swap(M1[i],M1[p-i]);
    for (int i=0;i<n-i;i++) swap(A[i],A[n-i]);
    for (int i=0;i<m-i;i++) swap(B[i],B[m-i]);
    
    M1.resize(p+1);
    Mul(M1,B);
    
    R.resize(m);
    for (int i=0;i<m;i++) R[i]=(A[i]-M1[i]+Mod)%Mod;
    M1.resize(0);
    return;
}
