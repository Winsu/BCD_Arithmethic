#include "SParBCD.hpp"

using namespace std;

/* si el caracter es '-' o menor, el numero sera negativo,
 * si es  mayor sera positivo 								*/
sign_e Char2Sign(char ch) {
	if (ch<='-') return m;
	else return p;
}

sign_e Int2Sign (int nu) {
	if (nu <= 0) return m;
	else return p;
}

sign_e Nat2Sign (uchint nu) {
	if (nu==0) return m;
	else return p;
}

SParBCD::SParBCD() {
	second = c;
	first  = c;
	signo = p;
}

SParBCD::SParBCD(sign_e mp,DigBCD decs,DigBCD uds) {
	second = decs;
	first  = uds;
	signo = mp;
}

SParBCD::SParBCD(DigBCD decs,DigBCD uds) {
	second = decs;
	first  = uds;
	signo = p;
}

SParBCD::SParBCD(uchint decs,uchint uds) {
	second = (Nat2Dig(decs));
	first  = (Nat2Dig(uds));
	signo = p;
}

SParBCD::SParBCD(uchint csigno, uchint decs, uchint uds) {
	second = (Nat2Dig(decs));
	first  = (Nat2Dig(uds));
	signo = (Nat2Sign(csigno));
}

SParBCD::SParBCD(char csigno,char decs,char uds) {
	second = (Char2Dig(decs));
	first  = (Char2Dig(uds));
	signo = (Char2Sign(csigno));
}

SParBCD::SParBCD(char decs,char uds) {
	second = (Char2Dig(decs));
	first  = (Char2Dig(uds));
	signo = p;
}

SParBCD::SParBCD(int decs,int uds) {
	second = (Int2Dig(decs));
	first  = (Int2Dig(uds));
	signo = p;
}

SParBCD::SParBCD(int isigno, int decs, int uds) {
	second = (Int2Dig(decs));
	first  = (Int2Dig(uds));
	signo = (Int2Sign(isigno));
}

SParBCD::SParBCD(const SParBCD & arg) {
	second = (arg.second);
	first  = (arg.first);
	signo = arg.signo;
}

SParBCD::SParBCD(SParBCD & arg) {
	second = (arg.second);
	first  = (arg.first);
	signo = arg.signo;
}

SParBCD::SParBCD(const ParBCD & arg) {
	second = (arg.g_second());
	first  = (arg.g_first());
	signo = p;
}

SParBCD::SParBCD(ParBCD & arg) {
	second = (arg.g_second());
	first  = (arg.g_first());
	signo = p;
}

SParBCD::SParBCD(const N2DigsBCD & arg) {
	second = (arg.second);
	first  = (arg.first);
	signo = p;
}

SParBCD::SParBCD(N2DigsBCD & arg) {
	second = (arg.second);
	first  = (arg.first);
	signo = p;
}

SParBCD::SParBCD(const string & arg) {
	second = Char2Dig(arg.at(1));
	first  = Char2Dig(arg.at(0));
	signo = Char2Sign(arg.at(2));
}

SParBCD::operator ParBCD() const {
		ParBCD ret;
		if (signo==p) ret=ParBCD(second,first);
		else {
				ret=ParBCD(!second,!first);
				++ret;
			}
		return ret;
	}

SParBCD SParBCD::abs() const {
		SParBCD ret;
		if (signo == p) {
				ret.first  = first;
				ret.second = second;
			} else {
				ret.first  = !first;
				ret.second = !second;
				++ret;
				ret.signo = p;
			}
		return ret;
	}

const SParBCD & SParBCD::operator = (const SParBCD & arg) {
	first=arg.first;
	second=arg.second;
	signo = arg.signo;
	return (*this);
}

SParBCD & SParBCD::operator = (SParBCD & arg) {
	first  = arg.first;
	second = arg.second;
	signo  = arg.signo;
	return (*this);
}

bool SParBCD::operator == (SParBCD arg) const {
		if ((second==arg.second)&&(first==arg.first)&&(signo==arg.signo)) return true;
		else return false;
	}

bool SParBCD::operator != (SParBCD arg) const {
		if ((second!=arg.second)||(first!=arg.first)||(signo!=arg.signo)) return true;
		else return false;
	}

bool SParBCD::operator <= (SParBCD arg) const {
		if ((signo==m)&&(arg.signo==p)) return true;
		else if ((signo==p)&&(arg.signo==m)) return false;
		else if (signo==p) {
				if (second < arg.second) return true;
				else if (second > arg.second) return false;
				else {
						if (first <=  arg.first) return true;
						else return false;
					}
			} else {
				if (second > arg.second) return true;
				else if (second < arg.second) return false;
				else {
						if (first >=  arg.first) return true;
						else return false;
					}
			}
	}

bool SParBCD::operator >= (SParBCD arg) const {
		if ((signo==m)&&(arg.signo==p)) return false;
		else if ((signo==p)&&(arg.signo==m)) return true;
		else if (signo==m) {
				if (second < arg.second) return true;
				else if (second > arg.second) return false;
				else {
						if (first <=  arg.first) return true;
						else return false;
					}
			} else {
				if (second < arg.second) return true;
				else if (second > arg.second) return false;
				else {
						if (first <=  arg.first) return true;
						else return false;
					}
			}
	}

bool SParBCD::operator <  (SParBCD arg) const {
		if ((signo==m)&&(arg.signo==p)) return true;
		else if ((signo==p)&&(arg.signo==m)) return false;
		else if (signo==p) {
				if (second < arg.second) return true;
				else return false;
			} else {
				if (second > arg.second) return true;
				else return false;
			}
	}

bool SParBCD::operator >  (SParBCD arg) const {
		if ((signo==m)&&(arg.signo==p)) return false;
		else if ((signo==p)&&(arg.signo==m)) return true;
		else if (signo==p) {
				if (second > arg.second) return true;
				else return false;
			} else {
				if (second < arg.second) return true;
				else return false;
			}
	}

SParBCD SParBCD::operator + (const SParBCD & arg) const {
		SParBCD carry=ParBCD(first+arg.first);
		SParBCD carry2=ParBCD(second+arg.second);
		SParBCD carry3=ParBCD(carry.second+carry2.first);
		carry.second =  carry3.first;
		carry3 = ParBCD(carry3.second + carry2.second);
		if (signo==arg.signo)
			carry.signo = signo;
		else
			carry.signo = ((carry3 != SParBCD(p,c,c))?m:p);
		return carry;
	}

SParBCD SParBCD::operator - (const SParBCD & arg) const {
		SParBCD cpy(-arg);
		SParBCD carry=ParBCD(first+cpy.first);
		SParBCD carry2=ParBCD(second+cpy.second);
		SParBCD carry3=ParBCD(carry.second+carry2.first);
		carry.second =  carry3.first;
		carry3 = ParBCD(carry3.second + carry2.second);
		if (signo==cpy.signo)
			carry.signo = signo;
		else
			carry.signo = ((carry3 != SParBCD(p,c,c))?m:p);
		return carry;
	}

SParBCD SParBCD::operator * (const SParBCD & arg) const {
		SParBCD ret(abs());
		SParBCD cpy(arg.abs());
		uchint retuds = Dig2Nat(ret.first);
		uchint retdecs = Dig2Nat(ret.second);
		uchint arguds = Dig2Nat(cpy.first);
		uchint argdecs = Dig2Nat(cpy.second);
		if (signo == arg.signo) ret.signo=p;
		else ret.signo=m;
		uchint  resultadobajo = retuds * arguds;
		uchint  resultadoalto = retuds*argdecs + retdecs*arguds;
		SParBCD retbajo((resultadobajo/10)%10,resultadobajo%10);
		SParBCD retalto((resultadoalto/10)%10,resultadoalto%10);
		ret.first = Nat2Dig(resultadobajo%10);
		ret.first = Nat2Dig(((resultadobajo/10)+resultadoalto)%10);
		if (ret.signo==m) {
				ret.second = !(ret.second);
				ret.first  = !(ret.first) ;
				++ret;
				ret.signo  =   m          ;
			}
		return ret;
	}

SParBCD SParBCD::operator / (const SParBCD & arg) const {
		SParBCD ret(abs());
		SParBCD cpy(arg.abs());
		sign_e retsign = ((arg.signo==signo)?(p):(m));
		uchint retuds = Dig2Nat(ret.first);
		uchint retdec = Dig2Nat(ret.second);
		uchint rettot = retdec+(retuds*10);
		uchint arguds = Dig2Nat(cpy.first);
		uchint argdec = Dig2Nat(cpy.second);
		uchint argtot = argdec+(arguds*10);

		if ((cpy.second == c)&&(cpy.first == c)) {
				ret.second = E;
				ret.first = E;
				ret.signo = retsign;
				return ret;
			} else {
				rettot = rettot/argtot;
				retuds = rettot % 10;
				retdec = (rettot/10)%10;
				ret.signo = retsign;
				ret.second = Nat2Dig(retdec);
				ret.first = Nat2Dig(retuds);
				if (ret.signo==m) { // Complementamos a 100 si el signo es negativo
						ret.second = !(ret.second);
						ret.first  = !(ret.first) ;
						++ret;
						ret.signo  =   m          ;
					}
				return ret;
			}
	}

SParBCD SParBCD::operator % (const SParBCD & arg) const {
		SParBCD ret(abs());
		SParBCD cpy(arg.abs());
		sign_e retsign = ret.signo;
		uchint retuds = Dig2Nat(ret.first);
		uchint retdec = Dig2Nat(ret.second);
		uchint rettot = retdec+(retuds*10);
		uchint arguds = Dig2Nat(cpy.first);
		uchint argdec = Dig2Nat(cpy.second);
		uchint argtot = argdec+(arguds*10);

		if ((cpy.second == c)&&(cpy.first == c)) {
				ret.second = E;
				ret.first = E;
				ret.signo = retsign;
				return ret;
			} else {
				rettot %= argtot;
				retuds  = rettot % 10;
				retdec  = (rettot/10)%10;
				ret.signo = retsign;
				ret.second = Nat2Dig(retdec);
				ret.first = Nat2Dig(retuds);
				if (ret.signo==m) { // Complementamos a 100 si el signo es negativo
						ret.second = !(ret.second);
						ret.first  = !(ret.first) ;
						++ret;
						ret.signo  =   m          ;
					}
				return ret;
			}
	}

const SParBCD & SParBCD::operator += (const SParBCD & arg) {
	N2DigsBCD carry (first+arg.first);
	N2DigsBCD carry2 =  N2DigsBCD (second+arg.second);
	N2DigsBCD carry3 =  N2DigsBCD (carry.second+carry2.first);
	second = carry3.first;
	carry3 = N2DigsBCD (carry3.second + carry2.second);
	first = carry.first;
	if (signo!=arg.signo)
		signo = ((carry3 != SParBCD(p,c,c))?m:p);
	return (*this);
}

const SParBCD & SParBCD::operator -= (const SParBCD & arg) {
	SParBCD   cpy (-arg);
	N2DigsBCD carry (first+cpy.first);
	N2DigsBCD carry2 =  N2DigsBCD (second+cpy.second);
	N2DigsBCD carry3 =  N2DigsBCD (carry.second+carry2.first);
	second = carry3.first;
	carry3 = N2DigsBCD (carry3.second + carry2.second);
	first = carry.first;
	if (signo!=cpy.signo)
		signo = ((carry3 != SParBCD(p,c,c))?m:p);
	return (*this);
}

const SParBCD & SParBCD::operator *= (const SParBCD & arg) {
	sign_e  scpy = signo;
	(*this)=abs();
	SParBCD cpy(arg.abs());
	uchint retud = Dig2Nat(first);
	uchint retde = Dig2Nat(second);
	uchint retto = (retud+10*retde);
	uchint argud = Dig2Nat(cpy.first);
	uchint argde = Dig2Nat(cpy.second);
	uchint argto = (argud+10*argde);

	if (arg.signo==scpy) signo=p;
	else signo=m;

	// 100*(argde*retde)+10*((argde*retud)+(argud*retde))+(argud+retud);
	second = Nat2Dig((((argde*retud)+(argud*retde))+((argud+retud)/10))%10);
	first = Nat2Dig((argud+retud)%10);

	signo = scpy;
	if (signo==m) {
			first  = !first;
			second = !second;
			++(*this);
			signo = m;
		}
	return (*this);
}

const SParBCD & SParBCD::operator /= (const SParBCD & arg) {
	SParBCD ret(abs());
	SParBCD cpy(arg.abs());
	signo = ((arg.signo==signo)?(p):(m));
	uchint retuds = Dig2Nat(ret.first);
	uchint retdec = Dig2Nat(ret.second);
	uchint rettot = retdec+(retuds*10);
	uchint arguds = Dig2Nat(cpy.first);
	uchint argdec = Dig2Nat(cpy.second);
	uchint argtot = argdec+(arguds*10);

	if ((second == c)&&(first == c)) {
			second = E;
			first = E;
			return (*this);
		} else {
			rettot /= argtot;
			retuds = rettot % 10;
			retdec = (rettot/10)%10;
			second = Nat2Dig(retdec);
			first = Nat2Dig(retuds);
			if (signo==m) { // Complementamos a 100 si el signo es negativo
					second = !second;
					first  = !first ;
					++(*this)       ;
					signo  =   m    ;
				}
			return (*this);
		}
}

const SParBCD & SParBCD::operator %= (const SParBCD & arg) {
	SParBCD ret(abs());
	SParBCD cpy(arg.abs());
	sign_e retsign = ret.signo;
	uchint retuds = Dig2Nat(ret.first);
	uchint retdec = Dig2Nat(ret.second);
	uchint rettot = retdec+(retuds*10);
	uchint arguds = Dig2Nat(cpy.first);
	uchint argdec = Dig2Nat(cpy.second);
	uchint argtot = argdec+(arguds*10);

	if ((second == c)&&(first == c)) {
			second = E;
			first = E;
			signo = retsign;
			return (*this);
		} else {
			rettot %= argtot;
			retuds = (rettot % 10);
			retdec = ((rettot/10)%10);
			signo = retsign;
			second = Nat2Dig(retdec);
			first = Nat2Dig(retuds);
			if (signo==m) { // Complementamos a 100 si el signo es negativo
					second =  !second ;
					first  =   !first ;
					++(*this)		  ;
					signo  =   m      ;
				}
			return (*this);
		}
}

SParBCD::operator ssint () const { // nos da el valor en formato entero del ordenador
		if (signo==p) return (Dig2Int(first)+(Dig2Int(second)*10));
		else return (-((Dig2Int(!first)+(Dig2Int(!second)*10))+1));
	} // nos da el valor en formato entero del ordenador

SParBCD::operator usint () const { // nos da el valor en formato entero del ordenador
		if (signo==p) return (Dig2Int(first)+(Dig2Int(second)*10));
		else 	return ((Dig2Int(!first)+(Dig2Int(!second)*10))+1);
	} // nos da el valor en formato entero del ordenador


SParBCD SParBCD::operator -() const { // menos unario (cambio de signo, en Complemento BCD);
		SParBCD cpy(*this);
		cpy.first = !first;
		cpy.second = !second;
		++cpy;
		cpy.signo = ((signo==m)?p:m);
		return cpy;
	}// menos unario (cambio de signo, en Complemento BCD);

SParBCD SParBCD::operator ! () const { // Complemento BCD menos 1
		SParBCD cpy(*this);
		cpy.first = !first;
		cpy.second = !second;
		cpy.signo = ((signo==m)?p:m);
		return cpy;
	} // Complemento BCD menos 1

const SParBCD & SParBCD::mC10  () { // auto modificación menos unario (cambio de signo, en Complemento BCD);
	first = !first;
	second = !second;
	++(*this);
	signo = ((signo==m)?p:m);
	return (*this);
} // auto modificación menos unario (cambio de signo, en Complemento BCD);

const SParBCD & SParBCD::mC9   () { // auto modificación Complemento BCD menos 1
	first = !(first);
	second = !(second);
	signo = ((signo==m)?p:m);
	return (*this);
} // auto modificación Complemento BCD menos 1

const SParBCD & SParBCD::operator ++ () {
	switch (signo) {
			case p : {
					if (first < n) {
							++first;
							return (*this);
						} else if (first == n) {
							first = c;
							++second;
							return (*this);
						} else {
							first = E;
							second = E;
							return (*this);
						}
				}
			case m : {
					if (ParBCD(second,first) < ParBCD(n,n)) {
							if (first < n) {
									++first;
									return (*this);
								} else if (first == n) {
									first = c;
									++second;
									return (*this);
								} else {
									first = E;
									second = E;
									return (*this);
								}
						} else {
							first=c;
							second=c;
							signo=p;
							return (*this);
						}
				}
		}
}

SParBCD SParBCD::operator ++ (int) {
	SParBCD thism(*this);
	switch (thism.signo) {
			case p : {
					if (thism.first < n) {
							thism.first=(thism.first)++;
							(*this)=thism;
							return thism;
						} else if (thism.first == n) {
							thism.first = c;
							thism.second=(thism.second)++;
							(*this)=thism;
							return thism;
						} else {
							thism.first = E;
							thism.second = E;
							(*this)=thism;
							return thism;
						}
				}
			case m : {
					if (ParBCD(thism.second,thism.first) < ParBCD(n,n)) {
							if (thism.first < n) {
									thism.first=(thism.first)++;
									(*this)=thism;
									return thism;
								} else if (thism.first == n) {
									thism.first = c;
									thism.second=(thism.second)++;
									(*this)=thism;
									return thism;
								} else {
									thism.first = E;
									thism.second = E;
									(*this)=thism;
									return thism;
								}
						} else {
							thism.first=c;
							thism.second=c;
							thism.signo=p;
							(*this)=thism;
							return thism;
						}
				}
		}
}

const SParBCD & SParBCD::operator -- () {
	if ((signo == p)&&(ParBCD(second,first)==ParBCD(c,c))) {
			first  = n;
			second = n;
			signo  = m;
			return (*this);
		} else {
			if (first > c) {
					first += n;
					second += n;
					++second;
					return (*this);
				} else if (first == c) {
					first = n;
					second += n;
					return (*this);
				} else {
					first = E;
					second = E;
					return (*this);
				}
		}
}

SParBCD SParBCD::operator -- (int) {
	SParBCD thism(*this);

	if ((thism.signo == p)&&(ParBCD(thism.second,thism.first)==ParBCD(c,c))) {
			thism.first  = n;
			thism.second = n;
			thism.signo  = m;
			(*this)=thism;
			return thism;
		} else {
			if (thism.first > c) {
					thism.first += n;
					thism.second += n;
					++(thism.second);
					(*this)=thism;
					return thism;
				} else if (first == c) {
					thism.first = n;
					thism.second += n;
					(*this)=thism;
					return thism;
				} else {
					thism.first = E;
					thism.second = E;
					(*this)=thism;
					return thism;
				}
		}
}

DigBCD SParBCD::g_second() const {
		return second;
	}

DigBCD SParBCD::g_first() const {
		return first;
	}

sign_e SParBCD::g_sign() const {
		return signo;
	}

void SParBCD::p_sign(sign_e arg) {
	signo = arg;
	return;
}

SParBCD::operator N2DigsBCD() const {
		N2DigsBCD ret;
		ret.first=first;
		ret.second=second;
		return ret;
	}

void SParBCD::p_second(DigBCD arg) {
	second = arg;
	return;
}

void SParBCD::p_first(DigBCD arg) {
	first = arg;
	return;
}

SParBCD::operator DigBCD() const {
		return first;
	}

istream & operator >> (istream & in,SParBCD & arg) {
	char C,D;
	uchint carry,cifra;
	in >> C;
	in >> D;
	if ((('0'-1)<C)&&(C<('9'+1))and(('0'-1)<C)&&(C<('9'+1))) {
			carry =C-'0';
			cifra =C-'0';
		} else {
			carry=255;
			cifra=255;
		}
	arg.p_second(Nat2Dig(carry));
	arg.p_first(Nat2Dig(cifra));
	return in;
}

ostream & operator << (ostream & on,SParBCD arg) {
	on  << Dig2Char(arg.g_second())
	<< Dig2Char(arg.g_first());
	return on;
}
