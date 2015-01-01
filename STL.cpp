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
//���ȶ��е�ʹ��
priority_queue <PP> q;
while(!q.empty())q.pop();
q.push(PP(..))
//set ʹ��
set<PP>SET;
set<PP>::iterator iter;
SET.clear();
SET.insert(PP);
for (iter=SET.begin();iter!=SET.end();++iter)//��������
//map ʹ��
map<string,int>MAP;
MAP.clear();
typedef map<string,int>::iterator ITER;
ITER iter=MAP.find(str2);
MAP.erase(iter);

/*
C++ STL set��multiset��ʹ��
1��set�ĺ����Ǽ��ϣ�����һ������������������Ԫ�ض�������õģ�֧�ֲ��룬ɾ�������ҵȲ������� ��һ������һ�������еĲ����Ķ����ϸ���lognʱ��֮����ɣ�Ч�ʷǳ��ߡ� set��multiset�������ǣ�set�����Ԫ�ز�����ͬ������multiset������ͬ��
���� multiset<ss> base;
ɾ�������ɾ��Ԫ��a,��ô�ڶ���ıȽϹ�ϵ�º�a��ȵ�����Ԫ�ض��ᱻɾ��
base.count( a )��set�ܷ��أ����ߣ���multiset���ж��ٸ����ض��ٸ���
Set��multiset��������<set>ͷ�ļ�,���Ӷȶ���logn
2��Set�е�Ԫ�ؿ������������͵ģ�����������Ҫ��������Ԫ�ر�����һ���򣬼���С�ıȽϹ�ϵ������ ���������ã��Ƚϣ�
3���Զ���ȽϺ�����
include<set>
typedef struct
{ �������͡�}
ss(������);
struct cmp
{
bool operator()( const int &a, const int &b ) const
{ ����ȽϹ�ϵ��}
};
(��������أ�����<)
set<ss> base; ( ����һ��Ԫ��������ss,������base��set )
ע�������ˣ��������ͣ��Լ������������Ͷ�ȷ���ˣ�STL�ıȽϹ�ϵ�����ã���ȷ���ģ����Ա���ͨ �����壼���������ϸ���С�ڡ���ȷ���ȽϹ�
4��set�Ļ���������
begin() ����ָ���һ��Ԫ�صĵ�����
clear() �������Ԫ��
count() ����ĳ��ֵԪ�صĸ���
empty() �������Ϊ�գ�����true
end() ����ָ�����һ��Ԫ�صĵ�����
equal_range() ���ؼ����������ֵ��ȵ������޵�����������
erase() ɾ�������е�Ԫ��
find() ����һ��ָ�򱻲��ҵ�Ԫ�صĵ�����
get_allocator() ���ؼ��ϵķ�����
insert() �ڼ����в���Ԫ��
lower_bound() ����ָ����ڣ�����ڣ�ĳֵ�ĵ�һ��Ԫ�صĵ�����
key_comp() ����һ������Ԫ�ؼ�ֵ�Ƚϵĺ���
max_size() ���ؼ��������ɵ�Ԫ�ص������ֵ
rbegin() ����ָ�򼯺������һ��Ԫ�صķ��������
rend() ����ָ�򼯺��е�һ��Ԫ�صķ��������
size() ������Ԫ�ص���Ŀ
swap() �����������ϱ���
upper_bound() ���ش���ĳ��ֵԪ�صĵ�����
value_comp() ����һ�����ڱȽ�Ԫ�ؼ��ֵ�ĺ���
5,�Զ���ȽϺ�����
For example��
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
};//the ��; �� is here;
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

    MmapType fruit;// ����һ���յ�ˮ������
    itType it;

    fruit.insert (PairType(22, "ƻ��"));
    fruit.insert (PairType(28, "�㽶"));
    fruit.insert (PairType(46, "����"));
    fruit.insert (PairType(22, "����"));
    fruit.insert (PairType(46, "����"));
    fruit.insert (PairType(22, "����"));
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
