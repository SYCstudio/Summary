void Init(){
    Phi[1]=Mu[1]=Low[1]=1;notprime[1]=1;
    for (int i=2;i<maxN;i++){
        if (notprime[i]==0){
            Prime[++pricnt]=i;Mu[i]=-1;Phi[i]=i-1;Low[i]=i;
        }
        for (int j=1;1ll*i*Prime[j]<maxN;j++){
            int p=Prime[j];
            notprime[i*p]=1;
            if (i%p==0){
                if (Low[i]==i){
                    Mu[i*p]=0;Phi[i*p]=Phi[i]*p;Low[i*p]=Low[i]*p;
                }
                else{
                    Mu[i*p]=Mu[i/Low[i]]*Mu[p*Low[i]];
                    Phi[i*p]=Phi[i/Low[i]]*Phi[p*Low[i]];Low[i*p]=Low[i]*p;
                }
                break;
            }
            Mu[i*p]=Mu[i]*Mu[p];Phi[i*p]=Phi[i]*Phi[p];Low[i*p]=p;
        }
    }
    return;
}
