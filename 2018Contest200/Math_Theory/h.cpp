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
const int N = 1000005;
ll p[N];
void phi(){
	for(int i = 0;i < N;i++) p[i] = i;
	for(int i = 2;i < N;i++){
		if(p[i] == i){
			for(int j = i;j < N;j += i) p[j] = p[j]/i * (i - 1);
		}
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	ll n;
	phi();
	//cout << p[8] << endl;
	while(cin >> n){
		if(n == 0)break;
		ll sum = 0;
		for(int i = 2;i <= n;i++)
			sum += p[i];
		cout << sum << endl;
	}
	
	return 0;
}
