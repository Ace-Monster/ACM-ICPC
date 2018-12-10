#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<functional>
#include<stack>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(a) (int)a.size()
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int INF = 0x3f3f3f3f;
int solve(int W, int w){
	int ans = 0;
	if(w > W) return INF;
	while(W > w){
		W = (W+1)/2;
		ans++;
	}
	return ans;
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	//freopen("folding.in", "r", stdin);
	//freopen("folding.out", "w", stdout);
	int W,H,w,h;
	cin >> W >> H >> w >> h;
	if(H > W) swap(H,W);
	if(h > w) swap(h,w);
	if(w > W || h > H) return cout << -1 << endl, 0;
	int ans = min(solve(W, w) + solve(H, h), solve(W, h) + solve(H, w));
	cout << ans << endl;
	return 0;
}
