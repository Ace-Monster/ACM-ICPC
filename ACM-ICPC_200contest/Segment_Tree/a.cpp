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
int tree[200005];
void pushup(int rt){
	tree[rt] = tree[rt<<1]+tree[rt<<1|1];
}
int build(int l, int r, int rt){
	if(l == r){
		cin >> tree[rt];
		return tree[rt];
	}
	int mid = (l + r) >> 1;
	return tree[rt] = build(l, mid, rt<<1) + build(mid+1, r, rt<<1|1);
}
void update(int p, int t, int l, int r, int rt){
	if(l == r){
		tree[rt] += t;
		return;
	}
	int mid = (l + r) >> 1;
	if(p <= mid) update(p, t, l, mid, rt<<1);
	else update(p, t, mid+1, r, rt<<1|1);
	pushup(rt);
}
int query(int L, int R, int l, int r, int rt){
	if(L<=l && r<=R) return tree[rt];
	int mid = (l + r)>>1;
	int sum = 0;
	if(L <= mid) sum += query(L,R,l,mid,rt<<1);
	if(mid+1 <= R) sum += query(L,R,mid+1,r,rt<<1|1);
	return sum;
}
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n;
	int T;
	cin >> T;
	int t = 0;
	while(T--){
		cin >> n;
		cout << "Case " << ++t << ':' << endl;
		build(1,n,1);
		string s;
		while(cin >> s){
			if(s == "End") break;
			int i,j;
			cin >> i >> j;
			if(s == "Query") cout << query(i,j,1,n,1) << endl;
			if(s == "Add") update(i, j, 1, n, 1);
			if(s == "Sub") update(i, -j, 1, n, 1);
		}
	}
	return 0;
}
