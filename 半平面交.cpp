//pku 2451 ģ����   ����������ָ�����ʱ��(���ַ���)
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=20010;
const double big=10000.0;
const double eps=1e-10;
int lnum;//�߶���
int ord[MAXN];//������
int dq[MAXN];//ջ
double at2[MAXN];//�����ļ���
struct node
{
	double x,y;
};//��
struct line
{
	node a,b;
}ls[MAXN];//�߶�
struct Polygon
{
	int n;
	node p[MAXN];
}pg;//�������ƽ�潻�����ڱߵĽ��㣬����һ������ε����е�
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
	node pnt=intersection(ls[x].a,ls[x].b,ls[y].a,ls[y].b);//�󽻵�
	return multi(ls[z].a,ls[z].b,pnt)<-eps;
	//�жϽ���λ�ã���������棬����true�����Ҫ�ų����㹲�ߣ��ĳ�<=
}
void HalfPlane(Polygon &pg)
{
	int n=lnum,tmpn,i;
	for(i=0;i<n;i++)
	{
		at2[i]=atan2(ls[i].b.y-ls[i].a.y,ls[i].b.x-ls[i].a.x);
		ord[i]=i;
		//printf("%d %lf\n",i,at2[i]*180/acos(-1.0)); //��������Ƕ�
	}
	//��ÿ���߶ΰ���б�ʴ�С��������
	//���б����ͬ�ģ��Ͱ�y�������ǰ��
	sort(ord,ord+n,cmp);
	//ɾ���ر�
	for(i=1,tmpn=1;i<n;i++)
		if(fabs(at2[ord[i-1]]-at2[ord[i]])>eps)
			ord[tmpn++]=ord[i];
		n=tmpn;
		//˫��ջ��botΪջ�ף�topΪջ��
		int bot=1,top=bot+1;
		dq[bot]=ord[0];
		dq[top]=ord[1];
		for(i=2;i<n;i++)
		{
			//bot < top ��ʾҪ��֤ջ��������2���߶Σ����ʣ��1�����Ͳ�������ջ
			//judgein���ж����ջ�������ߵĽ�������ڵ�ǰ�����ȵ��ұߣ�����ջ
			while(bot<top&&judgein(dq[top-1],dq[top],ord[i]))
				top--;
			//��ջ��Ҫͬ���Ĳ���
			while(bot<top&&judgein(dq[bot+1],dq[bot],ord[i]))
				bot++;
			dq[++top]=ord[i];
		}
		//���Ҫ����һ��ջ������ڵ�ջ��������ջ�׽���ĩβλ�ã�����ջ����ջβ�����ߵ��ұ�
		while(bot<top&&judgein(dq[top-1],dq[top],dq[bot]))
			top--;
		while(bot<top&&judgein(dq[bot+1],dq[bot],dq[top]))
			bot++;
		//���һ�������غϵ�
		dq[--bot]=dq[top];
		//���������������ߵĽ���
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
		//�������һ������(x = (c - a),y = (d - b));
		add(a,b,c,d);
	}
	//����Ŀ��˼����һ���߽�
	add(0,0,big,0);
	add(big,0,big,big);
	add(big,big,0,big);
	add(0,big,0,0);
	//���ƽ�潻
	HalfPlane(pg);
	//�������������Ķ���ζ�����pg.p[]��
	double area=0;
	n=pg.n;
	for(i=0;i<n;i++)
		area+=pg.p[i].x*pg.p[(i+1)%n].y-pg.p[(i+1)%n].x*pg.p[i].y;
	area=fabs(area)/2.0;
	printf("%.1lf\n",area);
	return 0;
}


