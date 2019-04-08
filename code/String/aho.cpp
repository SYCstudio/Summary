void GetFail(){
    while (!Q.empty()) Q.pop();
    for (int i=0;i<maxAlpha;i++)
    if (son[i][1]){
        fail[son[i][1]]=1;Q.push(son[i][1]);
    }
    else son[i][1]=1;
    while (!Q.empty()){
        int u=Q.front();Q.pop();
        for (int i=0;i<maxAlpha;i++)
        if (son[i][u]){
            fail[son[i][u]]=son[i][fail[u]];
            Q.push(son[i][u]);
        }
        else son[i][u]=son[i][fail[u]];
    }
    return;
}
