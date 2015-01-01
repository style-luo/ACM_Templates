//KMP Ä£°å
#include <stdio.h>
#include <string>
#define MAX 1000001
char a[MAX],b[MAX];
int next[MAX];
int la,lb;
void getnext(char b[])
{
	int lb=strlen(b);
    int i=0,j=-1;
    next[0]=-1;  //nextval[0]=-1;
    while(i<=lb)
    {
        if(j==-1||b[i]==b[j])
        {
            i++;
            j++;
			next[i]=j;
			//if (b[i]!=b[j]) nextval[i]=j;
    		//else nextval[i]=nextval[j];
        }
        else
            j=next[j];//j=nextval[j];
    }
}
int kmp(char a[],char b[])
{
	int la=strlen(a);
    int lb=strlen(b);
	int i,j,count=0;
	i=0;
	j=0;
	while(i<la&&j<lb)
	{
	   if(j==-1||a[i]==b[j])
	   {
	    	i++;
	    	j++;
	   }
	   else
	    	j=next[j];//j=nextval[j];
	   if(j==lb)
	   {
	 		count++;
	  		j=next[j];//j=nextval[j];
	   }
	}
	return count;
}
int main()
{
    int g=1;
    int t;
    scanf("%d",&t);
    while(t--)
    {
    	scanf("%s%s",b,a);
        getnext(b);
		printf("%d\n",kmp(a,b));
    }
    return 0;
}


