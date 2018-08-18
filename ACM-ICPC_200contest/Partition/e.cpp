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
ll dfs(ll mid, ll l, ll r) {
	if (l == r)
		return 1;
	ll sum = 0;
	if (l <= mid && r >= mid)
		sum++;
	if (l < mid) {
		ll tsum = dfs(mid >> 1, l, min(mid - 1, r));
		sum += tsum;
		if (r - mid == mid - l) {
			sum += (mid - l - tsum);
			return sum;
		}
	}
	if (r > mid) {
		sum += dfs(mid >> 1, 1, r - mid);
		if (r - mid >= (mid >> 1)) sum--;
	}
	return sum;
}
int main()
{
	//std::ios::sync_with_stdio(false);
	//std::cin.tie(0);
	int T;
	scanf("%d", &T);
	while (T--) {
		ll l, r;
		scanf("%lld%lld", &l, &r);
		printf("%lld\n", dfs((ll)1 << 62, 1, r) - dfs((ll)1 << 62, 1, l - 1));
	}
	return 0;
}
