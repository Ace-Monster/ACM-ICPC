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
struct Star{
	int next,to;
}maps[50005];
int head[maxn+5];
stack<int> q;
int gra[maxn+5],cnt = 0;
int dfn[maxn+5], low[maxn+5];
void tarjan(int u){
	dfn[u] = low[u] = ++cnt;
	q.push(u);
	for(int i = head[u];i != -1;i = maps[i].next){
		if(dfn[maps[i].to] == 0){
			tarjan(maps[i].to);
			low[u] = min(low[u], low[maps[i].to]);
		}
		else if(gra[maps[i].to] == 0){
			low[u] = min(low[u], dfn[maps[i].to]);
		}
	}
	if(dfn[u] == low[u]){
		int tu = q.top();
		do{
			tu = q.top();
			gra[tu] = low[u];
			q.pop();
		}while(tu != u);
	}
	return;
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n,m;
	while(~scanf("%d%d", &n, &m)){
		cnt = 0;
		memset(gra, 0, sizeof gra);
		memset(head, -1, sizeof head);
		memset(dfn, 0, sizeof dfn);
		for(int i = 1;i <= m;i++){
			int x,y;
			scanf("%d%d", &x, &y);
			maps[i].to = y;
			maps[i].next = head[x];
			head[x] = i;
		}
		for(int i = 1;i <= n;i++){
			if(gra[i] == 0)
				tarjan(i);
		}
		memset(dfn, 0, sizeof dfn);
		for(int i = 1;i <= n;i++){
			for(int j = head[i];j != -1;j = maps[j].next)
				if(gra[i] != gra[maps[j].to])
					dfn[gra[i]]++;
		}
		int sum = 0, j = 0, ans = 0;
		memset(low, 0, sizeof low);
		for(int i = 1;i <= n;i++){
			if(gra[i] != 0 && dfn[gra[i]] == 0 && low[gra[i]] == 0)
				sum++, j = i, low[gra[i]] = 1;
			//dd(gra[i]),dd(low[gra[i]]),de(dfn[gra[i]]);
		}
		//dd(ans),de(sum);
		if(sum == 0)
			printf("%d\n", n);
		if(sum > 1)
			printf("%d\n", 0);
		if(sum == 1){
			sum = 0;
			for(int i = 1;i <= n;i++){
				if(gra[i] == gra[j])
					sum++;
			}
			printf("%d\n", sum);
		}
	}
	return 0;
}
