ll Calc(ll a,ll b,ll c,ll n){
    if (n<0) return 0;
    if (n==0) return b/c;
    if (a==0) return (n+1)*(b/c);
    if ((a>=0)&&(a<c)&&(b>=0)&&(b<c)){
	ll f=(a*n+b)/c;return f*n-Calc(c,c-b-1,a,f-1);
    }
    ll p=(a>=0)?(a/c):(a/c-1),q=a-p*c,m=(b>=0)?(b/c):(b/c-1),t=b-m*c;
    if (n&1) return Calc(q,t,c,n)+(n+1)/2*n*p+(n+1)*m;
    else return Calc(q,t,c,n)+n/2*(n+1)*p+(n+1)*m;
}
