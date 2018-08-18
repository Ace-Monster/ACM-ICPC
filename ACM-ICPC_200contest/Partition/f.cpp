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
const int maxn = 200+5;
int h1[maxn],h2[maxn];
int dp[maxn][maxn];
int LCS(int n){
	for(int xn = 1;xn <= n;xn++){
		if(h1[xn] == h2[yn])
			dp[xn][yn] = dp[xn-1][yn-1]+1;
		else
			dp[xn][yn] = max(dp[xn][yn-1], dp[xn-1][yn]);
	}
	
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int T;
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d", &n);
		for(int i = 1;i <= n;i++){
			scanf("%d", &h1[i]);
			h2[n-i+1] = h1[i];
		}
		
	}
	return 0;
}
