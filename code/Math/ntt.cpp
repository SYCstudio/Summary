void NTT(int *P,int N,int opt){
    int l=-1,_N=N;while (_N) ++l,_N>>=1;
    for (int i=0;i<N;i++) Rader[i]=(Rader[i>>1]>>1)|((i&1)<<(l-1));
    for (int i=0;i<N;i++) if (i<Rader[i]) swap(P[i],P[Rader[i]]);
    for (int i=1;i<N;i<<=1){
	int dw=QPow(G,(Mod-1)/(i<<1));
	if (opt==-1) dw=QPow(dw,Mod-2);
	for (int j=0;j<N;j+=(i<<1))
	    for (int k=0,w=1;k<i;k++,w=1ll*w*dw%Mod){
		int X=P[j+k],Y=1ll*P[j+k+i]*w%Mod;
		P[j+k]=(X+Y)%Mod;P[j+k+i]=(X-Y+Mod)%Mod;
	    }
    }
    if (opt==-1){
	int inv=QPow(N,Mod-2);
	for (int i=0;i<N;i++) P[i]=1ll*P[i]*inv%Mod;
    }
    return;
}
