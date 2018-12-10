//KMP
//nex数组：最长公共前缀后缀的长度 
int nex[maxn];
char s[maxn], t[maxn];
void kmp_pre(int m){//匹配串处理 
	int i, j;
	j = nex[0] = -1;
	i = 0;
	while(i < m){
		while(j != -1 && t[i] != t[j]) j = nex[j];
		nex[++i] = ++j;
	}
}
vi pos;
int kmp(int n, int m){
	int i = 0, j = 0;
	int ans = 0;
	while(i < n){
		if(s[i] == t[j]){
			i++,j++;
			if(j == m){
				pos.pb(i-j+1);//记录出现的位置
				ans++; //出现次数，可重叠 
			}
		}else{
			if(j == 0) i++;
			else j = nex[j-1]+1;
		}
	}
	return ans;
}
//kmp的性质
//if(nex[i] > 0 && i%nex[i] == 0) 存在以i为结尾的最长循环节 
//最小循环节长度:i-nex[i]
//最大循环次数：i/(i-nex[i])
//对于不完整的最大循环节，至少需要补充ans个字符使其完整 
//ans = (len-nex[len])-len%(len-nex[len]) 

//EX_KMP
//nex[i] T[i...m-1]与T[0...m-1]的最长公共前缀长度
//extend[i] S[i...n-1]与T[0...m-1]的最长公共前缀
int nex[maxn];
char s[maxn],t[maxn];
void exkmp_pre(int m){
	int i = 0;
	nex[0] = m;
	while(i+1 < m && t[i] == t[i+1]) i++;
	nex[1] = i;
	int k = 1;
	for(int j = 2;j < m;j++){
		int p = nex[k]+k-1;
		int L = nex[j-k];
		if(j+L < p+1) nex[j] = L;
		else{
			i = max(0, p-j+1);
			while(j+i < m && t[j+i] == t[i]) i++;
			nex[j] = i;
			k = j;
		}
	}
}
void exkmp(int n,int m){
	int i = 0;
	while(i < n && i < m && s[i] == t[i]) i++;
	extend[0] = i;
	int k = 0;
	for(int j = 1;j < n;j++){
		int p = extend[k]+k-1;
		int L = nex[j-k];
		if(j+L < p+1) extend[j] = L;
		else{
			i = max(0, p-j+1);
			while(j+i < n && i < m && s[j+i] == t[i]) i++;
			extend[j] = i;
			k = j;
		}
	}
}
