#include<stdio.h>
#include<string.h>
struct
{
    int num,w,p;
}list[105];
struct
{
    int v,c;
}q[100005];
int dp[105];
int f,r;
int main()
{
    int c,n;
    int i,j,k;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&c,&n);
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++)    
        {
            scanf("%d%d%d",&list[i].p,&list[i].w,&list[i].num);
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<list[i].p;j++)
            {
                f=0;r=-1;
                for(k=0;k<=(c-j)/list[i].p;k++)
                {
                    int b=dp[k*list[i].p+j]-k*list[i].w;
                    while(f<=r&&q[r].v<=b)
                        r--;    
                    r=r+1;
                    q[r].c=k;
                    q[r].v=b;
                    if(q[f].c<k-list[i].num)f++;
                    dp[k*list[i].p+j]=q[f].v+k*list[i].w;        
                }
            }
        }
        int ans=-1;
        for(i=0;i<=c;i++)
        {
            if(dp[i]>ans)
            {
                ans=dp[i];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

