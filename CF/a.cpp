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

int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	ll n,h,a,b,k;
	scanf("%lld%lld%lld%lld%lld", &n, &h, &a, &b, &k);
	while(k--){
		ll bx,by,ex,ey;
		scanf("%lld%lld%lld%lld", &bx, &by, &ex, &ey);
		ll sum = 0;
		if(bx == ex){
			sum = abs(by-ey);
		}
		else{
			ll da = abs(by-a)+abs(bx-ex)+abs(a-ey);
			ll db = abs(by-b)+abs(bx-ex)+abs(b-ey);
			sum = min(da,db);
		}
		printf("%lld\n", sum);
	}
	return 0;
}
