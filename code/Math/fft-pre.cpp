//预处理:
for (int i=0;i<N;i++) Wn[i]=complex<ld>(cos(2*Pi*i/N),sin(2*Pi*i/N)),Iwn[i]=conj(Wn[i]);
//FFT:
void FFT(complex<ld> *P,int N,const int opt){
    for (int i=0;i<N;i++) if (i<Rader[i]) swap(P[i],P[Rader[i]]);
    for (int i=1;i<N;i<<=1){
        int l=i<<1;
        complex<ld> dw(cos(Pi/i),sin(Pi/i)*opt);
        for (int j=0;j<N;j+=l){
            complex<ld> w(1,0);
            for (int k=0;k<i;k++,w*=dw){
                complex<ld> X=P[j+k],Y=w*P[j+k+i];
                P[j+k]=X+Y;P[j+k+i]=X-Y;
            }
        }
    }
    return;
}
