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
int old[55];
int dp[55][10];
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n;
	cin >> n;
	rep(i, 0, n)
		cin >> old[i];
	rep(i, 0, 10)
		dp[0][i] = 1;
	rep(i, 1, n){
		rep(j, 0, 10){
			int k = j + old[i];
			if(k%2)
				dp[i][k/2] += dp[i - 1][j], dp[i][k/2+1] += dp[i - 1][j];
			else
				dp[i][k/2] += dp[i - 1][j];
		}
	}
	int t = old[0];
	long long sum = 0;
	rep(i, 1, n + 1){
		if(i == n)
		{
			sum--;
			break;
		}
		t = t + old[i];
		if(!(t%2))
		{
			if(t/2 != old[i])
				break;
		}
		else
			if(t/2 != old[i] && t/2+1 != old[i])
				break;
	}
	rep(i, 0, 10)
		sum+=dp[n - 1][i];
	cout << sum << endl;
	return 0;
}
