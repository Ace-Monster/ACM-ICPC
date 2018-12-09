#define _CRT_SECURE_NO_WARNINGS
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
const int mod = 10007;
struct TREE {
	ll sum1, sum2, sum3, add, mul, sets;
}tree[100005 << 2];
inline void Set(ll sets,int rt,ll i) {
	tree[rt].sum1 = (sets*i) % mod;
	tree[rt].sum2 = (sets*sets*i) % mod;
	tree[rt].sum3 = (sets*sets*sets*i) % mod;
}
inline void Add(ll add,int rt,ll i) {
	tree[rt].add = (tree[rt].add + add) % mod;
	tree[rt].sum3 = (tree[rt].sum3 + (add*add*add*i % mod) + 3 * add*((tree[rt].sum2 + tree[rt].sum1*add) % mod) % mod) % mod;
	tree[rt].sum2 = (tree[rt].sum2 + (add*add*i % mod + (2 * add*tree[rt].sum1) % mod) % mod) % mod;
	tree[rt].sum1 = (tree[rt].sum1 + add * i % mod) % mod;
}
inline void Mul(ll mul, int rt) {
	tree[rt].mul = (tree[rt].mul*mul) % mod;
	tree[rt].add = (tree[rt].add*mul) % mod;
	tree[rt].sum1 = (tree[rt].sum1*mul) % mod;
	tree[rt].sum2 = (tree[rt].sum2*mul*mul) % mod;
	tree[rt].sum3 = (tree[rt].sum3*mul*mul*mul) % mod;
}
inline void pushup(int rt) {
	tree[rt].sum1 = (tree[rt << 1].sum1 + tree[rt << 1 | 1].sum1) % mod;
	tree[rt].sum2 = (tree[rt << 1].sum2 + tree[rt << 1 | 1].sum2) % mod;
	tree[rt].sum3 = (tree[rt << 1].sum3 + tree[rt << 1 | 1].sum3) % mod;
}
inline void pushdown(int rt, int i) {
	if (tree[rt].sets != 0) {
		ll sets = tree[rt].sets;
		tree[rt].sets = 0;
		tree[rt << 1].sets = tree[rt << 1 | 1].sets = sets;
		Set(sets, rt << 1, i - (i >> 1));
		Set(sets, rt << 1 | 1, (i >> 1));
		tree[rt << 1].add = tree[rt << 1 | 1].add = 0;
		tree[rt << 1].mul = tree[rt << 1 | 1].mul = 1;
	}
	if (tree[rt].mul != 1) {
		ll mul = tree[rt].mul;
		tree[rt].mul = 1;
		Mul(mul, rt << 1);
		Mul(mul, rt << 1 | 1);
	}
	if (tree[rt].add != 0) {
		ll add = tree[rt].add;
		tree[rt].add = 0;
		Add(add, rt << 1, i - (i >> 1));
		Add(add, rt << 1 | 1, i >> 1);
	}
}
inline void update(ll t, ll q, ll L, ll R, int l, int r, int rt) {
	if (tree[rt].mul == 0) tree[rt].mul = 1;
	if (L <= l && r <= R) {
		if (q == 1) {
			Add(t, rt, r - l + 1);
		}
		if (q == 2) {
			Mul(t, rt);
		}
		if (q == 3) {
			tree[rt].mul = 1;
			tree[rt].add = 0;
			tree[rt].sets = t;
			Set(t, rt, r - l + 1);
		}
		return;
	}
	pushdown(rt, r - l + 1);
	int mid = (l + r) >> 1;
	if (L <= mid) update(t, q, L, R, l, mid, rt << 1);
	if (mid < R) update(t, q, L, R, mid + 1, r, rt << 1 | 1);
	pushup(rt);
	return;
}
inline ll query(ll t, ll L, ll R, int l, int r, int rt) {
	if (L <= l && r <= R) {
		if (t == 1)
			return tree[rt].sum1;
		if (t == 2)
			return tree[rt].sum2;
		if (t == 3)
			return tree[rt].sum3;
	}
	pushdown(rt, r - l + 1);
	int mid = (l + r) >> 1;
	ll a = 0, b = 0;
	if (L <= mid) a = query(t, L, R, l, mid, rt << 1);
	if (mid < R) b = query(t, L, R, mid + 1, r, rt << 1 | 1);
	return (a + b) % mod;
}
int main()
{
	//std::ios::sync_with_stdio(false);
	//std::cin.tie(0);
	int n, m;
	while (~scanf("%d%d", &n, &m)) {
		if (n == 0)break;
		memset(tree, 0, sizeof tree);
		/*for (int i = 1;i < (n << 4);i++) {
			tree[i].sum1 = 0, tree[i].sum2 = 0, tree[i].sum3 = 0, tree[i].add = 0, tree[i].mul = 1, tree[i].sets = 0;
		}*/
		while (m--) {
			ll op, x, y, c;
			scanf("%lld%lld%lld%lld", &op, &x, &y, &c);
			if (op != 4) {
				update(c, op, x, y, 1, n, 1);
			}
			else {
				printf("%lld\n", query(c, x, y, 1, n, 1));
			}
		}
	}
	return 0;
}
