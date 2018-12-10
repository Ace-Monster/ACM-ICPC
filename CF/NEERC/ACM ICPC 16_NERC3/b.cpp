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
	if(!b) return a;
	return gcd(b, a%b);
}
ll solve(ll l,ll r,ll w){
	if(l-w >= r-1) return 0;
	ll g = gcd(w,r);
	ll t = (l-w)/g*g;
	while(t <= l-w) 
		t += g;
	if(t < r) return 1;
	return 0;
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	ll l,r,w;
	cin >> l >> r >> w;
	if(solve(l, r, w))
		cout << "DEADLOCK" << endl;
	else
		cout << "OK" << endl;
	return 0;
}
