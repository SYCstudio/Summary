void GetSA(){
    for (int i=2;i<maxN;i++) Lg[i]=Lg[i>>1]+1;
    for (int i=1;i<=L;i++) ++CntA[S[i]];
    for (int i=1;i<maxN;i++) CntA[i]+=CntA[i-1];
    for (int i=L;i>=1;i--) SA[CntA[S[i]]--]=i;
    Rk[SA[1]]=1;
    for (int i=2;i<=L;i++){
	Rk[SA[i]]=Rk[SA[i-1]];
	if (S[SA[i]]!=S[SA[i-1]]) ++Rk[SA[i]];
    }
    for (int b=1;Rk[SA[L]]!=L;b<<=1){
	memset(CntA,0,sizeof(CntA));memset(CntB,0,sizeof(CntB));
	for (int i=1;i<=L;i++) ++CntA[A[i]=Rk[i]],++CntB[B[i]=(i+b<=L?Rk[i+b]:0)];
	for (int i=1;i<maxN;i++) CntA[i]+=CntA[i-1],CntB[i]+=CntB[i-1];
	for (int i=L;i>=1;i--) SSA[CntB[B[i]]--]=i;
	for (int i=L;i>=1;i--) SA[CntA[A[SSA[i]]]--]=SSA[i];
	Rk[SA[1]]=1;
	for (int i=2;i<=L;i++){
	    Rk[SA[i]]=Rk[SA[i-1]];
	    if (A[SA[i]]!=A[SA[i-1]]||B[SA[i]]!=B[SA[i-1]]) ++Rk[SA[i]];
	}
    }
    for (int i=1,j=0;i<=L;i++){
	while (S[i+j]==S[SA[Rk[i]+1]+j]) ++j;
	Ht[0][Rk[i]]=j;if (j) --j;
    }
    for (int i=1;i<maxB;i++) for (int j=1;j+(1<<i)-1<=L;j++) Ht[i][j]=min(Ht[i-1][j],Ht[i-1][j+(1<<(i-1))]);
    return;
}
