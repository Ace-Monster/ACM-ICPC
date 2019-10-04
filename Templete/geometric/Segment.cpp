
// �߶Ρ�ֱ��
struct L { P s, t; L () {} L(P s, P t) : s(s), t(t) {} };
bool onPS(P p, L a) { return sgn((a.t-a.s)/(p-a.s))==0 && sgn((p-a.s)*(p-a.t))<=0; }   // �� p �Ƿ����߶� a ��
bool inRec(P p, L a) { return inMid(a.s.x, p.x, a.t.x) && inMid(a.s.y, p.y, a.t.y); }  // �� p ����ֱ�� a Ϊ�Խ��ߵľ�����
P proj(P p, L a) { return (a.t-a.s) * ( (p-a.s) * (a.t-a.s) / (a.t-a.s).abs2() ) + a.s; }  // �� p ����ֱ�� a ��ͶӰ��
P reflect(P p, L a) { return proj(p, a) * 2 - p; }                                         // �� p ����ֱ�� a �ĶԳƵ�
bool xSSr(const L &a, const L &b) {  // �߶� a ���߶� b �ϸ��ཻ
    T c1 = (a.t-a.s) / (b.s-a.s), c2 = (a.t-a.s) / (b.t-a.s);
    T c3 = (b.t-b.s) / (a.s-b.s), c4 = (b.t-b.s) / (a.t-b.s);
    return sgn(c1) * sgn(c2) < 0 && sgn(c3) * sgn(c4) < 0;
}
bool xSS(L a, L b) {                 // �߶� a ���߶� b ���ϸ��ཻ
    T c1 = (a.t-a.s) / (b.s-a.s), c2 = (a.t-a.s) / (b.t-a.s);
    T c3 = (b.t-b.s) / (a.s-b.s), c4 = (b.t-b.s) / (a.t-b.s);
    return sgn(c1) * sgn(c2) <= 0 && sgn(c3) * sgn(c4) <= 0 &&
           sgn(max(a.s.x,a.t.x) - min(b.s.x,b.t.x)) >= 0 &&
           sgn(max(b.s.x,b.t.x) - min(a.s.x,a.t.x)) >= 0 &&
           sgn(max(a.s.y,a.t.y) - min(b.s.y,b.t.y)) >= 0 &&
           sgn(max(b.s.y,b.t.y) - min(a.s.y,a.t.y)) >= 0;
}
bool xSL(L a, L b) {  // �߶� a ��ֱ�� b �ཻ ( ���ϸ� : <= ; �ϸ� : < )
    return sgn( (b.t - b.s) / (a.s - b.s) ) * sgn( (b.t - b.s) / (a.t - b.s) ) <= 0;
}
P xLL(L a, L b) {  // ֱ�� a ��ֱ�� b �Ľ���
    T s1 = (b.t - b.s) / (a.s - b.s), s2 = (a.t - b.s) / (b.t - b.s);
    return (a.s * s2 + a.t * s1) / (s1 + s2);
}
db disPL(P p, L a) { return fabs( (a.t-a.s) / (p-a.s) ) / (a.t-a.s).abs(); }  // �� p ��ֱ�� a �ľ���
db disPS(P p, L a) {                                                          // �� p ���߶� a �ľ���
    return sgn( (a.t-a.s) * (p-a.s) ) * sgn( (a.s-a.t) * (p-a.t) ) == 1
           ? disPL(p, a) : min( (p-a.s).abs(), (p-a.t).abs() );
}
db disSS(L a, L b){                                                           // �߶� a ���߶� b �ľ���
    if (xSS(a,b)) return 0;
    return min( min( disPS(a.s,b), disPS(a.t,b) ), min( disPS(b.s,a), disPS(b.t,a) ) );
}
db disLL(L a, L b) { return (a.t-a.s) / (b.t-b.s) ? 0 : disPL(a.s, b); }      // ֱ�� a ��ֱ�� b �ľ���


