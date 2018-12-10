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
const int maxn = 300005;
ll a[maxn],sub[maxn];
struct Node{
	int l, r;
	int maxl,maxr,maxn;
}t[maxn<<2];
#define ls rt<<1
#define rs rt<<1|1
#define lson l,mid,ls
#define rson mid+1,r,rs
void sets(int i, int rt){
	t[rt].maxr = i,t[rt].maxl = i,t[rt].maxn = i;
}
void pushup(int l,int r,int rt){
	t[rt].maxn = max(t[ls].maxn, t[rs].maxn);
	t[rt].maxl = t[ls].maxl;
	t[rt].maxr = t[rs].maxr;
	int mid = (l+r)>>1;
	if((sub[mid] > 0 && sub[mid+1] != 0) || (sub[mid] <= 0 && sub[mid+1] < 0)){
		t[rt].maxn = max(t[rt].maxn, t[ls].maxr+t[rs].maxl);
		if(mid-l+1 == t[ls].maxl) t[rt].maxl += t[rs].maxl;
		if(r-mid == t[rs].maxr) t[rt].maxr += t[ls].maxr;
	}
}
void built(int l,int r,int rt){
	if(l == r){
		if(sub[l]) sets(1,rt);
		return;
	}
	int mid = (l+r)>>1;
	built(lson);
	built(rson);
	pushup(l,r,rt);
}
void update(int x, int l, int r, int rt){
	if(l == r && l == x){
		if(sub[l]) sets(1,rt);
		else sets(0,rt);
		return;
	}
	int mid = (l+r)>>1;
	if(x <= mid) update(x,lson);
	else update(x,rson);
	pushup(l,r,rt);
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n;
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%lld", &a[i]);
		if(i >= 2)
			sub[i-1] = a[i]-a[i-1];
	}
	built(1,n,1);
	int q;
	scanf("%d", &q);
	while(q--){
		ll x,y,z;
		scanf("%lld%lld%lld", &x, &y, &z);
		if(x != 1) sub[x-1] += z, update(x-1,1,n,1);
		if(y != n) sub[y] -= z, update(y,1,n,1);
		printf("%d\n", t[1].maxn+1);
	}
	return 0;
}
