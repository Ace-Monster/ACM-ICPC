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
priority_queue<int, vector<int>, greater<int> > p;
priority_queue<int> q;
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n,k;
	while(cin >> n >> k){
		while(!p.empty()) p.pop();
		while(n--){
			char c;
			cin >> c;
			if(c == 'I'){
				int t;
				cin >> t;
				p.push(t);
				if(p.size() > k){
					//q.push(p.top());
					p.pop();
				}
			}
			else
				cout << p.top() << endl;
		}
	}
	return 0;
}
