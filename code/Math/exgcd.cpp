ll Exgcd(ll a,ll b,ll &x,ll &y){
    if (a==0){
	x=0;y=1;return b;
    }
    ll gcd=Exgcd(b%a,a,x,y);
    ll t=x;x=y-b/a*x;y=t;
    return gcd;
}
