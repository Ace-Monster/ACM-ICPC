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
#define ddi(a) cout<<#a<<" = "<<a<<" "
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	//freopen("king.in", "r", stdin);
	//freopen("king.out", "w", stdout);
	int d,m,y;
	scanf("%d%d%d", &d, &m, &y);
	int n;
	y -= 18;
	scanf("%d", &n);
	int dd = 0,dm = 0,dy = 0;
	int ans = -1;
	//ddi(y),ddi(m),de(d);
	for(int i = 1;i <= n;i++){
		int td, tm, ty;
		scanf("%d%d%d", &td, &tm, &ty);
		//ddi(ty),ddi(tm),de(td);
		if(ty > y) continue;
		if(ty == y && tm > m) continue;
		if(ty == y && tm == m && td > d) continue;

		if(ty > dy){
			ans = i;
			dd = td,dm = tm,dy = ty;
			continue;
		}
		if(ty < dy) continue;
		if(tm > dm){
			ans = i;
			dd = td,dm = tm,dy = ty;
			continue;
		}
		if(tm < dm) continue;
		if(td >= dd){
			ans = i;
			dd = td,dm = tm,dy = ty;
			continue;
		}
	}
	printf("%d\n", ans);
	return 0;
}
