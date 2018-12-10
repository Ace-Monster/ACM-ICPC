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
ll gcd(ll a,ll b){
	if(b == 0) return a;
	return gcd(b, a%b);
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	ll a,b,x,y;
	scanf("%lld%lld%lld%lld", &a, &b, &x, &y);
	ll ans = 0;
	ll t = gcd(x,y);
	while(t > 1){
		x/=t,y/=t;
		t = gcd(x,y);
	}
	ans = min(a/x, b/y);
	printf("%lld\n", ans);
	return 0;
}
