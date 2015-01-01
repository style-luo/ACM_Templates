#include<stdio.h>
#include<string.h>
int const N=;
struct Trie
{
    int count; 
    int next[26];
    void init()
    {
        count= 0;
        for( int i= 0; i< 26; ++i ) next[i]= 0;
    }
}tb[N];
int top= 0;
void  insert( char s[] )
{
    int rt= 0;
    int i=0;
    while(s[i])
    {
        int t= s[i]-'a';
        if( !tb[rt].next[t] )
        {
            tb[++top].init();
            tb[rt].next[t]= top;
        }
        rt=tb[rt].next[t];i++;
    }
    tb[rt].count++;
}
int main()
{
	top=0;
	tb[0].init();
	return 0;
}



