#include<iostream>
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
char maps[5][5];
int flagx[5], flagy[5];
int dfs(int n, int x, int y) {
	if (x == n-1 && y == n-1) {
		if (flagx[x] == 0 && flagy[y] == 0 && maps[x][y] == '.')
			return 1;
		else
			return 0;
	}
	int s1 = 0, s2 = 0;
	bool tfx,tfy;
	if (maps[x][y] == 'X') {
		tfx = flagx[x], tfy = flagy[y];
		flagx[x] = 0, flagy[y] = 0;
	}
	else if (flagx[x] == 0 && flagy[y] == 0) {
		flagx[x] = 1, flagy[y] = 1;
		s1++;
		if (y == n-1) {
			s1 += dfs(n, x + 1, 0);
		}
		else
			s1 += dfs(n, x, y + 1);
		flagx[x] = 0, flagy[y] = 0;
	}
	if (y == n-1) {
		s2 += dfs(n, x + 1, 0);
	}
	else
		s2 += dfs(n, x, y + 1);
	if (maps[x][y] == 'X')
		flagx[x] = tfx, flagy[y] = tfy;
	return max(s1, s2);
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	while (cin >> n) {
		if (n == 0) break;
		rep(i, 0, n)
			rep(j, 0, n)
			cin >> maps[i][j];
		memset(flagx, 0, sizeof(flagx));
		memset(flagy, 0, sizeof(flagy));
		cout << dfs(n, 0, 0) << endl;
	}
	return 0;
}
