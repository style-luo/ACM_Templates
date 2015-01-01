//��ֱ�ߵĹ�ϵ
#include<iostream>
#include<algorithm>
#include<math.h>
#define esp 1e-8
using namespace std;
struct point   //�����
{
    double x,y;
};
struct line   //����ֱ��
{
    double a,b,c;
};
int dblcmp(double d) //��������
{
    if(fabs(d)<esp)
        return 0;
    return (d>0)?1:-1;
}
double cross(point a, point b, point c)  //���
{
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
void lineintersect(line l1,line l2, double &x, double &y)      //����ֱ�ߵĽ���
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
            if((b.y-a.y)*(d.x-c.x)==(d.y-c.y)*(b.x-a.x)) //���߻��ཻ
             {
                if(dblcmp(cross(a,b,c))==0) printf("LINE\n"); //����
                else
                 printf("NONE\n");
             }
            else //���ڽ���
             {
                 line l1,l2;
                double xx,yy;  //�洢����
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




