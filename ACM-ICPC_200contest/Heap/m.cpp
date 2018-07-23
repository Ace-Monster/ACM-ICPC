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
struct P {
	string n;
	int id, a;
	P() { }
	P(int t1, int t2, string s) :id(t1), a(t2), n(s) { }
	bool operator==(const P &x)const {
		return a >= x.a;
	}
	bool operator<(const P &x)const {
		return (a == x.a) ? id < x.id : a < x.a;
	}
};
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	cin >> T;
	int tt = 0;
	while (T--) {
		cout << "Case #" << ++tt << ':' << endl;
		set<P> q;
		int n;
		cin >> n;
		int t = 0;
		set<P>::iterator it;
		while (n--) {
			string s;
			cin >> s;
			if (s == "Find") {
				int a;
				cin >> a;
				P p(2, a, "str");
				for (it = q.begin();it != q.end();it++) {
					if (*it == p) break;
				}
				if (it == q.end()) cout << "WAIT..." << endl;
				else { cout << it->n << endl;q.erase(it); }
			}
			if (s == "Add") {
				int a;
				cin >> s >> a;
				P p(++t, a, s);
				q.insert(p);
				cout << q.size() << endl;
			}
		}
	}
	return 0;
}
