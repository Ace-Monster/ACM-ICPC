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
    int n;
    cin >> n;
	string s;
	while(n--){
		cin >> s;
		string x;
		rep(i, 4, sz(s))
			x += s[i];
		if(sz(x) == 1)
			cout << (x == "9" ? 198:199) << x << endl;
		else if(sz(x) == 2)
			cout << (x == "99" ? 19:20) << x << endl;
		else if(sz(x) == 3)
			cout << (x < "099" ? 3:2) << x << endl;
		else {
			string t;
			rep(i, 4, sz(x)) t += '1';
			t += "3099";
			//de(t);
			if(x < t) cout << 1;
			cout << x << endl;
		}
	}
	return 0;
}


