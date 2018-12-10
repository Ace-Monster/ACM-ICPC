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
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int maxn = 200005;
int tree[maxn<<2];
void pushup(int rt){
	tree[rt] = max(tree[rt<<1], tree[rt<<1|1]);
}
void built(int l,int r,int rt){
	if(l == r){
		scanf("%d", &tree[rt]);
		return;
	}
	int mid = (l+r)>>1;
	built(lson);
	built(rson);
	pushup(rt);
}
void update(int t, int x, int l, int r, int rt){
	if(l == r){
		tree[rt] = t;
		return;
	}
	int mid = (l+r)>>1;
	if(x <= mid) update(t,x,lson);
	else update(t,x,rson);
	pushup(rt);
}
int query(int L, int R, int l, int r, int rt){
	if(L <= l && r <= R){
		return tree[rt];
	}
	int sum = 0;
	int mid = (l+r)>>1;
	if(L <= mid) sum = max(sum, query(L, R, lson));
	if(R >= mid+1) sum = max(sum, query(L, R, rson));
	return sum;
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n,q;
	while(~scanf("%d%d", &n, &q)){
		built(1,n,1);
		while(q--){
			string s;
			cin >> s;
			int x,y;
			scanf("%d%d", &x, &y);
			if(s[0] == 'Q')
				printf("%d\n", query(x,y,1,n,1));
			if(s[0] == 'U')
				update(y,x,1,n,1);
		}
		memset(tree, 0, sizeof tree);
	}
	return 0;
}
