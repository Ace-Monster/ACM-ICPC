#include<iostream>
#include<vector>
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
int a[20], b[20];
bool cmp(const int a, const int b)
{
	return a > b;
}
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n;
	while(cin >> n){
		if(n == 0) break;
		int maxs = 0;
		rep(i, 0, n+1)
		{
			cin >> a[i];
			int t = a[i]/50;
			if(a[i]%50) t++;
			if(i != n) maxs = max(maxs, t);
		}
		rep(i, 0, n)
			b[i] = (maxs*50) - a[i];
		sort(b, b+n, cmp);
		while(a[n] > 0)
		{
			if(b[2] == 0)
			{
				maxs++;
				rep(i, 0, n) b[i]+=50;
			}
			a[n]--;
			b[0]--, b[1]--, b[2]--;
			sort(b, b+n, cmp);
		}
		cout << maxs << endl;
	}
	return 0;
}
