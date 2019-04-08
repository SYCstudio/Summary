for (int S=0;S<(1<<D);S++){
    for (int i=1;i<=n;i++){
        for (int s=(S-1)&S;s;s=(s-1)&S) F[i][S]=min(F[i][S],F[i][s]+F[i][S^s]);
        if (F[i][S]!=F[0][0]) H.push(make_pair(-F[i][S],i));
    }
    ++viscnt;
    while (!H.empty()){
        int u=H.top().second;H.pop();
        if (vis[u]==viscnt) continue;vis[u]=viscnt;
        for (int i=Head[u];i!=-1;i=Next[i])
            if (F[E[i].first][S]>F[u][S]+E[i].second)
                H.push(make_pair(-(F[E[i].first][S]=F[u][S]+E[i].second),E[i].first));
    }
}
