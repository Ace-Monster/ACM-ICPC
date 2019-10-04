----������----
// ���׹�ʽ
S = sqrt(p * (p - a) * (p - b) * (p - c)) , p = (a + b + c) / 2

----Բ̨----
һ���ϵװ뾶Ϊ r ���µװ뾶Ϊ R (r < R) ����Ϊ H ��Բ̨
���ϵ� h �����λ�ã��뾶 x Ϊ��
x = r + h * (R - r) / H
֤����
��Բ̨��һ�����ͼ����һ�� R * H �ľ��Σ����ɿ���
(x - r) / (R - r) = h / H

Բ̨�����ʽ��
PI * h * (R * R + R * r + r * r) / 3.0
r Ϊ�ϵװ뾶�� R Ϊ�µװ뾶�� h Ϊ�ߡ�

// ����Ρ�͹��
typedef vector<P> polygon;
polygon Convex(polygon A) {  // ��͹������ʱ������ �ڽ� <180 : (<=) ; �ڽ� <=180 : (<) ��
    int n = sz(A); if (n <= 1) return A;
    sort(all(A));
    polygon B;
    for (int i = 0; i < n; B.pb(A[i++]))
        while (sz(B) > 1 && crossSgn(B[sz(B)-2], B.back(), A[i]) < 0) B.pop_back();  // ��������� <
    for (int i = n - 2, t = sz(B); i >= 0; B.pb(A[i--]))
        while (sz(B) > t && crossSgn(B[sz(B)-2], B.back(), A[i]) < 0) B.pop_back();  // ͬ��
    B.pop_back(); return B;
}
T areaPoly(polygon A) {  // ����� A ����������Ϳ��Է�����������������־���
    T res = 0;
    rep(i, 0, sz(A)) res += A[i] / A[ (i+1) % sz(A) ];
    return fabs(res) / 2;
}
bool isConvex(polygon A) {  // ����� A �Ƿ���͹����Ҫ�� A �ĵ㼯����ʱ������
    rep(i, 0, 2) A.pb(A[i]);
    rep(i, 0, sz(A)-2) if ( sgn( (A[i+1]-A[i]) / (A[i+2]-A[i]) ) < 0 ) return 0;
    return 1;
}
int relPPoly(P p, polygon A) {  // ��Ͷ���ι�ϵ ( 2 : in , 1 : on , 0 : out )
    int res = 0; A.pb(A[0]);
    rep(i, 1, sz(A)) {
        P u = A[i-1], v = A[i];
        if (onPS(p, L(u, v))) return 1;
        if (sgn(u.y - v.y) > 0) swap(u, v);
        if (sgn(u.y - p.y) >= 0 || sgn(v.y - p.y) < 0) continue;
        if (crossSgn(v, u, p) < 0) res ^= 1;
    }
    return res << 1;
}
T ConvexDiameter(polygon A) {  // ͹�� A ��ֱ������͹�� A �ϵ���Զ���
    int now = 0, n = sz(A); T res = 0;
    if (n <= 1) return 0;
    rep(i, 0, sz(A)) {
        now = max(now, i);
        while (1) {
            T t1 = dis(A[i], A[now%n]), t2 = dis(A[i], A[(now+1)%n]);
            res = max(res, max(t1, t2));
            if (t2 > t1) now++; else break;
        }
    }
    return res;
}
polygon ConvexCut(polygon A, L a) {  // ��ƽ�� a �и�͹�� A �γɵ�͹����ֱ�� a ��ʱ�뷽��
    int n = sz(A); A.pb(A[0]); polygon res;
    rep(i, 0, n) {
        int w1 = crossSgn(a.s, a.t, A[i]), w2 = crossSgn(a.s, a.t, A[i+1]);
        if (w1 >= 0) res.pb(A[i]);
        if (w1 * w2 < 0) res.pb(xLL(a, L(A[i], A[i+1])));
    }
    return res;
}
T _closePP(polygon &A, int l, int r) {  // ��������� closePP(A)
    if (r - l < 6) {
        T res = 1e20;
        rep(i, l, r+1) rep(j, i+1, r+1) res = min(res, dis(A[i], A[j]));
        return res;
    }
    int m = l + r >> 1;
    T res = min(_closePP(A, l, m), _closePP(A, m+1, r));
    polygon B; rep(i, l, r+1) if (fabs(A[i].x - A[m].x) < res) B.pb(A[i]);
    sort(all(B), [&](P p1, P p2){ return p1.y < p2.y; });
    rep(i, 0, sz(B)) for (int j = i+1; j < sz(B) && B[j].y - B[i].y < res; j++)
        res = min(res, dis(B[i], B[j]));
    return res;
}
T closePP(polygon A) {  // �㼯 A �е�������
    sort(all(A), [&](P a, P b){ return a.x < b.x; });
    return _closePP(A, 0, sz(A)-1);
}


