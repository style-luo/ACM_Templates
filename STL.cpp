#include<stdio.h>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<queue>
using namespace std;	
const int maxn=10005;

struct PP
{
    int id;
    int dis;
    PP(int v = 0, int d = 0): id(v), dis(d){};
    bool operator<(const PP&a)const
    {
        return dis>a.dis;
    }
};
//优先队列的使用
priority_queue <PP> q;
while(!q.empty())q.pop();
q.push(PP(..))
//set 使用
set<PP>SET;
set<PP>::iterator iter;
SET.clear();
SET.insert(PP);
for (iter=SET.begin();iter!=SET.end();++iter)//遍历集合
//map 使用
map<string,int>MAP;
MAP.clear();
typedef map<string,int>::iterator ITER;
ITER iter=MAP.find(str2);
MAP.erase(iter);

/*
C++ STL set和multiset的使用
1，set的含义是集合，它是一个有序的容器，里面的元素都是排序好的，支持插入，删除，查找等操作，就 像一个集合一样。所有的操作的都是严格在logn时间之内完成，效率非常高。 set和multiset的区别是：set插入的元素不能相同，但是multiset可以相同。
创建 multiset<ss> base;
删除：如果删除元素a,那么在定义的比较关系下和a相等的所有元素都会被删除
base.count( a )：set能返回０或者１，multiset是有多少个返回多少个．
Set和multiset都是引用<set>头文件,复杂度都是logn
2，Set中的元素可以是任意类型的，但是由于需要排序，所以元素必须有一个序，即大小的比较关系，比如 整数可以用＜比较．
3，自定义比较函数；
include<set>
typedef struct
{ 定义类型　}
ss(类型名);
struct cmp
{
bool operator()( const int &a, const int &b ) const
{ 定义比较关系＜}
};
(运算符重载，重载<)
set<ss> base; ( 创建一个元素类型是ss,名字是base的set )
注：定义了＜，＝＝和＞以及＞＝，＜＝就都确定了，STL的比较关系都是用＜来确定的，所以必须通 过定义＜　－－“严格弱小于”来确定比较关
4，set的基本操作：
begin() 返回指向第一个元素的迭代器
clear() 清除所有元素
count() 返回某个值元素的个数
empty() 如果集合为空，返回true
end() 返回指向最后一个元素的迭代器
equal_range() 返回集合中与给定值相等的上下限的两个迭代器
erase() 删除集合中的元素
find() 返回一个指向被查找到元素的迭代器
get_allocator() 返回集合的分配器
insert() 在集合中插入元素
lower_bound() 返回指向大于（或等于）某值的第一个元素的迭代器
key_comp() 返回一个用于元素间值比较的函数
max_size() 返回集合能容纳的元素的最大限值
rbegin() 返回指向集合中最后一个元素的反向迭代器
rend() 返回指向集合中第一个元素的反向迭代器
size() 集合中元素的数目
swap() 交换两个集合变量
upper_bound() 返回大于某个值元素的迭代器
value_comp() 返回一个用于比较元素间的值的函数
5,自定义比较函数：
For example：
#include<iostream>
#include<set>
using namespace std;
typedef struct
{
	int a,b;
	char s;
}newtype;
struct compare //there is no ().
{
	bool operator()(const newtype &a, const newtype &b) const
	{
		return a.s<b.s;
	}
};//the “; ” is here;
set<newtype,compare>element;
int main()
{
	newtype a,b,c,d,t;
	a.a=1; a.s='b';
	b.a=2; b.s='c';
	c.a=4; c.s='d';
	d.a=3; d.s='a';
	element.insert(a);
	element.insert(b);
	element.insert(c);
	element.insert(d);
	set<newtype,compare>::iterator it;
	for(it=element.begin(); it!=element.end();it++)
		cout<<(*it).a<<" ";
	cout<<endl;
	for(it=element.begin(); it!=element.end();it++)
		cout<<(*it).s<<" ";
}
*/
/*
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <iterator>
using namespace std;
int main()
{
    typedef int KeyType;
    typedef pair<const KeyType, string> PairType;
    typedef multimap<KeyType, string> MmapType;
    typedef MmapType::iterator itType;

    MmapType fruit;// 定义一个空的水果容器
    itType it;

    fruit.insert (PairType(22, "苹果"));
    fruit.insert (PairType(28, "香蕉"));
    fruit.insert (PairType(46, "桔子"));
    fruit.insert (PairType(22, "桃子"));
    fruit.insert (PairType(46, "西瓜"));
    fruit.insert (PairType(22, "葡萄"));
    for(it = fruit.begin(); it != fruit.end(); ++it){
        cout << it->first << " : " << it->second << endl;
    }
    cout << "count(22):= " << fruit.count(22) << endl;
    cout << "count(28):= " << fruit.count(28) << endl;
    cout << "count(46):= " << fruit.count(46) << endl;

    pair<itType, itType> myRange = fruit.equal_range(22);
    for(it = myRange.first; it != myRange.second; ++it){
        cout << it->first << " : " << it->second << endl;
    }

    return 0;
}
*/
