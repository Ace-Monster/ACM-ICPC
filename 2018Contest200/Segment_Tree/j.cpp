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
int tree[8005 << 2];
void pushup(int rt) {
	if (tree[rt << 1] == tree[rt << 1 | 1])
		tree[rt] = tree[rt << 1];
	else
		tree[rt] = -1;
}
void pushdown(int rt) {
	if (tree[rt] != -1) {
		int ans = tree[rt];
		tree[rt << 1] = ans;
		tree[rt << 1 | 1] = ans;
	}
}
void update(int t, int L, int R, int l, int r, int rt) {
	if (L <= l && r <= R) {
		tree[rt] = t;
		return;
	}
	pushdown(rt);
	int mid = (l + r) / 2;
	if (L <= mid) update(t, L, R, l, mid, rt << 1);
	if (R > mid) update(t, L, R, mid + 1, r, rt << 1 | 1);
	pushup(rt);
	return;
}
int a[8005 << 2], b[8005 << 2];
void query(int l, int r, int rt) {
	if (tree[rt] != -1) {
		for (int i = l;i <= r;i++)
			a[i] = tree[rt];
		return;
	}
	if (l == r) return;
	int mid = (l + r) / 2;
	query(l, mid, rt << 1);
	query(mid + 1, r, rt << 1 | 1);
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	while (cin >> n) {
		memset(tree, -1, sizeof tree);
		memset(a, -1, sizeof a);
		memset(b, 0, sizeof b);
		for (int i = 0;i < n;i++) {
			int x, y, z;
			cin >> x >> y >> z;
			update(z, x + 1, y, 1, 8000, 1);
		}
		query(1, 8000, 1);
		int t = -1;
		for (int i = 1;i <= 8000;i++) {
			if(a[i] == -1) {
				t = -1;
				continue;
			}
			if (a[i] != t) {
				t = a[i];
				b[t]++;
			}
		}
		for (int i = 0;i <= 8000;i++) {
			if (b[i] != 0)
				cout << i << ' ' << b[i] << endl;
		}
		cout << endl;
	}
	return 0;
}
