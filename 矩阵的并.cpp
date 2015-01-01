//¾ØÕóµÄ²¢
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int MAXN=20005;
double pos[MAXN];
struct TT{
	int l,r,mid;
	double sum;
	int st;
}T[MAXN*3];
struct LL{
	double left,right,high;
	int flag;
}line[MAXN];
bool cmp(LL a,LL b){
	return a.high<b.high;
}
void build(int l,int r,int idx){
	int mid=(l+r)>>1;
	T[idx].l=l;
	T[idx].r=r;
	T[idx].mid=mid;
	T[idx].sum=0;
	T[idx].st=0;
	if(l==r)return ;
	build(l,mid,idx*2);
	build(mid+1,r,idx*2+1);
}

void update(int idx)
{
	if(T[idx].st){
		T[idx].sum=pos[T[idx].r+1]-pos[T[idx].l];
	}else if(T[idx].l==T[idx].r){
		T[idx].sum=0;
	}else{
		T[idx].sum=T[idx*2].sum+T[idx*2+1].sum;
	}
}
void update(int l,int r,int st,int idx){
	if(T[idx].l>=l&&T[idx].r<=r){
		T[idx].st+=st;
		update(idx);
		return ;
	}
	int mid=T[idx].mid;
	if(l<=mid)update(l,r,st,idx*2);
	if(r>mid)update(l,r,st,idx*2+1);
	update(idx);
}
int tot,top;
int bin(double x){
	int l=0,r=top-1,mid,best;
	while(l<=r){
		mid=(l+r)>>1;
		if(x<=pos[mid]){
			best=mid;
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	return best;
}
int main(){
	int n,i,j;
	double a,b,c,d;
	int g=1;
	while(scanf("%d",&n)!=-1&&n){
		tot=0;
		for(i=0;i<n;i++){
			scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
			pos[tot]=a;
			line[tot].left=a;
			line[tot].right=c;
			line[tot].high=b;
			line[tot].flag=1;
			pos[tot+1]=c;
			line[tot+1].left=a;
			line[tot+1].right=c;
			line[tot+1].high=d;
			line[tot+1].flag=-1;
			tot+=2;
		}
		sort(pos,pos+tot);
		sort(line,line+tot,cmp);
		for(i=1,j=1;i<tot;i++){
			if(pos[i]!=pos[i-1])
				pos[j++]=pos[i];
		}
		top=j;
		build(0,top-1,1);
		double ans=0;
		for(i=0;i<tot-1;i++){
			int l=bin(line[i].left);
			int r=bin(line[i].right)-1;
			if(l<=r)update(l,r,line[i].flag,1);
			ans+=T[1].sum*(line[i+1].high-line[i].high);
		}
		printf("Test case #%d\nTotal explored area: %.2lf\n\n",g++,ans);
	}
	return 0;
}


