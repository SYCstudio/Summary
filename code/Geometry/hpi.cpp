bool Isleft(Line A,Point B){
    return Cross(A.d,B-A.p)>0;
}
bool check(){
    int L=1,R=1;Q1[1]=A[1];
    for (int i=2;i<=scnt;i++){
        while ((L<R)&&(!Isleft(A[i],Q2[R-1]))) R--;
        while ((L<R)&&(!Isleft(A[i],Q2[L]))) L++;
        Q1[++R]=A[i];
        if (fabs(Cross(Q1[R].d,Q1[R-1].d))<1e-15){
            --R;
            if (Isleft(Q1[R],A[i].p)) Q1[R]=A[i];
        }
        if (L<R) Q2[R-1]=GetP(Q1[R-1],Q1[R]);
    }
    while ((L<R)&&(!Isleft(Q1[L],Q2[R-1]))) R--;
    return R-L>1;
}
