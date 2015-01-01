//无向图的最小割
#include<stdio.h>
#include<string.h>
const int INF=1000000000;
const int MAX=510;
int map[MAX][MAX],n,D[MAX];
bool vis[MAX],flag[MAX];
int Stoer_Wagner(int n)//坐标从0---n-1开始，求无向图的最小割O（n^3）
{
	int ans,s,t,k,i,tmp,pre,j;
	ans=INF; s=0;
	memset(flag,0,sizeof(bool)*n);
	for(t=1;t<n;t++)
	{
		for(i=0;i<n;i++)
			if(!flag[i])
				D[i]=map[s][i];
		memset(vis,0,sizeof(bool)*n);
		vis[s]=1;
		k=s;
		for(i=0;i<n-t;i++)
		{
			tmp=-1;
			pre=k;
			for(j=0;j<n;j++)if(!vis[j]&&!flag[j]&&tmp<D[j])
			{
				k=j;
				tmp=D[j];
			}
			if(tmp==-1)
				return 0;
			vis[k]=1;
			for(j=0;j<n;j++)
				if(!vis[j]&&!flag[j])
					D[j]+=map[k][j];
		}
		if(ans>D[k])
			ans=D[k];
		flag[k]=1;
		for(i=0;i<n;i++)
			if(!flag[i]&&i!=pre)
			{
				map[pre][i]+=map[k][i];
				map[i][pre]=map[pre][i];
			}
	}
	return ans;
}
int main(){
	int n,m,a,b,c;
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(map,0,sizeof(map));
		while(m--)
		{
			scanf("%d%d%d",&a,&b,&c);
			map[a][b]+=c;
			map[b][a]+=c;
		}
		printf("%d\n",Stoer_Wagner(n));
	}
	return 0;
}
