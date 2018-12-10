#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e5 + 10;
int cnt = 0, rt = 0;
struct TREAP {
	int rd;
	int v;
	int id;
	int cnt;
	int sz;
	int ch[2];
	TREAP() { }
	TREAP(int a, int c, int b) :v(a), id(c), rd(b) {
		cnt = sz = 1;
		ch[0] = ch[1] = 0;
	}
}treap[maxn];
inline int rand() {
	static int seed = 1007;
	return seed = (int)seed * 482711ll % 2147483647;
}
inline void updown(int x) {
	treap[x].sz = treap[x].cnt + treap[treap[x].ch[0]].sz + treap[treap[x].ch[1]].sz;
}
inline void rotate(int &x, int f) {
	int y = treap[x].ch[f ^ 1];
	treap[x].ch[f ^ 1] = treap[y].ch[f];
	treap[y].ch[f] = x;
	updown(x);
	updown(y);
	x = y;
}
inline void insert(int &x, int v, int id) {
	if (!x) {
		treap[x = ++cnt] = TREAP(v, id, rand());
		return;
	}
	int f = v < treap[x].v;
	insert(treap[x].ch[f ^ 1], v, id);
	if (treap[treap[x].ch[f ^ 1]].rd < treap[x].rd)
		rotate(x, f);
	updown(x);
	return;
}
int k_th(int x, int k, int &id)
{
	int ls = treap[x].ch[0], rs = treap[x].ch[1];
	if (treap[ls].sz >= k)
		return k_th(ls, k, id);
	if (treap[ls].sz + treap[x].cnt >= k) {
		id = treap[x].id;
		return treap[x].v;
	}
	return k_th(rs, k - treap[ls].sz - treap[x].cnt, id);
}
int count(int x, int v)
{
	if (!x)
		return 0;
	if (v > treap[x].v)
		return treap[x].sz - treap[treap[x].ch[1]].sz + count(treap[x].ch[1], v);
	return count(treap[x].ch[0], v);
}
int main() {
	int n;
	while (~scanf("%d", &n)) {
		if (n == 0)break;
		rt = 0, cnt = 0;
		memset(treap, 0, sizeof treap);
		insert(rt, 1000000000, 1);
		for (int i = 0;i < n;i++) {
			int id, g;
			scanf("%d%d", &id, &g);
			int k = count(rt, g);
			int aid, bid;
			int a = 1000000000,b;
			if(k != 0)
				a = k_th(rt, k, aid);
			b = k_th(rt, k + 1, bid);
			if (abs(b - g) < abs(a - g) || k == 0)
				aid = bid;
			printf("%d %d\n", id, aid);
			insert(rt, g, id);
		}
	}
	return 0;
}
