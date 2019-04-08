M.clear();
ll m=ceil(sqrt(p)),now=b,t=1;
M[now]=0;
for (int i=1;i<=m;i++){
    now=now*a%p;t=t*a%p;
    M[now]=i;
}
now=1;bool getans=0;
for (int i=1;i<=m;i++){
    now=now*t%p;
    if (M.count(now)){
        ll ans=1ll*i*m-M[now];
        ans=(ans%p+p)%p;getans=1;
        printf("%lld\n",ans);
        break;
    }
}
