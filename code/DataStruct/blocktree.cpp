void dfs(int u,int fa){
    int nowtop=top;
    for (int i=Head[u];i!=-1;i=Next[i])
	if (V[i]!=fa){
	    dfs(V[i],u);
	    if (top-nowtop>=blocksize)
	    {
		blockcnt++;
		while (top!=nowtop) Belong[St[top--]]=blockcnt;
	    }
	}
    St[++top]=u;return;
}
