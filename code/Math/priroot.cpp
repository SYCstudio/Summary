int main(){
    scanf("%d",&n);
    int num=n-1;
    for (int i=2;i<=sqrt(num);i++)
        if (num%i==0){
            P[++pcnt]=i;
            while (num%i==0) num/=i;
        }
    for (int g=2;g<=n-1;g++){
        bool flag=1;
        for (int i=1;i<=pcnt;i++)
	    if (QPow(g,(n-1)/P[i],n)==1){
		flag=0;break;
	    }
        if (flag){
            printf("%d\n",g);break;
        }
    }
}
