#include<stdio.h>
#include<string.h>
const int INF=1000000000;
const int MAX=1000;
int map[MAX][MAX];
int dis[MAX],cur[MAX];
int pre[MAX],gap[MAX];
int min(int a,int b){return (a==-1||b<a)?b:a;}
int SAP(int s,int t,int n)
{
	memset(dis,0,sizeof(int)*n);
	memset(cur,0,sizeof(int)*n);
	memset(gap,0,sizeof(int)*n);
	int u=pre[s]=s,max_flow=0,aug=-1,v;
	gap[0]=n;
	while(dis[s]<n)
	{
loop:	for(v=cur[u];v<n;v++)
		{
			if(map[u][v]>0&&dis[u]==dis[v]+1)
			{
				aug=min(aug,map[u][v]);
				pre[v]=u;
				cur[u]=v;
				u=v;
				if(u==t)
				{
					for(u=pre[u];v!=s;v=u,u=pre[u])
					{
						map[u][v]-=aug;
						map[v][u]+=aug;
					}
					max_flow+=aug;
					aug=-1;
				}
				goto loop;
			}
		}
		int min_dis=n-1,v;
		for(v=0;v<n;v++)
		{
			if(map[u][v]>0&&dis[v]<min_dis)
			{
				cur[u]=v;
				min_dis=dis[v];
			}
		}
		if((--gap[dis[u]])==0)break;
		gap[dis[u]=min_dis+1]++;
		u=pre[u];
	}
	return max_flow;
}
int main(){
	memset(map,0,sizeof(map));
	//½¨Í¼ 
	SAP(0,999,1000);
	return 0;
}






