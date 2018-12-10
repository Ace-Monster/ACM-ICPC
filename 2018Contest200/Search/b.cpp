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
char maps[25][25];
int xi[8] = {0,1,0,-1,1,1,-1,-1};
int yi[8] = {1,0,-1,0,1,-1,1,-1};
bool flag[25][25];
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n,m;
	while(cin >> n >> m){
		if(n == 0) break;
		memset(flag, 0, sizeof(flag));
		int x,y;
		cin >> x >> y;
		rep(i, 0, n)
			rep(j, 0, m)
				cin >> maps[i][j];
		queue<pair<int,int> > q;
		q.push(mp(x-1,y-1));
		flag[x-1][y-1] = 1;
		int sum = 0;
		while(!q.empty()){
			pair<int, int> t = q.front();
			q.pop();
			rep(i, 0, 8){
				int tx = t.fi+xi[i], ty = t.se+yi[i];
				if(tx < 0 || tx >= n || ty < 0 || ty >= m){
					if(i < 4) {sum++;}
					continue;
				}
				if(flag[tx][ty]){
					if(i < 4 && maps[tx][ty] == '.') sum++;
					continue;
				}
				if(maps[tx][ty] == 'X') q.push(mp(tx, ty));
				else if(i < 4) {sum++;}
				flag[tx][ty] = 1;
			}
		}
		cout << sum << endl;
	}
	return 0;
}
