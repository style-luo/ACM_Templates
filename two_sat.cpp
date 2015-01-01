//two¡ªsat
#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX=32005;
vector<int >edge[MAX];
int st[MAX];
int dfn[MAX],low[MAX];
int Top,Btype,Time;
int Belong [MAX];
bool ins [MAX];
void tarjan(int s)
{
	int i,t;
	dfn[s]=low[s]=++Time;
	ins[s]=true;
	st[++Top]=s;
	for (i=0;i<edge[s].size();i++)
	{
		t=edge[s][i];
		if (!dfn[t])
		{
			tarjan(t);
			if (low[t]<low[s])
				low[s]=low[t];
		}
		else if (ins[t] && dfn[t]<low[s])
			low[s]=dfn[t];
	}
	if (dfn[s]==low[s])
	{
		Btype++;
		do
		{
			t=st[Top--];
			ins[t]=false;
			Belong[t]=Btype;
		}
		while (t!=s);
	}
}
void SCC(int n)
{
	int i;
	Top=Btype=Time=0;
	memset(ins,0,sizeof(bool)*(n+1));
	memset(dfn,0,sizeof(int)*(n+1));
	for (i=1;i<=n;i++)
		if (!dfn[i])
			tarjan(i);
}
vector<int>map[MAX];

int c[MAX];
int topo[MAX];
int T;
bool dfs(int u)
{
	c[u]=-1;
	int v,i;
	for(i=0;i<map[u].size();i++)
	{
		v=map[u][i];
		if(c[v]<0)return false;
		else if(!c[v]&&!dfs(v))return false;
	}
	c[u]=1;
	topo[--T]=u;
	return 1;
}
bool topsort(int n)
{
	T=n;
	memset(c,0,sizeof(int)*(n+1));
	for(int i=1;i<=n;i++)if(!c[i])
		if(!dfs(i))return 0;
		return true;
}

int N;
int flag[MAX];

void color(int u)
{
	flag[u]=2;
	for(int i=0;i<map[u].size();i++)
	{
		int v=map[u][i];
		if(flag[v])continue;
		color(v);
	}
}
int ff(int a)
{
	if(a%2)
		return a+1;
	return a-1;
}

int main()
{
	int n,m;
	int i,j;
	int u,v;
	while(scanf("%d%d",&n,&m)!=-1)
	{
		N=n+n;
		for(i=0;i<=N;i++)
		{
			edge[i].clear();
			map[i].clear();
		}
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&u,&v);
			edge[u].push_back(ff(v));
			edge[v].push_back(ff(u));
		}
		SCC(N);
		for(i=1;i<=N;i+=2)
		{
			if(Belong[i]==Belong[i+1])
				break;
		}
		if(i<=N)
		{
			printf("NIE\n");
			continue;
		}
		for(i=1;i<=N;i++)
		{
			for(j=0;j<edge[i].size();j++)
			{
				u=i;
				v=edge[i][j];
				if(Belong[u]!=Belong[v])
				{
					map[Belong[v]].push_back(Belong[u]);
				}
			}
		}
		topsort(Btype);
		memset(flag,0,sizeof(int)*(Btype+1));
		for(i=0;i<Btype;i++)
		{
			u=topo[i];
			if (flag[u]) continue;
			flag[u]=1;
			for (j = 1; j <= N; j++) {
				if (Belong[j] != u) continue;
				int t = Belong[ff(j)];
				if (flag[t]) continue;
				color (t);
			}
		}
		for(i=1;i<=N;i++)
			if(flag[Belong[i]]==1)
				printf("%d\n",i);
	}
	return 0;
}

