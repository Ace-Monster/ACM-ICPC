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
struct TREE{
	ll sum, lay;
}tree[(100005)<<2];
void pushup(int rt){
	tree[rt].sum = tree[rt<<1].sum + tree[rt<<1|1].sum;
}
void pushdown(int rt, int i){
	if(tree[rt].lay){
		ll lay = tree[rt].lay;
		tree[rt].lay = 0;
		tree[rt<<1].lay += lay;
		tree[rt<<1|1].lay += lay;
		tree[rt<<1].sum += lay*(i-(i>>1));
		tree[rt<<1|1].sum += (i>>1)*lay;
	}
}
void build(int l,int r,int rt){
	if(l == r){
		scanf("%lld", &tree[rt].sum);
		return;
	}
	int mid = (l+r)/2;
	build(l, mid, rt<<1);
	build(mid+1, r, rt<<1|1);
	pushup(rt);
	return;
}
void update(int t, int L, int R,int l, int r, int rt){
	if(L <= l && r <= R){
		tree[rt].lay += t;
		tree[rt].sum += t*(r-l+1);
		return;
	}
	pushdown(rt, r-l+1);
	int mid = (l+r)/2;
	if(L <= mid) update(t,L,R,l,mid,rt<<1);
	if(R > mid) update(t,L,R,mid+1,r,rt<<1|1);
	pushup(rt);
}
ll query(int L,int R,int l,int r,int rt){
	if(L <= l && r <= R){
		return tree[rt].sum;
	}
	pushdown(rt, r-l+1);
	ll sum = 0;
	int mid = (l+r)/2;
	if(L <= mid) sum += query(L,R,l,mid,rt<<1);
	if(mid < R) sum += query(L,R,mid+1,r,rt<<1|1);
	return sum;
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n,m;
	cin >> n >> m;
	build(1,n,1);
	while(m--){
		char q;
		int a,b;
		cin >> q;
		scanf("%d%d", &a, &b);
		if(q == 'C'){
			int c;
			scanf("%d", &c);
			update(c,a,b,1,n,1);
		}
		if(q == 'Q')
			cout << query(a,b,1,n,1) << endl;
	}
	return 0;
}
