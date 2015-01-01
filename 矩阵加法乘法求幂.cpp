const int MAX=2;
struct PP
{
	int arcs[MAX][MAX];
}
PP add (PP a,PP b)  //����ӷ�
{
    PP c;
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            c.arcs[i][j]=a.arcs[i][j]+b.arcs[i][j];
            c.arcs[i][j]%=m;   //�ӵ�ʱ��ҲҪ%m
        }
    return c;
}
PP Mul(PP a,PP b)  //����˷�
{
    PP c;
    int i,j,k;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            c.arcs[i][j]=0;  //��ʼ������c
            for(k=0;k<n;k++)
                c.arcs[i][j]+=a.arcs[i][k]*b.arcs[k][j];
            c.arcs[i][j]%=m;  //����˷���ʱ��ҲҪ%m
        }
    return c;
}
PP Cal(int i)   //������
{
    PP p,q;
    p=a;  //p�ǳ�ʼ����
    q=e ;  //q�ǵ�λ����
    while(i)
    {
        if(i&1)  //Ҫ�����������
            q=Mul(q,p);
            p=Mul(p,p);
		i>>=1;
    }
    return q;
}
