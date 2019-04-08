Next[0]=Next[1]=0;
for (int i=2,j=0;i<=len;i++){
    while ((j!=0)&&(s[j+1]!=s[i])) j=Next[j];
    if (s[j+1]==s[i]) j++;
    Next[i]=j;
}
