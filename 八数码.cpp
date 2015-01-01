#include<stdio.h>
#include<string.h>
typedef int state[9];
int  goal[9]={1,2,3,4,5,6,7,8,0};
int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int  st[1000000][9];
int dist[1000000];
int head[1000004],next[1000000];
int hash(state& s)//得到哈希值 ——思想关键（决定速度） 
{
	int v=0;
	for(int i=0;i<9;i++)v=v*10+s[i];
	return v%1000003;
}
int inti_lookup_table(){memset(head,0,sizeof(head));return 0;}//初始化——表 
int try_to_insert(int rear)
{
	int h=hash(st[rear]);
	int u=head[h];
	while(u)
	{
		if(memcmp(st[u],st[rear],sizeof(st[rear]))==0)return 0;//插入不成功 
		u=next[u];//顺着链表找 
	}
		next[rear]=head[h];//连成链表 
		head[h]=rear//生成链表 
		return 1;//插入成功 
		printf(" OK ");
}
int bfs()
{
	inti_lookup_table();
	int front=1,rear=2;
	int i,z,x,y,newy,newx,newz;
	while(front<rear)
	{
		if(memcmp(goal,st[front],sizeof(st[front]))==0)return front;
		for(z=0;z<9;z++)if(!st[front][z])break;
		x=z/3;
		y=z%3;
		for(i=0;i<4;i++)
		{
			newx=x+d[i][0];
			newy=y+d[i][1];
			newz=newx*3+newy;
			if(newx>=0&&newx<3&&newy>=0&&newy<3)
			{
				memcpy(st[rear],st[front],sizeof(st[front]));
				st[rear][newz]=st[front][z];
				st[rear][z]=st[front][newz];
				dist[rear]=dist[front]+1;
				if(try_to_insert(rear))rear++;
			}
		}
		front++;
	}
	return 0;
}																			
int main()
{
	int i;
	int ans;
	char temp;
	while(scanf("%c",&temp)!=-1)
	{
		memset(dist,0,sizeof(dist));
	for(i=0;i<9;i++)
	{
		getchar();
		if(temp=='x')
			st[1][i]=0;
		else
			st[1][i]=temp-'0';
		if(i<8)
		temp=getchar();
	}
 	ans=bfs();
	if(ans>0)
	{
		printf("%d\n",dist[ans]);
	}
	else
	{
		printf("unsolveable\n");
	}
	}
	return 0;	
}



