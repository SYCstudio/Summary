ll gcd(ll a,ll b){
    if (!a||!b) return a|b;
    int t=__builtin_ctzll(a|b);ll tmp;
    a>>=__builtin_ctzll(a);
    do{
        b>>=__builtin_ctzll(b);
        if (a>b) tmp=a,a=b,b=tmp;b-=a;
    }
    while (b);
    return a<<t;
}
