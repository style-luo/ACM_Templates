//跳马的最小步数
#include<stdio.h>
int main()
{
    int k,i,x,y,t,sum;
    int a[3][3]={0,3,2,3,2,1,2,1,4};
    char s[50];
    while(gets(s))
    {
        if(s[0]=='E')
            break;
        sscanf(s,"%d %d",&x,&y);
        if(x<0)x=-x;
        if(y<0)y=-y;
        if(x<y){t=x;x=y;y=t;}
        if(x<3&&y<3)
        {
            printf("%d\n",a[x][y]);
            continue;
        }
        if(y<=(x/2))
        {
             sum=(x/4)*2+x%4;
            if(x%4<2)
                sum+=y%2;
            else
                sum-=y%2;
        }
        else
        {
            k=2*y-x;
            sum=(x-k)/2+(((k-1)/3)+1)*2;
        }
        printf("%d\n",sum);
    }
    return 0;
}


