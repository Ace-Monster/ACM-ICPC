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
const ll N = 2147483648;
bool Fib(ll n){
	int a = 1, b = 2;
	while(a <= n){
		if(b == n)
			return true;
		swap(a,b);
		b += a;
	}
	return false;
}
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n;
	while(cin >> n){
		if(n == 0)break;
		if(Fib(n)) cout << "Second win" << endl;
		else cout << "First win" << endl;
	}
	return 0;
}
