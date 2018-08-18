#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn = 1e5 + 10;
int cnt = 0,rt = 0;
struct TREAP {
	int rd;//随机值
	int v;//值
	int cnt;//出现的次数
	int sz;//儿子节点的次数
	int ch[2];//儿子节点的下标
	TREAP() { }
	TREAP(int a, int b) :v(a), rd(b) {
		sz = cnt = 1;
		ch[0] = ch[1] = 0;
	}
}treap[maxn];
inline int rand() {//生成随机值
	static int seed = 1007;
	return seed = (int)seed * 482711ll % 2147483647;
}
inline void updown(int x) {//更新父节点
	treap[x].sz = treap[x].cnt + treap[treap[x].ch[0]].sz + treap[treap[x].ch[1]].sz;
}
inline void rotate(int &x, int f) {//旋转，f==true右旋转，f==false左旋转
	int y = treap[x].ch[f ^ 1];
	treap[x].ch[f ^ 1] = treap[y].ch[f];
	treap[y].ch[f] = x;
	updown(x);
	updown(y);
	x = y;
}
inline void insert(int &x, int v) {//插入元素
	if (!x) {
		treap[x = ++cnt] = TREAP(v, rand());
		return;
	}
	if (v == treap[x].v) {
		treap[x].cnt++;//注释这句是set，不注释是mulset
		treap[x].sz++;//同上
		return;
	}
	int f = v < treap[x].v;
	insert(treap[x].ch[f ^ 1], v);
	if (treap[treap[x].ch[f ^ 1]].rd < treap[x].rd)
		rotate(x, f);
	updown(x);
}
inline bool del(int &x, int v) {//删除元素
	if (x == 0)
		return 0;
	if (treap[x].v == v) {
		if (treap[x].cnt > 1) {
			treap[x].cnt--;
			treap[x].sz--;
			return 1;
		}
		else {
			if (treap[x].ch[0] && treap[x].ch[1]) {
				rotate(x, treap[treap[x].ch[0]].rd < treap[treap[x].ch[1]].rd);
				int f = v < treap[x].v;
				del(treap[x].ch[f ^ 1], v);
			}
			else {
				if (treap[x].ch[0])
					x = treap[x].ch[0];
				else
					x = treap[x].ch[1];
				return 1;
			}
		}
	}
	int f = v < treap[x].v;
	f = del(treap[x].ch[f ^ 1], v);
	updown(x);
	return f;
}
int k_th(int x, int k)//询问第K大
{
	int ls = treap[x].ch[0], rs = treap[x].ch[1];
	if (treap[ls].sz >= k)
		return k_th(ls, k);
	if (treap[ls].sz + treap[x].cnt >= k)
		return treap[x].v;
	return k_th(rs, k - treap[ls].sz - treap[x].cnt);
}
struct LR{
	int l,r,id,k;
	bool operator <(const LR &x){
		return l<x.l;
	}
}lr[50000+5];
int t[maxn],ans[50000+5];
int main(){
	int n,m;
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++){
		scanf("%d", &t[i]);
	}
	for(int i = 1;i <= m;i++){
		scanf("%d%d%d", &lr[i].l,&lr[i].r,&lr[i].k);
		lr[i].id = i;
	}
	sort(lr+1,lr+m+1);
	for(int i = 1;i <= m;i++){
		if(i == 1){
			for(int j = lr[i].l;j <= lr[i].r;j++)
				insert(rt,t[j]);
			ans[lr[i].id] = k_th(rt,lr[i].k);
			continue;
		}
		for(int j = lr[i-1].l;j < lr[i].l && j <= lr[i-1].r;j++)
			del(rt,t[j]);
		if(lr[i].r < lr[i-1].r)
			for(int j = lr[i].r+1;j <= lr[i-1].r;j++)
				del(rt,t[j]);
		else
			for(int j = max(lr[i].l, lr[i-1].r+1);j <= lr[i].r;j++)
				insert(rt, t[j]);
		ans[lr[i].id] = k_th(rt,lr[i].k);
	}
	for(int i = 1;i <= m;i++)
		printf("%d\n",ans[i]);
	return 0;
}
