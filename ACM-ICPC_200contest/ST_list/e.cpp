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
const int maxn = 900;
const double eps = 1e-9;
struct Star{
	int next,to;
}edge[maxn+5];
int head[maxn+5],st[maxn<<2][64],number[maxn+5],limit[maxn+5];
int cnt = 0,num = 0;
void dfs(int u){
	st[++cnt][0] = ++num;
	int tnum = num;
	number[num] = u;
	limit[u] = cnt;
	for(int i = head[u];i != -1;i = edge[i].next){
		dfs(edge[i].to);
		st[++cnt][0] = tnum;
	}
	return;
}
void makest(){
	for(int j = 1;(1<<j) <= cnt;j++)
		for(int i = 1;(i + (j<<1) - 1) <= cnt;i++)
			st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
}
int query(int l,int r){
	int k = log2(r-l+1)+eps;
	return min(st[l][k],st[r-(1<<k)+1][k]);
}
bool flag[maxn+5];
int ans[maxn+5];
char s[10000];
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n;
	while(~scanf("%d", &n)){
	cnt = 0,num = 0;
	memset(flag, 0, sizeof flag);
	memset(head, -1, sizeof head);
	memset(ans, 0, sizeof ans);
	for(int i = 1;i <= n;i++){
		int x,t;
		scanf("%d:(%d)", &x, &t);
		for(int j = 0;j < t;j++){
			int y;
			scanf("%d", &y);
			flag[y] = true;
			edge[++cnt].to = y;
			edge[cnt].next = head[x];
			head[x] = cnt;
		}
	}
	cnt = 0;
	for(int i = 1;i <= n;i++){
		if(flag[i] == 0){
			dfs(i);
			break;
		}
	}
	makest();
	int q;
	scanf("%d", &q);
	int x = 0,y = 0;
	while(q){
		scanf("%s", s);
		int l = strlen(s);
		for(int i = 0;i < l;i++){
			if(s[i]>='0' && s[i]<='9'){
				if(x == 0)
					for(;s[i] >= '0' && s[i]<='9';i++)
						x = 10*x+(s[i]-'0');
				else{
					for(;s[i] >= '0' && s[i]<='9';i++)
						y = 10*y+(s[i]-'0');
					x = limit[x],y = limit[y];
					if(x>y)swap(x,y);
					ans[number[query(x,y)]]++;
					x = 0,y = 0;
					q--;
				}
			}
		}
	}
	for(int i = 1;i <= n;i++){
		if(ans[i] != 0)
			printf("%d:%d\n", i, ans[i]);
	}
	}
	return 0;
}
