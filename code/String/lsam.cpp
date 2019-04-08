int Extend(int c,int lst){
    if (S[lst].son[c]&&S[S[lst].son[c]].len==S[lst].len+1) return lst=S[lst].son[c];
    int np=++scnt,p=lst;lst=np;S[np].len=S[p].len+1;
    while (p&&S[p].son[c]==0) S[p].son[c]=np,p=S[p].fail;
    if (!p) S[np].fail=1;
    else{
	int q=S[p].son[c];
	if (S[q].len==S[p].len+1) S[np].fail=q;
	else{
	    int nq=++scnt;S[nq]=S[q];S[nq].len=S[p].len+1;S[np].fail=S[q].fail=nq;
	    while (p&&S[p].son[c]==q) S[p].son[c]=nq,p=S[p].fail;
	}
    }
    return lst;
}
