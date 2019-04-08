class Bigint
{
public:
    int sz;
    ll num[maxN];
    void MainTain(){
        for (int i=1;i<sz;i++) num[i+1]+=num[i]/maxM,num[i]%=maxM;
        while (num[sz]>=maxM) num[sz+1]=num[sz]/maxM,num[sz]%=maxM,++sz;
        return;
    }
    Bigint(){
        sz=0;return;
    }
    Bigint(int A){
        num[sz=1]=A;MainTain();return;
    }
    bool zero(){
        return (sz==1)&&(num[1]==0);
    }
    Bigint operator = (int A){
        num[sz=1]=A;MainTain();return *this;
    }
    Bigint operator = (Bigint A){
        sz=A.sz;for (int i=1;i<=sz;i++) num[i]=A.num[i];
        return *this;
    }
    void outp(){
        printf("%lld",num[sz]);
        for (int i=sz-1;i>=1;i--) printf("%02lld",num[i]);
        return;
    }
};

Bigint operator + (Bigint A,int B){
    A.num[1]+=B;A.MainTain();return A;
}
Bigint operator - (Bigint A,int B){
    if (A.num[1]<B){
        int b=2;while (A.num[b]==0) ++b;
        while (b!=1) A.num[b--]=maxM-1;
        A.num[1]+=maxM;
    }
    A.num[1]-=B;return A;
}
Bigint operator * (Bigint A,int B){
    for (int i=1;i<=A.sz;i++) A.num[i]*=B;
    A.MainTain();return A;
}
Bigint operator / (Bigint A,int B){
    for (int i=A.sz,sum=0;i>=1;i--){
        sum=sum*maxM+A.num[i];A.num[i]=0;
        A.num[i]=sum/B;sum%=B;
    }
    while ((A.sz>1)&&(A.num[A.sz]==0)) --A.sz;
    return A;
}
int operator % (Bigint A,int B){
    int ret=0;
    for (int i=A.sz;i>=1;i--){
        ret=ret*maxM+A.num[i];
        ret%=B;
    }
    return ret;
};
Bigint operator + (Bigint A,Bigint B){
    A.sz=max(A.sz,B.sz);
    for (int i=1;i<=A.sz;i++) A.num[i]+=B.num[i];
    A.MainTain();return A;
}
Bigint operator - (Bigint A,Bigint B){
    for (int i=1;i<=A.sz;i++){
        if (A.num[i]<B.num[i]){
            --A.num[i+1];A.num[i]+=maxM;
        }
        A.num[i]-=B.num[i];
    }
    while ((A.sz>1)&&(A.num[A.sz]==0)) --A.sz;
    return A;
}
Bigint operator * (Bigint A,Bigint B){
    for (int i=1;i<=A.sz;i++) Bp[i]=A.num[i];
    for (int i=1;i<=A.sz+B.sz;i++) A.num[i]=0;
    for (int i=1;i<=A.sz;i++)
	for (int j=1;j<=B.sz;j++)
	    A.num[i+j-1]+=Bp[i]*B.num[j];
    A.sz=A.sz+B.sz-1;A.MainTain();return A;
}
