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

int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
    freopen("anniversary.in", "r", stdin);
    freopen("anniversary.out", "w", stdout);
	int n,m;
	int a,b,x,y;
	cin >> n >> m >> a >> b >> x >> y;
	if(a == x) printf("0 %d %d %d", y, n, b);
	else printf("%d %d %d %d", a, 0, x, m);
	return 0;
}
