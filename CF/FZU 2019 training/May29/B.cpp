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
string s;
int n;
void solve(char r, int x, int f){
	//dd(r),dd(x),de(f);
	if(r == '+'){
		if(x){
			cout << n << ' ';
			x--;
		}else{
			cout << 1 + f << ' ';
			f = 0;
		}
	}else{
		cout << 1 << ' ';
	}
	int p = 2;
	while(s[p] != '='){
		cout << s[p] << ' ';
		if(s[p] == r) {
			if(x){
				cout << n << ' ';
				x--;
			}
			else{
				cout << 1 + f << ' ';
				f = 0;
			}
		}
		else cout << 1 << ' ';
		p += 4;
	}
	cout << "= " << n << endl;
}
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	getline(cin, s);
	int p = 2;
	int a = 1,b = 0;
	while(s[p] != '='){
		if(s[p] == '+') a++;
		else b++;
		p += 4;
	}
	int l = sz(s);
	for(p += 2;p < l;p++)
		n = n*10+(s[p]-'0');
	int asb = (a-b);
	//de(asb);
	if((asb < n && asb+a*(n-1) >= n) || (asb > n && asb-b*(n-1) <= n) || (asb == n)){
		cout << "Possible" << endl;
		if(asb<=n){
			int t = n-(a-b);
			int x = 0;
			if(n-1) x = t/(n-1);
			solve('+', x, t-x*(n-1));
		}else{
			int t = (a-b)-n;
			int x = 0;
			if(n-1) x = t/(n-1);
			solve('-', x, t-x*(n-1));
		}
	}else
		cout << "Impossible" << endl;
	return 0;
}


