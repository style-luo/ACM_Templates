#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
const double eps=1e-8;
bool zero(double x)
{
	if(fabs(x)<eps)return 1;
	return 0;
}
struct point
{
	double x,y;
}p[50005];
double  xmult(point p1,point p2,point p0)
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
double dis(point p1,point p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
bool cmp(point p1,point p2)
{
	double t=xmult(p1,p2,p[0]);
	if(zero(t))
	{
		return dis(p[0],p1)<dis(p[0],p2);
	}
	return t>0;
}
int  get_convex(point p[],int n)
{
	int i,v=0;
	point a,b;
	for(i=1;i<n;i++)
		if(p[i].x<p[v].x)v=i;
		else if(p[i].x==p[v].x&&p[i].y<p[v].y)v=i;
	a=p[v];	
	p[v]=p[0];
	p[0]=a;
	sort(p+1,p+n,cmp);
	int top=2;
	for(i=2;i<n;i++)
	{
		a=p[top-2];
		b=p[top-1];
		while(top>1&&(xmult(b,p[i],a)<0||zero(xmult(b,p[i],a))))
		{
			top--;
			a=p[top-2];
			b=p[top-1];
		}
		p[top++]=p[i];
	}
	while(top>1&&zero(p[top-1].x-p[0].x)&&zero(p[top-1].y-p[0].y))
		top--;
	return top;
}//浮点型注意精度,整数可以简单点


