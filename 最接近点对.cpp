#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
struct PP
{
    double x;
    double y;
}s[100005];
int q[100005];
bool cmp(PP a,PP b )
{
    return a.x<b.x;
}
bool cmp_(int a,int b )
{
    return  s[a].y<s[b].y;
}
double dist(int a,int b)
{
    return sqrt((s[a].x-s[b].x)*(s[a].x-s[b].x)+(s[a].y-s[b].y)*(s[a].y-s[b].y)) ;
}
double min(double a,double b)
{
    return a<b?a:b;
}
double search(int l,int r)
{
    if(l==r-1)
    {
        return dist(l,r);
    }
    else if (l==r-2)
    {
        return min(dist(r,l+1),min(dist(l,r),dist(l,l+1)));
    }
    else
    {
        int mid=(l+r)/2;
        double mmin=min(search(l,mid),search(mid+1,r));
        int size=0;
        int i;
        for (i=mid;i>=l&&s[mid].x-s[i].x<mmin;i--)
        {
            q[size++] = i;
        }
        for (i=mid+1;i<=r&&s[i].x-s[mid].x<mmin;i++ )
        {
            q[size++]=i;
        }
        sort(q,q+size,cmp_);
        int j;
        for (i =0;i<size-1;i++ )
        {
            for (j = i + 1;j<size &&s[q[j]].y-s[q[i]].y<mmin;j++ )
            {
                mmin=min(mmin,dist(q[i],q[j]));
            }
        }
        return mmin;
    }
}
int main()
{
    int n;
    int i,j,k;
    while(scanf("%d",&n)!=-1&&n)
    {
        for(i=0;i<n;i++)
        {
            scanf("%lf%lf",&s[i].x,&s[i].y);
        }
        sort(s,s+n,cmp);
        printf("%.2lf\n",search(0,n-1)/2);
    }
    return 0;
}



