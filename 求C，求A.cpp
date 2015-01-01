for(i=0;i<10;i++)
{
	c[i][0]=1;
	c[i][i]=1;
	for(j=1;j<i;j++)
	{
		c[i][j]=(c[i-1][j-1]+c[i-1][j])%100007;
		printf("c[%I64d][%I64d]=%I64d ",i,j,c[i][j]);
	}puts("\n");
}
for(i=0;i<10;i++)
{
	a[i][0]=1;
	for(j=1;j<=i;j++)
	{
		a[i][j]=(a[i][j-1]*(i-j+1))%100007;
		printf("a[%I64d][%I64d]=%I64d ",i,j,a[i][j]);
	}
	puts("\n");
}
__int64 GCD(__int64 x, __int64 y)
{
 if (y == 0)return x;
  return GCD(y, x%y);
}
