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
	double x, X, y;//起点，终点，高度
	int flag;//入边+1，出边-1
	void in(double a, double b, double c, int f) { x = a, X = b, y = c, flag = f; };
	bool operator<(const Line &b) const {
		return y<b.y;
	}
}line[2010];//边
const int L = 100005;//扫描线长度
struct TREE {
	double sum1, sum2;//至少覆盖1次/2次的长度
	int lay;//覆盖层数
}tree[L << 2];//扫描线
double S[2020];//离散化
const double eps = 1e-9;
void pushup(int l, int r, int rt) {
	if (tree[rt].lay > 1)
		tree[rt].sum2 = tree[rt].sum1 = S[r + 1] - S[l];
	else if (tree[rt].lay == 1) {
		tree[rt].sum1 = S[r + 1] - S[l];
		if (l == r) tree[rt].sum2 = 0;
		else tree[rt].sum2 = tree[rt << 1].sum1 + tree[rt << 1 | 1].sum1;
	}
	else {
		if (l == r) tree[rt].sum1 = tree[rt].sum2 = 0;
		else {
			tree[rt].sum1 = tree[rt << 1].sum1 + tree[rt << 1 | 1].sum1;
			tree[rt].sum2 = tree[rt << 1].sum2 + tree[rt << 1 | 1].sum2;
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
int main()
{
	//std::ios::sync_with_stdio(false);
	//std::cin.tie(0);
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		memset(tree, 0, sizeof tree);
		scanf("%d", &n);
		rep(i, 1, n+1) {
			double x, y, X, Y;
			scanf("%lf%lf%lf%lf", &x, &y, &X, &Y);
			line[i].in(x, X, y, 1), line[n + i].in(x, X, Y, -1);
			S[i] = x, S[n + i] = X;
		}
		n <<= 1;
		sort(S + 1, S + n + 1);
		sort(line + 1, line + n + 1);
		int s = unique(S + 1, S + n + 1) - (S + 1);
		double sum = 0;
		/*for (int i = 1;i <= 2 * n;i++)
			all[i] = lower_bound(S, S + s, all[i]) - S;*/
		for (int i = 0;i < n - 1;i++) {
			int l = lower_bound(S + 1, S + s + 1, line[i].x) - S;
			int r = lower_bound(S + 1, S + s + 1, line[i].X) - S;
			if(l < r) update(line[i].flag, l, r-1, 1, L, 1);
			sum += tree[1].sum2*(line[i+1].y - line[i].y);
		}
		printf("%.2lf\n", sum);
	}
	return 0;
}
