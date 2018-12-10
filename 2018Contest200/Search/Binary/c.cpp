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
int mi[100005];
int check(int n,int m,int mid,int sum){
	rep(i, 0, n){
		if(mid < mi[i])
			return false;
	}
	if(sum > m) return false;
	return true;
}
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n,m;
	while(cin >> n >> m){
		int l = 0,r = 0;
		rep(i, 0, n){
			cin >> mi[i];
			r += mi[i];
		}
		r *= 2;
		int mid = (l+r)/2;
		while(r - l > 1){
			int sum = 1,cnt = 0;
			rep(i, 0, n){
				cnt += mi[i];
				if(cnt > mid){
					sum++;
					cnt = mi[i];
				}
			}
			if(!check(n,m,mid,sum)) l = mid;
			else r = mid;
			mid = (l+r)/2;
		}
		cout << r << endl;
	}
	return 0;
}
