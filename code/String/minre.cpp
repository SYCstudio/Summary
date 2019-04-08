int i=1,j=2,k=0,d;
while ((i<=len)&&(j<=len)&&(k<len)){
    d=str[(i+k-1)%len+1]-str[(j+k-1)%len+1];
    if (d==0) k++;
    else{
        if (d>0) i+=k+1;
        else j+=k+1;
        k=0;
        if (i==j) j++;
    }
}
