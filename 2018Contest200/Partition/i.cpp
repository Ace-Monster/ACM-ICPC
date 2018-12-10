#include<iostream>
#include<stack>
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
ll pows(ll b,ll k){
	ll a = 10;
	int sum = 1;
	while(b){
		if(b&1) sum = (sum*a)%k;
		a = (a*a)%k;
		b>>=1;
	}
	return sum;
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int T;
	scanf("%d", &T);
	for(int t = 1;t <= T;t++){
		printf("Case #%d:\n", t);
		ll x,m,k,c;
		scanf("%lld%lld%lld%lld", &x, &m, &k, &c);
		if(((pows(m,k)-1)*x+k)%k == (9*c)%k)
			printf("Yes\n");
		else
			printf("No\n");
	
	}
	return 0;
}
