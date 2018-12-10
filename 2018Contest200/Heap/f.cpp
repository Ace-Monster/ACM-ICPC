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
int xi[4] = {1,0,-1,0};
int yi[4] = {0,1,0,-1};
bool flag[205][205];
struct A{
	int x,y;
	int sum;
	A(int tx, int ty, int tsum):x(tx),y(ty),sum(tsum) { }
	bool operator<(const A &x) const{
		return sum > x.sum;
	}
};
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n,m;
	//cin >> n >> m;
	while(cin >> n >> m){
		memset(flag, 0, sizeof(flag));
		int x,y;
		for(int i = 0;i < n;i++)
			for(int j = 0;j < m;j++){
				cin >> maps[i][j];
				if(maps[i][j] == 'a') x = i, y = j;
			}
		flag[x][y] = true;
		priority_queue<A> q;
		q.push(A(x,y,0));
		bool f = false;
		while(!q.empty()){
			A t = q.top();
			q.pop();
			for(int i = 0;i < 4;i++){
				int tx = t.x + xi[i],ty = t.y + yi[i];
				A tt(tx,ty,t.sum);
				if(tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
				if(flag[tx][ty]) continue;
				if(maps[tx][ty] == 'r'){ 
					cout << t.sum + 1 << endl;
					f = true;
					break;
				}
				if(maps[tx][ty] != '#')
				{
					if(maps[tx][ty] == 'x')
						tt.sum += 2;
					else 
						tt.sum++;
					flag[tx][ty] = true;
					q.push(tt);
				}
			}
			if(f) break;
		}
		if(!f)
			cout << "Poor ANGEL has to stay in the prison all his life." << endl;
	}
	return 0;
}
