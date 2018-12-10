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
const int maxn = 405;
struct A{
	int ai,hi,ci;
	bool operator<(const A &x) const{
		return ai < x.ai;
	}
}b[maxn];
int dp[40005];
int ZeroOnePack(int V, int c,int w){
	for(int v = V;v >= c;v--)
		dp[v] = max(dp[v], dp[v-c]+w);
	return dp[V];
}
int CompletePack(int V,int c,int w){
	for(int v = c;v <= V;v++){
		dp[v] = max(dp[v], dp[v-c]+w);
	}
	return dp[V];
}
int MultiplePack(int i){
	if(b[i].hi*b[i].ci >= b[i].ai){
		return CompletePack(b[i].ai, b[i].hi, b[i].hi);
	}
	int k = 1, m = b[i].ci;
	while(k < m){
		ZeroOnePack(b[i].ai, k*b[i].hi, k*b[i].hi);
		m = m-k;
		k = 2*k;
	}
	return ZeroOnePack(b[i].ai, b[i].hi*m, b[i].hi*m);
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int k;
	scanf("%d", &k);
	for(int i = 1;i <= k;i++)
		scanf("%d%d%d", &b[i].hi, &b[i].ai, &b[i].ci);
	sort(b+1, b+k+1);
	for(int i = 1;i <= k;i++){
		MultiplePack(i);
		for(int j = b[i].ai+1;j <= b[k].ai;j++)
			dp[j] = dp[b[i].ai];
	}
	printf("%d", dp[b[k].ai]);
	return 0;
}
