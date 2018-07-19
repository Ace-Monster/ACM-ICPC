#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
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
char m[10][10];
int x[10], y[10];
vector<int> q[10];
ll dfs(int n, int t, int k, int s){
	if(k == s) return 1;
	if(n == t) return 0;
	ll sum = 0;
	vector<int>::iterator it = q[t].begin();
	for(;it != q[t].end();it++){
		if(x[t] && y[*it]){
			x[t] = y[*it] = 0;
			sum += dfs(n, t+1, k, s+1);
			x[t] = y[*it] = 1;
		}
	}
	sum += dfs(n, t+1, k, s);
	return sum;
}
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n,k;
	cin >> n >> k;
	while(n != -1){
		rep(i, 0, 10)
			q[i].clear();
		memset(x, 0, sizeof(x));
		memset(y, 0, sizeof(y));
		rep(i, 0, n)
			rep(j, 0, n){
				cin >> m[i][j];
				if(m[i][j] == '#'){
					x[i] = y[j] = 1;
					q[i].pb(j);
				}
			}
		cout << dfs(n, 0, k, 0) << endl;
		cin >> n >> k;
	}
	return 0;
}
