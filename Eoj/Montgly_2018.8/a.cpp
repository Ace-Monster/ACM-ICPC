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
ll a[105][105],b[105][105],c[105][105];
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n,m;
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			scanf("%lld", &a[i][j]);
	int h,w;
	scanf("%d%d", &h, &w);
	for(int i = 1;i <= h;i++)
		for(int j = 1;j <= w;j++)
			scanf("%lld", &b[i][j]);
	for(int i = 1;i <= n-h+1;i++)
		for(int j = 1;j <= m-w+1;j++){
			for(int x = 1;x <= h;x++)
				for(int y = 1;y <= w;y++)
					c[i][j] += b[x][y]*a[i+x-1][j+y-1];
		}
	for(int i = 1;i <= n-h+1;i++)
		for(int j = 1;j <= m-w+1;j++)
			printf("%lld%c", c[i][j], j == m-w+1 ? '\n':' ');
	return 0;
}
