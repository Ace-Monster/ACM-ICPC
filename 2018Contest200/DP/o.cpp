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
char s[105];
int dp[105][105];
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	while(~scanf("%s", s+1)){
		if(s[1] == 'e')
			break;
		memset(dp, 0, sizeof dp);
		int n = strlen(s+1);
		for(int l = 2;l <= n;l++){
			for(int i = 1;i <= n;i++){
				int j = i+l-1;
				if(j > n)
					break;
				if((s[i] == '(' && s[j] == ')') || (s[i] == '[' && s[j] == ']'))
					dp[i][j] = dp[i+1][j-1]+2;
				for(int k = i;k < j;k++){
					dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j]);
				}
			}
		}
		printf("%d\n", dp[1][n]);
	}
	return 0;
}
