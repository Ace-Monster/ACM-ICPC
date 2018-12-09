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
const int maxn = 100005;
map<int, int> q;
int a[maxn],b[maxn],c[3*maxn];
bool js[10005];
int tree[maxn<<2];
void pushup(int rt){
	if(tree[rt<<1] == tree[rt<<1|1])
		tree[rt] = tree[rt<<1];
	else
		tree[rt] = -1;
}
void pushdown(int rt){
	if(tree[rt] != -1){
		tree[rt<<1] = tree[rt];
		tree[rt<<1|1] = tree[rt];
	}
}
void update(int t,int L,int R,int l,int r,int rt){
	if(L <= l && r <= R){
		tree[rt] = t;
		return;
	}
	pushdown(rt);
	int mid = (l+r)/2;
	if(L <= mid) update(t,L,R,l,mid,rt<<1);
	if(R > mid) update(t,L,R,mid+1,r,rt<<1|1);
	pushup(rt);
	return;
}
int query(int l,int r,int rt){
	if(tree[rt] != -1){
		if(js[tree[rt]])
			return 0;
		js[tree[rt]] = 1;
		return 1;
	}
	if(l >= r)
		return 0;
	pushdown(rt);
	int mid = (l+r)/2,sum = 0;
	sum = query(l,mid,rt<<1)+query(mid+1,r,rt<<1|1);
	return sum;
}
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		memset(js, 0, sizeof js);
		memset(tree, -1, sizeof tree);
		int n;
		cin >> n;
		for(int i = 0;i < n;i++){
			cin >> a[i] >> b[i];
			c[i] = a[i],c[n+i] = b[i];
		}
		sort(c, c+(2*n));
		int s = unique(c,c+(2*n)) - c;
		int j = 0;
		for(int i = 0;i < s;i++){
			if(c[i] - c[i-1] != 1)
				j++;
			q[c[i]] = ++j;
		}
		for(int i = 0;i < n;i++)
			a[i] = q[a[i]], b[i] = q[b[i]];
		for(int i = 0;i < n;i++){
			update(i,a[i],b[i],1,j,1);
		}
		cout << query(1,j,1) << endl;
	}
	return 0;
}
