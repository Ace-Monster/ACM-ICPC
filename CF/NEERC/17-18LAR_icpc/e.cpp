#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<functional>
#include<stack>
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
const int maxn = 1005;
char s[maxn], a[maxn];
int dp[maxn][maxn];
int mod(int l, int b){
	int d = 0;
	for(int i = 0;i < l;i++)  d = (d*10 + (s[i] - '0')) % b;
    return d;
}
int dfs(int pos, int m, int l, int n){
	if(pos == l){
		if(mod(l, n) == 0)
			return 1;
		return 0;
	}
	if(dp[pos][m] != -1) return dp[pos][m];
	if(a[pos] == '?'){
		for(int i = 0;i <= 9;i++){
			if(pos == 0 && i == 0)
				i = 1;
			s[pos] = i + '0';
			if(dfs(pos+1, (m*10 + i)%n, l, n))
				return 1;
		}
	}
	else
		return dfs(pos+1, (m*10 + (a[pos] - '0'))%n, l, n);
	if(dp[pos][m] == -1) dp[pos][m] = 0;
	return 0;
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
    int n;
	scanf("%s%d", s, &n);
	memcpy(a, s, sizeof a);
	memset(dp, -1, sizeof dp);
	int l = strlen(s);
	if(dfs(0, 0, l, n))
		printf("%s\n", s);
	else
		puts("*");
	return 0;
}
