#include<bits/stdc++.h>
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
const int inf = 0x3f3f3f3f;
int f[maxn], a[maxn];
struct A{
	int l,r;
}t[maxn];
map<int, bool> q;
void dfs(int v, int l, int r){
	if(l <= a[v] && r >= a[v]) q[a[v]] = true;
	if(t[v].l != -1){
		dfs(t[v].l, l, min(a[v],r));
	}
	if(t[v].r != -1){
		dfs(t[v].r, max(a[v],l), r);
	}
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n;
	scanf("%d", &n);
	rep(i, 1, n+1)
		f[i] = i;
	rep(i, 1, n+1){
		int v,l,r;
		scanf("%d%d%d", &v, &l, &r);
		a[i] = v;
		t[i].l = l, t[i].r = r;
		if(l != -1)
			f[l] = i;
		if(r != -1)
			f[r] = i;
	}
	rep(i, 1, n+1){
		if(f[i] == i){
			dfs(i, 0, 1e9+1);
			break;
		}
	}
	int sum = 0;
	rep(i, 1, n+1){
		if(!q[a[i]]) sum++;
	}
	printf("%d\n", sum);
	return 0;
}
