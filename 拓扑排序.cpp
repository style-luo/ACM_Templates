//zstu 1482
#include<stdio.h>
#include<string.h>
const int MAXN=27;
int c[MAXN];
int n,m;
int map[MAXN][MAXN];
int topo[MAXN],t;
char tmp[100000][5];
bool dfs(int u)
{
    c[u]=-1;
    for(int v=0;v<n;v++)if(map[u][v])
    {
        if(c[v]<0)return false;
        else if(!c[v]&&!dfs(v))return false;
    }
    c[u]=1;
    topo[--t]=u;
    return 1;
}
bool toposort()
{
    t=n;
    memset(c,0,sizeof(c));
    for(int u=0;u<n;u++)if(!c[u])
        if(!dfs(u))return 0;
    return true;
}
bool check()
{
    if(t>0)return  0;
    for(int i=0;i<n-1;i++)
    {
        if(!map[topo[i]][topo[i+1]])return 0;
    }

    return 1;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=-1)
    {
        if(n==0&&m==0)break;
        memset(map,0,sizeof(map));
        for(int i=0;i<m;i++)
            scanf("%s",tmp[i]);
        for(int i=0;i<m;i++)
        {
            int a=tmp[i][0]-'A';
            int b=tmp[i][2]-'A';
            if(tmp[i][1]=='<')
            {
                map[a][b]=1;
            }
            else
            {
                map[b][a]=1;
            }
            int flag=toposort();
            int mk=check();
            if(!flag)
            {
                printf("Inconsistency found after %d relations.\n",i+1);
                break;
            }
            else
            {
                if(mk)
                {
                    printf("Sorted sequence determined after %d relations: ",i+1);
                    for(int j=0;j<n;j++)
                    {
                        printf("%c",topo[j]+'A');
                    }
                    printf(".\n");
                    break;
                }
                else if(i==m-1)
                {
                    printf("Sorted sequence cannot be determined.\n");
                    break;
                }
            }
            
        }
    }
    return 0;
}


