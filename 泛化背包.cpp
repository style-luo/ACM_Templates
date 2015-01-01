//泛化背包O(n*C)
#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
const int MAX=105;
vector<int>son[MAX];
struct
{
    int v,w;
}list[MAX];
int dp[MAX][MAX];
int n,m;
/*
1  PROCEDURE DEAL i , C
2   FOR s: = 1 TO n
3    IF s 是 i 的子节点 THEN
4     Fi → Fs
5     DEAL s , C – Vs            //背包容量减小Vs
6     FOR K: =Vs TO C            //求两者的并
7      Max ( Fi[ k ] , Fs[ k-Vs ] + Ws ) → Fi[ k ]
8     END FOR
9    END IF
10  END FOR
11 END
*/
int flag[MAX];
void dfs(int f)
{
	flag[f]=1;
    int i,j,k;
    int s;
    for(i=0;i<son[f].size();i++)
    {
        s=son[f][i];
		if(flag[s])continue;
        for(j=0;j<=m;j++)
            dp[s][j]=dp[f][j];
        dfs(s);
		flag[s]=0;
        for(k=list[s].v;k<=m;k++)
        {
            if(dp[s][k-list[s].v]+list[s].w>dp[f][k])
                dp[f][k]=dp[s][k-list[s].v]+list[s].w;
        }
    }
}
int main()
{
    dfs(root);
    int ans=0;
    for(i=0;i<=m-list[root].v;i++)
    {
        if(dp[root][i]+list[root].w>ans)
            ans=dp[root][i]+list[1].w;
    }
}

