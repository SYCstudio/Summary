bool Isroot(int u){
    if ((S[S[u].fa].ch[0]==u)||(S[S[u].fa].ch[1]==u)) return 0;
    return 1;
}
void Rotate(int x){
    int y=S[x].fa,z=S[y].fa;
    int sx=(x==S[y].ch[1]),sy=(y==S[z].ch[1]);
    S[x].fa=z;if (Isroot(y)==0) S[z].ch[sy]=x;
    S[y].ch[sx]=S[x].ch[sx^1];if (S[x].ch[sx^1]) S[S[x].ch[sx^1]].fa=y;
    S[x].ch[sx^1]=y;S[y].fa=x;
    Update(y);return;
}
void Splay(int x){
    int now=x;
    St[0]=0;St[++St[0]]=x;
    while (Isroot(now)==0){
        now=S[now].fa;St[++St[0]]=now;
    }
    while (St[0]) PushDown(St[St[0]--]);
    while (Isroot(x)==0){
        int y=S[x].fa,z=S[y].fa;
        if (Isroot(y)==0)
	    ((x==S[y].ch[0])^(y==S[z].ch[0]))?(Rotate(x)):(Rotate(y));
        Rotate(x);
    }
    Update(x);return;
}
void Access(int x){
    int lastx=0;
    while (x){
        Splay(x);S[x].ch[1]=lastx;Update(x);
        lastx=x;x=S[x].fa;
    }
    return;
}
void Makeroot(int u){
    Access(u);Splay(u);
    Rev(u);return;
}
void Link(int u,int v){
    Makeroot(u);S[u].fa=v;
    return;
}
void Cut(int u,int v){
    Makeroot(u);Access(v);Splay(v);
    S[v].ch[0]=S[u].fa=0;
    Update(u);Update(v);
    return;
}
