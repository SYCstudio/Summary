class Auto
{
public:
    int last[maxAlpha],fa[maxN];
    int nodecnt,trans[maxN][maxAlpha];
    Auto(){
        nodecnt=1;for (int i=0;i<maxAlpha;i++) last[i]=1;return;
    }
    void Insert(int c){
        fa[++nodecnt]=last[c];
        for (int i=0;i<maxAlpha;i++)
            for (int j=last[i];(j!=0)&&(trans[j][c]==0);j=fa[j])
                trans[j][c]=nodecnt;
        last[c]=nodecnt;return;
    }
};
