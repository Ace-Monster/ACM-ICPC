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
int xi[8] = {0,1,0,-1,1,1,-1,-1};
int yi[8] = {1,0,-1,0,1,-1,1,-1};
char maps[105][105];
bool flag[105][105];
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n,m;
	while(cin >> n >> m){
		rep(i, 0, n)
			rep(j, 0, m)
				cin >> maps[i][j];
		memset(flag, 0, sizeof(flag));
		queue<pair<int, int> > q;
		int sum = 0;
		rep(i, 0, n)
			rep(j, 0, m){
				if(maps[i][j] == 'W' && flag[i][j] == 0)
					sum++,flag[i][j] = 1,q.push(mp(i,j));
				while(!q.empty()){
					int x = q.front().fi, y = q.front().se;
					q.pop();
					rep(k, 0, 8){
						int tx = x+xi[k], ty = y+yi[k];
						if(tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
						if(maps[tx][ty] != 'W' || flag[tx][ty]) continue;
						q.push(mp(tx,ty));
						flag[tx][ty] = 1;
					}
				}
			}
		cout << sum << endl;
	}
	return 0;
}
