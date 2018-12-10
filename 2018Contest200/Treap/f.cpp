#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 15000 + 10;
int cnt = 0, rt = 0;
struct TREAP {
	int rd;
	int v;
	int cnt;
	int sz;
	int ch[2];
	TREAP() { }
	TREAP(int a, int b) :v(a), rd(b) {
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
inline void insert(int &x, int v) {
	if (!x) {
		treap[x = ++cnt] = TREAP(v, rand());
		return;
	}
	int f = v < treap[x].v;
	insert(treap[x].ch[f ^ 1], v);
	if (treap[treap[x].ch[f ^ 1]].rd < treap[x].rd)
		rotate(x, f);
	updown(x);
	return;
}
int count(int x, int v)
{
	if (!x)
		return 0;
	if (v >= treap[x].v)
		return treap[x].sz - treap[treap[x].ch[1]].sz + count(treap[x].ch[1], v);
	return count(treap[x].ch[0], v);
}
int level[maxn];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1;i <= n;i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		insert(rt, x);
		level[count(rt, x)-1]++;
	}
	for (int i = 0;i < n;i++)
		printf("%d\n", level[i]);
	return 0;
}
