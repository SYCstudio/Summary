#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

#define ll long long
#define mem(Arr,x) memset(Arr,x,sizeof(Arr))

const int maxN=201000;
const int inf=2147483647;

class Treap
{
public:
    int key,rd;
    int ch[2],cnt,size;
};

int n,root;
int bcnt=0,Bin[maxN];
Treap T[maxN];

int random(int l,int r);
void Init();
int Newnode(int key);
void Update(int u);
int Merge(int u,int v);
void Split(int now,int key,int &u,int &v);
void Outp(int u);

int main(){
    for (int i=maxN-1;i>=1;i--) Bin[++bcnt]=i;
    Init();
    scanf("%d",&n);
    while (n--){
	int opt,x;scanf("%d%d",&opt,&x);
	if (opt==1){
	    int r1,r2,r3;Split(root,x,r1,r3);Split(r1,x-1,r1,r2);
	    if (r2){
		++T[r2].size;++T[r2].cnt;
		root=Merge(Merge(r1,r2),r3);
	    }
	    else root=Merge(Merge(r1,Newnode(x)),r3);
	}
	if (opt==2){
	    int r1,r2,r3;Split(root,x,r1,r3);Split(r1,x-1,r1,r2);
	    if (T[r2].cnt>1){
		--T[r2].cnt;--T[r2].size;root=Merge(Merge(r1,r2),r3);
	    }
	    else{
		Bin[++bcnt]=r2;
		root=Merge(r1,r3);
	    }
	}
	if (opt==3){
	    int r1,r2,r3;Split(root,x,r1,r3);Split(r1,x-1,r1,r2);
	    printf("%d\n",T[r1].size);
	    root=Merge(Merge(r1,r2),r3);
	}
	if (opt==4){
	    int now=root;++x;
	    do{
		if (T[T[now].ch[0]].size>=x) now=T[now].ch[0];
		else if (T[T[now].ch[0]].size+T[now].cnt>=x) break;
		else x=x-T[T[now].ch[0]].size-T[now].cnt,now=T[now].ch[1];
	    }
	    while (1);
	    printf("%d\n",T[now].key);
	}
	if (opt==5){
	    int r1,r2;Split(root,x-1,r1,r2);
	    int now=r1;
	    while (T[now].ch[1]) now=T[now].ch[1];
	    printf("%d\n",T[now].key);
	    root=Merge(r1,r2);
	}
	if (opt==6){
	    int r1,r2;Split(root,x,r1,r2);
	    int now=r2;
	    while (T[now].ch[0]) now=T[now].ch[0];
	    printf("%d\n",T[now].key);
	    root=Merge(r1,r2);
	}
    }
    return 0;
}

int random(int l,int r){
    double dou=1.0*rand()/RAND_MAX;
    return min(r,(int)(dou*(r-l+1))+l);
}

void Init(){
    root=Newnode(-inf);int right=Newnode(inf);
    T[root].ch[1]=right;Update(root);
    return;
}

int Newnode(int key){
    int id=Bin[bcnt--];T[id].key=key;T[id].rd=random(1,10000000);
    T[id].ch[0]=T[id].ch[1]=0;T[id].cnt=T[id].size=1;
    return id;
}

void Update(int u){
    T[u].size=T[T[u].ch[0]].size+T[T[u].ch[1]].size+T[u].cnt;
    return;
}

int Merge(int u,int v){
    if ((u==0)||(v==0)) return u+v;
    if (T[u].rd<=T[v].rd){
	T[u].ch[1]=Merge(T[u].ch[1],v);Update(u);return u;
    }
    else{
	T[v].ch[0]=Merge(u,T[v].ch[0]);Update(v);return v;
    }
}

void Split(int now,int key,int &u,int &v){
    Update(now);
    if (now==0){
	u=v=0;return;
    }
    if (T[now].key<=key){
	u=now;Split(T[now].ch[1],key,T[now].ch[1],v);
    }
    else{
	v=now;Split(T[now].ch[0],key,u,T[now].ch[0]);
    }
    Update(now);return;
}

void Outp(int u){
    if (T[u].ch[0]) Outp(T[u].ch[0]);
    cout<<T[u].key<<" ";
    if (T[u].ch[1]) Outp(T[u].ch[1]);
    return;
}
