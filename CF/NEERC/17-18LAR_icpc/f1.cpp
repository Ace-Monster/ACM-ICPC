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
const int maxn = 100005;
struct A{
	ll x,y,w;
	bool operator<(const A &t) const{
		return (x == t.x ? y > t.y : x < t.x);
	}
}m[maxn];
ll c[maxn];
ll tree[maxn<<2];
void pushup(ll rt){
	tree[rt] = max(tree[rt<<1], tree[rt<<1|1]);
}
void update(ll t, ll x, ll l, ll r, ll rt){
	if(l == r){
		tree[rt] = max(t, tree[rt]);
		return;
	}
	ll mid = (l+r)>>1;
	if(mid >= x) update(t, x, l, mid, rt<<1);
	else update(t, x, mid+1, r, rt<<1|1);
	pushup(rt);
}
ll query(ll L, ll R, ll l, ll r, ll rt){
	if(R < L) return 0;
	if(L <= l && r <= R){
		return tree[rt];
	}
	ll sum = 0;
	ll mid = (l+r)>>1;
	if(L <= mid) sum = max(sum, query(L, R, l, mid, rt<<1));
	if(R >= mid+1) sum = max(sum, query(L, R, mid+1, r, rt<<1|1));
	return sum;
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	ll n;
	scanf("%lld", &n);
	for(ll i = 1;i <= n;i++){
		scanf("%lld%lld%lld", &m[i].x, &m[i].y, &m[i].w);
		//c[i] = m[i].x, 
		c[i] = m[i].y;
	}
	//读入数据
	
	sort(c+1, c+n+1);
	ll l = unique(c+1, c+n+1)-c-1;
	for(ll i = 1;i <= n;i++){
		//ll a = lower_bound(c+1, c+l+1, m[i].x)-c;
		ll b = lower_bound(c+1, c+l+1, m[i].y)-c;
		//m[i].x = a, 
		m[i].y = b;
	}
	//离散化
	
	sort(m+1, m+n+1);
	for(ll i = 2;i <= n;i++){
		if(m[i].x == m[i-1].x && m[i].y == m[i-1].y)
			m[i].w += m[i-1].w, m[i-1].w = 0;
	}
	//去重

	ll ans = 0;
	for(ll i = 1;i <= n;i++){
		ll k = query(1, m[i].y-1, 1, n, 1)+m[i].w;
		ans = max(ans, k);
		update(k, m[i].y, 1, n, 1);
	}
	printf("%lld\n", ans);
	return 0;
}
