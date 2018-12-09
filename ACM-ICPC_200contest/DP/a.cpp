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
ll dp[7][2],a[10],b[10];
ll dfs(int pos,int pre,int sta,bool limit){
	if(pos == 0)return 1;
	ll tmp = 0;
	if(!limit && dp[pos][sta] != -1)
		return dp[pos][sta];
	int n = limit ? a[pos] : 9;
	for(int i = 0;i <= n;i++){
		if(pre == 6 && i == 2)
			continue;
		if(i == 4)
			continue;
		tmp += dfs(pos-1, i, i == 6,limit && i == a[pos]);
	}
	if(!limit) 
		dp[pos][sta] = tmp;
	return tmp;
}
ll solve(int n){
	int i;
	for(i = 1;n;i++)
		a[i] = n%10,n/=10;
	return dfs(i - 1, -1, 0, 1);
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	ll n,m;
	memset(dp,-1,sizeof dp);
	while(~scanf("%lld%lld", &n, &m) && n+m){
		printf("%lld\n",solve(m)-solve(n-1));
	}
	return 0;
}
