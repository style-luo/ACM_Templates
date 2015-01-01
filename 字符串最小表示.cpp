//字符串的最小表示 
#include<stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char s[2000005];
char tmp[2000005];
int minP(char s[])
{
		int l=strlen(s);
         int i=0, j=1, k=0;
         while (1)
         {
                   if (i+k>=l||j+k>=l) break;
                   if (s[i+k]==s[j+k])
                   {
                            k++;
                            continue;
                   }
                   else
                   {
                           if (s[j+k]>s[i+k])j+=k+1;
                           else
                           		i+=k+1;
                           k=0;
                           if (i==j)j++;
                   }
         }
         return min(i,j);
}
int main ()
{
         int t;
         int len;
         scanf("%d", &t);
         while (t--)
         {
             scanf("%d",&len);
             scanf("%s",s);
             strcpy(tmp,s);
             strcat(s,tmp);
             int ans=minP(s);
                   printf("%d\n", ans+1);
         }
         return 0;
}


