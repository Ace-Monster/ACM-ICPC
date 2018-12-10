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
struct Cmp {
	bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
		return (a.fi == b.fi)?a.se > b.se : a.fi > b.fi;
	}
};
priority_queue<pair<int, int>, vector<pair<int, int> >, Cmp > q;
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		for(int i = 0;i < n;i++){
			int a,b;
			cin >> a >> b;
			q.push(mp(a,b));
		}
		int i = 0;
		int sum = 0;
		while(!q.empty()){
			if(!(i%2)){
				pair<int, int> t = q.top();
				q.pop();
				t.fi += t.se;
				q.push(t);
			}
			else {
				sum = q.top().fi;
				q.pop();
			}
			i++;
		}
		cout << sum << endl;
	}
	return 0;
}
