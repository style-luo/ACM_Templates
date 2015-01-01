#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int MAXN=30005;
const int MAXM=2;
char str[30005];
struct PP
{
	int son,deep;
}d[MAXM][MAXN];
bool cmp(PP a ,PP b)
{
	if(a.deep==b.deep)return a.son<b.son;
	return a.deep<b.deep;
}
int now[MAXN];
int f[MAXN];
int main()
{
	int t;
	int i,j,k;
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<MAXM;i++)
		{
			scanf("%s",str);
			f[1]=now[i]=j=1;
			d[i][1].deep=d[i][1].son=0;
			for(k=0;str[k];k++)
			{
				if(str[k]=='0')
				{
					f[++now[i]]=j;
					d[i][now[i]].deep=d[i][j].deep+1;
					d[i][now[i]].son=0;
					d[i][j].son++;
					j=now[i];
				}
				else
				{
					j=f[j];
				}
			}
			for(j=now[i];j>1;j--)
			{
				d[i][f[j]].deep+=d[i][j].deep;
			}
		}
		for(i=1;i<MAXM;i++)
		{
			if(now[i]!=now[0])
				break;
		}
		if(i<MAXM)
		{
			printf("different\n");
			continue;
		}
		for(i=0;i<MAXM;i++)
		{
			sort(d[i]+1,d[i]+now[i]+1,cmp);
		}
		for(i=1;i<MAXM;i++)
		{
			for(j=0;j<=now[0];j++)
			{
				if(d[i][j].deep!=d[0][j].deep||d[i][j].son!=d[0][j].son)
				break;
			}
			if(j<=now[0])break;
		}
		if(i<MAXM)
		{
			printf("different\n");
		}
		else
		{
			printf("same\n");
		}
	}
	return 0;
}

