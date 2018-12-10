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
struct B{
	int i,y;
	B();
	B(int t1, int t2):i(t1),y(t2) { }
	bool operator<(const B &x) const {
		return (y==x.y) ? i > x.i : y < x.y;
	}
};
priority_queue<B> a[3];
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n;
	while(cin >> n){
		for(int i = 0;i < 3;i++)
			while(!a[i].empty())
				a[i].pop();
		int id = 1;
		while(n--){
		string s;
		cin >> s;
		if(s == "IN"){
			int x,y;
			cin >> x >> y;
			B t(id++,y);
			a[x-1].push(t);
		}
		if(s == "OUT"){
			int x;
			cin >> x;
			if(a[x - 1].empty())
			{
				cout << "EMPTY" << endl;
				continue;
			}
			cout << a[x - 1].top().i << endl;
			a[x - 1].pop();
		}
		}
	}
	return 0;
}
