#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<string>
#include<string.h>
#include<queue>
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
int sum[205][205];
struct Cmp{
	bool operator()(const pair<int, int> &a, const pair<int, int> &b) const{
		int i = 0, j = 0;
		if(maps[a.fi][a.se] == 'x') i++;
		if(maps[b.fi][b.se] == 'x') j++;
		return i < j;
	}
};
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n,m;
	cin >> n >> m;
	int x,y;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++){
			cin >> maps[i][j];
			if(maps[i][j] == 'a') x = i, y = j;
			sum[]
		}
	priority_queue<pair<int, int>, vector<pair<int, int> >, Cmp > q;
	q.push(mp(x,y));
	while(!q.empty()){
		x = q.top().fi, y = q.top().se;
		q.pop();
		for(int i = 0;i < 4;i++){
			tx = x + xi[i],ty = y + yi[i];
			if(tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
			if(maps[tx][ty] == )
			if(maps[tx][ty] != '#' && sum[tx][ty] == 0)
			{
				if(maps[tx][ty] == 'r')
					sum[tx][ty] = min(sum[x][y]+2);
				else
					sum[tx][ty] = sum[x][y]+1;
			}
		}
		if(maps[x])
	}
	return 0;
}
