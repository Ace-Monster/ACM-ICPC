//KMP
//nex���飺�����ǰ׺��׺�ĳ��� 
int nex[maxn];
char s[maxn], t[maxn];
void kmp_pre(int m){//ƥ�䴮���� 
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
				pos.pb(i-j+1);//��¼���ֵ�λ��
				ans++; //���ִ��������ص� 
			}
		}else{
			if(j == 0) i++;
			else j = nex[j-1]+1;
		}
	}
	return ans;
}
//kmp������
//if(nex[i] > 0 && i%nex[i] == 0) ������iΪ��β���ѭ���� 
//��Сѭ���ڳ���:i-nex[i]
//���ѭ��������i/(i-nex[i])
//���ڲ����������ѭ���ڣ�������Ҫ����ans���ַ�ʹ������ 
//ans = (len-nex[len])-len%(len-nex[len]) 

//EX_KMP
//nex[i] T[i...m-1]��T[0...m-1]�������ǰ׺����
//extend[i] S[i...n-1]��T[0...m-1]�������ǰ׺
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
