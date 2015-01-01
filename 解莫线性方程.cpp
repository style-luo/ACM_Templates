//解模线性方程 
__int64  mod(__int64  a, __int64  b)
	{
    if (a < 0) return a%b+b;
    return a % b;
}
void gcd(__int64 a,__int64 b,__int64&d,__int64 &x,__int64 &y)
{
	if(!b)
	{
		d=a;x=1;y=0;
	}
	else
	{
		gcd(b,a%b,d,y,x);
		y-=x*(a/b);
	}
}
int main()
{
        A =  
		B = 
		C = 
        gcd(A, B,d,x, y);
        if (C % d) printf("FOREVER\n");
        else printf("%I64d\n",mod(C*x/d, B /d));//输出最小值 
    }
    return 

