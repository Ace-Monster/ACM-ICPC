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
int tree[maxn<<2];
#define lson l, mid, rt<<1
#define rson mid+1, r, rt<<1|1
int sets[maxn<<2];
void pushup(int rt){
	tree[rt] = tree[rt<<1]+tree[rt<<1|1];
}
void pushdown(int i, int rt){
	if(sets[rt] != 0){
		tree[rt<<1] = sets[rt]*(i-(i>>1));
		tree[rt<<1|1] = sets[rt]*(i>>1);
		sets[rt<<1] = sets[rt<<1|1] = sets[rt];
		sets[rt] = 0;
	}
}
void built(int l,int r,int rt){
	if(l == r){
		tree[rt] = 1;
		return;
	}
	int mid = (l+r)>>1;
	built(lson);
	built(rson);
	pushup(rt);
	return;
}
void update(int t, int L, int R, int l, int r, int rt){
	if(L <= l && r <= R){
		tree[rt] = t*(r-l+1);
		sets[rt] = t;
		return;
	}
	pushdown(r-l+1, rt);
	int mid = (l+r)>>1;
	if(L <= mid) update(t, L, R, lson);
	if(R >= mid+1) update(t, L, R, rson);
	pushup(rt);
	return;
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int T;
	scanf("%d", &T);
	for(int i = 1;i <= T;i++){
		int n,q;
		scanf("%d%d", &n, &q);
		built(1, n, 1);
		while(q--){
			int l, r, t;
			scanf("%d%d%d", &l, &r, &t);
			update(t, l, r, 1, n, 1);
			//de(tree[1]);
		}
		memset(sets, 0, sizeof(int) * n);
		printf("Case %d: The total value of the hook is %d.\n", i, tree[1]);
	}
	return 0;
}
