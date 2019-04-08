void Add(int x,int key){
    x+=N;T[x]+=key;x>>=1;
    while (x) T[x]=T[x<<1]+T[x<<1|1],x>>=1;
    return;
}
int Min(int x){
    if (T[x]==0) return -1;
    while (x<=N) x=(T[x<<1])?(x<<1):(x<<1|1);
    return x-N-1;
}
int Max(int x){
    if (T[x]==0) return -1;
    while (x<=N) x=(T[x<<1|1])?(x<<1|1):(x<<1);
    return x-N-1;
}
int Pre(int x){
    x=x+N;
    while (x>1){
        if ((x&1)&&(T[x^1])) return Max(x^1);
        x>>=1;
    }
    return -1;
}
int Nex(int x){
    x+=N;
    while (x>1){
        if (((x&1)==0)&&(T[x^1])) return Min(x^1);
        x>>=1;
    }
    return -1;
}
int Find(int x){
    return T[x+N]?1:-1;
}
