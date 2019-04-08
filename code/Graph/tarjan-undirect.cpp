//点双联通
void tarjan(int u,int fa){
    dfn[u]=low[u]=++dfncnt;St[++top]=u;
    for (int i=Head[u];i!=-1;i=Next[i])
	if (V[i]!=fa){
	    if (dfn[V[i]]==0){
		tarjan(V[i],u);
		low[u]=min(low[u],low[V[i]]);
		if (low[V[i]]>=dfn[u]){
		    bcccnt++;int v;
		    do Bcc[v=St[top--]].push_back(bcccnt);
		    while (v!=V[i]);
		    Bcc[u].push_back(bcccnt);
		}
	    }
	    else low[u]=min(low[u],dfn[V[i]]);
	}
    return;
}
