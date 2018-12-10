
struct C { P o; T r; C () {} C (P o, T r) : o(o), r(r) {} };

int relCC(C A, C B) {  // 两圆关系，返回公切线数量 ( 4 : 相离 ; 3 : 外切 ; 2 : 相交 ; 1 : 内切 ; 0 : 内含 )
    T dis = (A.o - B.o).abs();
    if (sgn(dis - (A.r + B.r)) == 1) return 4;
    if (sgn(dis - (A.r + B.r)) == 0) return 3;
    if (sgn(dis - fabs(A.r - B.r)) == 1) return 2;
    if (sgn(dis - fabs(A.r - B.r)) == 0) return 1;
    return 0;
}

vector<P> xCL(C A, L b) {  // 圆 A 与直线 b 的交点
    P k = proj(A.o, b);
    T d = A.r * A.r - (k - A.o).abs2();
    if (sgn(d) == -1) return {};
    P del = (b.s - b.t).unit() * sqrt(max(d, 0.0));
    return { k - del, k + del };
}

vector<P> xCC(C A, C B) {  // 圆 A 与圆 B 的交点
    int pd = relCC(A, B); if (pd == 0 || pd == 4) return {};
    T a = (B.o - A.o).abs2();
    T cosA = (A.r * A.r + a - B.r * B.r) / (2 * A.r * sqrt(max(a, 0.0)));
    T b = A.r * cosA, c = sqrt(max(0.0, A.r * A.r - b * b));
    P k = (B.o - A.o).unit(), m = A.o + k * b, del = k.rot90() * c;
    return { m - del, m + del };
}

vector<P> tCP(C A, P p) {  // 过点 p 的切线与圆 A 的切点
    T a = (p - A.o).abs(), b = A.r * A.r / a, c = sqrt(max(0.0, A.r * A.r - b * b));
    P k = (p - A.o).unit(), m = A.o + k * b, del = k.rot90() * c;
    return { m - del, m + del };
}

vector<L> extCC(C A, C B) {  // 圆 A 与圆 B 的外公切线
    int pd = relCC(A, B); if (pd == 0) return {};
    if (pd == 1) { P k = xCC(A, B)[0]; return { L(k, k) }; }
    if (sgn(A.r - B.r) == 0) {
        P del = (B.o - A.o).unit().rot90().toR();
        return { L(A.o - del * A.r, B.o - del * B.r), L(A.o + del * A.r, B.o + del * B.r) };
    } else {
        P p = (B.o * A.r - A.o * B.r) / (A.r - B.r);
        vector<P> a = tCP(A, p), b  = tCP(B, p);
        vector<L> res;
        rep(i, 0, sz(a)) res.pb(L(a[i], b[i]));
        return res;
    }
}

vector<L> intCC(C A, C B) {  // 圆 A 与圆 B 的内公切线
    int pd = relCC(A, B); if (pd <= 2) return {};
    if (pd == 3) { P k = xCC(A, B)[0]; return { L(k, k) }; }
    P p = (B.o * A.r + A.o * B.r) / (A.r + B.r);
    vector<P> a = tCP(A, p), b = tCP(B, p);
    vector<L> res;
    rep(i, 0, sz(a)) res.pb(L(a[i], b[i]));
    return res;
}

vector<L> tCC(C A, C B) {  // 圆 A 与圆 B 的公切线
    int f = 0; if (A.r < B.r) swap(A, B), f = 1;
    vector<L> a = extCC(A, B), b = intCC(A, B);
    for (L o : b) a.pb(o);
    if (f) for (L &o : a) swap(o.s, o.t);
    return a;
}

T areaCTri(T r, P s, P t) {  // 圆 (o, r) 与三角形 (o, s, t) 相交的面积；由 areaCPoly() 调用，用来计算圆与多边形相交的面积
    vector<P> p12 = xCL(C(P(0, 0), r), L(s, t));
    if (sz(p12) == 0) return r * r * rad(s, t);
    P p1 = p12[0], p2 = p12[1];
    bool b1 = sgn(s.abs2() - r * r) == 1, b2 = sgn(t.abs2() - r * r) == 1;
    if (b1 && b2) {
        if (sgn((s - p1) * (t - p1)) <= 0 && sgn((s - p2) * (t - p2)) <= 0)
            return r * r * (rad(s, p2) + rad(p1, t)) + p2 / p1;
        else return r * r * rad(s, t);
    } else if (b1) return r * r * rad(s, p2) + p2 / t;
    else if (b2) return r * r * rad(p1, t) + s / p1;
    return s / t;
}

T areaCPoly(C A, polygon B) {  // 圆 A 与多边形 B 相交的面积
    T res = 0; B.pb(B[0]);
    rep(i, 1, sz(B)) {
        P u = B[i-1], v = B[i];
        res += areaCTri(A.r, u - A.o, v - A.o);
    }
    return fabs(res) / 2;
}

C getC(P a,P b,P c){  // 三点确定一个圆 （ 三角形外接圆 ）
    db a1 = b.x - a.x, b1 = b.y - a.y, c1 = (a1 * a1 + b1 * b1) / 2;
    db a2 = c.x - a.x, b2 = c.y - a.y, c2 = (a2 * a2 + b2 * b2) / 2;
    db d = a1 * b2 - a2 * b1;
    P o = P(a.x + (c1 * b2 - c2 * b1) / d, a.y + (a1 * c2 - a2 * c1) / d);
    return C(o, dis(a, o));
}


