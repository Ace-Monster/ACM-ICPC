#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(a-1); i>=(b); i--)
#define qrep(i, q) for(auto i : q)
#define sz(a) (int)a.size()
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
#define lowbit(x) x&(-x)
#define all(x) x.begin(),x.end()
#define endl "\n"
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn = 1005;
const int logn = (log(maxn)/log(2))+5;
const int inf = 0x3f3f3f3f;
const ld eps = 1e-9;
int a[maxn],b[maxn];
int dp[maxn][maxn];
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n;
	cin >> n;
	rep(i, 1, n+1) cin >> a[i];
	rep(i, 1, n+1) cin >> b[i];
	rep(i, 1, n+1){
		rep(j, 1, n+1){
			if(a[i] == b[j]) dp[i][j] = dp[i-1][j-1]+1;
			else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
		}
	}
	cout << dp[n][n] << endl;
	return 0;
}

