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
const int maxn = 10005;
struct A{
	int w,id;
	bool operator<(const A &x) const{
		return w < x.w;
	}
}wi[maxn];
int w[maxn];
struct Star{
	int next, to;
}edge[maxn<<1];
int head[maxn];
bool flag[maxn];
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int T;
	scanf("%d", &T);
	while(T--){
		int n;
		int cnt = 0;
		scanf("%d", &n);
		for(int i = 1;i <= n;i++){
			scanf("%d", &wi[i].w);
			wi[i].id = i;
		}
		memset(head, -1, sizeof head);
		memset(flag, 0, sizeof flag);
		for(int i = 1;i < n;i++){
			int x,y;
			scanf("%d%d", &x, &y);
			edge[++cnt].to = y;
			edge[cnt].next = head[x];
			head[x] = cnt;
			edge[++cnt].to = x;
			edge[cnt].next = head[y];
			head[y] = cnt;
		}
		sort(wi+1, wi+n+1);
		ll sum = 0;
		for(int i = 1;i <= n;i++){
			int w = wi[i].w;
			for(int j = head[wi[i].id];j != -1;j = edge[j].next){
				if(flag[edge[j].to])
					continue;
				sum += w;
			}
			flag[i] = 1;
		}
		printf("%lld\n", sum);
	}
	return 0;
}
