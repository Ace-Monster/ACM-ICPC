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
const int maxn = 200005;
struct Node{
	int l,r;
	bool operator<(const Node &x) const{
		return l < x.l;
	}
}a[maxn];
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n,h;
	scanf("%d%d", &n, &h);
	ll ans = 0;
	ll sum = h;
	for(int i = 1;i <= n;i++){
		scanf("%d%d", &a[i].l, &a[i].r);
	}
	sort(a+1, a+n+1);
	int p = 1;
	for(int i = 2;i <= n;i++){
		while(a[i].l - a[i-1].r >= sum){
			p++;
			sum += a[p].l - a[p-1].r;
		}
		sum -= (a[i].l - a[i-1].r);
		ans = max(ans, a[i].r-a[p].l+sum);
	}
	if(n == 1)
		ans = a[1].r-a[1].l+h;
	printf("%lld\n", ans);
	return 0;
}
