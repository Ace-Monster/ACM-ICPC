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
const int maxn = 1005;
char s[maxn], ss[maxn];
int n, k;
bool dp[maxn][maxn];
bool dfs(int pos, int t){
	if(pos >= n && (t == k || t == -k))
		return true;
	if(pos >= n && (t != k || t == -k))
		return false;
	if(t >= k || t <= -k)
		return false;
	if(dp[pos][t]) return false;
	if(s[pos] == '?'){
		ss[pos] = 'W';
		if(dfs(pos+1, t+1)) return true;
		ss[pos] = 'L';
		if(dfs(pos+1, t-1)) return true;
		ss[pos] = 'D';
		if(dfs(pos+1, t)) return true;
	}else{
		if(s[pos] == 'W') t++;
		else if(s[pos] == 'L') t--;
		return dfs(pos+1, t);
	}
	dp[pos][t] = 1;
	return false;
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	scanf("%d%d", &n, &k);
	scanf("%s", s);
	for(int i = 0;i <= n;i++)
		ss[i] = s[i];
	if(dfs(0, 0))
		printf("%s\n", ss);
	else
		puts("NO");
	return 0;
}
