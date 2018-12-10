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
struct TREE{
	int l = 0,r = 2e9+2;
}tree[maxn<<2];
void pushup(int rt){
	tree[rt].l = max(tree[rt<<1].l, tree[rt<<1|1].l);
	tree[rt].r = min(tree[rt<<1].r, tree[rt<<1|1].r);
	return;
}
void update(int x, int L, int R, int l, int r, int rt){
	if(l == r){
		tree[rt].l = L, tree[rt].r = R;
		return;
	}
	int mid = (l+r)>>1;
	//dd(x),dd(L),dd(R),dd(l),dd(r),de(mid);
	if(x <= mid) update(x, L, R, l, mid, rt<<1);
	else update(x, L, R, mid+1, r, rt<<1|1);
	pushup(rt);
	return;
}
void query(int &ql, int &qr, int L, int R, int l, int r, int rt){
	if(L <= l && r <= R){
		ql = max(tree[rt].l, ql);
		qr = min(tree[rt].r, qr);
		return;
	}
	int mid = (l+r)>>1;
	//dd(L),dd(R),dd(l),dd(r),de(mid);
	if(L <= mid) query(ql, qr, L, R, l, mid, rt<<1);
	if(R >= mid+1) query(ql, qr, L, R, mid+1, r, rt<<1|1);
	return;
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++){
		int l,r;
		scanf("%d%d", &l, &r);
		l += 1e9+1;
		r += 1e9+1;
		//dd(l),de(r);
		update(i, l, r, 1, n, 1);
	}
	//for(int i = 1;i <= n*2;i++)
	//	cout << tree[i].l << ' ' << tree[i].r << endl;
	for(int i = 1;i <= m;i++){
		char s[5];
		scanf("%s", s);
		if(s[0] == 'C'){
			int j,l,r;
			scanf("%d%d%d", &j, &l, &r);
			r+=1e9+1;
			l+=1e9+1;
			update(j, l, r, 1, n, 1);
			//dd(l),de(r);
			//for(int i = 1;i <= n*2;i++)
			//	cout << tree[i].l << ' ' << tree[i].r << endl;
		}
		else{
			int l = 0, r = 2e9+1, a, b;
			scanf("%d%d", &a, &b);
			query(l, r, a, b, 1, n, 1);
			int t = r-l+1;
			//dd(l),dd(r),de(t);
			if(t < 0) t = 0;
			printf("%d\n", t);
		}
	}
	return 0;
}
