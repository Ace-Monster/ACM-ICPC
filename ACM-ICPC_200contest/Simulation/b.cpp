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

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	string a,b;
	cin >> a >> b;
	int al = a.size(), bl = b.size();
	int sum = al+bl;
	for(int i = 0;i < al && i < bl;i++){
		if(a[al - i - 1] != b[bl - i - 1]) break;
		sum -= 2;
	}
	cout << sum << endl;
	return 0;
}
