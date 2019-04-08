while (Depth[S]<n){
    if (u==T){
	Ans+=ISAP();u=S;
    }
    bool flag=0;
    for (int now=cur[u];now!=-1;now=Next[now]){
	int v=E[now].v;
	if ((E[now].w>0)&&(Depth[u]==Depth[v]+1)){
	    flag=1;Path[v]=cur[u]=now;u=v;break;
	}
    }
    if (!flag){
	int MIN=n-1;
	for (i=Head[u];i!=-1;i=Next[i]) if (E[i].w>0) MIN=min(MIN,Depth[E[i].v]);
	Gap[Depth[u]]--;if (Gap[Depth[u]]==0) break;
	Depth[u]=MIN+1;Gap[Depth[u]]++;
	cur[u]=Head[u];if (u!=S) u=E[Path[u]].u;
    }
}
