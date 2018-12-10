#include<bits/stdc++.h>
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
int a[605];
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n;
	cin >> n;
	int t, sum = 0;
	rep(i, 0, n){
		cin >> t;
		if(t == 0) continue;
		if(a[t] == 0) sum++, a[t] = 1;
	}
	cout << sum << endl;
	return 0;
}
