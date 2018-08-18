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
const int maxn = 20;
ll dp[maxn][maxn][2000];
ll x[maxn];
ll dfs(ll pos, ll k, ll s, ll limit, ll line) {
	if (pos == 0) {
		if (line || k != 0)
			return 0;
		return 1;
	}
	if (!limit && dp[pos][k][s] != -1)
		return dp[pos][k][s];
	ll ts = s;
	ll si[maxn], cnt = 0, j = 0;
	memset(si, -1, sizeof si);
	while (ts) {
		if (ts % 2)
			si[++cnt] = j;
		ts >>= 1, ++j;
	}
	ll n = limit ? x[pos] : 9;
	ll tmp = 0;
	for (int i = 0;i <= n;i++) {
		if (line) {
			if (i == 0) {
				tmp += dfs(pos - 1, k, s, limit && i == x[pos], line);
				continue;
			}
		}
		ts = s;
		if (cnt == 0) {
			ts = 1 << i;
			tmp += dfs(pos - 1, k - 1, ts, limit && i == x[pos], 0);
		}
		for (j = 1;j <= cnt;j++) {
			if (si[j] >= i && si[j - 1] < i) {
				ts = (ts - (1 << si[j])) + (1 << i);
				tmp += dfs(pos - 1, k, ts, limit && i == x[pos], 0);
				break;
			}
			if (j == cnt) {
				if (k == 0)
					break;
				ts = ts + (1 << i);
				tmp += dfs(pos - 1, k - 1, ts, limit && i == x[pos], 0);
			}
		}
	}
	if (!limit)
		dp[pos][k][s] = tmp;
	return tmp;
}
ll solve(ll n, ll k) {
	int l = 1;
	while (n) {
		x[l++] = n % 10;
		n /= 10;
	}
	return dfs(l - 1, k, 0, 1, 1);
}
int main()
{
	//std::ios::sync_with_stdio(false);
	//std::cin.tie(0);
	int T;
	scanf("%d", &T);
	memset(dp, -1, sizeof dp);
	for (int i = 1;i <= T;i++) {
		ll a, b, k;
		scanf("%lld%lld%lld", &a, &b, &k);
		printf("Case #%d: %lld\n", i, solve(b, k) - solve(a - 1, k));
	}
	return 0;
}
