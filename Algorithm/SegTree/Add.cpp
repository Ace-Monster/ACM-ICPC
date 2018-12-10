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
ll tree[maxn<<2];
ll lay[maxn<<2];
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
void pushup(int rt){
	tree[rt] = tree[rt<<1] + tree[rt<<1|1];
}
void pushdown(int rt, int i){
	if(lay[rt] != 0){
		lay[rt<<1] += lay[rt];
		lay[rt<<1|1] += lay[rt];
		tree[rt<<1] += (lay[rt]*(i-(i>>1)));
		tree[rt<<1|1] += (lay[rt]*(i>>1));
		lay[rt] = 0;
	}
}
void built(int l,int r,int rt){
	if(l == r){
		scanf("%lld", &tree[rt]);
		return;
	}
	int mid = (l+r)>>1;
	built(lson);
	built(rson);
	pushup(rt);
}
void update(ll t,int L,int R,int l,int r,int rt){
	if(L <= l && r <= R){
		lay[rt] += t;
		tree[rt] += (t*(r-l+1));
		return;
	}
	pushdown(rt, r-l+1);
	int mid = (l+r)>>1;
	if(L <= mid) update(t,L,R,lson);
	if(R >= mid+1) update(t,L,R,rson);
	pushup(rt);
}
ll query(int L, int R,int l, int r, int rt){
	if(L <= l && r <= R)
		return tree[rt];
	pushdown(rt, r-l+1);
	int mid = (l+r)>>1;
	ll sum = 0;
	if(L <= mid) sum+=query(L,R,lson);
	if(R >= mid+1) sum+=query(L,R,rson);
	return sum;
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n,q;
	scanf("%d%d", &n, &q);
	built(1,n,1);
	while(q--){
		char s[3];
		scanf("%s", s);
		if(s[0] == 'C'){
			int x,y;
			ll z;
			scanf("%d%d%lld", &x, &y, &z);
			if(y < x)swap(x,y);
			update(z, x, y, 1, n, 1);
			//for(int i = 1;i <= 40;i++)
			//	cout << tree[rt] << ' ';
			//cout << endl;
			//de(query(1,1,1,n,1));
		}
		else{
			int x,y;
			scanf("%d%d", &x, &y);
			//dd(x),de(y);
			if(y < x) swap(x, y);
			printf("%lld\n", query(x,y,1,n,1));
		}
	}
	return 0;
}
