#define _CRT_SECURE_NO_DEPRECATE
#include<cstdio>
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
int r[1000005], l[1000005];
inline void links(int L, int R) {
	l[R] = L, r[L] = R;
}
int main()
{
	ll n, m;
	int t = 0;
	while (~scanf("%lld%lld", &n, &m)) {
		for (int i = 1;i <= n;i++) {
			r[i] = (i + 1) % (n + 1);
			l[i] = i - 1;
		}
		r[0] = 1, l[0] = n;
		int op;
		bool flag = false;
		for (int i = 0;i < m;i++) {
			scanf("%d", &op);
			if (op == 4) { flag = !flag;continue; }
			int x, y;
			scanf("%d%d", &x, &y);
			if ((op == 1 || op == 2) && flag) op = 3 - op;
			if (op == 1) {
				if (x == l[y]) continue;
				int lx = l[x], ly = l[y], rx = r[x], ry = r[y];
				links(lx, rx);
				links(ly, x);
				links(x, y);
			}
			else if (op == 2) {
				if (x == r[y]) continue;
				int lx = l[x], ly = l[y], rx = r[x], ry = r[y];
				links(lx, rx);
				links(y, x);
				links(x, ry);
			}
			else if (op == 3) {
				if (r[y] == x) swap(x, y);
				int lx = l[x], ly = l[y], rx = r[x], ry = r[y];
				if (rx == y) {
					links(lx, y);
					links(y, x);
					links(x, ry);
				}
				else {
					links(lx, y);
					links(y, rx);
					links(ly, x);
					links(x, ry);
				}
			}
		}
		ll sum = 0;
		for (int i = 1,k = 0;i <= n;i++) {
			k = r[k];
			if (i % 2) sum += k;
		}
		if (flag && n % 2 == 0) sum = n * (n + 1) / 2 - sum;
		printf("Case %d: %lld\n", ++t, sum);
	}
	return 0;
}

