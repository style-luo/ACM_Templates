//PKU 2449 题解：求第 k 短路，dijkstra(堆优化)+ A* 搜索
#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
using namespace std;
const int maxn =1005;
const int INF=0x7ffffff;
int  S, T, K, dis[maxn];

struct node 
{
    int e, d;
    node(int e, int d) : e(e), d(d) {}
   bool operator<(const node b) const 
	{
        return d + dis[e] > b.d + dis[b.e]; //这里是对估价函数的使用，使得路径最短的先出队
    }
};

vector<node> map[maxn],fmap[maxn]; // 图的邻接表表示（正反图） 

void dijkstra(int s,int n,vector<node> map[maxn]) //求所有点到终点的最短路径
{
    int i, u, mark[maxn];
    for (i = 1; i <= n; i++)
		dis[i] = INF,mark[i]=0;
    priority_queue<node> heap;
    dis[s] = 0;
    heap.push(node(s, 0));
    while (!heap.empty()) 
	{
        u = heap.top().e;
        heap.pop();
        if (mark[u])continue;
        mark[u] = 1;
        for (i = 0; i < map[u].size(); i++)
		{
			int v=map[u][i].e; 
			int d=map[u][i].d;
            if (!mark[v] && dis[u] + d< dis[v]) 
			{
                dis[v] = dis[u] + d;
                heap.push(node(v, dis[v]));
            }
		}
    }
}
int A_star() //A*搜索
{
    int u, i, len, c[maxn];
    if (dis[S] == INF)return -1;
    priority_queue<node> heap;
    memset(c, 0, sizeof c);
    heap.push(node(S, 0));
    while (!heap.empty()) 
	{
        u = heap.top().e;
        len = heap.top().d;
        heap.pop();
        c[u]++;
        if (c[T] == K)return len;
        if (c[u] > K)continue;
        for (i = 0; i < map[u].size(); i++)
            heap.push(node(map[u][i].e, len +map[u][i].d));
    }
    return -1;
}
int main() {
    int i, u, v, w;
	int n,m;
    while (scanf("%d %d", &n, &m) != EOF) 
	{
		for(i=0;i<n;i++)map[i].clear(),fmap[i].clear();
        for (i = 0; i < m; i++) 
		{
			scanf("%d%d%d",&u,&v,&w);
            map[u].push_back(node(v, w));
            fmap[v].push_back(node(u, w));
        }
		scanf("%d%d%d",&S,&T,&K);
        if (S==T) K++;  /* 如果 s==t ，那么就是求 k+1 短路 */
        dijkstra(T,n,fmap);
        printf("%d\n", A_star());
    }
    return 0;
}
