#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<functional>
#include<stack>
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
ll dp[20][5];
int a[20];
ll dfs(int pos, int s, int limit){
	//dd(pos),de(s);
	if(pos == 0) return 1;
	if(!limit && dp[pos][s] != -1) return dp[pos][s];
	int n = (limit ? a[pos] : 9);
	//de(n);
	ll tmp = 0;
	for(int i = 0;i <= n;i++){
		if(i == 0)
			tmp += dfs(pos-1, s, limit && i == a[pos]);
		else if(s < 3)
			tmp += dfs(pos-1, s+1, limit && i == a[pos]);
	}
	if(!limit)
		dp[pos][s] = tmp;
	return tmp;
}
ll solve(ll b){
	int i = 0;
	while(b){
		a[++i] = b%10;
		b/=10;
	}
	ll s = dfs(i, 0, 1);
	//de(s);
	return s;
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int q;
	scanf("%d", &q);
	memset(dp, -1, sizeof dp);
	while(q--){
		ll l,r;
		scanf("%lld%lld", &l, &r);
		printf("%lld\n", solve(r)-solve(l-1));
	}
	return 0;
}
