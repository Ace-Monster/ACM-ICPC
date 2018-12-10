#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(a) (int)a.size()
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn = 5005;
ll dp[maxn][maxn];
ll a[maxn];
deque<ll> q[maxn];
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n,k,x;
	scanf("%d%d%d", &n, &k, &x);
	rep(i, 0, n){
		scanf("%lld", &a[i]);
	}
	if(n/k > x){
		puts("-1");
		return 0;
	}
	rep(i, 0, n){
		dp[i][x] = -1;
		int j = min(i+1, x);
		for(;j >= 1;j--){
			while(q[j-1].size() && i-q[j-1].front() > k) q[j-1].pop_front();
			if(q[j-1].size())
				dp[i][j] = dp[q[j-1].front()][j-1]+a[i];
			else if(j == 1 && i < k)
				dp[i][j] = a[i];
			else{
				dp[i][j] = -1;
				continue;
			}
			while(q[j].size() && dp[q[j].back()][j] < dp[i][j]) q[j].pop_back();
			q[j].push_back(i);
		}
		dp[i][0] = 0;
	}
	ll ans = -1;
	rep(i, n-k, n){
		ans = max(ans, dp[i][x]);
	}
	printf("%lld\n", ans);
	return 0;
}
