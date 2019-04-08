void Rotate(int x){
    int y=S[x].fa,z=S[y].fa;
    int sx=(x==S[y].ch[1]),sy=(y==S[z].ch[1]);
    S[x].fa=z;if (z) S[z].ch[sy]=x;
    S[y].ch[sx]=S[x].ch[sx^1];if (S[x].ch[sx^1]) S[S[x].ch[sx^1]].fa=y;
    S[y].fa=x;S[x].ch[sx^1]=y;
    Update(y);return;
}
void Splay(int &rt,int x,int goal){
    int top=0,now=x;
    while (now) St[++top]=now,now=S[now].fa;
    for (int i=top;i>=1;i--) PushDown(St[i]);
    while (S[x].fa!=goal){
	int y=S[x].fa,z=S[y].fa;
	if (z!=goal)
	    ((x==S[y].ch[0])^(y==S[z].ch[0]))?(Rotate(x)):(Rotate(y));
	Rotate(x);
    }
    Update(x);
    if (goal==0) rt=x;return;
}
int Prev(int &rt,int x){
    Splay(rt,x,0);if (S[x].ch[0]==0) return -1;
    int now=S[x].ch[0];while (S[now].ch[1]) now=S[now].ch[1];
    return now;
}
int Next(int &rt,int x){
    Splay(rt,x,0);if (S[x].ch[1]==0) return -1;
    int now=S[x].ch[1];while (S[now].ch[0]) now=S[now].ch[0];
    return now;
}
