int Merge(int u,int v){
    if (u==0) return v;
    if (v==0) return u;
    if (H[u].key>H[v].key) swap(u,v);
    H[u].rs=Merge(H[u].rs,v);
    if (H[H[u].ls].dis<H[H[u].rs].dis) swap(H[u].ls,H[u].rs);
    if (H[u].rs) H[u].dis=H[H[u].rs].dis+1;
    else H[u].dis=0;
    return u;
}
