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
int dp[20][5000],b[20];
int dfs(int pos,int df,int limit){
	if(pos == 0)return 1;
	int tmp = 0;
	if(!limit && dp[pos][df] != -1)
		return dp[pos][df];
	int n = limit ? b[pos] : 9;
	for(int i = 0;i <= n;i++){
		int tf = i*(1<<(pos-1));
		if(tf > df)
			break;
		tmp += dfs(pos-1,df-tf,limit && i == b[pos]);
	}
	if(!limit)
		dp[pos][df] = tmp;
	return tmp;
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int T;
	scanf("%d", &T);
	memset(dp, -1, sizeof dp);
	for(int t = 1;t <= T;t++){
		int a,B;
		scanf("%d%d", &a, &B);
		int ta = a;
		int fa = 0;
		for(int i = 0;ta;i++){
			fa += (ta%10)*(1<<i);
			ta/=10;
		}
		ta = B;
		int l = 1;
		while(ta){
			b[l++] = ta%10;
			ta/=10;
		}
		printf("Case #%d: %d\n", t, dfs(l-1,fa,1));
	}
	return 0;
}
