const int maxn = 1005;
const int N = 30;			//�ַ�����С 
struct PailndromicTree{	
	int cnt;				//�������ڵ����� 
	int last;				//last��� 
	int ts[maxn], n;		//�ַ���������,��Ч����[2,n-1] 
	int next[maxn][N];		//������ 
	int fail[maxn];			//ʧ��ָ�� 
	int sum[maxn];			//sum[i]:�Խڵ�i��β��������Ӵ�������,��Ч��Χ[2,cnt-1] 
	int num[maxn];			//num[i]:�Խڵ�i��β�Ļ����Ӵ���������,��Ч��Χ[2,cnt-1]
	int len[maxn];			//len[i]:�Խڵ�i��β��������Ӵ��ĳ��� ,��Ч��Χ[2,cnt-1]
	int s_sum[maxn];		//s_sum[i]:���±�i��β�Ļ����Ӵ����� ,��Ч��Χ[0,n-3] 
	
	
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
	
	void count(){			//ͳ�ƻ��Ĵ����ִ��� 
		for(int i = cnt-1;i >= 2;i--) sum[fail[i]] += sum[i];
	}
	
	void init(){			//��ʼ�������� 
		cnt = 0;last = 0;
		n = 1;ts[0] = -1;ts[1] = -1;
		fail[0] = fail[1] = 1;
		newnode(0);newnode(-1);
	}
	
	void built(char t[]){	//���������� 
		int tn = strlen(t);
		for(int i = 0;i < tn;i++) {
			add(t[i]);
			s_sum[i] = num[last];
		} 
		ts[++n] = 0;
		count();
	}
	
	int diff_num(){			//���ʲ�ͬ���Ĵ����� 
		return cnt - 2;
	}
};

