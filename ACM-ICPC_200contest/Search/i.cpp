#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
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
map<pair<int, int>, pair<int, int> > p;
queue<pair<int, int> > q;
pair<int, int> t, f;
const int yi[4] = {0, 1, 0, -1};
const int xi[4] = {1, 0, -1, 0};
const int x = 4, y = 4;
int m[10][10];
void cleans(){
	while(!q.empty())
		q.pop();
}
bool find(int xx, int yy){
	return (xx > x || xx < 0 || yy > y || yy < 0);
}
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n = 5;
	int maps[10][10];
	rep(i, 0, 5)
		rep(j, 0, 5)
			cin >> maps[i][j];
	t = mp(0, 0);
	m[0][0] = 1;
	q.push(t);
	while(!q.empty()){
		f = q.front();
		q.pop();
		rep(i, 0, 4){
			t = f;
			t.fi += xi[i];
			t.se += yi[i];
			if(find(t.fi, t.se) || maps[t.fi][t.se] != 0 || m[t.fi][t.se] != 0)
				continue;
			p[t] = f;
			m[t.fi][t.se] = 1;
			q.push(t);
			if(t.fi == x && t.se == y)
				break;
		}
		if(t.fi == x && t.se == y)
			break;
	}
	vector<pair<int, int> >tt;
	f = mp(0, 0);
	while(t != f){
		tt.pb(t);
		t = p[t];
	}
	tt.pb(mp(0, 0));
	vector<pair<int, int> >::reverse_iterator rit = tt.rbegin();
	for(;rit != tt.rend();rit++){
		cout << '(' << (*rit).fi << ", " << (*rit).se << ')' << endl;
	}
	return 0;
}
