#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<string>
#include<string.h>
#include<queue>
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
ll gcd(ll a, ll b){
	if(b == 0) return a;
	return gcd(b, a%b);
}
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	ll T, t = 0;
	cin >> T;
	while(T--){
		cout << "Case #" << ++t << ": ";
		ll n,k,j;
		cin >> n >> j >> k;
		ll g = gcd(j, k);
		if((n/g)%2 == 0) cout << "Iaka" << endl;
		else cout << "Yuwgna" << endl;
	}
	return 0;
}
