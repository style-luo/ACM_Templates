//高精度模版
//大整数加减乘除模版
#include<stdio.h>
#include<string.h>
typedef __int64 lld;
int andbit =1000000000; //进位数
const int numbit = 9; //数组一位表示整形数的位数
const int numlen = 2001; //整形数的位数
const int maxn = numlen/numbit + 10; //数组的位数
const char outstr[] = {'%','0','0'+numbit,'d',0}; //标准化输出字符串

void  mem(int *a) //初始化为零
{
	memset(a,0,sizeof(int)*maxn);
	a[0]=1;
}

void ToBig(const char *s,int *a)//将输入的字符串转为整形数组的大整数
{
	int len=0,ret,ten;
	mem(a);
	for(int i=(int)strlen(s)-1;i>=0;i-=numbit)
	{
		ret = 0; ten = 1;
		for(int j=0;j<numbit&&i-j>=0;j++)
		{
			ret += (s[i-j]-'0')*ten;
			ten *= 10;
		}
		a[++len]=ret;
	}
	a[0]=len;
}

void OutBig(const int *a)//输出大整数
{
	int tmp = a[0];
	printf("%d",a[tmp]);
	for(int i=tmp-1;i>0;i--)
		printf(outstr,a[i]);
	//printf("\n");
}

void AddBig(const int *a,const int *b,int *c)//大整数加法：c=a+b
{
	mem(c);
	int i=0,la=a[0],lb=b[0];
	for(i=1;;i++)
	{
		if(i>la&&i>lb) break;
		if(i<=la)c[i]+=a[i];
		if(i<=lb)c[i]+=b[i];
		if(c[i]>=andbit)
		{
			c[i+1]++;
			c[i]-=andbit;
		}
	}
	while(c[i]==0&&i>1) i--;
	c[0]=i;
}

void SubBig(const int *a,const int *b,int *c)//大整数减法：c=a-b (a>b)
{
	mem(c);
	int i=0,la=a[0],lb=b[0];
	for(i=1;;i++)
	{
		if(i>la&&i>lb) break;
		c[i] += a[i]-b[i];
		if(c[i]<0)
		{
			c[i+1]--;
			c[i]+=andbit;
		}
	}
	while(c[i]==0&&i>1) i--;
	c[0]=i;
}

void MulBig(const int *a,const int *b,int *c)//大整数乘法：c=a*b
{
	mem(c);
	int i,j,k;
	lld t;
	for(i=1;i<=a[0];i++)
	{
		for(j=1;j<=b[0];j++)
		{
			t = (lld)a[i]*(lld)b[j] + c[i+j-1];
			if(t >= andbit)
			{
				c[i+j] += t/andbit;
				t %= andbit;
			}
			c[i+j-1] = t;
		}
	}
	k=i+j+1;
	while(c[k]==0&&k>1) k--;
	c[0]=k;
}

void BigMulInt(const int *a,const int b,int *c)//大整数与Int数乘法：C=A*b;
{
	mem(c);
	int i=0;
	lld t;
	for(i=1;i<=a[0];i++)
	{
		t = c[i] + (lld)a[i]*(lld)b;
		if(t>=andbit)
		{
			c[i+1]+=t/andbit;
			t%=andbit;
		}
		c[i] = t;
	}
	while(c[i]>=andbit)
	{
		c[i+1]+=c[i]/andbit;
		c[i]=c[i]%andbit;
		i++;
	}
	while(c[i]==0&&i>1) i--;
	c[0]=i;
}

void BigDivInt(const int *a,int b,int *c,int &d){//a大数除以b小数

	int i,len;
	mem(c);
	len=a[0];
	d=0;
	lld t=0;
	for(i=len;i>=1;i--)
	{
		t=t*(lld)andbit+(lld)a[i];
		c[i]=t/b;
		t%=b;
   	}
	while(len>1&&c[len]==0) len--;
	c[0]=len;
	d=t;
}

void Leftshift(int *a,int b)//大整数左移移位运算
{
	int l=a[0];
	for(int i=l+1;i>1;i--)
		a[i] = a[i-1];
	a[1] = b;
	if(a[l+1]!=0) a[0]++;
}

int ComBig(const int *a,const int *b)//大整数比较：若a>b返回，若a=b返回，否则返回-1
{
	int la=a[0],lb=b[0];
	if(la>lb) return 1;
	if(la<lb) return -1;
	for(int i=la;i>=1;i--)
	{
		if(a[i]>b[i]) return 1;
		if(a[i]<b[i]) return -1;
	}
	return 0;
}

void DivBig(const int *a,const int *b,int *c,int *d)//大整数除法：c=a/b,d=a%b
{
	int *td = new int[maxn],*tb = new int[maxn];
	mem(c);mem(d);
	if(b[0]==1&&b[1]==0) return ;
	int tmax,tmid,tmin,la=a[0],lb=b[0],lc=la,ld=0;//二分辅助变量
	double bmin=b[lb],bmax=bmin+1,dmax=0,dmin=0;
	if(lb>1)
	{
		bmin = bmin*andbit + b[lb-1];
		bmax = bmin + 1;
	}
	for(int i=la;i>=1;i--)
	{
		Leftshift(d,a[i]);
		if(ComBig(b,d)==1) continue;
		ld = d[0]; dmin = d[ld];
		while(dmin<bmin)
			dmin = dmin*andbit + d[ld-1];
		dmax = dmin+1;
		tmax = (int)(dmax/bmin) + 1,tmin = (int)(dmin/bmax)-1;
		while(true)//二分查找一位商
		{
			tmid = (tmax + tmin)/2;
			BigMulInt(b,tmid,tb);
			if(ComBig(tb,d)==1)
			{
				tmax = tmid-1;
				continue;
			}
			SubBig(d,tb,td);
			if(ComBig(td,b)>=0)
			{
				tmin = tmid+1;
				continue;
			}
			break;
		}
		memcpy(d,td,sizeof(int)*maxn);
		c[i] = tmid;
	}
	delete []td;delete []tb;
	while(c[lc]==0&&lc>1) lc--;
	c[0]=lc;
}
int main()
{
	char str1[numlen],str2[numlen];
	int tmp=0;
	int a[maxn],b[maxn],c[maxn],d[maxn];
	while(scanf("%d%s%s",&tmp,str1,str2)!=EOF)
	{
		andbit=1;
		for(int i=1;i<=9;i++)
		{
			andbit*=tmp;
		}
		printf("andbit==%d\n",andbit);
		ToBig(str1,a);
		ToBig(str2,b);
		DivBig(a,b,c,d);
		OutBig(c);printf(" ");
		OutBig(d);printf("\n");
	}
	return 0;
}
/*
//进制转换
#include<stdio.h>
#include<string.h>
int dig[255];
char cdig[63];
const int MAX=1005;
char a[MAX],b[MAX];
void change(int from,int to,char *a,char *b)
{//“from”进制装换成“to”进制
	int len1,len2=0;
	len1=strlen(a);
	while(1)
	{
		int flag=1,count=0,t=0;
		for(int i=0;i<len1;i++)
		{
			int num=dig[a[i]]+t*from;
			if(num<to)
			{
				if(flag)count++;
				t=num,a[i]='0';
			}
			else
			{
				flag=0;
				a[i]=cdig[num/to];
				t=num%to;
			}
		}
		if(count==len1)
		{
			b[len2++]=cdig[t];
			break;
		}
		b[len2++]=cdig[t];
	}
	for(int i=len2-1;i>=len2/2;i--)
	{
		char tmp=b[i];
		b[i]=b[len2-i-1];
		b[len2-i-1]=tmp;
	}
	b[len2]=0;
}
int main()
{
	int i;
	for(i='0';i<='9';i++) dig[i]=i-'0',cdig[i-'0']=i;
	for(i=0;i<26;i++) dig[i+'A']=10+i,cdig[10+i]=i+'A';
	for(i=0;i<26;i++) dig[i+'a']=36+i,cdig[36+i]=i+'a';
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int from,to;
		scanf("%d%d%s",&from,&to,a);
		printf("%d %s\n",from,a);
		change (from,to,a,b);
		printf("%d %s\n\n",to,b);
	}
	return 0;
}*/