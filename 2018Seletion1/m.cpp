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
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n;
	cin >> n;
	int sum = 0;
	int i;
	for(i = 1;i*i < n;i++)
	{
		if(!(n%i))
			sum += i, sum += (n/i);
	}
	if(!(n%i))
		sum += i;
	cout << sum << endl;
	return 0;
}
