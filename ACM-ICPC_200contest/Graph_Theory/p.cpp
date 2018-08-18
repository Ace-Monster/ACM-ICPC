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
struct Star{
	int next, to;
}edge[100000];
int head[200],match[200];
bool flag[200];
bool find(int u){
	for(int i = head[u];i != -1;i = edge[i].next){
		int to = edge[i].to;
		if(!flag[to]){
			flag[to] = true;
			if(match[to] == 0 || find(match[to])){
				match[to] = u;
				return true;
			}
		}
	}
	return false;
}
int hungary(int n){
	int sum = 0;
	memset(match, 0, sizeof match);
	for(int i = 1;i <= n;i++){
		if(find(i))
			sum++;
		memset(flag, 0, sizeof flag);
	}
	return sum;
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int T;
	scanf("%d", &T);
	while(T--){
		int n,m;
		scanf("%d%d", &n, &m);
		memset(head, -1, sizeof head);
		for(int i = 1;i <= m;i++){
			int x,y;
			scanf("%d%d", &x, &y);
			edge[i].to = y;
			edge[i].next = head[x];
			head[x] = i;
		}
		printf("%d\n", n - hungary(n));
	}
	return 0;
}
