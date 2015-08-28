#include "ParBCD.hpp"
using namespace std;

DigBCD Div2(DigBCD arg) {		//Divide the number by 2 like this /
	switch (arg) {
			case c:
			case u:
				return c;
			case d:
			case t:
				return u;
			case q:
			case z:
				return d;
			case x:
			case s:
				return t;
			case o:
			case n:
				return q;
			case E:
			default:
				return E;
		}
}

DigBCD Rem2(DigBCD arg) {		//divide the number by 2 like this %
	switch (arg) {
			case c:
			case d:
			case q:
			case x:
			case o:
				return c;
			case u:
			case t:
			case z:
			case s:
			case n:
				return u;
			case E:
			default:
				return E;
		}
}

const DigBCD & operator *= (DigBCD & a,DigBCD b) {
	if ((a==c)||(b==u)) return a;
	else if ((b==c)||(a==u)) {
			a=b;
			return a;
		} else if ((b==E)||(a==E)) {
			a=E;
			return a;
		} else
		switch (b) {
				case d :
					switch (a) {
							case d: {
									a=q;
									return a;
								}
							case t: {
									a=x;
									return a;
								}
							case q: {
									a=o;
									return a;
								}
							case z: {
									a=c;
									return a;
								}
							case x: {
									a=d;
									return a;
								}
							case s: {
									a=q;
									return a;
								}
							case o: {
									a=x;
									return a;
								}
							case n:
							default: {
									a=o;
									return a;
								}
						}
				case t :
					switch (a) {
							case d: {
									a=x;
									return a;
								}
							case t: {
									a=n;
									return a;
								}
							case q: {
									a=d;
									return a;
								}
							case z: {
									a=z;
									return a;
								}
							case x: {
									a=o;
									return a;
								}
							case s: {
									a=u;
									return a;
								}
							case o: {
									a=q;
									return a;
								}
							case n:
							default: {
									a=s;
									return a;
								}
						}
				case q :
					switch (a) {
							case d: {
									a=o;
									return a;
								}
							case t: {
									a=d;
									return a;
								}
							case q: {
									a=x;
									return a;
								}
							case z: {
									a=c;
									return a;
								}
							case x: {
									a=q;
									return a;
								}
							case s: {
									a=o;
									return a;
								}
							case o: {
									a=d;
									return a;
								}
							case n:
							default: {
									a=x;
									return a;
								}
						}
				case z :
					switch (a) {
							case d: {
									a=c;
									return a;
								}
							case t: {
									a=z;
									return a;
								}
							case q: {
									a=c;
									return a;
								}
							case z: {
									a=z;
									return a;
								}
							case x: {
									a=c;
									return a;
								}
							case s: {
									a=z;
									return a;
								}
							case o: {
									a=c;
									return a;
								}
							case n:
							default: {
									a=z;
									return a;
								}
						}
				case x :
					switch (a) {
							case d: {
									a=d;
									return a;
								}
							case t: {
									a=o;
									return a;
								}
							case q: {
									a=q;
									return a;
								}
							case z: {
									a=z;
									return a;
								}
							case x: {
									a=x;
									return a;
								}
							case s: {
									a=d;
									return a;
								}
							case o: {
									a=o;
									return a;
								}
							case n:
							default: {
									a=q;
									return a;
								}
						}
				case s :
					switch (a) {
							case d: {
									a=q;
									return a;
								}
							case t: {
									a=u;
									return a;
								}
							case q: {
									a=o;
									return a;
								}
							case z: {
									a=z;
									return a;
								}
							case x: {
									a=d;
									return a;
								}
							case s: {
									a=n;
									return a;
								}
							case o: {
									a=x;
									return a;
								}
							case n:
							default: {
									a=t;
									return a;
								}
						}
				case o :
					switch (a) {
							case d: {
									a=x;
									return a;
								}
							case t: {
									a=q;
									return a;
								}
							case q: {
									a=d;
									return a;
								}
							case z: {
									a=c;
									return a;
								}
							case x: {
									a=o;
									return a;
								}
							case s: {
									a=x;
									return a;
								}
							case o: {
									a=q;
									return a;
								}
							case n:
							default: {
									a=d;
									return a;
								}
						}
				case n :
				default :
					switch (a) {
							case d: {
									a=o;
									return a;
								}
							case t: {
									a=s;
									return a;
								}
							case q: {
									a=x;
									return a;
								}
							case z: {
									a=z;
									return a;
								}
							case x: {
									a=q;
									return a;
								}
							case s: {
									a=t;
									return a;
								}
							case o: {
									a=d;
									return a;
								}
							case n:
							default: {
									a=u;
									return a;
								}
						}
			}
}

const DigBCD & operator += (DigBCD & a,DigBCD b) {
	if (b==c) return a;
	else if (a==c) {
			a=b;
			return a;
		} else if (b==u) {
			a=Sig(a);//sig means siguiente It obtains the nxt value in decimal
			return a;
		} else if (a==u) {
			a=Sig(b);
			return a;
		} else if ((a==E)||(b==E)) {
			a=E ;
			return a;
		} else
		switch (b) {
				case d :
					switch (a) {
							case d: {
									a=q;
									return a;
								}
							case t: {
									a=z;
									return a;
								}
							case q: {
									a=x;
									return a;
								}
							case z: {
									a=s;
									return a;
								}
							case x: {
									a=o;
									return a;
								}
							case s: {
									a=n;
									return a;
								}
							case o: {
									a=c;
									return a;
								}
							case n:
							default: {
									a=u;
									return a;
								}
						}
				case t :
					switch (a) {
							case d: {
									a=z;
									return a;
								}
							case t: {
									a=x;
									return a;
								}
							case q: {
									a=s;
									return a;
								}
							case z: {
									a=o;
									return a;
								}
							case x: {
									a=n;
									return a;
								}
							case s: {
									a=c;
									return a;
								}
							case o: {
									a=u;
									return a;
								}
							case n:
							default: {
									a=d;
									return a;
								}
						}
				case q :
					switch (a) {
							case d: {
									a=x;
									return a;
								}
							case t: {
									a=s;
									return a;
								}
							case q: {
									a=o;
									return a;
								}
							case z: {
									a=n;
									return a;
								}
							case x: {
									a=c;
									return a;
								}
							case s: {
									a=u;
									return a;
								}
							case o: {
									a=d;
									return a;
								}
							case n:
							default: {
									a=t;
									return a;
								}
						}
				case z :
					switch (a) {
							case d: {
									a=s;
									return a;
								}
							case t: {
									a=o;
									return a;
								}
							case q: {
									a=n;
									return a;
								}
							case z: {
									a=c;
									return a;
								}
							case x: {
									a=u;
									return a;
								}
							case s: {
									a=d;
									return a;
								}
							case o: {
									a=t;
									return a;
								}
							case n:
							default: {
									a=q;
									return a;
								}
						}
				case x :
					switch (a) {
							case d: {
									a=o;
									return a;
								}
							case t: {
									a=n;
									return a;
								}
							case q: {
									a=c;
									return a;
								}
							case z: {
									a=u;
									return a;
								}
							case x: {
									a=d;
									return a;
								}
							case s: {
									a=t;
									return a;
								}
							case o: {
									a=q;
									return a;
								}
							case n:
							default: {
									a=z;
									return a;
								}
						}
				case s :
					switch (a) {
							case d: {
									a=n;
									return a;
								}
							case t: {
									a=c;
									return a;
								}
							case q: {
									a=u;
									return a;
								}
							case z: {
									a=d;
									return a;
								}
							case x: {
									a=t;
									return a;
								}
							case s: {
									a=q;
									return a;
								}
							case o: {
									a=z;
									return a;
								}
							case n:
							default: {
									a=x;
									return a;
								}
						}
				case o :
					switch (a) {
							case d: {
									a=c;
									return a;
								}
							case t: {
									a=u;
									return a;
								}
							case q: {
									a=d;
									return a;
								}
							case z: {
									a=t;
									return a;
								}
							case x: {
									a=q;
									return a;
								}
							case s: {
									a=z;
									return a;
								}
							case o: {
									a=x;
									return a;
								}
							case n:
							default: {
									a=s;
									return a;
								}
						}
				case n :
				default :
					switch (a) {
							case d: {
									a=u;
									return a;
								}
							case t: {
									a=d;
									return a;
								}
							case q: {
									a=t;
									return a;
								}
							case z: {
									a=q;
									return a;
								}
							case x: {
									a=z;
									return a;
								}
							case s: {
									a=x;
									return a;
								}
							case o: {
									a=s;
									return a;
								}
							case n:
							default: {
									a=o;
									return a;
								}
						}
			}
}

const DigBCD & operator -= (DigBCD & a,DigBCD b) { // Complemento a la Base 10 como complemento a 9 mas 1
	if (b==c) return a;
	else if (a==c) {
			a=Sig((n-b).first);
			return a;
		} else if (b==u) {
			a=Pre(a);
			return a;
		} else if (a==u) {
			a=Sig(Sig((n-b).first));
			return a;
		} else if ((a==E)||(b==E)) {
			a=E ;
			return a;
		} else  {
			a+=Sig((n-b).first) ;
			return a;
		}
}

const DigBCD  & operator /= (DigBCD & a,DigBCD b) {
	if (b==c) {
			a=E;
			return a;
		} else if (a==c) {
			a=c ;
			return a ;
		} else if (b==u) return a;
	else if (a==u) {
			a=c;
			return a;
		} else if (a<b) {
			a=c ;
			return a;
		} else if (a==b) {
			a=u ;
			return a;
		} else if ((a==E)||(b==E)) {
			a=E ;
			return a;
		} else
		switch (a) {
				case t : {
						a=u;
						return a;
					}
				case q :
					switch (b) {
							case d : {
									a=d;
									return a;
								}
							case t :
							default: {
									a=u;
									return a;
								}
						}
				case z :
					switch (b) {
							case d: {
									a=d;
									return a;
								}
							case t:
							case q:
							default: {
									a=u;
									return a;
								}
						}
				case x :
					switch (b) {
							case d: {
									a=t;
									return a;
								}
							case t: {
									a=d;
									return a;
								}
							case q:
							case z:
							default: {
									a=u;
									return a;
								}
						}
				case s :
					switch (b) {
							case d: {
									a=t;
									return a;
								}
							case t: {
									a=d;
									return a;
								}
							case q:
							case z:
							case x:
							default: {
									a=u;
									return a;
								}
						}
				case o :
					switch (b) {
							case d: {
									a=q;
									return a;
								}
							case t: {
									a=d;
									return a;
								}
							case q: {
									a=d;
									return a;
								}
							case z:
							case x:
							case s:
							default: {
									a=u;
									return a;
								}
						}
				case n  :
				default :
					switch (b) {
							case d: {
									a=q;
									return a;
								}
							case t: {
									a=t;
									return a;
								}
							case q: {
									a=d;
									return a;
								}
							case z:
							case x:
							case s:
							case o:
							default: {
									a=u;
									return a;
								}
						}
			}
}

const DigBCD  & operator %= (DigBCD & a,DigBCD b) {
	if (b==c) {
			a=E;
			return a;
		} else if (a==c) {
			a=c;
			return a ;
		} else if (b==u) {
			a=c;
			return a;
		} else if (a==u) {
			return a;
		} else if (a<b)  {
			return a;
		} else if (a==b) {
			a=c;
			return a;
		} else if ((a==E)||(b==E)) {
			a=E ;
			return a;
		} else
		switch (a) {
				case t : {
						a=u;
						return a;
					}
				case q :
					switch (b) {
							case d : {
									a=c;
									return a;
								}
							case t :
							default: {
									a=u;
									return a;
								}
						}
				case z :
					switch (b) {
							case d: {
									a=u;
									return a;
								}
							case t: {
									a=d;
									return a;
								}
							case q:
							default: {
									a=u;
									return a;
								}
						}
				case x :
					switch (b) {
							case d:
							case t: {
									a=c;
									return a;
								}
							case q: {
									a=d;
									return a;
								}
							case z:
							default: {
									a=u;
									return a;
								}
						}
				case s :
					switch (b) {
							case q: {
									a=t;
									return a;
								}
							case z: {
									a=d;
									return a;
								}
							case d:
							case t:
							case x:
							default: {
									a=u;
									return a;
								}
						}
				case o :
					switch (b) {
							case d:
							case q: {
									a=c;
									return a;
								}
							case z: {
									a=t;
									return a;
								}
							case t:
							case x: {
									a=d;
									return a;
								}
							case s:
							default: {
									a=u;
									return a;
								}
						}
				case n  :
				default :
					switch (b) {
							case t: {
									a=c;
									return a;
								}
							case z: {
									a=q;
									return a;
								}
							case x: {
									a=t;
									return a;
								}
							case s: {
									a=d;
									return a;
								}
							case d:
							case q:
							case o:
							default: {
									a=u;
									return a;
								}
						}
			}
}

N2DigsBCD Dig2CDig(DigBCD arg) {
	N2DigsBCD ret(c,arg);
	return ret;
}

istream & operator >> (istream & is,DigBCD & a) {
	char chin;
	is >> chin;
	uchint ret=(chin-'0')%10;
	a = Nat2Dig(ret);
	return is;
}

ostream & operator << (ostream & os,DigBCD a) {
	os << char(Dig2Char(a)+'0');//Here we plus two value char(hexadecimal)
	return os;//0 value is #9648 and `i #96
}

N2DigsBCD operator * (DigBCD a,DigBCD b) {
	N2DigsBCD ret(c,c);
	uchint tempa = Dig2Int(a);
	tempa *=  Dig2Int(b);
	ret.first = (Int2Dig(tempa%10));
	ret.second = (Int2Dig((tempa/10)%10));
	return ret;
}

N2DigsBCD operator + (DigBCD a,DigBCD b) {
	N2DigsBCD ret(c,c);
	uchint tempa = Dig2Int(a);
	tempa +=  Dig2Int(b);
	ret.first = (Int2Dig(tempa%10));
	ret.second = (Int2Dig((tempa/10)%10));
	return ret;
}

N2DigsBCD operator - (DigBCD a,DigBCD b) {
	N2DigsBCD ret(c,c);
	uchint tempa = Dig2Int(a);
	tempa -=  Dig2Int(b);
	if (a<b) {
			ret.first  = E;
			ret.second = E;		//return two E when the result is negative
		} else {
			ret.first  =(Int2Dig(tempa%10));
			ret.second =(Int2Dig((tempa/10)%10));
		}
	return ret;
}

DigBCD operator / (DigBCD a,DigBCD b) {
	DigBCD ret=c;
	uchint tempa = Dig2Int(a);
	if ((b==c) || (a==E) || (b==E))
		return E;
	else if (a<b)
		return c;
	else if (a==b)
		return u;
	else {
			tempa /= Dig2Int(b);
			ret = Int2Dig(tempa%10);
			return ret;
		}
}

DigBCD operator % (DigBCD a,DigBCD b) {
	DigBCD ret=c;
	uchint tempa = Dig2Int(a);
	if ((b==c) || (a==E) || (b==E))
		return E;
	else if (a<b)
		return a;
	else if (a==b)
		return c;
	else {
			tempa %= Dig2Int(b);
			ret = Int2Dig(tempa%10);
			return ret;
		}
}

DigBCD  operator ! (DigBCD a) {
	switch (a) {
			case c:
				return n;
			case u:
				return o;
			case d:
				return s;
			case t:
				return x;
			case q:
				return z;
			case z:
				return q;
			case x:
				return t;
			case s:
				return d;
			case o:
				return u;
			case n:
				return c;
			case E:
			default:
				return E;
		}
}

DigBCD  operator - (DigBCD a) {
	switch (a) {
		case c:  return c;
		case u:  return n;
		case d:  return o;
		case t:  return s;
		case q:  return x;
		case z:  return z;
		case x:  return q;
		case s:  return t;
		case o:  return d;
		case n:  return u;
		case E:
		default: return E;
	}
}

const DigBCD & mC9 (DigBCD & a) { // Complemento a nueve
	switch (a) {
			case c:
				return (a=n);
			case u:
				return (a=o);
			case d:
				return (a=s);
			case t:
				return (a=x);
			case q:
				return (a=z);
			case z:
				return (a=q);
			case x:
				return (a=t);
			case s:
				return (a=d);
			case o:
				return (a=u);
			case n:
				return (a=c);
			case E:
			default:
				return (a=E);
		}
}// Complemento a nueve

const DigBCD & mC10 (DigBCD & a) { // Complemento a la Base 10
	switch (a) {
			case c:  {
					a=c;
					return a;
				}
			case u:  {
					a=n;
					return a;
				}
			case d:  {
					a=o;
					return a;
				}
			case t:  {
					a=s;
					return a;
				}
			case q:  {
					a=x;
					return a;
				}
			case z:  {
					a=z;
					return a;
				}
			case x:  {
					a=q;
					return a;
				}
			case s:  {
					a=t;
					return a;
				}
			case o:  {
					a=d;
					return a;
				}
			case n:  {
					a=u;
					return a;
				}
			case E:
			default: {
					a=E;
					return a;
				}
		}
}// Complemento a la Base 10

N2DigsBCD DivRem (DigBCD a,DigBCD b) {
	N2DigsBCD ret(c,c);
	uchint tempa = Dig2Int(a);
	if ((b==c) || (a==E) || (b==E))
		return N2DigsBCD(E,E);
	else if (a<b) {
			ret = N2DigsBCD(c,a);
			return ret;
		} else {
			tempa /= Dig2Int(b);
			ret.second=Int2Dig(tempa%10);
			tempa = Dig2Int(a);
			tempa %= Dig2Int(b);
			ret.first=Int2Dig(tempa%10);
			return ret;
		}
}

char Dig2Char(DigBCD a) {
	switch (a) {
			case c:
				return '0';
			case u:
				return '1';
			case d:
				return '2';
			case t:
				return '3';
			case q:
				return '4';
			case z:
				return '5';
			case x:
				return '6';
			case s:
				return '7';
			case o:
				return '8';
			case n:
				return '9';
			case E:
			default:
				return 'E';
		}
}

DigBCD Char2Dig(char a) {
	switch (a) {
			case '0':
				return c;
			case '1':
				return u;
			case '2':
				return d;
			case '3':
				return t;
			case '4':
				return q;
			case '5':
				return z;
			case '6':
				return x;
			case '7':
				return s;
			case '8':
				return o;
			case '9':
				return n;
			case 'E':
			default:
				return E;
		}
}

uchint Dig2Nat(DigBCD a) {
	switch (a) {
			case c:
				return 0;
			case u:
				return 1;
			case d:
				return 2;
			case t:
				return 3;
			case q:
				return 4;
			case z:
				return 5;
			case x:
				return 6;
			case s:
				return 7;
			case o:
				return 8;
			case n:
				return 9;
			case E:
			default:
				return 255;
		}
}

DigBCD Nat2Dig(uchint a) {
	switch (a) {
			case 0:
				return c;
			case 1:
				return u;
			case 2:
				return d;
			case 3:
				return t;
			case 4:
				return q;
			case 5:
				return z;
			case 6:
				return x;
			case 7:
				return s;
			case 8:
				return o;
			case 9:
				return n;
			default:
				return E;
		}
}

int    Dig2Int(DigBCD a) {
	switch (a) {
			case c:
				return 0;
			case u:
				return 1;
			case d:
				return 2;
			case t:
				return 3;
			case q:
				return 4;
			case z:
				return 5;
			case x:
				return 6;
			case s:
				return 7;
			case o:
				return 8;
			case n:
				return 9;
			case E:
				return 255;
			default:
				return -256;
		}
}

DigBCD Int2Dig(int a) {
	switch (a) {
			case 0:
				return c;
			case 1:
				return u;
			case 2:
				return d;
			case 3:
				return t;
			case 4:
				return q;
			case 5:
				return z;
			case 6:
				return x;
			case 7:
				return s;
			case 8:
				return o;
			case 9:
				return n;
			default:
				return E;
		}
}

bool operator <= (DigBCD a,DigBCD b) {
	switch (a) {
			case c:
				switch (b) {
						case  c:
						case  u:
						case  d:
						case  t:
						case  q:
						case  z:
						case  x:
						case  s:
						case  o:
						case  n:
						case  E:
						default:
							return true;
					}
			case u:
				switch (b) {
						case  c:
							return false;
						case  u:
						case  d:
						case  t:
						case  q:
						case  z:
						case  x:
						case  s:
						case  o:
						case  n:
						case  E:
						default:
							return true;
					}
			case d:
				switch (b) {
						case  c:
						case  u:
							return false;
						case  d:
						case  t:
						case  q:
						case  z:
						case  x:
						case  s:
						case  o:
						case  n:
						case  E:
						default:
							return true;
					}
			case t:
				switch (b) {
						case  c:
						case  u:
						case  d:
							return false;
						case  t:
						case  q:
						case  z:
						case  x:
						case  s:
						case  o:
						case  n:
						case  E:
						default:
							return true;
					}
			case q:
				switch (b) {
						case  c:
						case  u:
						case  d:
						case  t:
							return false;
						case  q:
						case  z:
						case  x:
						case  s:
						case  o:
						case  n:
						case  E:
						default:
							return true;
					}
			case z:
				switch (b) {
						case  c:
						case  u:
						case  d:
						case  t:
						case  q:
							return false;
						case  z:
						case  x:
						case  s:
						case  o:
						case  n:
						case  E:
						default:
							return true;
					}
			case x:
				switch (b) {
						case  c:
						case  u:
						case  d:
						case  t:
						case  q:
						case  z:
							return false;
						case  x:
						case  s:
						case  o:
						case  n:
						case  E:
						default:
							return true;
					}
			case s:
				switch (b) {
						case  c:
						case  u:
						case  d:
						case  t:
						case  q:
						case  z:
						case  x:
							return false;
						case  s:
						case  o:
						case  n:
						case  E:
						default:
							return true;
					}
			case o:
				switch (b) {
						case  c:
						case  u:
						case  d:
						case  t:
						case  q:
						case  z:
						case  x:
						case  s:
							return false;
						case  o:
						case  n:
						case  E:
						default:
							return true;
					}
			case n:
				switch (b) {
						case  c:
						case  u:
						case  d:
						case  t:
						case  q:
						case  z:
						case  x:
						case  s:
						case  o:
							return false;
						case  n:
						case  E:
						default:
							return true;
					}
			case E:
			default:
				switch (b) {
						case  c:
						case  u:
						case  d:
						case  t:
						case  q:
						case  z:
						case  x:
						case  s:
						case  o:
						case  n:
							return false;
						case  E:
						default:
							return true;
					}
		}
}

bool operator >= (DigBCD a,DigBCD b) {
	switch (a) {
			case c:
				switch (b) {
						case  c:
							return true;
						case  u:
						case  d:
						case  t:
						case  q:
						case  z:
						case  x:
						case  s:
						case  o:
						case  n:
						case  E:
						default:
							return false;
					}
			case u:
				switch (b) {
						case  c:
						case  u:
							return true;
						case  d:
						case  t:
						case  q:
						case  z:
						case  x:
						case  s:
						case  o:
						case  n:
						case  E:
						default:
							return false;
					}
			case d:
				switch (b) {
						case  c:
						case  u:
						case  d:
							return true;
						case  t:
						case  q:
						case  z:
						case  x:
						case  s:
						case  o:
						case  n:
						case  E:
						default:
							return false;
					}
			case t:
				switch (b) {
						case  c:
						case  u:
						case  d:
						case  t:
							return true;
						case  q:
						case  z:
						case  x:
						case  s:
						case  o:
						case  n:
						case  E:
						default:
							return false;
					}
			case q:
				switch (b) {
						case  c:
						case  u:
						case  d:
						case  t:
						case  q:
							return true;
						case  z:
						case  x:
						case  s:
						case  o:
						case  n:
						case  E:
						default:
							return false;
					}
			case z:
				switch (b) {
						case  c:
						case  u:
						case  d:
						case  t:
						case  q:
						case  z:
							return true;
						case  x:
						case  s:
						case  o:
						case  n:
						case  E:
						default:
							return false;
					}
			case x:
				switch (b) {
						case  c:
						case  u:
						case  d:
						case  t:
						case  q:
						case  z:
						case  x:
							return true;
						case  s:
						case  o:
						case  n:
						case  E:
						default:
							return false;
					}
			case s:
				switch (b) {
						case  c:
						case  u:
						case  d:
						case  t:
						case  q:
						case  z:
						case  x:
						case  s:
							return true;
						case  o:
						case  n:
						case  E:
						default:
							return false;
					}
			case o:
				switch (b) {
						case  c:
						case  u:
						case  d:
						case  t:
						case  q:
						case  z:
						case  x:
						case  s:
						case  o:
							return true;
						case  n:
						case  E:
						default:
							return false;
					}
			case n:
				switch (b) {
						case  c:
						case  u:
						case  d:
						case  t:
						case  q:
						case  z:
						case  x:
						case  s:
						case  o:
						case  n:
							return true;
						case  E:
						default:
							return false;
					}
			case E:
			default:
				switch (b) {
						case  c:
						case  u:
						case  d:
						case  t:
						case  q:
						case  z:
						case  x:
						case  s:
						case  o:
						case  n:
						case  E:
						default:
							return true;
					}
		}
}

bool operator <  (DigBCD a,DigBCD b) {
	switch (a) {
			case c:
				switch (b) {
						case  c:
							return false;
						case  u:
						case  d:
						case  t:
						case  q:
						case  z:
						case  x:
						case  s:
						case  o:
						case  n:
						case  E:
						default:
							return true;
					}
			case u:
				switch (b) {
						case  c:
						case  u:
							return false;
						case  d:
						case  t:
						case  q:
						case  z:
						case  x:
						case  s:
						case  o:
						case  n:
						case  E:
						default:
							return true;
					}
			case d:
				switch (b) {
						case  c:
						case  u:
						case  d:
							return false;
						case  t:
						case  q:
						case  z:
						case  x:
						case  s:
						case  o:
						case  n:
						case  E:
						default:
							return true;
					}
			case t:
				switch (b) {
						case  c:
						case  u:
						case  d:
						case  t:
							return false;
						case  q:
						case  z:
						case  x:
						case  s:
						case  o:
						case  n:
						case  E:
						default:
							return true;
					}
			case q:
				switch (b) {
						case  c:
						case  u:
						case  d:
						case  t:
						case  q:
							return false;
						case  z:
						case  x:
						case  s:
						case  o:
						case  n:
						case  E:
						default:
							return true;
					}
			case z:
				switch (b) {
						case  c:
						case  u:
						case  d:
						case  t:
						case  q:
						case  z:
							return false;
						case  x:
						case  s:
						case  o:
						case  n:
						case  E:
						default:
							return true;
					}
			case x:
				switch (b) {
						case  c:
						case  u:
						case  d:
						case  t:
						case  q:
						case  z:
						case  x:
							return false;
						case  s:
						case  o:
						case  n:
						case  E:
						default:
							return true;
					}
			case s:
				switch (b) {
						case  c:
						case  u:
						case  d:
						case  t:
						case  q:
						case  z:
						case  x:
						case  s:
							return false;
						case  o:
						case  n:
						case  E:
						default:
							return true;
					}
			case o:
				switch (b) {
						case  c:
						case  u:
						case  d:
						case  t:
						case  q:
						case  z:
						case  x:
						case  s:
						case  o:
							return false;
						case  n:
						case  E:
						default:
							return true;
					}
			case n:
				switch (b) {
						case  c:
						case  u:
						case  d:
						case  t:
						case  q:
						case  z:
						case  x:
						case  s:
						case  o:
						case  n:
							return false;
						case  E:
						default:
							return true;
					}
			case E:
			default:
				switch (b) {
						case  c:
						case  u:
						case  d:
						case  t:
						case  q:
						case  z:
						case  x:
						case  s:
						case  o:
						case  n:
						case  E:
						default:
							return false;
					}
		}
}

bool operator >  (DigBCD a,DigBCD b) {
	switch (a) {
			case c:
				switch (b) {
						case  c:
						case  u:
						case  d:
						case  t:
						case  q:
						case  z:
						case  x:
						case  s:
						case  o:
						case  n:
						case  E:
						default:
							return false;
					}
			case u:
				switch (b) {
						case  c:
							return true;
						case  u:
						case  d:
						case  t:
						case  q:
						case  z:
						case  x:
						case  s:
						case  o:
						case  n:
						case  E:
						default:
							return false;
					}
			case d:
				switch (b) {
						case  c:
						case  u:
							return true;
						case  d:
						case  t:
						case  q:
						case  z:
						case  x:
						case  s:
						case  o:
						case  n:
						case  E:
						default:
							return false;
					}
			case t:
				switch (b) {
						case  c:
						case  u:
						case  d:
							return true;
						case  t:
						case  q:
						case  z:
						case  x:
						case  s:
						case  o:
						case  n:
						case  E:
						default:
							return false;
					}
			case q:
				switch (b) {
						case  c:
						case  u:
						case  d:
						case  t:
							return true;
						case  q:
						case  z:
						case  x:
						case  s:
						case  o:
						case  n:
						case  E:
						default:
							return false;
					}
			case z:
				switch (b) {
						case  c:
						case  u:
						case  d:
						case  t:
						case  q:
							return true;
						case  z:
						case  x:
						case  s:
						case  o:
						case  n:
						case  E:
						default:
							return false;
					}
			case x:
				switch (b) {
						case  c:
						case  u:
						case  d:
						case  t:
						case  q:
						case  z:
							return true;
						case  x:
						case  s:
						case  o:
						case  n:
						case  E:
						default:
							return false;
					}
			case s:
				switch (b) {
						case  c:
						case  u:
						case  d:
						case  t:
						case  q:
						case  z:
						case  x:
							return true;
						case  s:
						case  o:
						case  n:
						case  E:
						default:
							return false;
					}
			case o:
				switch (b) {
						case  c:
						case  u:
						case  d:
						case  t:
						case  q:
						case  z:
						case  x:
						case  s:
							return true;
						case  o:
						case  n:
						case  E:
						default:
							return false;
					}
			case n:
				switch (b) {
						case  c:
						case  u:
						case  d:
						case  t:
						case  q:
						case  z:
						case  x:
						case  s:
						case  o:
							return true;
						case  n:
						case  E:
						default:
							return false;
					}
			case E:
			default:
				switch (b) {
						case  c:
						case  u:
						case  d:
						case  t:
						case  q:
						case  z:
						case  x:
						case  s:
						case  o:
						case  n:
							return true;
						case  E:
						default:
							return false;
					}
		}
}


const DigBCD Sig(const DigBCD & arg) {
	switch (arg) {
			case c:
				return u;
			case u:
				return d;
			case d:
				return t;
			case t:
				return q;
			case q:
				return z;
			case z:
				return x;
			case x:
				return s;
			case s:
				return o;
			case o:
				return n;
			case n:
				return c;
			case E:
			default:
				return E;
		}
}

const DigBCD Pre(const DigBCD & arg) {
	switch (arg) {
			case c:
				return n;
			case u:
				return c;
			case d:
				return u;
			case t:
				return d;
			case q:
				return t;
			case z:
				return q;
			case x:
				return z;
			case s:
				return x;
			case o:
				return s;
			case n:
				return o;
			case E:
			default:
				return E;
		}
}

const DigBCD & operator ++ (DigBCD & arg) {
	arg=Sig(arg);
	return arg;
}

DigBCD operator ++ (DigBCD & arg,int) {
	DigBCD argc;
	arg=Sig(arg);
	argc=arg;
	return argc;
}

const DigBCD& operator -- (DigBCD & arg) {
	arg=Pre(arg);
	return arg;
}

DigBCD operator -- (DigBCD & arg,int) {
	DigBCD argc;
	arg=Pre(arg);
	argc=arg;
	return argc;
}
