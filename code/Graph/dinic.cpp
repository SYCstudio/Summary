while (Bfs()){
    memcpy(cur,Hd,sizeof(cur));
    while (ll di=dfs(S,INF)) Ans-=di;
}
bool Bfs(){
    memset(label,-1,sizeof(label));int ql=1,qr=1;Qu[1]=S;label[S]=1;
    while (ql<=qr) for (int u=Qu[ql++],i=Hd[u];i!=-1;i=Nt[i]) if (E[i].flow&&label[E[i].v]==-1) label[Qu[++qr]=E[i].v]=label[u]+1;
    return label[T]!=-1;
}
ll dfs(int u,ll flow){
    if (u==T) return flow;
    for (int &i=cur[u];i!=-1;i=Nt[i]) if (E[i].flow&&label[E[i].v]==label[u]+1) if (ll di=dfs(E[i].v,min(flow,E[i].flow))) return E[i].flow-=di,E[i^1].flow+=di,di;
    return 0;
}
