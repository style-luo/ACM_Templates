const int MAX=2;
struct PP
{
	int arcs[MAX][MAX];
}
PP add (PP a,PP b)  //矩阵加法
{
    PP c;
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            c.arcs[i][j]=a.arcs[i][j]+b.arcs[i][j];
            c.arcs[i][j]%=m;   //加的时候也要%m
        }
    return c;
}
PP Mul(PP a,PP b)  //矩阵乘法
{
    PP c;
    int i,j,k;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            c.arcs[i][j]=0;  //初始化矩阵c
            for(k=0;k<n;k++)
                c.arcs[i][j]+=a.arcs[i][k]*b.arcs[k][j];
            c.arcs[i][j]%=m;  //计算乘法的时候也要%m
        }
    return c;
}
PP Cal(int i)   //矩阵幂
{
    PP p,q;
    p=a;  //p是初始矩阵
    q=e ;  //q是单位矩阵
    while(i)
    {
        if(i&1)  //要求得幂是奇数
            q=Mul(q,p);
            p=Mul(p,p);
		i>>=1;
    }
    return q;
}
