void Extend(int c){
    int np=++smcnt,p=lst;lst=np;Sm[np].len=Sm[p].len+1;
    while (p&&Sm[p].son[c]==0) Sm[p].son[c]=np,p=Sm[p].fail;
    if (p==0) Sm[np].fail=1;
    else{
        int q=Sm[p].son[c];
        if (Sm[q].len==Sm[p].len+1) Sm[np].fail=q;
        else{
            int nq=++smcnt;Sm[nq]=Sm[q];Sm[nq].len=Sm[p].len+1;Sm[np].fail=Sm[q].fail=nq;
            while (p&&Sm[p].son[c]==q) Sm[p].son[c]=nq,p=Sm[p].fail;
        }
    }
    return;
}
