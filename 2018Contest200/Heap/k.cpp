#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<string>
#include<string.h>
#include<queue>
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
int dp[205][205];
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n,m;
	int T = 0;
	while(cin >> n >> m){
		if(n == 0) break;
		cout << "Scenario #" << ++T << endl;
		memset(dp, -1, sizeof(dp));
		for(int i = 1;i <= n;i++)
			dp[i][i] = 0;
		int t = 0;
		map<string, int> e;
		string s1, s2;
		for(int i = 0;i < m;i++){
			int j;
			cin >> s1 >> s2 >> j;
			if(e[s1] == 0)e[s1] = ++t;
			if(e[s2] == 0)e[s2] = ++t;
			dp[e[s1]][e[s2]] = j;
			dp[e[s2]][e[s1]] = j;
		}
		cin >> s1 >> s2;
		int x = e[s1], y = e[s2];
		for(int k = 1;k <= n;k++)
			for(int i = 1;i <= n;i++)
				for(int j = 1;j <= n;j++)
					dp[i][j] = max(dp[i][j], min(dp[i][k], dp[k][j]));
		cout << dp[x][y] <<" tons"<< endl;
		cout << endl;
	}
	return 0;
}
