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
ll phi(ll n){
	ll res = n;
	for(ll i = 2;i < n;i++){
		if(n % i == 0){
			res = res / i * (i - 1);
			while(n % i == 0) n /= i;
		}
	}
	if(n != 1) res = res / n * (n-1);
	return res;
}
inline ll first_mod(ll a, ll b, ll mod){
	ll sum = 1;
	a %= mod;
	while(b){
		if(b&1) sum = (sum * a) % mod;
		a = (a*a) % mod;
		b>>=1;
	}
	return sum;
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	ll a,c;
	char B[1000005];
	while(scanf("%lld", &a) != EOF){
		memset(B, 0, sizeof(B));
		scanf("%s %lld", B, &c);
		int l = strlen(B);
		ll p = phi(c);
		ll b = 0;
		for(int i = 0;i < l;i++){
			b = (b*10 + ll(B[i] - '0'))%p;
		}
		cout << first_mod(a, b+p, c) << endl;
	}
	return 0;
}
