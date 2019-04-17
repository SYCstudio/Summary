int Merge(int u,int v){
    if (!u||!v) return u+v;
    if (u==v) return u;
    if (Dst[u]>Dst[v]) swap(u,v);
    
    if (Hfa[v]){
	int pre=Hpre[Hfa[v]],nxt=Hnxt[Hfa[v]];
	if (Hf[Fa[v]]==Hfa[v]) Hf[Fa[v]]=Hpre[Hf[Fa[v]]];
	if (pre!=-1) Hnxt[pre]=nxt;
	if (nxt!=-1) Hpre[nxt]=pre;
	Recycle(Hfa[v]);
    }
    Hfa[v]=Fa[v]=0;
    
    int id=New();Hv[id]=v;Hfa[v]=id;Fa[v]=u;
    if (Hf[u]!=-1) Hnxt[Hf[u]]=id;
    Hpre[id]=Hf[u];Hf[u]=id;Hnxt[id]=-1;
    return u;
}
void Pop(){
    static int scnt[2],Seq[2][maxN];
    scnt[0]=0;
    for (int i=Hf[rt];i!=-1;i=Hpre[i]){
	if (Fa[Hv[i]]==rt) Seq[0][++scnt[0]]=Hv[i],Hfa[Hv[i]]=Fa[Hv[i]]=0;
	Recycle(i);
    }
    int opt=0;Hf[rt]=-1;
    while (scnt[opt]>1){
	opt^=1;scnt[opt]=0;
	for (int i=1;i+1<=scnt[opt^1];i+=2) Seq[opt][++scnt[opt]]=Merge(Seq[opt^1][i],Seq[opt^1][i+1]);
	if (scnt[opt^1]&1) Seq[opt][++scnt[opt]]=Seq[opt^1][scnt[opt^1]];
    }
    rt=Seq[opt][1];return;
}
void Decrease(int u,ll key){
    if (Hfa[u]){
	int pre=Hpre[Hfa[u]],nxt=Hnxt[Hfa[u]];
	if (Hf[Fa[u]]==Hfa[u]) Hf[Fa[u]]=Hpre[Hf[Fa[u]]];
	if (pre!=-1) Hnxt[pre]=nxt;
	if (nxt!=-1) Hpre[nxt]=pre;
	Recycle(Hfa[u]);
    }
    Fa[u]=0;Hfa[u]=0;
    Dst[u]=key;rt=Merge(rt,u);return;
}
void Recycle(int id){
    Ryc[++top]=id;return;
}
int New(){
    if (top) return Ryc[top--];
    return ++hcnt;
}
