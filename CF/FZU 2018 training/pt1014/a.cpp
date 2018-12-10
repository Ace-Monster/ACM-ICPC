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

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n;
	cin >> n;
	int ans1 = (n/7)*2, ans2 = ans1;
	int a = n%7;
	if(a > 2) a = 2;
	ans2 += a;
	a = (n%7 - 5);
	if(a < 0) a = 0;
	ans1 += a;
	cout << ans1 << ' ' << ans2 << endl;
	return 0;
}
