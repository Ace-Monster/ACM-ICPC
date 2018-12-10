#include<cstdio>
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
const int maxn = 100;
stack<int> q;//栈
struct Star{
	int to,next;
}maps[10000];
int head[maxn+5],cnt = 1;//前向星
int gra[maxn+5];//上色
int dfn[maxn+5],low[maxn+5];//判断
int n;//点
int ind = 0;//颜色计数器
int scc = 0;
bool flag[maxn+5];//标记
int ob[maxn+5],rb[maxn+5];
void tarjan(const int u){
	dfn[u] = low[u] = ++ind;
	q.push(u);
	flag[u] = 1;
	for(int i = head[u];i != -1;i = maps[i].next){
		if(flag[maps[i].to] == 0){
			tarjan(maps[i].to);
			low[u] = min(low[u],low[maps[i].to]);
		}
		else if(gra[maps[i].to] == 0)
			low[u] = min(low[u],dfn[maps[i].to]);
	}
	if(dfn[u] == low[u]){
		scc++;
		while(q.top() != u) {
			gra[q.top()] = low[u];
			q.pop();
		}
		gra[u] = low[u];
		q.pop();
	}
}
void bfs(){
	memset(flag, 0, sizeof flag);
	queue<int> p;
	for(int i = 1;i <= n;i++){
		if(flag[i])continue;
		p.push(i);
		while(p.size()){
			int u = p.front();
			p.pop();
			for(int i = head[u];i != -1;i = maps[i].next){
				if(gra[maps[i].to] != gra[u]){
					ob[gra[u]]++,rb[gra[maps[i].to]]++;
				}
				if(flag[maps[i].to] == 0){
					p.push(maps[i].to);
					flag[maps[i].to] = 1;
				}
			}
		}
	}
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	scanf("%d", &n);
	memset(head, -1, sizeof head);
	for(int i = 1;i <= n;i++){
		int t;
		while(~scanf("%d", &t)){
			if(t == 0) break;
			maps[cnt].to = t;
			maps[cnt].next = head[i];
			head[i] = cnt++;
		}
	}
	for(int i = 1;i <= n;i++){
		if(flag[i] == 0)
			tarjan(i);
	}
	bfs();
	int osum = 0,isum = 0;
	memset(flag, 0, sizeof flag);
	for(int i = 1;i <= n;i++){
		if(flag[gra[i]]) continue;
		if(ob[gra[i]] == 0) osum++;
		if(rb[gra[i]] == 0) isum++;
		flag[gra[i]] = 1;
	}
	if(scc == 1)
		printf("%d\n%d\n", 1, 0);
	else
		printf("%d\n%d\n", isum, max(osum,isum));
	return 0;
}
