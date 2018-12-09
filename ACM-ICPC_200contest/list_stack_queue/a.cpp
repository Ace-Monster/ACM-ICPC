#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<string>
#include<string.h>
#include<list>
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
		list<string> q;
		rep(i, 0, n) {
			string t;
			cin >> t;
			q.pb(t);
		}
		int w, s;
		char c;
		cin >> w >> c >> s;
		list<string>::iterator it = q.be();
		while (--w) {
			it++;
			if (it == q.en())
				it = q.be();
		}
		while (!q.empty()) {
			for (int i = 0;i < s - 1;i++, it++)
				if (it == q.en())
					it = q.be();
			if (it == q.en())
				it = q.be();
			cout << *it << endl;
			it = q.erase(it);
		}
	}
	return 0;
}
