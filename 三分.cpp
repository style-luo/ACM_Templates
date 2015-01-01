#include<stdio.h>
#include<string.h>
#include<math.h>
const double EPS=1.0e-12;
const int MAX=50005;
const int INF=1000000000;
struct Tpoint
{
	double x,y;
}p[MAX];
double dis(Tpoint a,Tpoint b)
{
	double dx=a.x-b.x;
	double dy=a.y-b.y;
	return sqrt(dx*dx+dy*dy);
}
double cal(Tpoint x,int n)
{
	double ret=dis(x,p[0]),tmp;
	int i;
	for(i=1;i<n;i++)
	{
		tmp=dis(x,p[i]);
		if(ret<tmp)
			ret=tmp;
	}
	return ret;
}
int main()
{
	int n;
	int i;
	double high;
	double low;
	Tpoint tp;
	while(scanf("%d",&n)!=EOF&&n)
	{
		high=-INF;
		low=INF;
		for(i=0;i<n;i++)
		{
			scanf("%lf%lf",&p[i].x,&p[i].y);
			if(p[i].x>high)
				high=p[i].x;
			if(p[i].x<low)
				low=p[i].x;
		}
		double mid,mmid,ans=INF;
		double t,tt;
		int test=50;
		while(test--)
		{
			mid=(low+high)/2;
			mmid=(high+mid)/2;
			tp.x=mid;
			tp.y=0;
			t=cal(tp,n);
			tp.x=mmid;
			tt=cal(tp,n);
			if(t<tt)
			{
				ans=mid;
				high=mmid;
			}
			else
			{
				ans=mmid;
				low=mid;
			}
		}
		tp.x=ans;
		tp.y=0;
		printf("%.9lf %.9lf\n",ans,cal(tp,n));
	}
	return 0;
}

