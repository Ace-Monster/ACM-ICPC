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
priority_queue<int, vector<int>, greater<int> > minq;
priority_queue<int> maxq;
int a[30005],u[30005];
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n,m;
	while(cin >> n >> m){
		int k = 0;
		rep(i, 0, n)
			cin >> a[i];
		rep(i, 0, m)
			cin >> u[i];
		int s = 0, i = 0;
		while(true){
			if(s == n && i == m) break;
			if(s == u[i]){
				cout << minq.top() << endl;
				//if(!maxq.empty()) de(maxq.top());
				//else cout << "Empty" << endl;
				i++,k++;
				while(maxq.size() < k && !minq.empty()){
					maxq.push(minq.top());
					minq.pop();
				}
			}
			else{
				maxq.push(a[s++]);
				if(maxq.size() > k){
					minq.push(maxq.top());
					maxq.pop();
				}
				else if(!minq.empty() && !maxq.empty()){
					if(maxq.top() > minq.top()){
						maxq.push(minq.top());
						minq.pop();
						minq.push(maxq.top());
					}
				}
			}/*
				de(k);
				if(minq.size())
					dd(minq.size()),de(minq.top());
				else de(minq.size());
				if(maxq.size())
					dd(maxq.size()),de(maxq.top());
				else de(maxq.size());
		*/
		}
	}
	return 0;
}
