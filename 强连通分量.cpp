//强连通分量
#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX=5005;
vector<int >edge[MAX];
int st[MAX];
int dfn[MAX],low[MAX];
int Top,Btype,Time;
int Belong[MAX];
bool ins[MAX];
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
	return ;
}int chu[MAX];
int cnt[MAX];
bool mk[MAX];
int main()
{
		for(i=0;i<=n;i++)edge[i].clear();
}
