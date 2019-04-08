for (int i=1;i<=n;i++){
    int j=i;
    while (fabs(Mat[j][i])<eps) j++;
    for (int k=1;k<=n+1;k++) swap(Mat[j][k],Mat[i][k]);
    ld d=(ld)1.0/Mat[i][i];
    for (int k=1;k<=n+1;k++) Mat[i][k]*=d;
    for (int k=1;k<=n;k++)
	if ((i!=k)&&(fabs(Mat[k][i])>eps)){
	    d=Mat[k][i]/Mat[i][i];
	    for (int l=1;l<=n+1;l++) Mat[k][l]=Mat[k][l]-Mat[i][l]*d;
	}
}
