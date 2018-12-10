#include<iostream>
#include<cstdio>
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
int a[1030];
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n,k;
		scanf("%d %d", &n, &k);
		rep(i, 0, n)
			scanf("%d", &a[i]);
		while(k--){
			next_permutation(a, a+n);
		}
		rep(i, 0, n)
			printf("%d ", a[i]);
		cout << endl;
	}
	return 0;
}
