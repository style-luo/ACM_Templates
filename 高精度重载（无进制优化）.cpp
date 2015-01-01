//高精度重载（无进制优化）
#include<stdio.h>
#include<string.h>
const int maxn =505;
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
		int ret=0;
		len=strlen(s);
		for(int i=0;s[i];i++)
		{
			num[len-i-1]=s[i]-'0';
		}
	}
	void OutBig()
	{
		for(int i=len-1;i>=0;i--)
			printf("%d",num[i]);
		puts("");
	}
	void fixlen(BigInt &C,int i)
	{
		while(C.num[i]==0&&i>0) i--;
		C.len=i+1;
	}
	BigInt operator+(const BigInt &B)
	{
		BigInt C;
		int i=0,la=len,lb=B.len;
		for(i=0;;i++)
		{
			if(i>=la&&i>=lb) break;
			if(i<la)C.num[i]+=num[i];
			if(i<lb)C.num[i]+=B.num[i];
			if(C.num[i]>=10)
			{
				C.num[i+1]++;
				C.num[i]-=10;
			}
		}
		fixlen(C,i);
		return C;
	}
	BigInt operator-(const BigInt &B)
	{
		BigInt C;
		int i=0,la=len,lb=B.len;
		for(i=0;;i++)
		{
			if(i>=la&&i>=lb) break;
			if(i<la)C.num[i]+=num[i];
			if(i<lb)C.num[i]-=B.num[i];
			if(C.num[i]<0)
			{
				C.num[i+1]--;
				C.num[i]+=10;
			}
		}
		fixlen(C,i);
		return C;
	}
	BigInt operator*(const BigInt &B)
	{
		BigInt C;
		int i,j;
		int t;
		for(i=0;i<len;i++)
		{
			for(j=0;j<B.len;j++)
			{
				t = num[i]*B.num[j] + C.num[i+j];
				if(t >= 10)
				{
					C.num[i+j+1]+=(t/10);
					t %= 10;
				}
				C.num[i+j]=t;
			}
		}
		fixlen(C,i+j+1);
		return C;
	}
	BigInt(int t)
	{
		num[0]=0;len=0;
		while(t)
		{
			num[len++]=t%10;
			t/=10;
		}
		if(!len)len=1;
	}
};



