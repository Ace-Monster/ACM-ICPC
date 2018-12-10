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
#define ls rt<<1
#define rs rt<<1|1
#define lson l,mid,ls
#define rson mid+1,r,rs
const int maxn = 1<<17;
struct A{
	int a;
	bool f;
}tree[maxn<<2];
void pushup(int rt){
	tree[rt].f = (tree[ls].f^1);
	if(tree[rt].f)
		tree[rt].a = (tree[ls].a|tree[rs].a);
	else
		tree[rt].a = (tree[ls].a^tree[rs].a);
	//dd(rt), dd(tree[rt].f), de(tree[rt].a);
}
void built(int l,int r,int rt){
	if(l == r){
		scanf("%d", &tree[rt].a);
		tree[rt].f = 0;
		return;
	}
	int mid = (l+r)>>1;
	built(lson);
	built(rson);
	pushup(rt);
}
void update(int t,int x,int l,int r,int rt){
	if(l == r){
		tree[rt].a = t;
		return;
	}
	int mid = (l+r)>>1;
	if(x <= mid) update(t, x, lson);
	else update(t, x, rson);
	pushup(rt);
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n,m;
	scanf("%d%d", &n, &m);
	n = 1<<n;
	built(1, n, 1);
	while(m--){
		int x,y;
		scanf("%d%d", &x, &y);
		update(y, x, 1, n, 1);
		printf("%d\n", tree[1].a);
	}
	return 0;
}
