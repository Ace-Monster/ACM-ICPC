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
const int xi[4] = {1,0,-1,0};
const int yi[4] = {0,1,0,-1};
char maps[305][305];
bool flag[305][305];
struct A{
	int y,x;
	int sum;
	A(int a,int b,int c):x(a),y(b),sum(c) { }
	bool operator<(const A &x)const{
		return sum > x.sum;
	}
};
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n,m;
	while(cin >> n >> m){
		if(n == 0)break;
		memset(flag, 0, sizeof(flag));
		int bx,by,ex,ey;
		rep(i, 0, n)
			rep(j, 0, m){
				cin >> maps[i][j];
				if(maps[i][j] == 'Y') bx = i,by = j;
				if(maps[i][j] == 'T') ex = i,ey = j;
			}
		priority_queue<A> q;
		q.push(A(bx,by,0));
		flag[bx][by] = true;
		while(!q.empty()){
			A tem = q.top();
			q.pop();
			rep(i, 0, 4){
				int tx = tem.x+xi[i], ty = tem.y+yi[i];
				if(tx < 0 || ty < 0 || tx >= n || ty >= m) continue;
				if(flag[tx][ty] || maps[tx][ty] == 'S' || maps[tx][ty] == 'R') continue;
				if(maps[tx][ty] == 'T') {
					tem.x = tx,tem.y = ty;
					break;
				}
				if(maps[tx][ty] == 'E') q.push(A(tx,ty,tem.sum+1));
				if(maps[tx][ty] == 'B') q.push(A(tx,ty,tem.sum+2));
				flag[tx][ty] = true;
			}
			if(tem.x == ex && tem.y == ey){
				cout << tem.sum+1 << endl;
				flag[ex][ey] = true;
				break;
			}
		}
		if(!flag[ex][ey]) cout << -1 << endl;
	}
	return 0;
}
