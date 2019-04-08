#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

typedef long long ll;
#define mem(Arr,x) memset(Arr,x,sizeof(Arr))
const int maxN=100010;
const int maxM=maxN<<1;
const int maxB=17;
const double alpha=0.8;
const int inf=1000000000;

class SplayData{
public:
    int ch[2],fa,size;
    int key,cnt;
};

int n;
SplayData S[maxN*50+10];
int edgecnt=-1,Head[maxN],Next[maxM],V[maxM],W[maxM];
int nodecnt,ryctop,Ryc[maxN*50+10],R[maxN],rt1[maxN],rt2[maxN];
int Dep[maxN],LCA[maxB][maxN],Dst[maxN],root,Sz[maxN],Mx[maxN];
int Csz[maxN],St[maxN],Fa[maxN];
ll Ans=0;
vector<int> Dt[maxN];
bool vis[maxN];

void Add_Edge(int u,int v,int w);
void Recycle(int x);
int Newnode();
void Update(int x);
void Rotate(int x);
void Splay(int &rt,int x,int goal);
int Rank(int &rt,int key);
void Insert(int &rt,int key);
int GetLCA(int u,int v);
int Dist(int u,int v);
void dfs_mark(int u);
void dfs_root(int u,int fa,int size);
void Divide(int u,int size);
void dfs_calc(int u,int fa,int d,int r1,int r2);
void dfs_init(int u,int fa,int r,int rd);
void outp(int x);

int main(){
    mem(Head,-1);
    for (int i=1;i<maxN*50;i++) Ryc[++ryctop]=i;
    reverse(&Ryc[1],&Ryc[maxN*50]);

    scanf("%d%d",&n,&n);
    scanf("%lld%lld%d",&Ans,&Ans,&R[1]);Csz[1]=1;Dep[1]=1;vis[1]=1;Insert(rt1[1],-R[1]);
    printf("0\n");Ans=0;Mx[0]=inf;
    for (int qi=2;qi<=n;qi++){
        int a,b;scanf("%d%d%d",&a,&b,&R[qi]);a=a^(Ans%1000000000);
        vis[qi]=1;
        Add_Edge(a,qi,b);Fa[qi]=a;Dep[qi]=Dep[a]+1;LCA[0][qi]=a;Dst[qi]=Dst[a]+b;Dt[a].push_back(qi);
        for (int i=1;i<maxB;i++) LCA[i][qi]=LCA[i-1][LCA[i-1][qi]];

        int now=qi,top=1;St[1]=qi;
        while (Fa[now]) St[++top]=now=Fa[now];
        for (int i=1;i<=top;i++){
            int d=Dist(St[i],qi);++Csz[St[i]];
            Ans+=Rank(rt1[St[i]],R[qi]-d);Insert(rt1[St[i]],d-R[qi]);
            if (i!=1) Ans-=Rank(rt2[St[i-1]],R[qi]-d),Insert(rt2[St[i-1]],d-R[qi]);
        }

        for (int i=top-1;i>=1;i--)
            if (Csz[St[i]]>Csz[St[i+1]]*alpha){
                int rt=St[i+1];dfs_mark(rt);
                root=0;dfs_root(rt,rt,Csz[rt]);
                if (i!=top-1){
                    for (int j=0,sz=Dt[St[i+2]].size();j<sz;j++)
                        if (Dt[St[i+2]][j]==rt){
                            Dt[St[i+2]][j]=root;break;
                        }
                    dfs_init(root,0,root,St[i+2]);
                }
                Fa[root]=(i==top-1)?0:St[i+2];Divide(root,Csz[rt]);
                break;
            }

        printf("%lld\n",Ans);
    }
    return 0;
}
void Add_Edge(int u,int v,int w){
    Next[++edgecnt]=Head[u];Head[u]=edgecnt;V[edgecnt]=v;W[edgecnt]=w;
    Next[++edgecnt]=Head[v];Head[v]=edgecnt;V[edgecnt]=u;W[edgecnt]=w;
    return;
}
void Recycle(int x){
    if (x==0) return;Ryc[++ryctop]=x;
    if (S[x].ch[0]) Recycle(S[x].ch[0]);
    if (S[x].ch[1]) Recycle(S[x].ch[1]);
    return;
}
int Newnode(){
    int id=Ryc[ryctop--];
    S[id].ch[0]=S[id].ch[1]=S[id].fa=S[id].key=S[id].size=S[id].cnt=0;
    return id;
}
void Update(int x){
    S[x].size=S[S[x].ch[0]].size+S[S[x].ch[1]].size+S[x].cnt;
    return;
}
void Rotate(int x){
    int y=S[x].fa,z=S[y].fa,sx=(x==S[y].ch[1]),sy=(y==S[z].ch[1]);
    S[x].fa=z;if (z) S[z].ch[sy]=x;
    S[y].ch[sx]=S[x].ch[sx^1];if (S[x].ch[sx^1]) S[S[x].ch[sx^1]].fa=y;
    S[y].fa=x;S[x].ch[sx^1]=y;
    Update(y);return;
}
void Splay(int &rt,int x,int goal){
    while (S[x].fa!=goal){
        int y=S[x].fa,z=S[y].fa;
        if (z!=goal)
            ((x==S[y].ch[0])^(y==S[z].ch[0]))?Rotate(x):Rotate(y);
        Rotate(x);
    }
    Update(x);if (goal==0) rt=x;
    return;
}
int Rank(int &rt,int key){
    int ret=0,x=rt,lstx=rt;
    while (x){
        lstx=x;
        if (S[x].key<=key) ret+=S[S[x].ch[0]].size+S[x].cnt,x=S[x].ch[1];
        else x=S[x].ch[0];
    }
    Splay(rt,lstx,0);return ret;
}
void Insert(int &rt,int key){
    if (rt==0){
        rt=Newnode();S[rt].cnt=S[rt].size=1;S[rt].key=key;
        return;
    }
    int x=rt;
    while (x){
        if (S[x].key==key){
            ++S[x].cnt;Splay(rt,x,0);return;
        }
        if (S[x].key<key){
            if (S[x].ch[1]) x=S[x].ch[1];
            else break;
        }
        else if (S[x].ch[0]) x=S[x].ch[0];
        else break;
    }
    int id=Newnode();S[id].fa=x;S[id].cnt=S[id].size=1;S[id].key=key;
    S[x].ch[key>S[x].key]=id;Splay(rt,id,0);return;
}
int GetLCA(int u,int v){
    if (Dep[u]<Dep[v]) swap(u,v);
    for (int i=maxB-1;i>=0;i--) if (LCA[i][u]&&Dep[LCA[i][u]]>=Dep[v]) u=LCA[i][u];
    if (u==v) return u;
    for (int i=maxB-1;i>=0;i--) if (LCA[i][u]&&LCA[i][v]&&LCA[i][u]!=LCA[i][v]) u=LCA[i][u],v=LCA[i][v];
    return LCA[0][u];
}
int Dist(int u,int v){
    int lca=GetLCA(u,v);
    return Dst[u]+Dst[v]-Dst[lca]*2;
}
void dfs_mark(int u){
    Recycle(rt1[u]);Recycle(rt2[u]);rt1[u]=rt2[u]=0;
    for (int i=0,sz=Dt[u].size();i<sz;i++) dfs_mark(Dt[u][i]);
    Dt[u].clear();vis[u]=0;return;
}
void dfs_root(int u,int fa,int size){
    Sz[u]=1;Mx[u]=0;
    for (int i=Head[u];i!=-1;i=Next[i])
        if (V[i]!=fa&&vis[V[i]]==0){
            dfs_root(V[i],u,size);Sz[u]+=Sz[V[i]];
            Mx[u]=max(Mx[u],Sz[V[i]]);
        }
    Mx[u]=max(Mx[u],size-Sz[u]);
    if (Mx[u]<Mx[root]) root=u;return;
}
void Divide(int u,int size){
    vis[u]=1;Csz[u]=size;
    Insert(rt1[u],0-R[u]);
    for (int i=Head[u];i!=-1;i=Next[i])
        if (vis[V[i]]==0){
            int ssz=Sz[V[i]]>Sz[u]?size-Sz[u]:Sz[V[i]];
            root=0;dfs_root(V[i],V[i],ssz);
            Dt[u].push_back(root);Fa[root]=u;
            dfs_calc(V[i],u,W[i],u,root);
            Divide(root,ssz);
        }
    return;
}
void dfs_calc(int u,int fa,int d,int r1,int r2){
    Insert(rt1[r1],d-R[u]);Insert(rt2[r2],d-R[u]);
    for (int i=Head[u];i!=-1;i=Next[i])
        if (V[i]!=fa&&vis[V[i]]==0) dfs_calc(V[i],u,d+W[i],r1,r2);
    return;
}
void dfs_init(int u,int fa,int r,int rd){
    int d=Dist(u,rd);Insert(rt2[r],d-R[u]);
    for (int i=Head[u];i!=-1;i=Next[i])
        if (V[i]!=fa&&vis[V[i]]==0) dfs_init(V[i],u,r,rd);
    return;
}
void outp(int x){
    if (S[x].ch[0]) outp(S[x].ch[0]);
    printf("%2d%3d%3d%3d%4d%4d%3d\n",x,S[x].fa,S[x].ch[0],S[x].ch[1],S[x].key,S[x].cnt,S[x].size);
    if (S[x].ch[1]) outp(S[x].ch[1]);
    return;
}
