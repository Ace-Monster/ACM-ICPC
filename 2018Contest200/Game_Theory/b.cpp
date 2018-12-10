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
double k = (sqrt(5)+1)/2;
bool check(int x, int y){
	int z = (y - x);
	for(;x > 0;z++, x--){
		if(x == (int)(k*z)){
			cout << x << ' ' << y << endl;
			return true;
		}
	}
	return false;
}
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int x,y;
	while(cin >> x >> y){
		if(x == 0)break;
		if(x > y) swap(x, y);
		int z = y - x;
		int w = k*z;
		if(w == x){
			cout << 0 << endl;
			continue;
		}
		cout << 1 << endl;

		int tx = x - 1, ty = y - 1;
		for(int i = 0;i < x;i++, tx--, ty--){
			if(tx == w) {
				cout << tx << ' ' << ty << endl;
				break;
			}
		}

		if(check(x - 1, y)) continue;
		z = (y-x)-1, ty = y - 1;
		for(int i = 0;i < y;i++, z--, ty--){
			if(ty >= x && x == (int)(k*z)){
				cout << x << ' ' << ty << endl;
				break;
			}
			else if(ty < x){
				check(y, x);
				break;
			}
		}
	}
	return 0;
}
