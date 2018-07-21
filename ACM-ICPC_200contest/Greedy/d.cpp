#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
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
int d[10005];
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n,m;
	int t = 0;
	while(cin >> n >> m){
		if(n == 0)break;
		memset(d, 0, sizeof(d));
		int a[10005];
		rep(i, 0, m)
			cin >> a[i];
		sort(a, a+m);
		a[m] = n*m + 1;
		d[m] = 0;
		int sum = 0;
		for(int i = m - 1; i >= 0; i--){
			d[i] = a[i+1] - a[i] - 1 + d[i+1];
			if(d[i] <= 0){
				sum++;
				/*
				d[i]--;
				if(d[i] < 0)
					d[i] = 0;
					*/
			}
			else d[i]--;
		}
		//for(int i = m;i >= 0;i--)
		//	cout << d[i] << ' ';
		//cout << endl;
		cout << "Case " << ++t << ": " << sum << endl;
	}
	return 0;
}
