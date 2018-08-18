#include<iostream>
#include<stack>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<string>
#include<string.h>
#include<queue>
#include<functional>
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
const int maxn = 1000000;
int f[10005],a[maxn+5],b[10005];
void fnext(int n){
	f[0] = -1;
	for(int i = 1;i < n;i++){
		int j = f[i-1];
		while(b[j+1] != b[i] && j >= 0)
			j = f[j];
		if(b[j+1] == b[i])
			f[i] = j+1;
		else
			f[i] = -1;

	}
}
int find(int n,int m){
	int i = 0,j = 0;
	while(i<n){
		if(a[i] == b[j])
		{
			i++;j++;
			if(j == m)
				return i-j+1;
		}
		else
		{
			if(j == 0)
				i++;
			else
				j = f[j-1]+1;
		}
	}
	return -1;
}
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n,m;
		cin >> n >> m;
		for(int i = 0;i < n;i++){
			cin >> a[i];}
		for(int j = 0;j < m;j++)
			cin >> b[j];
		fnext(m);
		cout << find(n,m) << endl;
	}
	return 0;
}
