void FFT(complex<ld> *P,int opt){
    for (int i=0;i<N;i++) if (i<Rader[i]) swap(P[i],P[Rader[i]]);
    for (int i=1;i<N;i<<=1){
        complex<ld> dw(cos(Pi/i),sin(Pi/i)*opt);
        int l=i<<1;
        for (int j=0;j<N;j+=l){
            complex<ld> w(1,0);
            for (int k=0;k<i;k++,w*=dw){
                complex<ld> X=P[j+k],Y=w*P[j+k+i];
                P[j+k]=X+Y;P[j+k+i]=X-Y;
            }
        }
    }
    if (opt==-1) for (int i=0;i<N;i++) P[i].real()=P[i].real()/N+0.5;
    return;
}
