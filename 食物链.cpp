//Ê³ÎïÁ´
#include<stdio.h>
int father[60000];
int rank[60000];
void init(int i)
{
	father[i]=-1;
	rank[i]=0;
}
int find(int i)
{
	if(father[i]==-1)
	 return i;
 	int t=father[i];
 	father[i]=find(t);
 	rank[i]=(rank[i]+rank[t])%3;
	return father[i];
}
void unionone (int a,int b,int d)
{
	int ra=find(a);
	int rb=find(b);
	father[ra]=rb;
	rank[ra]=(rank[b]-rank[a]+d)%3;
}
int main()
{
	int n,m,i,x,y,d,rx,ry;
	int sum=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		init(i);	
	}
	while(m--)
	{
		scanf("%d%d%d",&d,&x,&y);
		if(x>n||y>n||(d==2&&x==y))
		{
			sum++;
		}
		else
		{
			rx=find(x);
			ry=find(y);
			if(rx==ry)
			{
				if((rank[x]-rank[y]+3)%3!=d-1)
					sum++;
			}
			else
			{
				unionone(x,y,d-1);	
			}
		}
	}printf("%d\n",sum);
}



