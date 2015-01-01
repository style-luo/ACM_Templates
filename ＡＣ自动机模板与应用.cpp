#include <stdio.h>
#include<string.h>
const int INF=1000000000;
int const MAXN= 10005;
struct Trie
{
    int flag; // 标记是否为某一模式串的结尾
    int fail; // 失败指针
    int next[26];
    void init()
    {
        flag= 0; fail=0;
        for( int i= 0; i< 26; ++i ) next[i]= 0;
    }
}tb[1000000];
int tot= 0, q[1000000], n;
char a[100001],b[10005];
void  insert( char s[] )
{
    int rt= 0;
    int i=0;
    while(s[i])
    {
        int t= s[i]- 'a';
        if( !tb[rt].next[t] )
        {
            tb[++tot].init();
            tb[rt].next[t]= tot;
        }
        rt=tb[rt].next[t];i++;
    }
    tb[rt].flag++;
}
void get_fail()
{
    int h=0,i;
    int f=-1,r=0;
    int now,fail,son;
    q[0]=0;
    while(f!=r)
    {
        now=q[++f];
        for(i=0;i<26;i++)
        { 
            if(tb[now].next[i]==0)
            {
                fail=tb[now].fail;
                tb[now].next[i]=tb[fail].next[i];
                continue;
            }
            son=tb[now].next[i];
            fail=tb[now].fail;
            if(tb[fail].next[i]!=son)
				tb[son].fail=tb[fail].next[i];
			else
				tb[son].fail=0;
            q[++r]=son;
        }
    }
}
int dp[2][MAXN];
int main()
{
    int n,m,T;
    int i,j;
    scanf("%d",&T);
    while(T--)
    {
		tot=0;
        tb[tot].init();
        scanf("%s%s",a,b);
        n=strlen(a);
        m=strlen(b);
        insert(b);
        get_fail();
        int tag=0;
        for(i=0;i<=tot;i++)
            dp[tag][i]=INF;
        dp[tag][0]=0;
        int tmp,cha;
        for(i=0;i<n;i++)
        {
            cha=a[i]-'a';
            tag=i&1;
            for(j=0;j<=tot;j++)
                dp[tag^1][j]=dp[tag][j]+1;
            for(j=0;j<tot;j++)
            {
                tmp=tb[j].next[cha];
                if(tmp!=tot&&dp[tag][j]<dp[tag^1][tmp])
                    dp[tag^1][tmp]=dp[tag][j];
            }
        }
        int ans=INF;
        tag^=1;
        for(i=0;i<tot;i++)
            if(dp[tag][i]<ans)
                ans=dp[tag][i];
        printf("%d\n",ans);
    }
    return 0;
}


