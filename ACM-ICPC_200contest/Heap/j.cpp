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
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		queue<int> p;
		priority_queue<int> q;
		int n,k;
		cin >> n >> k;
		rep(i, 0, n){
			int temp;
			cin >> temp;
			p.push(temp);
			q.push(temp);
		}
		int sum = 0;
		rep(i, 0, n){
			while(p.front() != q.top()){
				p.push(p.front());
				p.pop();
				if(k == 0) k = p.size() - 1;
				else k--;
			}
			sum++;
			if(k == 0) break;
			k--;
			p.pop();
			q.pop();
		}
		cout << sum << endl;
	}
	return 0;
}
