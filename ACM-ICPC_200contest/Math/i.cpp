#include<iostream>
#include<vector>
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
ll dp[125][125];
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	dp[1][1] = 1, dp[0][0] = 1;
	int n;
	while(cin >> n){
		rep(i, 2, n+1){
			rep(j, 1, i+1)
			{
				dp[i][j] = dp[i][j-1]+dp[i-j][j];
				if(i-j < j) dp[i][j] += dp[i-j][i-j];
			}
		}
		cout << dp[n][n] << endl;
	}
	return 0;
}
