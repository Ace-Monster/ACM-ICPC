#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
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
struct P{
	double x,y,l,r;
	bool operator<(const P& a)const {
		return r < a.r;
	}
}p[1005];
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n, d;
	int t = 0;
	while(cin >> n >> d){
		if(n == 0) break;
		cout << "Case " << ++t << ": ";
		bool flag = 0;
		rep(i, 0, n){
			int x,y;
			cin >> p[i].x >> p[i].y;
		}
		rep(i, 0, n){
			if(p[i].y > d){
				flag = 1;
				break;
			}
			double di = sqrt(d*d-p[i].y*p[i].y);
			p[i].l = p[i].x-di,p[i].r = p[i].x+di;
		}
		if(flag){
			cout << -1 << endl;
			continue;
		}
		sort(p, p+n);
		int sum = 1;
		double li = p[0].r;
		rep(i, 1, n){
			if(p[i].l > li){
				sum++;
				li = p[i].r;
			}
		}
		cout << sum << endl;
	}
	return 0;
}
