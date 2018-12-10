#define _CRT_SECURE_NO_DEPRECATE 
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
struct Line {
	ll x, X, y;//起点，终点，高度
	int flag;//入边+1，出边-1
	void in(ll a, ll b, ll c, int f) { x = a, X = b, y = c, flag = f; };
	bool operator<(const Line &b) const {
		return y<b.y;
	}
}line[2010];//边
const int L = 2005;//扫描线长度
struct TREE {
	ll sum1, sum2, sum3;//至少覆盖1次/2次的长度
	int lay;//覆盖层数
}tree[L << 2];//扫描线
ll S[2020];//离散化
const double eps = 1e-9;
void pushup(int l, int r, int rt) {
	if (tree[rt].lay > 2)
		tree[rt].sum3 = tree[rt].sum2 = tree[rt].sum1 = S[r + 1] - S[l];
	else if (tree[rt].lay == 2) {
		tree[rt].sum2 = S[r + 1] - S[l];
		if (l == r) tree[rt].sum3 = 0;
		else tree[rt].sum3 = tree[rt << 1].sum1 + tree[rt << 1 | 1].sum1;
	}
	else if (tree[rt].lay == 1) {
		tree[rt].sum1 = S[r + 1] - S[l];
		if (l == r) tree[rt].sum3 = 0, tree[rt].sum2 = 0;
		else {
			tree[rt].sum3 = tree[rt << 1].sum2 + tree[rt << 1 | 1].sum2;
			tree[rt].sum2 = tree[rt << 1].sum1 + tree[rt << 1 | 1].sum1;
		}
	}
	else {
		if (l == r) tree[rt].sum1 = tree[rt].sum2 = tree[rt].sum3 = 0;
		else {
			tree[rt].sum1 = tree[rt << 1].sum1 + tree[rt << 1 | 1].sum1;
			tree[rt].sum2 = tree[rt << 1].sum2 + tree[rt << 1 | 1].sum2;
			tree[rt].sum3 = tree[rt << 1].sum3 + tree[rt << 1 | 1].sum3;
		}
	}
}
void update(int v, int L, int R, int l, int r, int rt) {
	if (L <= l && r <= R) {
		tree[rt].lay += v;
		pushup(l, r, rt);
		return;
	}
	int mid = (l + r) >> 1;
	if (L <= mid) update(v, L, R, l, mid, rt << 1);
	if (R > mid) update(v, L, R, mid + 1, r, rt << 1 | 1);
	pushup(l, r, rt);
	return;
}
struct point {
	ll x, X, y, Y, z, Z;
	bool operator <(const point &a)const {
		return z == a.z ? Z < a.Z : z < a.z;
	}
}p[1001];
int main()
{
	//std::ios::sync_with_stdio(false);
	//std::cin.tie(0);
	int T;
	scanf("%d", &T);
	int t = 0;
	while (T--) {
		int n;
		scanf("%d", &n);
		ll mz = 1e9, Mz = 0;
		
		rep(i, 1, n + 1) {
			scanf("%lld%lld%lld%lld%lld%lld", &p[i].x, &p[i].y, &p[i].z, &p[i].X, &p[i].Y, &p[i].Z);
			p[i].z += 500;
			p[i].Z += 500;
			mz = min(p[i].z, mz);
			Mz = max(p[i].Z, Mz);
			/*for (int j = z[i];j < Z[i];j++)
				zi[j] += 2, line[j][zi[j] - 1].in(x[i], X[i], y[i], 1), line[j][zi[j]].in(x[i], X[i], Y[i], -1);*/
			S[i] = p[i].x, S[n + i] = p[i].X;
		}
		//sort(p + 1, p + n + 1);
		int m = n;
		n <<= 1;
		sort(S + 1, S + n + 1);
		/*for (int i = mz;i <= Mz;i++) {
			if (zi[i] == 0) continue;
			sort(line[i] + 1, line[i] + zi[i] + 1);
		}*/
		int s = unique(S + 1, S + n + 1) - (S + 1);
		ll sum = 0;
		for (int j = mz;j <= Mz;j++) {
			int sz = 0;
			for (int k = 1;k <= m;k++) {
				if (p[k].z <= j && p[k].Z > j)
					line[++sz].in(p[k].x, p[k].X, p[k].y, 1), line[++sz].in(p[k].x,p[k].X,p[k].Y,-1);
			}
			sort(line + 1, line + sz + 1);
			memset(tree, 0, sizeof tree);
			for (int i = 0;i < sz - 1;i++) {
				int l = lower_bound(S + 1, S + s + 1, line[i].x) - S;
				int r = lower_bound(S + 1, S + s + 1, line[i].X) - S;
				if (l < r) update(line[i].flag, l, r - 1, 1, L, 1);
				sum += tree[1].sum3*(line[i + 1].y - line[i].y);
			}
		}
		printf("Case %d: %lld\n", ++t, sum);
	}
	return 0;
}
