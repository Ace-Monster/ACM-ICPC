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
const ll mod = 1e9+7;
const int maxn = 100000;
int f[maxn+5];
ll check(int x){
	int sum = 0;
	for(int i = 2;i*i <= x;i++){
		if(x%i == 0){
			sum++;
			x /= i;
			if(x%i == 0) return 0;
		}
	}
	if(x > 1) sum++;
	if(sum&1) return -1;
	else return 1;
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n;
	scanf("%d", &n);
	ll ans = 1;
	for(int i = 1;i <= n;i++){
		ans = (ans * (ll)2)%mod;
	}
	ans = (ans - 1 + mod)%mod;
	for(int i = 1;i <= n;i++){
		int a;
		scanf("%d", &a);
		for(int j = 1;j*j <= a;j++){
			if(a%j == 0){
				f[j]++;
				if(j*j != a)
					f[a/j]++;
			}
		}
	}
	for(int i = 2;i <= maxn;i++){
		if(!f[i]) continue;
		ll sum = 1, k = check(i);
		if(k == 0) continue;
		for(int j = 1;j <= f[i];j++)
			sum = (sum * (ll)2)%mod;
		sum = ((sum - 1 + mod)%mod)*k;
		ans = (ans + sum + mod)%mod;
	}
	printf("%lld\n", ans);
	return 0;
}
