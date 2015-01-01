//表达式的计算
#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;
const int maxn=1005;
int shu[maxn];
int topshu;//保存数的栈
char op[maxn];
int topop;//保存操作的栈
int map[50][50];
int num;
char oper,c;
int flag=0;
int tot;
char str[maxn];
int get_val(char str[])
{
	num=0;
	if((c<='9'&&c>='0'))
	{
		while((c<='9'&&c>='0'))
		{
			flag=0;
			num=num*10+c-'0';
			c=str[tot++];	
		}return 1;
	}
	else if((c=='-'||c=='+')&&flag)
	{
		int tmp=1;
		flag=0;
		if(c=='-')tmp=-tmp;
		while(((c=str[tot++])&&(c<='9'&&c>='0')))
			num=num*10+c-'0';
		num*=tmp;
		return  1;
		
	}
	else if(c=='('||c==')')
	{
		if(c=='(')flag=1;
		if(c==')')flag=0;
		oper=c;return 0;
	}
	else if(c==0)
		oper=')';
	else
		oper=c;flag=1;
	return 0;
}
int zero;
int yunsuan(int a,int b,char tmp)
{
	if(tmp=='+')return a+b;
	if(tmp=='-')return a-b;
	if(tmp=='*')return a*b;
	if(b==0)
    {
        zero=1;
        return 1;
    }
	return a/b;	
}
int solve(char str[])
{
	tot=0;
	zero=0;
	topop=0;
	topshu=0;
    c=str[tot++];
	int ans;
	op[++topop]='(';
	while(topop!=0)
	{
		if(get_val(str))
			shu[++topshu]=num;
		else
		{	
		loop:char t1=op[topop];
			switch(map[t1][oper])
			{
				case 0:
					op[++topop]=oper;
					c=str[tot++];break;
				case 1:topop--;if(topop==0)break;c=str[tot++];break;
				case 2:
					char tmp=op[topop];topop--;;
					int b=shu[topshu];topshu--;
					int a=shu[topshu];topshu--;
					shu[++topshu]=yunsuan(a,b,tmp);goto loop;
					break;
			}
		}
	}
	ans=shu[topshu];
	return ans;
}

int main()
{
	int i;
	map['+']['+']=2;map['+']['-']=2;map['+']['*']=0;
	map['+']['/']=0;map['+']['(']=0;map['+'][')']=2;
	map['-']['+']=2;map['-']['-']=2;map['-']['*']=0;
	map['-']['/']=0;map['-']['(']=0;map['-'][')']=2;
	map['*']['+']=2;map['*']['-']=2;map['*']['*']=2;
	map['*']['/']=2;map['*']['(']=0;map['*'][')']=2;
	map['/']['+']=2;map['/']['-']=2;map['/']['*']=2;
	map['/']['/']=2;map['/']['(']=0;map['/'][')']=2;
	map['(']['+']=0;map['(']['-']=0;map['(']['*']=0;
	map['(']['/']=0;map['(']['(']=0;map['('][')']=1;
	while(scanf("%s",str)!=-1)
	{
		int ans=solve(str);
		printf("ans==%d\n",ans);
	}
	return 0;
	
}




