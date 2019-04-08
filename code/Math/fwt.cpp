void FWTAnd(int *P,int N,int opt){
    for (int i=1;i<N;i<<=1)
        for (int j=0;j<N;j+=(i<<1))
            for (int k=0;k<i;k++)
                P[j+k]=P[j+k]+P[j+k+i]*opt;
    return;
}
void FWTOr(int *P,int N,int opt){
    for (int i=1;i<N;i<<=1)
        for (int j=0;j<N;j+=(i<<1))
            for (int k=0;k<i;k++)
                P[j+k+i]=P[j+k+i]+P[j+k]*opt;
    return;
}
void FWTXor(int *P,int N,int opt){
    for (int i=1;i<N;i<<=1)
        for (int j=0;j<N;j+=(i<<1))
            for (int k=0;k<i;k++){
                int X=P[j+k],Y=P[j+k+i];
                P[j+k]=X+Y;P[j+k+i]=X-Y;
                if (opt==-1) P[j+k]/=2,P[j+k+i]/=2;
	    }
    return;
}
