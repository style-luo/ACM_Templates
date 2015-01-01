//��չKMP
#include<string.h>
#include<stdio.h>
const int MAX=1000005;
int a[MAX];//Ai��T[i..m]��T[1..m]�������ǰ׺������T�ĵ�iλ��Tȥƥ�����󳤶ȡ�
int b[MAX];//Bi��S[i..n]��T[1..m]�������ǰ׺������S�ĵ�iλ��Tȥƥ�����󳤶ȡ�
//S������������Ϊn
//T��ƥ�䴮������Ϊm
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



