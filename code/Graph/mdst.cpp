double Directed_MST(int root,int NV,int NE){//根节点为root，NV为点数，NE为边数
    double ret=0;int cntnode;
    while (1){
        //A.选出每个点的最小入边
        for (int i=0;i<NV;i++) In[i]=inf;
        for (int i=0;i<NE;i++){
            int u=E[i].u,v=E[i].v;
            if ((u!=v)&&(E[i].w<In[v])) Pre[v]=u,In[v]=E[i].w;
        }
        //若存在孤立点，则不存在在最小树形图
        for (int i=0;i<NV;i++) if ((i!=root)&&(In[i]==inf)) return -1;
        //B.标记环
        memset(Id,-1,sizeof(Id));memset(vis,-1,sizeof(vis));
        cntnode=0;In[root]=0;//因为先前处理时略过了根节点，所以要使根节点入度为0
        for (int i=0;i<NV;i++){
            ret+=In[i];int v=i;
            while ((vis[v]!=i)&&(Id[v]==-1)&&(v!=root)) vis[v]=i,v=Pre[v];
            if ((v!=root)&&(Id[v]==-1)){
                for (int x=Pre[v];x!=v;x=Pre[x])Id[x]=cntnode;
                Id[v]=cntnode++;
            }
        }
        if(cntnode==0) break;//当前图中已无环，表示算法结束
        //C.缩点，重新分配编号
        for (int i=0;i<NV;i++)//给不是环中的点分配编号
            if (Id[i]==-1) Id[i]=cntnode++;
        for (int i=0;i<NE;i++){
            int v=E[i].v;E[i].u=Id[E[i].u];E[i].v=Id[E[i].v];
            if(E[i].u!=E[i].v) E[i].w=E[i].w-In[v];
        }
        NV=cntnode;root=Id[root];
    }
    return ret;
}
