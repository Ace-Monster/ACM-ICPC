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
int A[200005],BIT[200005];
int lowbit(int x){
	return x&(-x);
}
int query(int l, int r){
	int sum = 0;
	while(r >= l){
		sum = max(A[r], sum);
		r--;
		for(;r-lowbit(r) >= l;r -= lowbit(r))
			sum = max(BIT[r], sum);
	}
	return sum;
}
void update(int q){
	while(q <= 200000){
		BIT[q] = A[q];
		int lq = lowbit(q);
		for(int i = 1;i < lq; i<<=1)
			BIT[q] = max(BIT[q], BIT[q-i]);
		q += lowbit(q);
	}
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n,m;
	while(scanf("%d%d", &n, &m) != EOF){
		memset(BIT, 0, sizeof BIT);
		rep(i, 1, n+1){
			scanf("%d", &A[i]);
			update(i);
		}
		while(m--){
			char s;
			int a,b;
			cin >> s;
			scanf("%d%d", &a, &b);
			if(s == 'U'){
				A[a] = b;
				update(a);
			}
			if(s == 'Q')
				printf("%d\n", query(a,b));
		}
	}
	return 0;
}
