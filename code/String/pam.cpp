void Insert(int pos,int c){
    int p=last;
    while (str[pos-1-P[p].len]!=str[pos]) p=P[p].fail;
    if (P[p].son[c]==0){
        int np=++nodecnt,q=P[p].fail;
        while (str[pos-1-P[q].len]!=str[pos]) q=P[q].fail;
        P[np].fail=P[q].son[c];
        P[p].son[c]=np;P[np].len=P[p].len+2;
    }
    last=P[p].son[c];
    P[last].cnt++;
    return;
}
