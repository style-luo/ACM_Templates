//邻接表
#include<stdio.h>
#include<string.h>
const int MAX=100005;
const int INF=1000000000;

struct
{
	int v,c,next;
}edge[1000000];
int E,head[MAX];
int gap[MAX],cur[MAX];
int pre[MAX],dis[MAX];
void add_edge(int s,int t,int c,int cc)
{ //加了反向边 
	edge[E].v=t; edge[E].c=c;
	edge[E].next=head[s];
	head[s]=E++;
	edge[E].v=s; edge[E].c=cc;
	edge[E].next=head[t];
	head[t]=E++;
}
int min(int a,int b){return (a==-1||b<a)?b:a;}
int SAP(int s,int t,int n)
{
	memset(gap,0,sizeof(gap));
	gap[0]=n;
	memset(dis,0,sizeof(dis));
	int i;
	for(i=0;i<n;i++)cur[i]=head[i];
	int u=pre[s]=s,max_flow=0,aug=-1,v;
	while(dis[s]<n)
	{
loop:	for(i=cur[u];i!=-1;i=edge[i].next)
		{
			v=edge[i].v;
			if(edge[i].c>0&&dis[u]==dis[v]+1)
			{
				aug=min(aug,edge[i].c);
				pre[v]=u;
				cur[u]=i;
				u=v;
				if(u==t)
				{
					for(u=pre[u];v!=s;v=u,u=pre[u])
					{
						edge[cur[u]].c-=aug;
						edge[cur[u]^1].c+=aug;
					}
					max_flow+=aug;
					aug=-1;
				}
				goto loop;
			}
		}
		int _min=n;
		for(i=head[u];i!=-1;i=edge[i].next)
		{
			v=edge[i].v;
			if(edge[i].c>0&&dis[v]<_min)
			{
				cur[u]=i;
				_min=dis[v];
			}
		}
		if((--gap[dis[u]])==0)break;
		gap[dis[u]=_min+1]++;
		u=pre[u];
	}
	return max_flow;
}
int main()
{
	memset(head,-1,sizeof(head));
	E=0;
	//建图 
	SAP(0,9999,10000);
	return 0;
}

