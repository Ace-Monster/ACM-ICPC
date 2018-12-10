const int maxn = 1005;
const int N = 30;			//字符集大小 
struct PailndromicTree{	
	int cnt;				//回文树节点数量 
	int last;				//last标记 
	int ts[maxn], n;		//字符串及长度,有效区间[2,n-1] 
	int next[maxn][N];		//回文树 
	int fail[maxn];			//失败指针 
	int sum[maxn];			//sum[i]:以节点i结尾的最长回文子串的数量,有效范围[2,cnt-1] 
	int num[maxn];			//num[i]:以节点i结尾的回文子串的种类数,有效范围[2,cnt-1]
	int len[maxn];			//len[i]:以节点i结尾的最长回文子串的长度 ,有效范围[2,cnt-1]
	int s_sum[maxn];		//s_sum[i]:以下标i结尾的回文子串个数 ,有效范围[0,n-3] 
	
	
	int newnode(int l){		
		for(int i = 0;i < N;i++) next[cnt][i] = 0;
		sum[cnt] = 0;num[cnt] = 0;len[cnt] = l;
		return cnt++;
	}
	
	int get_fail(int x){
		while(ts[n-len[x]-1] != ts[n]) x = fail[x];
		return x;
	}
	
	void add(char c){
		c -= 'a'; ts[++n] = c;
		int cur = get_fail(last);
		if(!next[cur][c]){
			int now = newnode(len[cur]+2);
			fail[now] = next[get_fail(fail[cur])][c];
			next[cur][c] = now;
			num[now] = num[fail[now]]+1;
		}
		sum[last = next[cur][c]]++;
	}
	
	void count(){			//统计回文串出现次数 
		for(int i = cnt-1;i >= 2;i--) sum[fail[i]] += sum[i];
	}
	
	void init(){			//初始化回文树 
		cnt = 0;last = 0;
		n = 1;ts[0] = -1;ts[1] = -1;
		fail[0] = fail[1] = 1;
		newnode(0);newnode(-1);
	}
	
	void built(char t[]){	//建立回文树 
		int tn = strlen(t);
		for(int i = 0;i < tn;i++) {
			add(t[i]);
			s_sum[i] = num[last];
		} 
		ts[++n] = 0;
		count();
	}
	
	int diff_num(){			//本质不同回文串数量 
		return cnt - 2;
	}
};

