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
int dp[505], men[505][505];
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n;
	while(~scanf("%d", &n)){
		memset(dp, 0, sizeof dp);
		memset(men, 0, sizeof men);
		for(int t = 1;t <= n;t++){
			int x,y;
			scanf("%d%d", &x, &y);
			if(men[x+1][n-y] >= (n-y)-x || x+y >= n)
				continue;
			men[x+1][n-y]++;
		}
		for(int i = 1;i <= n;i++){
			for(int k = 0;k < i;k++)
				dp[i] = max(dp[i], dp[k]+men[k+1][i]);
		}
		printf("%d\n", dp[n]);
	}
	return 0;
}
