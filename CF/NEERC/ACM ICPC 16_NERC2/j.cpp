#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<functional>
#include<stack>
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
string a[11] = {
	"a = ? max ?",
	"b = a max a",
	"c = b max b",
	"d = c max c",
	"e = d max d",
	"f = e max e",
	"g = f max f",
	"h = g max g",
	"i = h max h",
	"j = i max i",
	"k = (j max j) / j"
};
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	//freopen("java2016.in", "r", stdin);
	//freopen("java2016.out", "w", stdout);
	int c;
	cin >> c;
	if(c == 0)
		return cout << "? /?/ ?" << endl, 0;
	for(int i = 0;i <= 10;i++)
		cout << a[i] << endl;
	int t = sqrt(c);
	string l = "k";
	for(int i = 1;i < t;i++)
		l = l+"+k";
	cout << "l=" << l << endl;
	cout << "l*l";
	int tt = c-t*t;
	for(int i = 1;i <= tt;i++)
		cout << "+k";
	cout << endl;
	return 0;
}
