
这里只记录一下最大，最小流求法，暂不写理论证明

1.新源S'给每个点加一条容量为《流入的下界总和》的边

2.新汇T'给每个点加一条容量为《流出的下界总和》的边。

若最小流:

求一次S'->T'最大流，T->S add inf 再求一次 S'->T'最大流

若满流，可行

T->S的流量为最小流，各边流量+下界为最小流各边实际流量

若最大流:

T->S add inf 求一次最大流

若满流，可行

去掉T->S的边（我感觉用sap应该不要去也可以？？待验证 (成功一次，理论上没问题)）

求S->T最大流，结果为最大流，各边流量+下界为最大流实际流量

 

ps:如果是无源无汇的话，直接求一次最大流就可以了
//zoj 2314 Reactor Cooling
/*
//上下界有源汇判可行流
add_edge(t,s,INF,0);
ans=SAP(ss,tt,tt+1);
if(sum!=ans)
	printf("impossible\n");
//上下界有源汇最小流
ans=SAP(ss,tt,tt+1);
add_edge(t,s,INF,0);
ans+=SAP(ss,tt,tt+1);
if(sum!=ans)
    printf("impossible\n");
else
    printf("%d\n",edge[E-1].c);
//上下界有源汇最大流
int ans=SAP(ss,tt,tt+1);
if(ans!=sum)
SAP(s,t,t+1);
max_flow+=残图;
*/
//上下界可行流
int N,M;
int ru[MAX];
int chu[MAX];
int imap[MAX][MAX];//保存原图
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




