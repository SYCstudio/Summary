void Pop(){
    if (Empty()) return;
    H[1]=H[size--];int now=1,lson,rson,mnson;
    while (now<=size){
        lson=now*2;rson=now*2+1;
        if (lson>size) break;
        if ((rson<=size)&&(H[lson]>H[rson])) mnson=rson;
        else mnson=lson;
        if (H[mnson]<H[now]){
            swap(H[mnson],H[now]);
            now=mnson;
        }
        else break;
    }
}
void Insert(int x)
{
    H[++size]=x;int now=size,fa=now/2;
    while (fa){
        if (H[fa]>H[now]){
            swap(H[fa],H[now]);
            now=fa;fa=now/2;
        }
        else break;
    }
    return;
}
