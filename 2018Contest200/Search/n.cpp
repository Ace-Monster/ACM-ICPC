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
char maps[205][205];
int flagy[205][205],flagm[205][205];
int n,m;
int xi[4] = {0,1,0,-1};
int yi[4] = {1,0,-1,0};
const int inf = 0x3f3f3f3f;
void bfs(int x,int y,int flag[205][205]){
	queue<pair<int,int> > q;
	q.push(mp(x,y));
	flag[x][y] = 0;
	while(!q.empty()){
		int ttx = q.front().fi,tty = q.front().se;
		q.pop();
		rep(i, 0, 4){
			int tx = ttx+xi[i], ty = tty+yi[i];
			if(tx < 0 || tx >= n || ty < 0 || ty >= m)continue;
			if(maps[tx][ty] == '#') continue;
			if(flag[tx][ty] != inf) continue;
			flag[tx][ty] = flag[ttx][tty]+1;
			q.push(mp(tx,ty));
		}
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	while(cin >> n >> m){
		int yx,yy,mx,my;
		memset(flagy, inf, sizeof(flagy));
		memset(flagm, inf, sizeof(flagm));
		vector<pair<int, int> > kfc;
		rep(i, 0, n)
			rep(j, 0, m){
				cin >> maps[i][j];
				if(maps[i][j] == 'Y') yx = i, yy = j;
				if(maps[i][j] == 'M') mx = i, my = j;
				if(maps[i][j] == '@') kfc.pb(mp(i,j));
			}
		bfs(yx,yy,flagy);
		bfs(mx,my,flagm);
		vector<pair<int,int> >::iterator it;
		int sum = 1e9;
		for(it = kfc.begin();it != kfc.end();it++){
			int tsum = flagy[(*it).fi][(*it).se]+flagm[(*it).fi][(*it).se];
			sum = min(tsum,sum);
		}
		cout << sum*11 << endl;
	}
	return 0;
}
