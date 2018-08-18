#define  _CRT_SECURE_NO_WARNINGS
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
#define rep(i, a, b) for(ll i=(a); i<(b); i++)
#define sz(a) (ll)a.size()
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
#define be begin
#define en end
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
const ll maxn = 30;
const ll M = 1000000007;
struct A {
	ll sum1;
	ll sum2;
	ll s;
	A() {
		sum1 = 0;
		sum2 = 0;
		s = -1;
	}
	A(ll a, ll b, ll c) { sum1 = a, sum2 = b, s = c; }
}dp[maxn][maxn][maxn];
ll x[maxn];
ll pows[maxn];
A dfs(ll pos, ll add, ll mods, ll limit) {
	if (pos == 0) {
		if (add == 0 || mods == 0)
			return A(0, 0, 0);
		return A(0, 0, 1);
	}
	if (!limit && dp[pos][add][mods].s != -1)
		return dp[pos][add][mods];
	ll n = limit ? x[pos] : 9;
	A tmp;
	tmp.s = 0;
	for (int i = 0;i <= n;i++) {
		if (i == 7)
			continue;
		A t = dfs(pos - 1, (add + i) % 7, (mods * 10 + i) % 7, limit && i == x[pos]);
		tmp.s = (t.s + tmp.s) % M;
		tmp.sum1 = (((((t.s*i) % M) * pows[pos - 1]) % M) + t.sum1 + tmp.sum1) % M;
		tmp.sum2 = ((((((t.s*i*i) % M)*pows[pos - 1]) % M)*pows[pos - 1]) % M + (t.sum2) % M + ((((2 * i*pows[pos - 1]) % M)*t.sum1) % M) + tmp.sum2) % M;
	}
	if (!limit)
		dp[pos][add][mods] = tmp;
	return tmp;
}
ll solve(ll n) {
	int l = 1;
	while (n) {
		x[l++] = n % 10;
		n /= 10;
	}
	return dfs(l - 1, 0, 0, 1).sum2;
}
int main()
{
	//std::ios::sync_with_stdio(false);
	//std::cin.tie(0);
	ll T;
	scanf("%lld", &T);
	memset(dp, -1, sizeof dp);
	pows[0] = 1;
	for (int i = 1;i < 20;i++) pows[i] = (pows[i - 1] * 10) % M;
	while (T--) {
		ll a, b;
		scanf("%lld%lld", &a, &b);
		printf("%lld\n", ((solve(b) - solve(a - 1)) + M) % M);
	}
	return 0;
}
