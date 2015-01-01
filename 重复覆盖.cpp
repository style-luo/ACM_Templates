//http://acm.nuaa.edu.cn/acmhome/problemdetail.do?&method=showdetail&id=1507
//÷ÿ∏¥∏≤∏«
#include<stdio.h>
#include<string.h>
const int inf=0x7fffffff;
const int maxn=60*60+65;
int R[maxn],L[maxn],D[maxn],U[maxn],Col[maxn],Sum[maxn],ans;
#define FOR(i,c,M) for(int i=M[c];i!=c;i=M[i])
#define CC(x) (R[x]=L[x]=U[x]=D[x]=x)
#define HL(r,x) (R[L[r]]=x,L[x]=L[r],R[x]=r,L[r]=x)
#define VL(c,x) (D[U[c]]=x,U[x]=U[c],D[x]=c,U[c]=x)
void Cov(int c)//…æ≥˝¡–
{
    FOR(i,c,D)R[L[i]]=R[i],L[R[i]]=L[i];
}
void Res(int c)//ª÷∏¥¡–
{
    FOR(i,c,U)R[L[i]]=i,L[R[i]]=i;
}
int h()
{
    bool static hash[65];
    memset(hash,0,sizeof(hash));
    int ret=0;
    FOR(i,0,R)
	{
        if(!hash[i])
		{
            ++ret;
            hash[i]=true;
            FOR(j,i,D)
			{
                FOR(k,j,R)hash[Col[k]]=true;
            }
        }
    }
    return ret;
}
bool Dlx(int k)
{
    if(R[0]==0){
        ans=k;
        return true;
    }
	if(k+h()>=ans) return false;
    int c=R[0];
	int min=Sum[c];
	FOR(idx,0,R)
		if(Sum[idx]<min)
			min=Sum[idx],c=idx;
	if(min==0)return false;
    FOR(i,c,D)
	{
        Cov(i);
        FOR(j,i,R) Cov(j);
        Dlx(k+1);
        FOR(jj,i,L) Res(jj);
        Res(i);
    }
    return false;
}//÷ÿ∏¥∏≤∏«
int main()
{
	int i;
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
	{
        int N=0;
        CC(0);
		memset(Sum,0,sizeof(int)*(n+1));
        for(i=1;i<=n;++i)++N,CC(N),HL(0,N);
        for(i=1;i<=m;++i){
            int sz,x,head=N+1;
            scanf("%d",&sz);
            while(sz--)
			{
                scanf("%d",&x);
				Sum[x]++;
                ++N;
                CC(N);
                Col[N]=x;
                VL(x,N);
                HL(head,N);
            }
        }
        ans=m;
        Dlx(0);
        printf("%d\n",ans);
    }
    return 0;
}

