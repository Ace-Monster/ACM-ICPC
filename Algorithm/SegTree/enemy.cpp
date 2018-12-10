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
const int maxn = 50005;
int tree[maxn<<2];
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
void pushup(int rt){
	tree[rt] = tree[rt<<1]+tree[rt<<1|1];
}
void build(int l, int r,int rt){
	if(l == r){
		scanf("%d", &tree[rt]);
		return;
	}
	int mid = (l+r)>>1;
	build(lson);
	build(rson);
	pushup(rt);
	return;
}
void update(int t, int x, int l, int r, int rt){
	if(l == r){
		tree[rt] += t;
		return;
	}
	int mid = (l+r)>>1;
	if(x <= mid) update(t, x, lson);
	else update(t, x, rson);
	pushup(rt);
	return;
}
int query(int L, int R, int l,int r,int rt){
	if(L <= l && r <= R){
		return tree[rt];
	}
	int sum = 0;
	int mid = (l+r)>>1;
	if(L <= mid) sum+=query(L,R,lson);
	if(R >= mid+1) sum+=query(L,R,rson);
	return sum;
}
string s;
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int T;
	scanf("%d", &T);
	for(int i = 1;i <= T;i++){
		printf("Case %d:\n", i);
		int n;
		scanf("%d", &n);
		build(1, n, 1);
		while(true){
			int a,b;
			cin >> s;
			if(s[0] == 'E')
				break;
			scanf("%d%d", &a, &b);
			if(s[0] == 'Q')
				printf("%d\n", query(a,b,1,n,1));
			if(s[0] == 'A')
				update(b,a,1,n,1);
			if(s[0] == 'S')
				update(-b,a,1,n,1);
		}
	}
	return 0;
}
