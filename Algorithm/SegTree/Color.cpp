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
bool flag[maxn<<2];
int num[maxn<<2];
int lay[maxn<<2];
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
bool sum[30];
void pushup(int rt){
	if(flag[rt<<1] == 1 && flag[rt<<1|1] == 1 && num[rt<<1] == num[rt<<1|1])
		flag[rt] = 1,num[rt] = num[rt<<1];
	else
		flag[rt] = 0;
}
void pushdown(int rt){
	if(lay[rt] != 0){
		lay[rt<<1] = lay[rt<<1|1] = lay[rt];
		num[rt<<1] = num[rt<<1|1] = lay[rt];
		flag[rt<<1] = flag[rt<<1|1] = 1;
		lay[rt] = 0;
	}
}
void update(int t,int L,int R, int l,int r,int rt){
	if(L <= l && r <= R){
		lay[rt] = t;
		num[rt] = t;
		flag[rt] = 1;
		return;
	}
	pushdown(rt);
	int mid = (l+r)>>1;
	if(L <= mid) update(t,L,R,lson);
	if(R >= mid+1) update(t,L,R,rson);
	pushup(rt);
}
void query(int L,int R,int l,int r,int rt){
	if(L <= l && r <= R && flag[rt] == 1){
		sum[num[rt]] = 1;
		return;
	}
	pushdown(rt);
	int mid = (l+r)>>1;
	if(L <= mid) query(L,R,lson);
	if(R >= mid+1) query(L,R,rson);
}
void build(int l, int r,int rt){
	if(l == r){
		num[rt] = 1;
		flag[rt] = 1;
		return;
	}
	int mid = (l+r)>>1;
	build(lson);
	build(rson);
	pushup(rt);
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n,t,op;
	scanf("%d%d%d", &n, &t, &op);
	//build(1,n,1);
	flag[1] = 1, num[1] = 1, lay[1] = 1;
	while(op--){
		char s[3];
		scanf("%s", s);
		if(s[0] == 'P'){
			int x,y;
			scanf("%d%d", &x, &y);
			if(x > y) swap(x,y);
			query(x,y,1,n,1);
			int ans = 0;
			for(int i = 1;i <= t;i++)
				if(sum[i]) ans++, sum[i] = 0;
			printf("%d\n", ans);
		}
		else{
			int x,y,z;
			scanf("%d%d%d", &x, &y, &z);
			if(x > y) swap(x,y);
			update(z,x,y,1,n,1);
		}
	}
	return 0;
}
