#include<iostream>
#include<cstdio>
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
int c[5], w[5] = {0,1,5,10,25}, ans[5][10005];
int dp[10][10005];
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int v;
	while(~scanf("%d", &v) && v){
		memset(ans, 0, sizeof ans);
		for(int i = 1;i <= 4;i++)
			scanf("%d", &c[i]);
		for(int i = 0;i <= v;i++)
			dp[0][i] = -1;
		dp[0][0] = 0;
		for(int i = 1;i <= 4;i++){
			for(int j = 0;j <= v;j++){
				if(dp[i-1][j] >= 0){
					dp[i][j] = c[i];
					ans[i][j] = c[i];
				}
				else
					dp[i][j] = -1;
			}
			for(int j = 0;j <= v-w[i];j++)
				if(dp[i][j] > 0)
					if(dp[i][j+w[i]] < dp[i][j]-1){
						dp[i][j+w[i]] = dp[i][j]-1;
						ans[i][j]--;
					}
		}
		if(dp[4][v] == -1)
			printf("Charlie cannot buy coffee.\n");
		else
			printf("Throw in %d cents, %d nickels, %d dimes, and %d quarters.\n", ans[1][v], ans[2][v], ans[3][v], ans[4][v]);
	}
	return 0;
}
