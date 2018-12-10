/* 注意
  1. 点、向量
    1. 如果角度出现 -pi ，可以加上 2pi 修正为 pi
    2. atan2(y, x) 的参数是浮点数时，可能出现 -pi ，如 atan2(-0.0, -1.0)
  2. 线段、直线
    1. 线段严格相交定义为：每条线段的两个端点落在另一条线段两边，形象来说，就是可以在图形里看到四个端点和一个交点
*/

typedef db T;
const db eps = 1e-7, pi = acosl(-1.);
int sgn(T x) { return (x > eps) - (x < -eps); }
bool inMid(T l, T x, T r) { return sgn(l - x) * sgn(r - x) <= 0; }  // 数 x 在区间 [l, r] 内（包括边界）

// 点、向量
struct P {
    T x, y; P () {} P(T x, T y) : x(x), y(y) {}
    P operator + (const P &b) const { return P(x + b.x, y + b.y); }  // 向量加
    P operator - (const P &b) const { return P(x - b.x, y - b.y); }  // 向量减
    T operator * (const P &b) const { return x * b.x + y * b.y; }    // 向量点积
    T operator / (const P &b) const { return x * b.y - y * b.x; }    // 向量叉积
    P operator * (const T &k) const { return P(x * k, y * k); }      // 向量数乘
    P operator / (const T &k) const { return P(x / k, y / k); }      // 向量数除
    bool operator < (const P &b) const { return sgn(x - b.x) ? x < b.x : y < b.y; }  // 左小右大，下小上大
    bool operator == (const P &b) const { return !sgn(x - b.x) && !sgn(y - b.y); }   // 向量相等
    P rot(T t) { return P(x * cos(t) - y * sin(t), x * sin(t) + y * cos(t)); }  // 向量逆时针旋转 t 弧度
    P rot90() { return P(-y, x); }           // 向量逆时针旋转 90 度
    db arg() const { return atan2(y, x); }   // 方位角 (-pi, pi]
    T abs() { return sqrt(x * x + y * y); }  // 向量模长
    T abs2() { return x * x + y * y; }       // 向量模长的平方
    P unit() { return (*this) / abs(); }     // 单位向量
    void scan() { db tx, ty; scanf("%lf%lf", &tx, &ty); x = tx; y = ty; }  // 输入
    void print() { printf("%.11lf %.11lf\n", x, y); }                      // 输出
    P toR() { return (sgn(x) == -1 || !sgn(x) && sgn(y) == -1) ? (*this)*(-1) : (*this); }  // 若向量在 2 3 象限，则取相反向量
    bool isUp() const { return sgn(y) == 1 || !sgn(y) && sgn(x) == -1; }                    // 向量是否在 1 2 象限
};
T dis(P a, P b) { return (b - a).abs(); }   // 点 a 到点 b 的距离
P symmetry(P p, P a) { return a + a - p; }  // 点 p 关于点 a 的中心对称点
T cross(P o, P a, P b) { return (a - o) / (b - o); }         // 向量 oa 与 ob 的叉积
int crossSgn(P o, P a, P b) { return sgn(cross(o, a, b)); }  // 向量 oa 与 ob 的叉积符号
db rad(P a, P b) { return atan2(a / b, a * b); }             // 向量 a 与 b 的夹角（弧度制）
bool order(const P &a, const P &b) { return a.isUp() < b.isUp() || a.isUp() == b.isUp() && sgn(a/b) > 0; }  // 极角排序


