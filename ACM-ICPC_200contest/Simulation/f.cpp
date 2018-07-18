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
	int n,a,b;
	cin >> n >> a >> b;
	if(a > b) swap(a, b);
	int sum = 0;
	const double eps = 1e-9;
	//cout << l << endl;
	while(a != b)
	{
		if(a % 2 == 0)a/=2;
		else a = (a+1)/2;
		if(b % 2 == 0)b/=2;
		else b = (b+1)/2;
		sum++;
	}
	//cout << sum << endl;
	if(n == pow(2, sum))
		return cout << "Final!" << endl, 0;
	cout << sum << endl;
	return 0;
}
