int n,A[50005],B[50005];
int lowbit(int i)  //compute lowest bit 1 in i {   
return i&(-i);   
}     
int sum(int i)   //sum of A[1]...A[i]   
{   
    int sum=0;   
    for(;i>0;i-=lowbit(i))
        sum+=B[i];   
    return sum;   
}   
int sum_(int i,int j)  //sum of A[i]...A[j]   
{   return sum(j)-sum(i-1);   }   
void update(int i,int value)//add value to A[i]
{      
    for(;i<=N;i+=lowbit(i))   
        B[i]+=value;    
} 
int getK(int k){
	int ans=0;
	for(int i=MAXLOG;i>=0;i--)
	{
		ans+=(1<<i);
		if(ans>N||B[ans]>=k)
			ans-=(1<<i);
		else k-=B[ans];
	}
	return ans+1;
}
void updateM(int i, int value)
{
	for(;i<=N;i+=lowbit(i))
		if(value>B[i])
			B[i]=value;
} 
int update(int  x ,int y){
	int i,j;
	for(int i=x;i<=n;i+=lowbit(i))
		for(j=y;j<=n;j+=lowit(j))
			tree[i][j]++;
	return 0;
}
int getM(int i){
	int ans=0;
	for (;i>0;i-=lowbit(i))
		if(B[i]>ans)ans=B[i];
		return ans;
}
int update(int  x ,int y)//¶şÎ¬Ê÷×´Êı×é
{
	int i,j;
	for(i=x;i<=n;i+=lowbit(i))
		for(j=y;j<=n;j+=lowbit(j))
			tree[i][j]++;
	return 0;
}

