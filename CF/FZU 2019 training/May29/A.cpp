#include<bits/stdc++.h>
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
const int maxn = 100005;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9;
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	string a,b;
	cin >> a >> b;
	if(a == b) cout << a;
	else cout << 1;
	return 0;
}


