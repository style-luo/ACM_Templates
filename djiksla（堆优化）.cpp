#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
#include<stdio.h>
using namespace std;
struct PP
{
    int id;
    int dis;
    PP(int v = 0, int d = 0): id(v), dis(d){};
    bool operator<(const PP&a)const
    {
        return dis>a.dis;
    }
};
priority_queue <PP> q;
bool flag[MAXN];
int dis[MAXN];
int ok;
void dijkstra(int st)
{
    while(!q.empty())q.pop();
    int i,k;
    for(i=0;i<=n;i++){
        dis[i]=INF;
        flag[i]=0;        
    }
    dis[st]=0;
    q.push(PP(st,dis[st]));
    for (i =1;i<n;++i) 
    {
        do{
            if(q.empty())
            {
                ok=1;
                break;
            }
            k=q.top().id;
            q.pop();
        }while (flag[k]);//¿ÉÄÜ¶ÑÎª¿Õ 
        if(ok)break;
        flag[k]=1;
		getnext(k, dis[k]);
    } 
}


