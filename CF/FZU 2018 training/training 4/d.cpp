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
vector<int> q[maxn];
int f[maxn];
int find(int x){
	if(f[x] == x){
		return x;
	}
	return f[x] = find(f[x]);
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	freopen("dream.in", "r", stdin);
	int T;
	scanf("%d", &T);
	for(int k = 1;k <= T;k++){
		int n;
		scanf("%d", &n);
		for(int i = 1;i < maxn;i++){
			q[i].clear();
			f[i] = i;
		}
		for(int i = 1;i <= n;i++){
			int t;
			scanf("%d", &t);
			int st = sqrt(t);
			for (int j = 1; j <= st; j++) {
                if (t%j == 0) {
                    q[j].pb(i);
                    if (t/j != j)q[t/j].pb(i);
                }
            }
		}
		int ans = 0;
		for(int j = maxn - 1;j >= 1;j--){
			if(q[j].empty()) continue;
			int l = q[j].size();
			for(int i = 1;i < l;i++){
				int x = find(q[j][i]);
				int y = find(q[j][i-1]);
				if(x != y){
					ans += j;
					f[x] = y;
				}
			}
		}
		printf("Case %d: %d\n", k, ans);
	}
	return 0;
}
