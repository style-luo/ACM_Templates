//最小（V0）K限度生成树poj1639
#include<stdio.h>
#include<string.h>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
map<string,int>MAP;
const int INF=1000000000;
const int maxn=25;
struct EDGE
{
	int s,t,w;
	int flag,next,idx;
	bool operator<(EDGE y)const 
	{ return w<y.w; }
}list[maxn * maxn],item[maxn],edge[maxn * maxn];
//list为kursker的所用的边，item为与V0相关的边集，edge为原图
int head[maxn];
int fa[maxn];
int flag[maxn];
int tot,V0,V0n,totN;
void add_edge(int s,int t,int w)
{
	list[tot].s = s;
	list[tot].t = t;
	list[tot].w = w;
	list[tot].flag = 0;
	list[tot].idx = tot;
	edge[tot]=list[tot];
	edge[tot].next =head[s];
	head[s]=tot ++;
}

int findfa(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=findfa(fa[x]);
}
bool Union(int x,int y)
{
	x=findfa(x);y=findfa(y);
	if(x!=y)
	{
		fa[x]=y;
		return 1;
	}
	return 0;
}
int dfs(int s,int pre,int e) 
{
	int i,t;
	int j=e,max=pre;
	flag[s] = 1;
	for(i =head[s];i != -1;i= edge[i].next )
	{
		t=edge[i].t;
		if(edge[i].flag && !flag[t])
		{	
			j=e,max=pre;	
			if(t == V0) return e;
			if(edge[i].w>max)
				j=i,max=edge[i].w;
			j = dfs(t,max,j);
			if( j != -1 ) return j;
			flag[t] = 0;
		}
	}
	return -1;
}
int KMST(int k)
{
	int res,ans,tmp;
	int i,j,count=0;
	for(j =head[V0],i = 0;j != -1; j = edge[j].next,i ++) item[i] = edge[j];
	V0n = i;
	sort(list,list+tot);
	for(res = i = 0; i < tot;i ++)
	{
		if(list[i].s == V0 || list[i].t == V0) continue;
		if(Union(list[i].s,list[i].t))
		{
			edge[ list[i].idx ].flag  = 1;
			edge[ list[i].idx^1 ].flag  = 1;
			res += list[i].w;
		}
	}
	sort(item,item+V0n);
	for(i = 0;i< V0n;i ++)
	{
		if(	Union(item[i].s,item[i].t))
		{
			edge[item[i].idx].flag = 1;
			edge[ item[i].idx^1 ].flag  = 1;
			res += item[i].w;
			count ++;
		}
	}
	ans = res;
	while(count < k)
	{
		int min = INF;
		int midi,maxe;
		for(i =head[V0];i != -1;i = edge[i].next )
		{
			if(edge[i].flag == 0)
			{
				memset(flag,0,sizeof(flag));
				tmp = dfs(edge[i].t,-INF,i);
				if(res - edge[tmp].w + edge[i].w < min)
				{
					min = res - edge[tmp].w + edge[i].w;
					midi = i;
					maxe = tmp;
				}
			}
		}
		if(min == INF) break;
		edge[midi].flag = 1;
		edge[midi^1].flag = 1;
		edge[maxe].flag = 0;
		edge[maxe^1].flag = 0;
		res = min;
		if(res < ans)ans = res;
		count ++;
	}
	return ans;
}
char str1[maxn],str2[maxn];
int main()
{
	int i,k;
	int n; EDGE e;
	while(scanf("%d",&n)!=-1)
	{
		tot=0;
		for(i=0;i<maxn;i++)
		fa[i]=i,head[i]=-1;
		totN=0;
		MAP.clear();
		for(i=0;i<n;i++)
		{
			scanf("%s%s%d",str1,str2,&e.w);
			if(!(e.s=MAP[str1]))e.s=MAP[str1]=++totN;
			if(!(e.t=MAP[str2]))e.t=MAP[str2]=++totN;
			add_edge(e.s,e.t,e.w);
			add_edge(e.t,e.s,e.w);
		}
		scanf("%d",&k);
		V0 = MAP["Park"];
		int ans=KMST(k);
		printf("Total miles driven: %d\n",ans);
	}
	return 0;
}