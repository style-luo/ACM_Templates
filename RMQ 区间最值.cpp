#include<stdio.h>
#include<string.h>
const int maxn=2000005;
int num[maxn];
int LOG[maxn];
int dp[maxn][17];//log(maxn)+1;
int n;
void rmq_init(int n)
{
    int i,j;
    for(j=1;j<=n;j++) 
    {
        dp[j][0]=num[j];
    }
    int m=LOG[n];
    for(j=1;j<=m;j++)
    {
         for(i=1;i+(1<<j)<=n+1;i++)
         {
         	int x=i+(1<<j>>1);
            dp[i][j]=dp[x][j-1]>dp[i][j-1]?dp[x][j-1]:dp[i][j-1];
         }
    }
}
int  rmq(int l,int r)
{
    int m=LOG[r-l+1];
    return dp[l][m]>dp[r-(1<<m)+1][m]?dp[l][m]:dp[r-(1<<m)+1][m];
}
int main()
{
    int i,j,k;
    LOG[0]=-1;
    for(i=1;i<=200005;i++)
    {
        LOG[i]=LOG[i-1];
        if((i&(i-1))==0)
            LOG[i]++;    
    }
    rmq_init(n);//预处理O(nlog(n )) ;
    sum+=rmq(l,r); //闭区间   
    return 0;
}
