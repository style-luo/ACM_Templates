//无向图最小环
#include<stdio.h>
#include<string.h>
const int maxn=105;
int map[maxn][maxn];
int in[maxn][maxn];
const int INF=100000000;
int pre[maxn][maxn];
int path[maxn];
int len;
void getpath(int i,int j)
{
	if(pre[i][j]!=-1)
		getpath(i, pre[i][j]);
	path[len++] = j;
}
int solve(int n)
{
	int i,j,k;
	int ret=INF;
	for(k=1;k<=n;k++)
	{
		for(i=1;i<k;i++)
			for(j=i+1;j<k;j++)
				if(ret>map[i][j]+in[i][k]+in[k][j])
				{
					ret=map[i][j]+in[i][k]+in[k][j];
					len=0;
					getpath(i,j);
					path[len++]=k;
				}
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
			{
				if(map[i][k]+map[k][j]<map[i][j])
				{
					map[i][j]=map[i][k]+map[k][j];
					pre[i][j]=pre[k][j];
				}
			}
	}
	return ret;
}
int main()
{
	int n,m;
	int i,j,k;
	int a,b,c;
	while(scanf("%d%d",&n,&m)!=-1)
	{
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=n;j++)
			{
				map[i][j]=INF;
				pre[i][j]=-1;
			}
			map[i][i]=0;
		}
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			if(c<map[a][b])
			{
				map[a][b]=map[b][a]=c;
				pre[a][b]=a;
				pre[b][a]=b;
			}
		}
		memcpy(in,map,sizeof(map));
		int ans=solve(n);
		if(ans==INF) printf("No solution.\n");
		else
		{
			for(i=0;i<len;i++)
			printf("%d ",path[i]);
			puts("");
		}
	}
	return 0;
}


