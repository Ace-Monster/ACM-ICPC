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
int a[1005];
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n;
	while(cin >> n){
		if(n == 0) break;
		while(cin >> a[0]){
			if(a[0] == 0)
				break;
			rep(i, 1, n)
				cin >> a[i];
			stack<int> q;
			int j = 0;
			rep(i, 1, n+1){
				while(q.size()){
					if(q.top() != a[j]) break;
					q.pop();
					j++;
				}
				q.push(i);
			}
			while(q.size()){
				if(q.top() != a[j]) break;
				q.pop();
				j++;
			}
			if(q.size())
				cout << "No" << endl;
			else
				cout << "Yes" << endl;
		}
		cout << endl;
	}
	return 0;
}
