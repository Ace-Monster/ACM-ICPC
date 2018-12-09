#include<iostream>
#include<stack>
#include<cstdio>
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
long double dp[25][200];
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	printf("Round   A wins    B wins    Tie\n");
	dp[0][100] = 1;
	for(int i = 1;i <= 20;i++){
		for(int j = -100;j <= 100;j++){
			dp[i][j+100] = dp[i-1][j+100]*(6.0/16.0)+dp[i-1][j+100+1]*(2.0/16.0)+dp[i-1][j+100-1]*(4.0/16.0)+dp[i-1][j+100-2]*(2.0/16.0)+dp[i-1][j+100-3]*(1.0/16.0)+dp[i-1][j+100+3]*(1.0/16.0);
		}
		long double A = 0,B = 0,C = 0;
		for(int j = 1;j < 100;j++)
			B += dp[i][j], A += dp[i][j+100];
		C = dp[i][100];
		printf("%5d   %7.4Lf%% %8.4Lf%% %8.4Lf%%\n",i,A*100,B*100,C*100);
	}
	return 0;
}
