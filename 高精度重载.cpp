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
struct BigInt
{
	int len;
	int num[maxn];
	BigInt()
	{
		memset(num,0,sizeof(num));
		len=1;
	}
	void ToBig(const char *s)
	{
		int l=0,ret,ten;
		for(int i=(int)strlen(s)-1;i>=0;i-=numbit)
		{
			ret = 0; ten = 1;
			for(int j=0;j<numbit&&i-j>=0;j++)
			{
				ret += (s[i-j]-'0')*ten;
				ten *= 10;
			}
			num[l++]=ret;
		}
		len=l;
	}
	void OutBig()
	{
		int tmp=len;
		printf("%d",num[tmp-1]);
		for(int i=tmp-2;i>=0;i--)
			printf(outstr,num[i]);
		puts("");
	}
	void fixlen(BigInt &C,int i)
	{
		while(C.num[i]==0&&i>0) i--;
		C.len=i+1;
	}
	BigInt operator+(BigInt B)
	{
		BigInt C;
		int i=0,la=len,lb=B.len;
		for(i=0;;i++)
		{
			if(i>=la&&i>=lb) break;
			if(i<la)C.num[i]+=num[i];
			if(i<lb)C.num[i]+=B.num[i];
			if(C.num[i]>=andbit)
			{
				C.num[i+1]++;
				C.num[i]-=andbit;
			}
		}
		fixlen(C,i);
		return C;
	}
	BigInt operator-(BigInt B)
	{
		BigInt C;
		int i=0,la=len,lb=B.len;
		for(i=0;;i++)
		{
			if(i>=la&&i>=lb) break;
			C.num[i]+=num[i]-B.num[i];
			if(C.num[i]<0)
			{
				C.num[i+1]--;
				C.num[i]+=andbit;
			}
		}
		fixlen(C,i);
		return C;
	}
	BigInt operator*(BigInt B)
	{
		BigInt C;
		int i,j;
		lld t;
		for(i=0;i<len;i++)
		{
			for(j=0;j<B.len;j++)
			{
				t = (lld)num[i]*(lld)B.num[j] + C.num[i+j];
				if(t >= andbit)
				{
					C.num[i+j+1]+=(int)(t/andbit);
					t %= andbit;
				}
				C.num[i+j]=(int)t;
			}
		}
		fixlen(C,i+j+1);
		return C;
	}
	BigInt(int t)
	{
		memset(num,0,sizeof(num));
		len=0;
		while(t)
		{
			num[len++]=t%andbit;
			t/=andbit;
		}
		if(!len)len=1;
		
		OutBig();
	}
};
int main()
{
	BigInt a;
	BigInt b;
	BigInt c;
	char ina[maxn],inb[maxn];
	while(scanf("%s%s",ina,inb)!=-1)
	{
		a.ToBig(ina);
		b.ToBig(inb);
		c=a*b;
		c.OutBig();
		c=a-b;
		c.OutBig();
		c=a+b;
		c.OutBig();
	}
	return 0;
}

