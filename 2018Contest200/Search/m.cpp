#include<iostream>
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
int gcd(int a, int b) {
	if (b) return gcd(b, a%b);
	return a;
}
struct A {
	int a, b;
	vector<string> s;
	A(int x, int y) :a(x), b(y) { }
	A(int x, int y, vector<string> c) :a(x), b(y) {
		s = c;
	}
};
bool flag[105][105];
bool check(int a, int b) {
	if (flag[a][b])
		return false;
	flag[a][b] = 1;
	return true;
}
void bfs(int a, int b, int c) {
	memset(flag, 0, sizeof(flag));
	queue<A> q;
	q.push(A(0, 0));
	while (!q.empty()) {
		int tta = q.front().a, ttb = q.front().b;
		vector<string> s = q.front().s;
		q.pop();
		if (tta == c || ttb == c) {
			vector<string>::iterator it;
			cout << s.size() << endl;
			for (it = s.begin();it != s.end();it++)
				cout << *it << endl;
			return;
		}
		int ta, tb;
		if (tta != a) {
			ta = a, tb = ttb;//add a
			if (check(ta, tb)) {
				vector<string> ts = s;
				ts.pb("FILL(1)");
				q.push(A(ta, tb, ts));
			}
		}
		if (ttb != b) {
			ta = tta, tb = b;//add b
			if (check(ta, tb)) {
				vector<string> ts = s;
				ts.pb("FILL(2)");
				q.push(A(ta, tb, ts));
			}
		}
		if (tta != 0) {
			ta = 0, tb = ttb;//drop a
			if (check(ta, tb)) {
				vector<string> ts = s;
				ts.pb("DROP(1)");
				q.push(A(ta, tb, ts));
			}
		}
		if (tta != 0 && ttb != b) {
			tb = b - ttb;
			if (tb >= tta)tb = ttb + tta, ta = 0;
			else ta = tta - tb, tb = b;//pour a->b
			if (check(ta, tb)) {
				vector<string> ts = s;
				ts.pb("POUR(1,2)");
				q.push(A(ta, tb, ts));
			}
		}
		if (ttb != 0) {
			ta = tta, tb = 0;//drop b
			if (check(ta, tb)) {
				vector<string> ts = s;
				ts.pb("DROP(2)");
				q.push(A(ta, tb, ts));
			}
		}
		if (tta != a && ttb != 0) {
			ta = a - tta;
			if (ta >= ttb)ta = ttb + tta, tb = 0;
			else tb = ttb - ta, ta = a;//pour b->a
			if (check(ta, tb)) {
				vector<string> ts = s;
				ts.pb("POUR(2,1)");
				q.push(A(ta, tb, ts));
			}
		}
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int a, b, c;
	while (cin >> a >> b >> c) {
		if (c%gcd(a, b) != 0)
			cout << "impossible" << endl;
		else
			bfs(a, b, c);
	}
	return 0;
}
