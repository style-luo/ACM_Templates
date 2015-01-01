//pku 2451 模板题   所求方向：向量指向的逆时针(左手方向)
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=20010;
const double big=10000.0;
const double eps=1e-10;
int lnum;//线段数
int ord[MAXN];//排序用
int dq[MAXN];//栈
double at2[MAXN];//向量的极角
struct node
{
	double x,y;
};//点
struct line
{
	node a,b;
}ls[MAXN];//线段
struct Polygon
{
	int n;
	node p[MAXN];
}pg;//存放最后半平面交中相邻边的交点，就是一个多边形的所有点
void add(double x1,double y1,double x2,double y2)
{
	ls[lnum].a.x=x1;
	ls[lnum].a.y=y1;
	ls[lnum].b.x=x2;
	ls[lnum++].b.y=y2;
}
bool cmp(int u,int v)
{
	if(fabs(at2[u]-at2[v])<eps)
		return (ls[u].b.x-ls[u].a.x)*(ls[v].b.y-ls[u].a.y)-(ls[u].b.y-ls[u].a.y)*(ls[v].b.x-ls[u].a.x)<0;
	return at2[u]<at2[v];
}
double multi(node o,node s,node e)
{
	return (s.x-o.x)*(e.y-o.y)-(e.x-o.x)*(s.y-o.y);
}
node intersection(node s1,node e1,node s2,node e2)
{
	double dot1,dot2;
	node p;
	dot1=multi(s2,e1,s1);
	dot2=multi(e1,e2,s1);
	p.x=(s2.x*dot2+e2.x*dot1)/(dot1+dot2);
	p.y=(s2.y*dot2+e2.y*dot1)/(dot1+dot2);
	return p;
}
bool judgein(int x,int y,int z)
{
	node pnt=intersection(ls[x].a,ls[x].b,ls[y].a,ls[y].b);//求交点
	return multi(ls[z].a,ls[z].b,pnt)<-eps;
	//判断交点位置，如果在右面，返回true，如果要排除三点共线，改成<=
}
void HalfPlane(Polygon &pg)
{
	int n=lnum,tmpn,i;
	for(i=0;i<n;i++)
	{
		at2[i]=atan2(ls[i].b.y-ls[i].a.y,ls[i].b.x-ls[i].a.x);
		ord[i]=i;
		//printf("%d %lf\n",i,at2[i]*180/acos(-1.0)); //输出向量角度
	}
	//把每条线段按照斜率从小到大排序
	//如果斜率相同的，就把y大的排在前面
	sort(ord,ord+n,cmp);
	//删掉重边
	for(i=1,tmpn=1;i<n;i++)
		if(fabs(at2[ord[i-1]]-at2[ord[i]])>eps)
			ord[tmpn++]=ord[i];
		n=tmpn;
		//双端栈，bot为栈底，top为栈顶
		int bot=1,top=bot+1;
		dq[bot]=ord[0];
		dq[top]=ord[1];
		for(i=2;i<n;i++)
		{
			//bot < top 表示要保证栈里至少有2条线段，如果剩下1条，就不继续退栈
			//judgein，判断如果栈中两条线的交点如果在当前插入先的右边，就退栈
			while(bot<top&&judgein(dq[top-1],dq[top],ord[i]))
				top--;
			//对栈顶要同样的操作
			while(bot<top&&judgein(dq[bot+1],dq[bot],ord[i]))
				bot++;
			dq[++top]=ord[i];
		}
		//最后还要处理一下栈里面存在的栈顶的线在栈底交点末尾位置，或者栈顶在栈尾两条线的右边
		while(bot<top&&judgein(dq[top-1],dq[top],dq[bot]))
			top--;
		while(bot<top&&judgein(dq[bot+1],dq[bot],dq[top]))
			bot++;
		//最后一条线是重合的
		dq[--bot]=dq[top];
		//求多边形相邻两条线的交点
		pg.n=0;
		for(i=bot+1;i<=top;i++)
			pg.p[pg.n++]=intersection(ls[dq[i-1]].a, ls[dq[i-1]].b, ls[dq[i]].a, ls[dq[i]].b);
}
int main()
{
	int n,i;
	double a,b,c,d;
	scanf("%d",&n);
	lnum=0;
	for(i=0;i<n;i++)
	{
		scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
		//输入代表一条向量(x = (c - a),y = (d - b));
		add(a,b,c,d);
	}
	//按题目意思构造一个边界
	add(0,0,big,0);
	add(big,0,big,big);
	add(big,big,0,big);
	add(0,big,0,0);
	//求半平面交
	HalfPlane(pg);
	//计算面积，构造的多边形顶点在pg.p[]中
	double area=0;
	n=pg.n;
	for(i=0;i<n;i++)
		area+=pg.p[i].x*pg.p[(i+1)%n].y-pg.p[(i+1)%n].x*pg.p[i].y;
	area=fabs(area)/2.0;
	printf("%.1lf\n",area);
	return 0;
}


