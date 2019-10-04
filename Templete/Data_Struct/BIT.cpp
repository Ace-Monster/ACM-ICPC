//�߶����ʺ��� �����+�β�ѯ���θ���+���ѯ
//�����������ʹ���߶��� 

const int maxn = 100005;
#define lowbit(x) x&-x

//�����+�β�ѯ������ǰ׺�ͣ�bΪǰ׺������ 
int b[maxn], n; 
void add(int i, int t){//������� 
	for(;i <= n;b[i] += t,i += lowbit(i));
}
int query(int i){//���ز�ѯ���ǰ׺�� 
	int sum;
	for(sum = 0;i >= 1;sum += b[i], i -= lowbit(i));
	return sum;
}


//�θ���+���ѯ�����ز�ѯ���ֵ��cΪ�������
//query()��add()�͵�+����ͬ 
int c[maxn], n;
void add(int i, int t){
	for(;i <= n;c[i] += t,i += lowbit(i));
}
void range_add(int i, int l, int r){//������� 
	add(i, l);
	add(-i, r+1);
}
int query(int i){//���ز�ѯ���ֵ 
	int sum;
	for(sum = 0;i >= 1;sum += c[i], i -= lowbit(i));
	return sum;
}


//�θ���+�β�ѯ����ͬΪ������������£����ѯ(ǰ׺��)��ʽΪ
// sum(i) = c[0]+(c[0]+c[1])+(c[0]+c[1]+c[2])+...+(c[0]+...+c[i])
//�� sum(i) = ��(x=0, i) (i-x)*c[x]
//sum(i) = i*(c[1]+c[2]+...+c[i])-(0*c[1]+1*c[2]+...+(i-1)*c[i])
//����ά������������飬c1[i] = c[i],c2[i] = (i-1)*c[i]; 
int c1[maxn],c2[maxn],n;
int add(int t, int p){
	for(int i = p;i <= n;i += (i&-i)){
		c1[i] += t;
		c2[i] += (p-1)*t;
	}
}
int r_add(int l,int r,int t){
	add(t, l);
	add(-t, r+1);
}
int query(int p){
	int sum = 0;
	for(int i = p;i >= 1;i-=(i&-i)){
		sum += p*c1[i] - c2[i];
	}
	return sum;
}
int r_query(int l,int r){
	return query(r)-query(l-1);
}
