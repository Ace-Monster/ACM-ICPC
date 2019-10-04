/* ע��
  1. �㡢����
    1. ����Ƕȳ��� -pi �����Լ��� 2pi ����Ϊ pi
    2. atan2(y, x) �Ĳ����Ǹ�����ʱ�����ܳ��� -pi ���� atan2(-0.0, -1.0)
  2. �߶Ρ�ֱ��
    1. �߶��ϸ��ཻ����Ϊ��ÿ���߶ε������˵�������һ���߶����ߣ�������˵�����ǿ�����ͼ���￴���ĸ��˵��һ������
*/

typedef db T;
const db eps = 1e-7, pi = acosl(-1.);
int sgn(T x) { return (x > eps) - (x < -eps); }
bool inMid(T l, T x, T r) { return sgn(l - x) * sgn(r - x) <= 0; }  // �� x ������ [l, r] �ڣ������߽磩

// �㡢����
struct P {
    T x, y; P () {} P(T x, T y) : x(x), y(y) {}
    P operator + (const P &b) const { return P(x + b.x, y + b.y); }  // ������
    P operator - (const P &b) const { return P(x - b.x, y - b.y); }  // ������
    T operator * (const P &b) const { return x * b.x + y * b.y; }    // �������
    T operator / (const P &b) const { return x * b.y - y * b.x; }    // �������
    P operator * (const T &k) const { return P(x * k, y * k); }      // ��������
    P operator / (const T &k) const { return P(x / k, y / k); }      // ��������
    bool operator < (const P &b) const { return sgn(x - b.x) ? x < b.x : y < b.y; }  // ��С�Ҵ���С�ϴ�
    bool operator == (const P &b) const { return !sgn(x - b.x) && !sgn(y - b.y); }   // �������
    P rot(T t) { return P(x * cos(t) - y * sin(t), x * sin(t) + y * cos(t)); }  // ������ʱ����ת t ����
    P rot90() { return P(-y, x); }           // ������ʱ����ת 90 ��
    db arg() const { return atan2(y, x); }   // ��λ�� (-pi, pi]
    T abs() { return sqrt(x * x + y * y); }  // ����ģ��
    T abs2() { return x * x + y * y; }       // ����ģ����ƽ��
    P unit() { return (*this) / abs(); }     // ��λ����
    void scan() { db tx, ty; scanf("%lf%lf", &tx, &ty); x = tx; y = ty; }  // ����
    void print() { printf("%.11lf %.11lf\n", x, y); }                      // ���
    P toR() { return (sgn(x) == -1 || !sgn(x) && sgn(y) == -1) ? (*this)*(-1) : (*this); }  // �������� 2 3 ���ޣ���ȡ�෴����
    bool isUp() const { return sgn(y) == 1 || !sgn(y) && sgn(x) == -1; }                    // �����Ƿ��� 1 2 ����
};
T dis(P a, P b) { return (b - a).abs(); }   // �� a ���� b �ľ���
P symmetry(P p, P a) { return a + a - p; }  // �� p ���ڵ� a �����ĶԳƵ�
T cross(P o, P a, P b) { return (a - o) / (b - o); }         // ���� oa �� ob �Ĳ��
int crossSgn(P o, P a, P b) { return sgn(cross(o, a, b)); }  // ���� oa �� ob �Ĳ������
db rad(P a, P b) { return atan2(a / b, a * b); }             // ���� a �� b �ļнǣ������ƣ�
bool order(const P &a, const P &b) { return a.isUp() < b.isUp() || a.isUp() == b.isUp() && sgn(a/b) > 0; }  // ��������


