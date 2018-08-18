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
int BIT[50005];
int lowbit(int x){
	return x&(-x);
}
void update(int q, int t){
	while(q <= 50000){
		BIT[q] += t;
		q += lowbit(q);
	}
}
int query(int q){
	int sum = 0;
	while(q > 0){
		sum += BIT[q];
		q -= lowbit(q);
	}
	return sum;
}
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int T;
	int t = 0;
	cin >> T;
	while(T--){
		cout << "Case " << ++t << ':' << endl;
		memset(BIT, 0, sizeof BIT);
		int n;
		cin >> n;
		rep(i, 1, n+1){
			int tem;
			cin >> tem;
			update(i, tem);
		}
		string s;
		while(cin >> s){
			if(s == "End") break;
			int i,j;
			cin >> i >> j;
			if(s == "Add") update(i, j);
			if(s == "Sub") update(i, -j);
			if(s == "Query") cout << query(j)-query(i-1) << endl;
		}
	}
	return 0;
}
