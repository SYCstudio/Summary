bool Hungary(int u){
    for (int i=Head[u];i!=-1;i=Next[i])
	if (vis[V[i]]==0){
	    vis[V[i]]=1;
	    if ((Match[V[i]]==-1)||(Hungary(Match[V[i]]))){
		Match[V[i]]=u;return 1;
	    }
	}
    return 0;
}
