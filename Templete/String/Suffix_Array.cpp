//suffix(i):下标为i的后缀 
int sa[maxn];//sa[i]:大小排名为i的后缀的下标，有效下标[1...n] 
int ranks[maxn];//rank[i]:suffix(i)的名次，有效下标[0...n-1] 
int height[maxn];//height[i]: suffix(sa[i-1])与suffix(sa[i])的公共前缀长度，有效下标[2...n] 
//suffix(j)与suffix(k)的公共前缀长度 = min(height[rank[j]+1]...height[rank[k]]) 
//倍增
const int M = 30;
int t1[maxn],t2[maxn],c[maxn];
bool cmp(int r[], int a, int b, int l){
	return r[a] == r[b] && r[a+l] == r[b+l];
}
void da(char s[], int sa[], int rank[], int height[], int n, int m){
	n++;
	int *x = t1, *y = t2, p;
	for(int i = 0;i < m;i++) c[i] = 0;//init
	for(int i = 0;i < n;i++) c[x[i] = s[i]]++;//sort key1
	for(int i = 1;i < m;i++) c[i] += c[i-1];
	for(int i = n-1;i >= 0;i--) sa[--c[x[i]]] = i;//upd sa
	for(int j = 1;j <= n;j <<= 1){
		p = 0;
		for(int i = n-j;i < n;i++) y[p++] = i;
		for(int i = 0;i < n;i++) 
			if(sa[i] >= j) y[p++] = sa[i]-j;//sort key2
			
		for(int i = 0;i < m;i++) c[i] = 0;
		for(int i = 0;i < n;i++) c[x[y[i]]]++;//sort key1
		for(int i = 1;i < m;i++) c[i] += c[i-1];
		for(int i = n-1;i >= 0;i--) sa[--c[x[y[i]]]] = y[i];//upd sa
		
		swap(x,y);
		p = 1;x[sa[0]] = 0;
		for(int i = 1;i < n;i++)
			x[sa[i]] = cmp(y, sa[i-1], sa[i], j) ? p-1:p++;
		if(p >= n) break;
		m = p;
	}
	int k = 0, j;
	n--;
	for(int i = 0;i <= n;i++) ranks[sa[i]] = i;
	for(int i = 0;i < n;i++){
		if(k) k--;
		j = sa[ranks[i]-1];
		while(s[i+k] == s[j+k] && i+k < n && j+k < n) 
			k++;
		height[ranks[i]] = k;
	}
}

//LCP(l,r),suffix(l)与suffix(r)的最长公共前缀长度 
int LCP(int l, int r){
	l = ranks[l], r = ranks[r];
	if(l > r) swap(l, r);
	return query(l+1, r);//st表维护min(height[l+1]...height[r]) 
}
