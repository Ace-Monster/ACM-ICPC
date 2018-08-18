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
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	while (cin >> n) {
		vi a, b;
		stack<int> q;
		vector<string> p;
			string t;
			cin >> t;
			int l = t.size();
			rep(j, 0, l)
				a.pb(int(t[j] - '0'));
			cin >> t;
			l = t.size();
			rep(j, 0, l)
				b.pb(int(t[j] - '0'));
		vi::iterator it = a.be();
		vi::iterator at = b.be();
		for (;it != a.en();it++) {
			while (!q.empty()) {
				if (q.top() != *at) break;
				at++;
				q.pop();
				p.pb("out");
			}
			q.push(*it);
			p.pb("in");
		}
		while (!q.empty()) {
			if (q.top() != *at) break;
			at++;
			q.pop();
			p.pb("out");
		}
		if (q.size())
			cout << "No." << endl;
		else {
			cout << "Yes." << endl;
			vector<string>::iterator pt = p.be();
			for (;pt != p.en();pt++)
				cout << *pt << endl;
		}
		cout << "FINISH" << endl;
	}
	return 0;
}
