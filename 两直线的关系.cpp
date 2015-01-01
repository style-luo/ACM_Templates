//两直线的关系
#include<iostream>
#include<algorithm>
#include<math.h>
#define esp 1e-8
using namespace std;
struct point   //定义点
{
    double x,y;
};
struct line   //定义直线
{
    double a,b,c;
};
int dblcmp(double d) //浮点误差处理
{
    if(fabs(d)<esp)
        return 0;
    return (d>0)?1:-1;
}
double cross(point a, point b, point c)  //叉积
{
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
void lineintersect(line l1,line l2, double &x, double &y)      //求两直线的交点
{
    double d=l1.a*l2.b-l2.a*l1.b;
     x=(l2.c*l1.b-l1.c*l2.b)/d;
     y=(l2.a*l1.c-l1.a*l2.c)/d;
}
void lineform(double x1,double y1,double x2,double y2, line &temp)//ax+by+c=0;
{
     temp.a=y2-y1;
     temp.b=x1-x2;
     temp.c=x2*y1-x1*y2;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
     {
         printf("INTERSECTING LINES OUTPUT\n");
         point a,b,c,d;
        while(n--)
         {
             scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&a.x, &a.y, &b.x, &b.y, &c.x, &c.y, &d.x, &d.y);
            if((b.y-a.y)*(d.x-c.x)==(d.y-c.y)*(b.x-a.x)) //共线或不相交
             {
                if(dblcmp(cross(a,b,c))==0) printf("LINE\n"); //共线
                else
                 printf("NONE\n");
             }
            else //存在交点
             {
                 line l1,l2;
                double xx,yy;  //存储交点
                 lineform(a.x, a.y, b.x, b.y, l1);
                 lineform(c.x, c.y, d.x, d.y, l2);
                 lineintersect(l1,l2,xx,yy);
                 printf("POINT %.2lf %.2lf\n",xx,yy);
             }
         }
         printf("END OF OUTPUT\n");
     }
    return 0;
}




