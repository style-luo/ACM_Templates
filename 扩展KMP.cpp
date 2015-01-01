//扩展KMP
#include<string.h>
#include<stdio.h>
const int MAX=1000005;
int a[MAX];//Ai－T[i..m]和T[1..m]的最长公共前缀，即从T的第i位用T去匹配的最大长度。
int b[MAX];//Bi－S[i..n]和T[1..m]的最长公共前缀，即从S的第i位用T去匹配的最大长度。
//S－主串，长度为n
//T－匹配串，长度为m
char S[MAX],T[MAX];
void get_fail(char *S,char *T,int n,int m)
{
	int i,j=0;
	a[0]=m;
	while(1+j<m&&T[j]==T[1+j])j++;
	a[1]=j;
	int k=1;
	int need=0;
	for(i=2;i<m;i++)
	{
		need=k+a[k]-i;
		if(a[i-k]<need)a[i]=a[i-k];
		else
		{
			j=0>need?0:need;
			while(i+j<m&&T[j]==T[j+i])j++;
			a[i]=j;
			k=i;
		}
	}
	j=0;
	while(j<n&&j<m&&S[j]==T[j])j++;
	b[0]=j;
	k=0;
	for(i=1;i<n;i++)
	{
		need=k+b[k]-i;
		if(a[i-k]<need)b[i]=a[i-k];
		else
		{
			j=0>need?0:need;
			while(i+j<n&&j<m&&S[i+j]==T[j])j++;
			b[i]=j;
			k=i;
		}
	}
}



