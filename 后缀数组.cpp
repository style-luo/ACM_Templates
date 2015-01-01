//rank从0开始
//sa从1开始,因为最后一个字符(最小的)排在第0位
//high从2开始,因为表示的是sa[i-1]和sa[i]
#define M 220000
int rank[M],sa[M],X[M],Y[M],high[M],init[M];
int buc[M];
void calhigh(int n) {
	int i , j , k = 0;
	for(i = 1 ; i <= n ; i++) rank[sa[i]] = i;
	for(i = 0 ; i < n ; high[rank[i++]] = k)
		for(k?k--:0 , j = sa[rank[i]-1] ; init[i+k] == init[j+k] ; k++);
}
bool cmp(int *r,int a,int b,int l) {
	return (r[a] == r[b] && r[a+l] == r[b+l]);
}
void suffix(int n,int m = 128) {
	int i , j , p , *x = X , *y = Y,*t;
	for(i = 0 ; i < m ; i ++) buc[i] = 0;
	for(i = 0 ; i < n ; i ++) buc[ x[i] = init[i]  ] ++;
	for(i = 1 ; i < m ; i ++) buc[i] += buc[i-1];
	for(i = n - 1; i >= 0 ; i --) sa[ --buc[ x[i] ]] = i;
	for(j = 1,p = 1 ; p < n ; m = p , j<<=1) {
		p = 0;
		for(i = n-j ; i < n ; i ++) y[p++] = i;
		for(i = 0 ; i < n ; i ++) if(sa[i] >= j) y[p++] = sa[i] - j;
		for(i = 0 ; i < m ; i ++) buc[i] = 0;
		for(i = 0 ; i < n ; i ++) buc[ x[y[i]] ] ++;
		for(i = 1 ; i < m ; i ++) buc[i] += buc[i-1];
		for(i = n - 1; i >= 0 ; i --) sa[ --buc[ x[y[i]] ] ] = y[i];
		for(t=x,x=y,y=t,x[sa[0]] = 0 , i = 1 , p = 1 ; i < n ; i ++)
			x[ sa[i] ] = cmp(y,sa[i-1],sa[i],j) ? p-1 : p++;
	}
	calhigh(n-1);//后缀数组关键是求出high,所以求sa的时候顺便把rank和high求出来
}


//当需要反复询问两个后缀的最长公共前缀时用到RMQ
int Log[M];
int best[20][M];
void initRMQ(int n) {//初始化RMQ
	for(int i = 1; i <= n ; i ++) best[0][i] = high[i];
	for(int i = 1; i <= Log[n] ; i ++) {
		int limit = n - (1<<i) + 1;
		for(int j = 1; j <= limit ; j ++) {
			best[i][j] = min(best[i-1][j] , best[i-1][j+(1<<i>>1)]);
		}
	}
}
int lcp(int a,int b) {//询问a,b后缀的最长公共前缀
	a = rank[a];    b = rank[b];
	if(a > b) swap(a,b);
	a ++;
	int t = Log[b - a + 1];
	return min(best[t][a] , best[t][b - (1<<t) + 1]);
}


int main() {
	//预处理每个数字的Log值,常数优化,用于RMQ
	Log[0] = -1;
	for(int i = 1; i <= M ; i ++) {
		Log[i] = (i&(i-1)) ? Log[i-1] : Log[i-1] + 1 ;
	}
	//*******************************************
	//	n为数组长度,下标0开始
	//	将初始数据,保存在init里,并且保证每个数字都比0大
	//	m = max{ init[i] } + 1
	//	一般情况下大多是字符操作,所以128足够了
	//*******************************************
	init[n] = 0;
	suffix(n+1,m);

	initRMQ(n);
}

-------------------------------------------------------------------------
//DC3
//sa从0开始
#define M 220000
#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
int X[M],Y[M],wv[M],buc[M];
int sa[3*M],init[3*M];
int c0(int *r,int a,int b)
{return r[a]==r[b]&&r[a+1]==r[b+1]&&r[a+2]==r[b+2];}
int c12(int k,int *r,int a,int b)
{if(k==2)return r[a]<r[b]||r[a]==r[b]&&c12(1,r,a+1,b+1);
else return r[a]<r[b]||r[a]==r[b]&&wv[a+1]<wv[b+1];}
void sort(int *r,int *a,int *b,int n,int m)
{
	int i;
	for(i=0;i<n;i++)wv[i]=r[a[i]];
	for(i=0;i<m;i++)buc[i]=0;
	for(i=0;i<n;i++)buc[wv[i]]++;
	for(i=1;i<m;i++)buc[i]+=buc[i-1];
	for(i=n-1;i>=0;i--)b[--buc[wv[i]]]=a[i];
	return ;
}
void dc3(int *r,int *sa,int n,int m)
{
	int i,j,*rn=r+n,*san=sa+n,ta=0,tb=(n+1)/3,tbc=0,p;
	r[n]=r[n+1]=0;
	for(i=0;i<n;i++)if(i%3!=0)X[tbc++]=i;
	sort(r+2,X,Y,tbc,m);
	sort(r+1,Y,X,tbc,m);
	sort(r,X,Y,tbc,m);
	for(p=1,rn[F(Y[0])]=0,i=1;i<tbc;i++)
		rn[F(Y[i])]=c0(r,Y[i-1],Y[i])?p-1:p++;
	if(p<tbc)dc3(rn,san,tbc,p);
	else for(i=0;i<tbc;i++)san[rn[i]]=i;
	for(i=0;i<tbc;i++) if(san[i]<tb) Y[ta++]=san[i]*3;
	if(n%3==1) Y[ta++]=n-1;
	sort(r,Y,X,ta,m);
	for(i=0;i<tbc;i++) wv[Y[i]=G(san[i])]=i;
	for(i=0,j=0,p=0;i<ta&&j<tbc;p++) sa[p]=c12(Y[j]%3,r,X[i],Y[j])?X[i++]:Y[j++];
	for(;i<ta;p++) sa[p]=X[i++];
	for(;j<tbc;p++) sa[p]=Y[j++];
	return ;
}
int main()
{
	int n,m;
	dc3(init,sa,n,128);
	return 0;
}