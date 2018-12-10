#include<iostream>
#include<stack>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<string>
#include<string.h>
#include<queue>
#include<functional>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(a) (int)a.size()
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
#define be begin
#define en end
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn = 100000;
struct TREE {
	int len;
	int nsmaxr, nsmaxl, nsmax;
	int dsmaxr, dsmaxl, dsmax;
	int nslay, dslay, sxlay;
}tree[maxn << 2];
#define ls rt<<1
#define rs rt<<1|1
#define lson l,mid,ls
#define rson mid+1,r,rs
void ds(int rt) {
	tree[rt].dslay = 1;
	tree[rt].dsmax = tree[rt].dsmaxl = tree[rt].dsmaxr = 0;
}
void ns(int rt) {
	tree[rt].nslay = 1;
	tree[rt].dslay = 0;
	tree[rt].dsmax = tree[rt].dsmaxl = tree[rt].dsmaxr = 0;
	tree[rt].nsmax = tree[rt].nsmaxl = tree[rt].nsmaxr = 0;
}
void sx(int rt) {
	tree[rt].dslay = tree[rt].nslay = 0;
	tree[rt].sxlay = 1;
	tree[rt].nsmax = tree[rt].nsmaxl = tree[rt].nsmaxr = tree[rt].len;
	tree[rt].dsmax = tree[rt].dsmaxl = tree[rt].dsmaxr = tree[rt].len;
}
void pushup(int rt) {
	tree[rt].dsmax = max(tree[ls].dsmaxr + tree[rs].dsmaxl, max(tree[ls].dsmax, tree[rs].dsmax));
	tree[rt].dsmaxl = (tree[ls].dsmaxl == tree[ls].len) ? tree[ls].dsmaxl + tree[rs].dsmaxl : tree[ls].dsmaxl;
	tree[rt].dsmaxr = (tree[rs].dsmaxr == tree[rs].len) ? tree[rs].dsmaxr + tree[ls].dsmaxr : tree[rs].dsmaxr;

	tree[rt].nsmax = max(tree[ls].nsmaxr + tree[rs].nsmaxl, max(tree[ls].nsmax, tree[rs].nsmax));
	tree[rt].nsmaxl = (tree[ls].nsmaxl == tree[ls].len) ? tree[ls].nsmaxl + tree[rs].nsmaxl : tree[ls].nsmaxl;
	tree[rt].nsmaxr = (tree[rs].nsmaxr == tree[rs].len) ? tree[rs].nsmaxr + tree[ls].nsmaxr : tree[rs].nsmaxr;
}
void pushdown(int rt) {
	if (tree[rt].sxlay) {
		sx(ls);
		sx(rs);
		tree[rt].sxlay = 0;
	}
	if (tree[rt].dslay) {
		ds(ls);
		ds(rs);
		tree[rt].dslay = 0;
	}
	if (tree[rt].nslay) {
		ns(ls);
		ns(rs);
		tree[rt].nslay = 0;
	}
}
void build(int l, int r, int rt) {
	tree[rt].len = r - l + 1;
	tree[rt].nslay = tree[rt].dslay = tree[rt].sxlay = 0;
	if (l == r) {
		tree[rt].dsmax = tree[rt].nsmax = 1;
		tree[rt].dsmaxl = tree[rt].nsmaxl = 1;
		tree[rt].dsmaxr = tree[rt].nsmaxr = 1;
		return;
	}
	int mid = (l + r) >> 1;
	build(lson);
	build(rson);
	pushup(rt);
	return;
}
void update(int op, int L, int R, int l, int r, int rt) {
	if (L <= l && r <= R) {
		if (op == 2)
			sx(rt);
		else if (op == 1)
			ds(rt);
		else ns(rt);
		return;
	}
	pushdown(rt);
	int mid = (l + r) >> 1;
	if (L <= mid) update(op, L, R, lson);
	if (mid < R) update(op, L, R, rson);
	pushup(rt);
	return;
}
int query(int op, int t, int l, int r, int rt) {
	if (l == r)
		return l;
	pushdown(rt);
	int mid = (l + r) >> 1;
	if (op == 1) {
		if (tree[ls].dsmax >= t) return query(op, t, lson);
		if (tree[ls].dsmaxr + tree[rs].dsmaxl >= t) return mid - tree[ls].dsmaxr + 1;
		return query(op, t, rson);//
	}
	else {
		if (tree[ls].nsmax >= t) return query(op, t, lson);
		if (tree[ls].nsmaxr + tree[rs].nsmaxl >= t) return mid - tree[ls].nsmaxr + 1;
		return query(op, t, rson);//
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	scanf("%d", &T);
	for (int i = 1;i <= T;i++) {
		int t, n;
		printf("Case %d:\n", i);
		scanf("%d%d", &t, &n);
		build(1, t, 1);
		while (n--) {
			//getchar();
			char s[10];
			int q;
			scanf("%s%d", s, &q);
			if (s[0] == 'D') {
				if (tree[1].dsmax < q) puts("fly with yourself");
				else {
					int x = query(1, q, 1, t, 1);
					printf("%d,let's fly\n", x);
					update(1, x, q + x - 1, 1, t, 1);
				}
			}
			else if (s[0] == 'N') {
				if(tree[1].dsmax < q){
					if (tree[1].nsmax < q) puts("wait for me");
					else {
						int x = query(0, q, 1, t, 1);
						printf("%d,don't put my gezi\n", x);
						update(0, x, x + q - 1, 1, t, 1);
					}
				}
				else {
					int x = query(1, q, 1, t, 1);
					printf("%d,don't put my gezi\n", x);
					update(0, x, x + q - 1, 1, t, 1);
				}
			}
			else {
				int r;
				scanf("%d", &r);
				puts("I am the hope of chinese chengxuyuan!!");
				update(2, q, r, 1, t, 1);
			}
		}
	}
	return 0;
}
