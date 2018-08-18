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
int a[25][4];
int flag[25];
vector<string> S;
string adds(int x, string s) {
	if (x < 10)
		s = s + (char)(x + '0');
	else
		s = s + char(x / 10 + '0') + char(x % 10 + '0');
	return s;
}
bool check(int n,int x) {
	return a[x][0] == n || a[x][1] == n || a[x][2] == n;
}
void dfs(int n, int x, int l, string s) {
	if (check(n, x) && l == 19) {
		S.pb(adds(n, adds(x, s) + ' '));
		return;
	}
	s = adds(x, s) + ' ';
	flag[x] = 1;
	rep(i, 0, 3)
		if (flag[a[x][i]] == 0)
			dfs(n, a[x][i], l + 1, s);
	flag[x] = 0;
	return;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	rep(i, 1, 21) {
		int b[3];
		cin >> b[0] >> b[1] >> b[2];
		sort(b, b + 3);
		rep(j, 0, 3)
			a[i][j] = b[j];
	}
	int m;
	cin >> m;
	string s;
	dfs(m, m, 0, s);
	vector<string>::iterator it = S.begin();
	for (int i = 1;it != S.en();i++, it++) {
		cout << i << ":  " << *it << endl;
	}
	return 0;
}
