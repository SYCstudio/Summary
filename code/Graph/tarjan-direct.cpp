void tarjan(int u){
    St[++top]=u;dfn[u]=low[u]=++dfncnt;ink[u]=1;
    for (int i=Head[u];i!=-1;i=Next[i])
	if (dfn[V[i]]==0){
	    tarjan(V[i]);
	    low[u]=min(low[u],low[V[i]]);
	}
	else if (ink[V[i]]) low[u]=min(low[u],dfn[V[i]]);
    if (dfn[u]==low[u]){
        int v;idcnt++;
        do Size[Id[v=St[top--]]=idcnt]++,ink[v]=0;
        while (v!=u);
    }
    return;
}
