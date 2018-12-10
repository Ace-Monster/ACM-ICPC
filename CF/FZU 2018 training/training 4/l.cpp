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
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	freopen("lazy.in", "r", stdin);
	int T;
	cin >> T;
	for(int i = 1;i <= T;i++){
		int n;
		cin >> n;
		//if(n == 1)
		//	printf("Case %d: 1\n", i);
		//else
		cout << "Case " << i << ": " << n-1 << endl;
	}
	return 0;
}
