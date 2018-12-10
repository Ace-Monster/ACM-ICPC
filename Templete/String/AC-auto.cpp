int trie[maxn][26], tot = 1;
int counts[maxn];
int fail[maxn];
char s[maxn];
void insert(char s[]){
	int n = strlen(s);
	int p = 1;
	for(int k = 0; k < n;k++){
		int ch = s[k]-'a';
		if(trie[p][ch] == 0) trie[p][ch] = ++tot;
		p = trie[p][ch];
	}
	counts[p]++;
}
void getfail(){
	queue<int> q;
	for(int i = 0;i < 26;i++){
		if(trie[1][i]){
			fail[trie[1][i]] = 1;
			q.push(trie[1][i]);
		}
		else trie[1][i] = 1;
	}
	while(sz(q)){
		int p = q.front();
		q.pop();
		for(int i = 0;i < 26;i++){
			if(trie[p][i]){
				fail[trie[p][i]] = trie[fail[p]][i];
				q.push(trie[p][i]);
			}else{
				trie[p][i] = trie[fail[p]][i];
			}
		}
	}
}
int query(char s[], int n){
	int ans = 0;
	int p = 1;
	for(int i = 0;i < n;i++){
		int ch = s[i]-'a';
		p = trie[p][ch];
		for(int j = p;j > 1 && counts[j] != -1;j = fail[j]){
			ans += counts[j];
			counts[j] = -1;
		}
	}
	return ans;
}
void init(){
	tot = 1;
	memset(fail, 0, sizeof fail);
	memset(trie, 0, sizeof trie);
	memset(counts, 0, sizeof counts);
}
