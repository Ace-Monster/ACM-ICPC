#include<bits/stdc++.h>
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
const int maxn = 100005;
const int inf = 0x3f3f3f3f;
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n;
	scanf("%d", &n);
	ll t,maxnn = -inf, ans = 0, minn = inf;
	rep(i, 1, n+1){
		scanf("%lld", &t);
		if(t > 0){
			ans += t;
		}
		if(t > 0){
			if(t&1) minn = min(minn, t);
		}
		else if(t&1) {
			maxnn = max(maxnn, t);
		}
	}
	if(ans&1)
		printf("%lld\n", ans);
	else{
		ans = max(ans-minn, ans+maxnn);
		printf("%lld\n", ans);
	}
	return 0;
}
