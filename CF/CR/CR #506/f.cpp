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

int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	ll a,b;
	scanf("%lld%lld", &a, &b);
	
	ll ax = sqrt(a);
	while(a%ax != 0)ax--;
	ll ay = a/ax;
	
	ll bx = sqrt(b);
	while(b%bx != 0)bx--;
	ll by = b/bx;
	
	ll t = a+b;
	ll x = sqrt(t);
	while(t%x != 0)x--;
	ll y = t/x;
	
	ll r = min(max(ax, ay), max(bx, by));
	ll l;
	if(r == ax || r == ay)
		l = min(ax, ay);
	else
		l = min(bx, by);
	if(min(x, y) < l){
		//dd(min(x, y)), de(r);
		if(ax == r || ay == r){
			ax = a/r;
			while(a%ax != 0 || ax == r)ax--;
			ay = a/ax;
		}
		else{
			bx = b/r;
			while(b%bx != 0 || bx == r)bx--;
			by = b/bx;
		}
		r = min(max(ax, ay), max(bx, by));
		//break;
	}
	//dd(r),de(max(x,y));
	if(max(x, y) < r){
		y = t/r;
		while(t%y != 0)y--;
		x = t/y;
	}

	ll sum = 2*x+2*y;
	printf("%lld\n", sum);
	return 0;
}
