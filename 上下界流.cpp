
����ֻ��¼һ�������С���󷨣��ݲ�д����֤��

1.��ԴS'��ÿ�����һ������Ϊ��������½��ܺ͡��ı�

2.�»�T'��ÿ�����һ������Ϊ���������½��ܺ͡��ıߡ�

����С��:

��һ��S'->T'�������T->S add inf ����һ�� S'->T'�����

������������

T->S������Ϊ��С������������+�½�Ϊ��С������ʵ������

�������:

T->S add inf ��һ�������

������������

ȥ��T->S�ıߣ��Ҹо���sapӦ�ò�ҪȥҲ���ԣ�������֤ (�ɹ�һ�Σ�������û����)��

��S->T����������Ϊ���������������+�½�Ϊ�����ʵ������

 

ps:�������Դ�޻�Ļ���ֱ����һ��������Ϳ�����
//zoj 2314 Reactor Cooling
/*
//���½���Դ���п�����
add_edge(t,s,INF,0);
ans=SAP(ss,tt,tt+1);
if(sum!=ans)
	printf("impossible\n");
//���½���Դ����С��
ans=SAP(ss,tt,tt+1);
add_edge(t,s,INF,0);
ans+=SAP(ss,tt,tt+1);
if(sum!=ans)
    printf("impossible\n");
else
    printf("%d\n",edge[E-1].c);
//���½���Դ�������
int ans=SAP(ss,tt,tt+1);
if(ans!=sum)
SAP(s,t,t+1);
max_flow+=��ͼ;
*/
//���½������
int N,M;
int ru[MAX];
int chu[MAX];
int imap[MAX][MAX];//����ԭͼ
struct
{
	int a,b;
	int l;
}edge[MAX*MAX];
int main()
{
	int ca;
	int tot;
	int i,j;
	int a,b,c,d;
	scanf("%d",&ca);
	while(ca--)
	{
		tot=0;
		scanf("%d%d",&N,&M);
		for(i=0;i<=N+1;i++)
		for(j=0;j<=N+1;j++)
			map[i][j]=0;
		memset(ru,0,sizeof(int)*(N+5));
		memset(chu,0,sizeof(int)*(N+5));
		for(i=0;i<M;i++)
		{
			scanf("%d%d%d%d",&a,&b,&c,&d);
			chu[a]+=c;
			ru[b]+=c;
			edge[tot].a=a;
			edge[tot].l=c;
			edge[tot++].b=b;
			map[a][b]=d-c;
		}
		for(i=0;i<=N;i++)
			for(j=0;j<=N;j++)
				imap[i][j]=map[i][j];
		int s=0;
		int t=N+1;
		int sum=0;
		for(i=1;i<=N;i++)
		{
			int d=ru[i]-chu[i];
			if(d>0)
			{
				map[s][i]=d;
				sum+=d;
			}
			else
				map[i][t]=-d;
		}
		int ans=SAP(s,t,t+1);
		if(ans==sum)
		{
			printf("YES\n");
			for(i=0;i<tot;i++)
			{
				a=edge[i].a;
				b=edge[i].b;
				printf("%d\n",edge[i].l+imap[a][b]-map[a][b]);
			}
		}
		else
			printf("NO\n");
	}
	return 0;
}




