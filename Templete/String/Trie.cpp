//Trie
int trie[size][26], tot = 1;
int count[size];
void insert(int x, char s[]){
	int n = strlen(s);
	int p = 1;
	for(int k = 0; k < n;k++){
		int ch = s[k]-'a';
		if(trie[p][ch] == 0) trie[p][ch] = ++tot;
		p = trie[p][ch];
	}
	count[p] += x;
}
int search(char s[]){
	int n = strlen(s);
	int p = 1;
	for(int k = 0;k < n;k++){
		int ch = s[k]-'a';
		if(trie[p][ch] == 0) return 0;
		p = trie[p][ch];
	}
	return count[p];
}

