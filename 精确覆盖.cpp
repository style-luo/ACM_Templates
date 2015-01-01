//http://poj.org/problem?id=3740
//精确覆盖
#include<stdio.h>
#include<string.h>
const int inf=0x7fffffff;
const int maxn=305*17+65;
int R[maxn],L[maxn],D[maxn],U[maxn],Col[maxn],Sum[maxn],ans;
#define FOR(i,c,M) for(int i=M[c];i!=c;i=M[i])
#define CC(x) (R[x]=L[x]=U[x]=D[x]=x)
#define HL(r,x) (R[L[r]]=x,L[x]=L[r],R[x]=r,L[r]=x)
#define VL(c,x) (D[U[c]]=x,U[x]=U[c],D[x]=c,U[c]=x)
void Cov(int c)
{
    L[R[c]]=L[c];R[L[c]]=R[c];
    FOR(i,c,D){
        FOR(j,i,R){
            U[D[j]]=U[j];D[U[j]]=D[j];
            --Sum[Col[j]];
        }
    }
}
void Res(int c)
{
    FOR(i,c,U){
        FOR(j,i,L){
            U[D[j]]=j;D[U[j]]=j;
            ++Sum[Col[j]];
        }
    }
    L[R[c]]=c;R[L[c]]=c;
}
bool Dlx(int k)
{
    if(R[0]==0){
        ans=k;
        return true;
    }
	int c=R[0];
	int min=Sum[c];
	FOR(idx,0,R)
		if(Sum[idx]<min)
			min=Sum[idx],c=idx;
		if(min==0)return false;
	Cov(c);
	FOR(i,c,D){
		FOR(j,i,R) Cov(Col[j]);
		if(Dlx(k+1))return true;
		FOR(jj,i,L) Res(Col[jj]);
	}
	Res(c);
	return false;
}// 精确覆盖
int main()
{
	int i,j;
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
	{
        int N=0;
        CC(0);
		memset(Sum,0,sizeof(int)*(n+1));
        for(i=1;i<=m;++i)++N,CC(N),HL(0,N);
		for(j=1;j<=n;j++)
		{
			int head=N+1;
			for(i=1;i<=m;++i)
			{
				int x;
                scanf("%d",&x);
				if(!x)continue;
				x=i;
				Sum[x]++;
                ++N;
                CC(N);
                Col[N]=x;
                VL(x,N);
                HL(head,N);
			}
        }
		if(!Dlx(0))
			printf("It is impossible\n");
		else
			printf("Yes, I found it\n");
    }
    return 0;
}







