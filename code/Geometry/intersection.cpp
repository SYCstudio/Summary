Point GetP(Line A,Line B){//.p 为位置向量， .d 为方向向量
    Point dx=A.p-B.p;
    ld t=Cross(B.d,dx)/Cross(A.d,B.d);
    return A.p+A.d*t;
}
