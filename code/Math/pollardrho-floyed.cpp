void Pollard_Rho(ll x){
    if (MR(x)) return Ans=x,(void(0));
    do{
        ll k=rand()%x,a=k,b=f(a,k,x),g;
        if (a&&(x%a==0)) return PR(a),PR(x/a),(void(0));
        if (b&&(x%b==0)) return PR(b),PR(x/b),(void(0));
        while (a!=b){
            g=gcd(abs(a-b),x);
            if (g!=1) return PR(g),PR(x/g),(void(0));
            a=(Mul(a,a,x)+k);if (a>=x) a-=x;
            b=(Mul(b,b,x)+k);if (b>=x) b-=x;
            b=(Mul(b,b,x)+k);if (b>=x) b-=x;
        }
    }
    while (1);
}
