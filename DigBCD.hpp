# include "tipos_basicos.hpp"

enum DigBCD {c=uci(0),u=uci(1),d=uci(2),t=uci(3),q=uci(4),z=uci(5),x=uci(6),s=uci(7),o=uci(8),n=uci(9),E=uci(255)};

typedef pair<DigBCD,DigBCD> N2DigsBCD;//The pair class couples together a pair of values, which may be of different types (T2 and T1)
									//The individual values can be accessed through its public members first and second.
const DigBCD & operator ++ (DigBCD &);
DigBCD operator ++ (DigBCD &,int);
const DigBCD & operator -- (DigBCD &);
DigBCD operator -- (DigBCD &,int);
DigBCD  operator ! (DigBCD a);// Complemento a nueve
DigBCD operator - (DigBCD a);// Complemento a la Base 10
const DigBCD & mC9 (DigBCD & a);// Complemento a nueve
const DigBCD & mC10 (DigBCD & a);// Complemento a la Base 10
N2DigsBCD operator + (DigBCD a,DigBCD b);
N2DigsBCD operator - (DigBCD a,DigBCD b);
N2DigsBCD operator * (DigBCD a,DigBCD b);
DigBCD  operator / (DigBCD a,DigBCD b);
DigBCD  operator % (DigBCD a,DigBCD b);
const DigBCD & operator *= (DigBCD & a,DigBCD b);
const DigBCD & operator += (DigBCD & a,DigBCD b);
const DigBCD & operator -= (DigBCD & a,DigBCD b);
const DigBCD & operator /= (DigBCD & a,DigBCD b);
const DigBCD & operator %= (DigBCD & a,DigBCD b);
N2DigsBCD DivRem (DigBCD a,DigBCD b);
const DigBCD Sig(const DigBCD & arg);
const DigBCD Pre(const DigBCD & arg);
DigBCD Div2(DigBCD arg);
DigBCD Rem2(DigBCD arg);
N2DigsBCD DivRem_2(DigBCD arg);

bool operator <= (DigBCD,DigBCD);
bool operator >= (DigBCD,DigBCD);
bool operator <  (DigBCD,DigBCD);
bool operator >  (DigBCD,DigBCD);

char Dig2Char(DigBCD);
DigBCD Char2Dig(char);

uchint Dig2Nat(DigBCD);
DigBCD Nat2Dig(uchint);

int    Dig2Int(DigBCD);
DigBCD Int2Dig(int);

N2DigsBCD Dig2N2DigsBCD(DigBCD);

istream & operator >> (istream &,DigBCD &);
ostream & operator << (ostream &,DigBCD);
