int pos=0,mxR=0;
for (int i=1;i<=len+len;i++){
    if (i<mxR) P[i]=min(P[pos*2-i],mxR-i);
    else P[i]=1;
    while (Input[i-P[i]]==Input[i+P[i]]) P[i]++;
    if (i+P[i]>mxR){
	mxR=i+P[i];pos=i;
    }
}
