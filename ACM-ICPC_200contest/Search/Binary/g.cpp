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
ll li[505], mi[505], ni[505], lmi[250005];
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int t = 0;
	int L,N,M;
	while(cin >> L >> N >> M){
		cout << "Case " << ++t << ':' << endl;
		for(int i = 0;i < L;i++)
		cin >> li[i];
		int lm = 0;
		for(int i = 0;i < N;i++){
			cin >> ni[i];
			for(int j = 0;j < L;j++){
				lmi[lm++] = li[j]+ni[i];
			}
		}
		sort(lmi, lmi+lm);
		for(int i = 0;i < M;i++)
			cin >> mi[i];
		int s;
		cin >> s;
		for(int i = 0;i < s;i++){
			int temp;
			cin >> temp;
			for(int j = 0;j < M;j++){
				int l = 0,r = lm;
				int mid = (r+l)/2;
				bool flag = false;
				while(r-l > 1){
					if(lmi[mid]+mi[j] == temp){
						flag = true;
					}
					if(lmi[mid]+mi[j] < temp) l = mid;
					else r = mid;
					mid = (l+r)/2;
				}
				if(flag){
					cout << "YES" << endl;
					break;
				}
				if(j == M-1) cout << "NO" << endl;
			}
		}
	}
	return 0;
}
