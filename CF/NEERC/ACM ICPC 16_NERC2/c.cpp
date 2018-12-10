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
struct M{
	int num,a,b;
}peo[maxn];
struct Star{
	int v,next;
}edge[maxn<<1];
int head[maxn],cnt = 0;
void lb(int n){
	for(int i = 2;i <= n;i++){
		edge[++cnt].next = head[peo[i].num];
		edge[cnt].v = peo[i-1].num;
		head[peo[i].num] = cnt;
	}
}
bool cmp1(const M &a, const M &b){
	return a.a < b.a;
}
bool cmp2(const M &a, const M &b){
	return a.b < b.b;
}
int ans[maxn];
void dfs(int v){
	if(ans[v] == -1) cnt++;
	ans[v] = 0;
	for(int i = head[v];i != -1;i = edge[i].next){
		int u = edge[i].v;
		if(ans[u] == -1) dfs(u);
	}
	return;
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n;
	scanf("%d", &n);
	memset(head, -1, sizeof head);
	memset(ans, -1, sizeof ans);
	for(int i = 1;i <= n;i++){
		peo[i].num = i;
		scanf("%d%d", &peo[i].a, &peo[i].b);
	}
	sort(peo+1,peo+n+1,cmp1);
	lb(n);
	sort(peo+1,peo+n+1,cmp2);
	lb(n);
	cnt = 0;
	for(int i = 1;i <= n;i++){
		dfs(peo[i].num);
		ans[peo[i].num] = cnt-1;
	}
	for(int i = 1;i <= n;i++)
		printf("%d\n", ans[i]);
	return 0;
}
