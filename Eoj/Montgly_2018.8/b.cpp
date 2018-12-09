#include<iostream>
#include<stack>
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
bool maps[105][105];
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n,m,x,y;
	scanf("%d%d%d%d", &n, &m, &x, &y);
	int t = n*m-1;
	maps[x][y] = true;
	while(t--){
		int mx = 0,my = 0,dx = 0;
		for(int i = 1;i <= m;i++){
			if(maps[i][y] == 0 && abs(i-x) > dx){
				dx = abs(i-x);
				mx = i;
				my = y;
			}
		}
		for(int i = 1;i <= n;i++){
			if(maps[x][i] == 0 && abs(i-y) > dx){
				dx = abs(i-y);
				mx = x;
				my = i;
			}
		}
		for(int i = x,j = y;i <= m && j <= n;i++,j++){
			if(maps[i][j] == 0 && abs(i-x) > dx){
				dx = abs(i-x);
				mx = i;
				my = j;
			}
		}
		for(int i = x,j = y;i >= 1 && j >= 1;i--,j--){
			if(maps[i][j] == 0 && abs(i-x) > dx){
				dx = abs(i-x);
				mx = i;
				my = j;
			}
		}
		for(int i = x,j = y;i >= 1 && j <= n;i--,j++){
			if(maps[i][j] == 0 && abs(i-x) > dx){
				dx = abs(i-x);
				mx = i;
				my = j;
			}
		}
		for(int i = x,j = y;i <= m && j >= 1;i++,j--){
			if(maps[i][j] == 0 && abs(i-x) > dx){
				dx = abs(i-x);
				mx = i;
				my = j;
			}
		}
		x = mx,y = my;
		maps[mx][my] = true;
		printf("%d %d\n",mx,my);
	}
	return 0;
}
