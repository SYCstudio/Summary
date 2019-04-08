//主过程
for (int i=1;i<=K;i++){
    for (int j=1;j<=K;j++) Slack[j]=inf;
    do{
	tim++;
	if (Hungary(i)) break;
	int mnd=inf;
	for (int j=1;j<=K;j++) if (timy[j]!=tim) mnd=min(mnd,Slack[j]);
	for (int j=1;j<=K;j++){
	    if (timx[j]==tim) Lkey[j]-=mnd;
	    if (timy[j]==tim) Rkey[j]+=mnd;
	    else Slack[j]-=mnd;
	}
    }
    while (1);
}
//匈牙利增广
bool Hungary(int u){
    timx[u]=tim;
    for (int i=1;i<=K;i++)
	if (timy[i]!=tim){
	    if (Lkey[u]+Rkey[i]==W[u][i]){
		timy[i]=tim;
		if ((Match[i]==-1)||(Hungary(Match[i]))){
		    Match[i]=u;return 1;
		}
	    }
	    Slack[i]=min(Slack[i],Lkey[u]+Rkey[i]-W[u][i]);
	}
    return 0;
}
