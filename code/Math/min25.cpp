for (int j=1;j<=pcnt;j++)
    for (int i=1;(i<=num)&&(1ll*P[j]*P[j]<=Num[i]);i++){
	G[i]=(G[i]-1ll*(G[GetId(Num[i]/P[j])]-SumP[j-1]+Mod)%Mod*P[j]%Mod+Mod)%Mod;
	H[i]=((H[i]-H[GetId(Num[i]/P[j])]+j-1)%Mod+Mod)%Mod;
    }
ll S(ll m,int p){
    if ((m<=1)||(P[p]>m)) return 0;
    int id=GetId(m);ll ret=(((G[id]-SumP[p-1])-(H[id]-(p-1)))%Mod+Mod)%Mod;
    if (p==1) ret=ret+2;
    for (int i=p;(i<=pcnt)&&(1ll*P[i]*P[i]<=m);i++){
        ll x=P[i];
        for (int e=1;x*P[i]<=m;e++,x*=P[i])
	    ret=((ret+1ll*S(m/x,i+1)*(P[i]^e)%Mod)%Mod+((P[i])^(e+1))%Mod)%Mod;
    }
    return ret;
}
