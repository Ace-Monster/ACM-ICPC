#include<iostream>
#include<vector>
#include<algorithm>
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
typedef unsigned long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
ll mod;
inline ll mods(ll a,ll b){
	if(a+b >= mod)
		return a+b - mod;
	return a+b;
}
inline ll first_mulit(ll a,ll b){//快速乘
	ll sum = 0;
	while(b){
		if(b&1)
			sum = mods(sum, a);
		a = mods(a, a);
		b>>=1;
	}
	return sum%mod;
}

inline ll first_pow(ll a,ll b){//快速幂
	a%=mod;//初始可能a>c
	ll sum = 1;
	while(b){
		if(b&1)
			sum = first_mulit(sum, a);
		a = first_mulit(a, a);
		b>>=1;
	}
	return sum%mod;
}

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	ll a,b,c;
	while(cin >> a >> b >> c){
		mod = c;
		cout << first_pow(a,b) << endl;
	}
	return 0;
}
