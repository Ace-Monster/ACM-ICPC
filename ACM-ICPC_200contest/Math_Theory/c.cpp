#include<iostream>
#include<vector>
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
inline ll mods(ll a, ll b, ll mod){
	if(a+b >= mod)
		return a+b - mod;
	return a+b;
}
inline ll first_mulit(ll a, ll b, ll mod){
	ll sum = 0;
	while(b){
		if(b&1) 
			sum = mods(sum, a, mod);
		a = mods(a, a, mod);
		b>>=1;
	}
	return sum%mod;
}
inline ll first_pow(ll a, ll b, ll mod){
	a%=mod;
	ll sum = 1;
	while(b){
		if(b&1)
			sum = first_mulit(sum, a, mod);
		a = first_mulit(a, a, mod);
		b>>=1;
	}
	return sum%mod;
}
inline bool melb(ll n, ll a){
	ll d = n-1, s = 0;
	while(!(d&1)){
		d>>=1;
		s++;
	}
	ll t = first_pow(a, d, n);
	if(t == 1 || t == -1)
		return 1;
	for(int i = 0;i < s;i++)
	{
		if(t == n-1)
			return 1;
		t = first_mulit(t, t, n);
	}
	return 0;
}
inline bool isPrime(ll n){
	if(n == 2) return 1;
	if(n < 2 || !n%2) return 0;
	ll a[4] = {3, 5, 7, 11};
	rep(i, 0, 4){
		if(n == a[i])
			return 1;
		if(n%a[i] == 0)
			return 0;
		if(n > a[i] && melb(n, a[i]) == 0)
			return 0;
	}
	return 1;
}
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	ll n;
	while(cin >> n){
		if(isPrime(n)) cout << "It is a prime number." << endl;
		else cout << "It is not a prime number." << endl;
	}
	return 0;
}
