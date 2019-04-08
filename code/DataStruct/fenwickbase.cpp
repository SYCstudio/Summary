void Add(int pos,int key){
    while (pos<=n){
        BIT[pos]+=key;pos+=(pos)&(-pos);
    }
    return;
}
int Sum(int pos){
    int ret=0;
    while (pos){
        ret+=BIT[pos];pos-=(pos)&(-pos);
    }
    return ret;
}
