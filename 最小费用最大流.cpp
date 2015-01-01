#include<stdio.h>
#include<string.h>
const int MAX=5100;
const int INF=1000000000;
const int MOD=1000000;
struct EDGE
{
	int cap,cost,v,next;
}edge[MOD];
int head[MAX],E,q[MOD];
bool used[MAX];
int pre[MAX],cur[MAX],dis[MAX];
void add_edge(int s,int t,int cap,int cost)
{
	edge[E].cap=cap;
	edge[E].cost=cost;
	edge[E].next=head[s];
	edge[E].v=t;
	head[s]=E++;
	edge[E].cap=0;
	edge[E].cost=-cost;
	edge[E].next=head[t];
	edge[E].v=s;
	head[t]=E++;
}
int min(int a,int b){return (a==-1||b<a)?b:a;}
int SPFA(int s,int t,int n)
{
	int f=-1,r=0;
	int i,v;
	q[r]=s;
	for(i=0;i<n;i++)
		 dis[i]=INF;
 	dis[s]=0;
	pre[s]=s;
	cur[s]=-1;
	memset(used,false,sizeof(bool)*n);
	used[s]=true;
	while(f!=r)
	{
		f++;
		if(f>=MOD)f-=MOD;
		s=q[f];
		used[s]=false;
		for(i=head[s];i!=-1;i=edge[i].next)
		{
			v=edge[i].v;
			if(edge[i].cap>0&&dis[s]+edge[i].cost<dis[v])
			{
				dis[v]=dis[s]+edge[i].cost;
				pre[v]=s;
				cur[v]=i;
				if(!used[v])
				{
					used[v]=true;
					r++;
					if(r>=MOD)r-=MOD;
					q[r]=v;
				}
			}
		}
	}
	return dis[t];
}
int MinCost(int s,int t,int n)
{
	int ans=0;
	int u,v,cap;
	int cost;
	while(1)
	{
		cost=SPFA(s,t,n);
		if(cost==INF)break;
		u=v=t;
		cap=-1;
		for(u=t;u!=s;u=pre[u])
		{
			cap=min(cap,edge[cur[u]].cap);
		}
		ans+=cost*cap;
		u=v=t;
		for(u=t;u!=s;u=pre[u])
		{
			edge[cur[u]].cap-=cap;
			edge[cur[u]^1].cap+=cap;
		}
	}
	return ans;
}
int main()
{
	int s=;
	int t=;
	E=0;
	memset(head,-1,sizeof(int)*(t+1));
}




