class Fraction
{
public:
    Bigint A,B;
    Fraction(){}
    Fraction(int a,int b){
        A=a;B=b;Reduction();return;
    }
    Fraction(Bigint a,Bigint b){
        A=a;B=b;Reduction();return;
    }
    void Reduction(){
        if (A.zero()){
            B=1;return;
        }
        for (int i=2;i<=100;i++)
	    while ((A%i==0)&&(B%i==0)) A=A/i,B=B/i;
        return;
    }
    bool zero(){
        return A.zero();
    }
    Fraction Assign(int a,int b){
        A=a;B=b;Reduction();return *this;
    }
    void outp(){
        A.outp();printf("/");B.outp();
        return;
    }
};
Fraction operator + (Fraction F,int a){
    F.A=F.A+F.B*a;F.Reduction();return F;
}
Fraction operator - (Fraction F,int a){
    F.A=F.A-F.B*a;F.Reduction();return F;
}
Fraction operator * (Fraction F,int a){
    F.A=F.A*a;F.Reduction();return F;
}
Fraction operator / (Fraction F,int a){
    F.B=F.B*a;F.Reduction();return F;
}
Fraction operator + (Fraction F,Bigint a){
    F.A=F.A+F.B*a;F.Reduction();return F;
}
Fraction operator - (Fraction F,Bigint a){
    F.A=F.A-F.B*a;F.Reduction();return F;
}
Fraction operator * (Fraction F,Bigint a){
    F.A=F.A*a;F.Reduction();return F;
}
Fraction operator / (Fraction F,Bigint a){
    F.B=F.B*a;F.Reduction();return F;
}
Fraction operator + (Fraction F,Fraction a){
    a.Reduction();if (a.zero()) return F;
    F.A=F.A*a.B+F.B*a.A;F.B=F.B*a.B;F.Reduction();return F;
}
Fraction operator - (Fraction F,Fraction a){
    a.Reduction();if (a.zero()) return F;
    F.A=F.A*a.B-F.B*a.A;F.B=F.B*a.B;F.Reduction();return F;
}
Fraction operator * (Fraction F,Fraction a){
    F.A=F.A*a.A;F.B=F.B*a.B;
    F.Reduction();return F;
}
Fraction operator / (Fraction F,Fraction a){
    F.A=F.A*a.B;F.B=F.B*a.A;F.Reduction();return F;
}
