//字典树+AC自动机（trie 图）
#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
const int maxn=250005;//节点数，状态数
const int N=27;
struct Tire           //字典树
{
    int flag,fail;
    int next[N];
    void init()
    {
        flag=0;fail=0;
        for(int i=0;i<N;i++)
            next[i]=0;
    }
}tb[maxn];
int tot;

void insert(char s[],int flag)
{
    int rt=0;
    for(int i=0;s[i];i++)
    {
        int t=s[i]-'A';
        if(!tb[rt].next[t])
        {
            tb[++tot].init();
            tb[rt].next[t]=tot;
        }
        rt=tb[rt].next[t];
    }
    tb[rt].flag=flag;
}

queue<int>q;
void get_fail()       //获得失败指针
{
    int h=0,i;
    int now,fail,son;
    while(!q.empty())q.pop();
    q.push(0);
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        for(i=0;i<N;i++)
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
            else tb[son].fail=0;
            q.push(son);
        }
    }
}

void workfail()  //匹配串中包含关系
{
	int i,p;
	int sum;
	for(i=1;i<=tot;i++)
	{
		sum=0;
		p=tb[i].fail;
		while(p!=0)
		{
			sum+=tb[p].flag;
			p=tb[p].fail;
		}
		tb[i].flag+=sum;
	}
}

void Match( char s[],int idx)//匹配功能
{
    int rt=0,t;
    for(int i=0;s[i];i++)
    {
        t= s[i]-'A';
        rt= tb[rt].next[t];
        if(tb[rt].flag){;}
    }
}

int main()
{
	tot=0;
	tb[0].init();
	//scanf("%s",str);
	//insert(str,idx);
	get_fail();//不要忘记
	workfail();
	//	solve();
	return 0;
}


