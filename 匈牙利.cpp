（二分匹配）匈牙利
#define N 100005
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int n,m;
vector<int>edge[66];
int pre[N];
bool used[N];
bool dfs(int u)
{
	int i;
	for(i=0;i<edge[u].size();i++)
		if(!used[edge[u][i]])
		{
			used[edge[u][i]]=1;
			if(pre[edge[u][i]]==-1||dfs(pre[edge[u][i]]))
			{
				pre[edge[u][i]]=u;
				return 1;
			}
		}
		return 0;
}
//特别是要输出字典最大（小）
int main()
{
		memset(pre,-1,sizeof(pre));
		int cnt=0;
		for(i=n;i>=1;i--)
		{
			memset(used,0,sizeof(bool)*max);
	if(dfs(i))
				cnt++;
		}
	return 0；
}

