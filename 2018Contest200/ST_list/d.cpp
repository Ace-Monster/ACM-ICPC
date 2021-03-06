#include<iostream>
#include<cstdio>
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
const int maxn = 10000;
const double eps = 1e-9;
struct Star{
	int next,to;
}edge[maxn+5];
int head[maxn+5];
int d[maxn<<2][64],limit[maxn+5],number[maxn+5];
int cnt = 0,num = 0;
void dfs(int u){
	d[++cnt][0] = ++num;
	int tnum = num;
	limit[u] = cnt;
	number[num] = u;
	for(int i = head[u];i != -1;i = edge[i].next){
		dfs(edge[i].to);
		d[++cnt][0] = tnum;
	}
	return;
}
void makst(){
	for(int j = 1;(1<<j) <= cnt;j++)
		for(int i = 1;(i + (j << 1) - 1) <= cnt;i++)
			d[i][j] = min(d[i][j-1], d[i + (1<<(j-1))][j-1]);
}
int query(int l,int r){
	int k = log2(r-l+1)+eps;
	return min(d[l][k], d[r-(1<<k)+1][k]);
}
bool flag[maxn+5];
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int T;
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d", &n);
		cnt = 0,num = 0;
		memset(flag, 0, sizeof flag);
		memset(head, -1, sizeof head);
		for(int i = 1;i < n;i++){
			int x,y;
			scanf("%d%d", &x, &y);
			flag[y] = true;
			edge[++cnt].to = y;
			edge[cnt].next = head[x];
			head[x] = cnt;
		}
		cnt = 0;
		for(int i = 1;i <= n;i++){
			if(flag[i] == 0){
				dfs(i);
				break;
			}
		}
		makst();
		int x,y;
		scanf("%d%d", &x, &y);
		if(limit[x] > limit[y]) swap(x,y);
		printf("%d\n", number[query(limit[x],limit[y])]);
	}
	return 0;
}
