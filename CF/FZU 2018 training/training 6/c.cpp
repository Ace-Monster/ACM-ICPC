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
set<ll> q;
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	ll n, k;
	scanf("%lld%lld", &n, &k);
	if(k > 1e6){
		puts("-1");
		return 0;
	}
	ll sk = (k*(k+1))>>1; 
	ll t = n/sk;
	for(ll i = 1;i*i <= n;i++){
		if(n%i != 0)
			continue;
		q.insert(-i),q.insert(-n/i);
	}
	for(set<ll>::iterator i = q.begin();i != q.end();i++){
		if(n%(-(*i)) == 0 && (-(*i)) <= t){
			t = -(*i);
			sk = n/(-(*i));
			break;
		}
	}
	if(t == 0){
		puts("-1");
		return 0;
	}
	for(int i = 1;i <= k;i++){
		printf("%lld%c", i == k ? sk*t:i*t, i == k ? '\n':' ');
		sk -= i;
	}
	return 0;
}
