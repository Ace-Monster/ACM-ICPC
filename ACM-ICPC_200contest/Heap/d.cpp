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
struct A{
	string s;
	int a, d, id;
	A(string t1, int t2, int t3, int t4):s(t1), a(t2), d(t3), id(t4) { }
	bool operator<(const A &x)const{
		return (d == x.d)?id > x.id : d < x.d;
	}
};
priority_queue<A> q;
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	string s;
	int T = 0;
	while(cin >> s){
		if(s == "GET"){
			if(q.empty()) cout << "EMPTY QUEUE!" << endl;
			else{
				cout << q.top().s << ' ' << q.top().a << endl;
				q.pop();
			}
		}
		else{
			int a,d;
			cin >> s >> a >> d;
			A t(s, a, d, ++T);
			q.push(t);
		}
	}
	return 0;
}
