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
const int xi[4] = {0,1,0,-1};
const int yi[4] = {1,0,-1,0};
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int q;
	scanf("%d", &q);
	for(int i = 1;i <= q;i++){
		ll x,y,k;
		scanf("%lld%lld%lld", &x, &y, &k);
		ll step = min(x,y);
		step = step+(max(x,y)-step);
		if(step > k){
			puts("-1");
			continue;
		}
		if(x == y){
			ll ans;
			if((k-x)%2 == 0)
				ans = k;
			else
				ans = k-2;
			printf("%lld\n", ans);
			continue;
		}
		ll ans;
		ll l = max(x,y)-min(x,y);
		if(l%2)
			ans = (k-1);
		else{
			if((k-max(x,y))%2)
				ans = k-2;
			else
				ans = k;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
