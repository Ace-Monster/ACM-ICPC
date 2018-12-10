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
const int maxn = 100005;
ll dp[105][10005], a[105];
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n;
	scanf("%d", &n);
	ll sum = 0, m = 0;
	for(int i = 1;i <= n;i++){
		int t;
		scanf("%d", &t);
		a[t]++;
		sum += a[t];
		if(a[t] == 1) m++;
	}
	if(m == 1 || m == 2){
		printf("%d\n", n);
		return 0;
	}
	dp[0][0] = 1;
	for(int i = 1;i <= 100;i++){
		if(a[i] == 0)
			continue;
		for(int j = 10000;j >= 0;j--){
			for(int k = 100;k >= 1;k--){
				for(int l = 1;l <= a[i];l++){
					if(k >= l && j >= l*i)
						dp[k][j] += dp[k-l][j-l*i];
				}
			}
		}
	}
	int ans = 0;
	for(int i = 1;i <= 100;i++){
		if(a[i] == 0) continue;
		for(int j = 1;j <= a[i];j++){
			if(dp[j][i*j] == 1) ans = max(ans, j);
		}
	}
	printf("%d\n", ans);
	return 0;
}
