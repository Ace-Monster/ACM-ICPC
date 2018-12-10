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
ll f[maxn], a[maxn];
int finds(int x, ll b){
	b = min(a[x], b);
	a[x] = b;
	return f[x] = (f[x] == x ? x : finds(f[x], b));
}
void unin(int x,int y){
	x = finds(x, a[x]);
	y = finds(y, a[y]);
	f[x] = y;
	a[x] = min(a[x], a[y]);
}
bool flag[maxn];
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n,m;
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++){
		scanf("%lld", &a[i]);
		f[i] = i;
	}
	for(int i = 1;i <= m;i++){
		int x,y;
		scanf("%d%d", &x, &y);
		unin(x, y);
	}
	ll ans = 0;
	for(int i = 1;i <= n;i++){
		if(!flag[finds(i, a[i])]){
			ans += a[finds(i, a[i])];
			flag[finds(i, a[i])] = 1;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
