#include "NumB10Str.hpp"//jiojk
#include <list>
#include <string>
#include <iterator>
#include <algorithm>

NumB10Str::NumB10Str(): signo(p),aux(SParBCD(c,c)) {
	clear();
}

NumB10Str::NumB10Str(const NumB10Str & a): signo(a.signo),aux(a.aux) {
	resize(a.size());
	for (usint k=0; k < a.size() ; ++k)
		operator[](k)=a[k];
}

NumB10Str::NumB10Str(const BasicNumB10Str & a): signo(p),aux(c,c) {
	resize(a.size());
	for (usint k=0; k < a.size() ; ++k)
		operator[](k)=a[k];
}

NumB10Str::NumB10Str(const string & a): signo(p),aux(c,c) {
	bool Exit = false;
	resize(a.size());
	for (usint k=0; k < a.size() ; ++k) {
			if (a[k]=='E') {
					resize(1);
					operator[](k)=E;
					Exit = true;
				}
		}
	if (!Exit) {
			usint k = 0;
			while ((a[k]<'0')||(a[k]>'9')) ++k;
			if (k >= a.size()) Exit=true;
			if (!Exit) {
					for ( ; (k < a.size())&&(!Exit) ; ++k) {
							if ((a[k]>='0')&&(a[k]<='9'))
								operator[](k)=Char2Dig(a[k]);
							else Exit=true;
						}
				}
		}
}

NumB10Str::NumB10Str(DigBCD a0): signo(p),aux(c,c) {
	resize(1);
	operator[](0)=a0;
}

/*
NumB10Str::NumB10Str(DigBCD,DigBCD);
NumB10Str::NumB10Str(DigBCD,DigBCD,DigBCD);
NumB10Str::NumB10Str(DigBCD,DigBCD,DigBCD,DigBCD);
NumB10Str::NumB10Str(DigBCD,DigBCD,DigBCD,DigBCD,DigBCD);
NumB10Str::NumB10Str(DigBCD,DigBCD,DigBCD,DigBCD,DigBCD,DigBCD);
NumB10Str::NumB10Str(DigBCD,DigBCD,DigBCD,DigBCD,DigBCD,DigBCD,DigBCD);
NumB10Str::NumB10Str(DigBCD,DigBCD,DigBCD,DigBCD,DigBCD,DigBCD,DigBCD,DigBCD);
NumB10Str::NumB10Str(DigBCD,DigBCD,DigBCD,DigBCD,DigBCD,DigBCD,DigBCD,DigBCD,DigBCD);
NumB10Str::NumB10Str(DigBCD,DigBCD,DigBCD,DigBCD,DigBCD,DigBCD,DigBCD,DigBCD,DigBCD,DigBCD);
NumB10Str::NumB10Str(sign_e,DigBCD);
NumB10Str::NumB10Str(sign_e,DigBCD,DigBCD);
NumB10Str::NumB10Str(sign_e,DigBCD,DigBCD,DigBCD);
NumB10Str::NumB10Str(sign_e,DigBCD,DigBCD,DigBCD,DigBCD);
NumB10Str::NumB10Str(sign_e,DigBCD,DigBCD,DigBCD,DigBCD,DigBCD);
NumB10Str::NumB10Str(sign_e,DigBCD,DigBCD,DigBCD,DigBCD,DigBCD,DigBCD);
NumB10Str::NumB10Str(sign_e,DigBCD,DigBCD,DigBCD,DigBCD,DigBCD,DigBCD,DigBCD);
NumB10Str::NumB10Str(sign_e,DigBCD,DigBCD,DigBCD,DigBCD,DigBCD,DigBCD,DigBCD,DigBCD);
NumB10Str::NumB10Str(sign_e,DigBCD,DigBCD,DigBCD,DigBCD,DigBCD,DigBCD,DigBCD,DigBCD,DigBCD);
NumB10Str::NumB10Str(sign_e,DigBCD,DigBCD,DigBCD,DigBCD,DigBCD,DigBCD,DigBCD,DigBCD,DigBCD,DigBCD);
*/

NumB10Str::NumB10Str(SParBCD a): signo(p),aux(c,c) {
	resize(2);
	operator[](0) = a.g_first();
	operator[](1) = a.g_second();
}

NumB10Str::NumB10Str(uchint a): signo(p),aux(c,c) {
	resize(1);
	operator[](0)=Nat2Dig(a);
}

NumB10Str::NumB10Str(unsigned long long a) : signo(p),aux(c,c) {
	list<DigBCD> temp;
	unsigned long long rem=0,coc=a;
	while (coc > 10) {
			coc = a/10;
			rem = a%10;
			temp.push_back(Int2Dig(rem));
		}
	temp.push_back(Int2Dig(rem));
	resize(temp.size());
	const list<DigBCD>::iterator fin = temp.end();
	list<DigBCD>::iterator  it = temp.begin();
	for ( usint k=0 ; it != fin ; ++k ) {
			operator[](k)=(*it);
			++it;
		}
}

NumB10Str NumB10Str::operator !() const {
		NumB10Str cpy(*this);
		cpy.reduce();
		const basic_string<DigBCD>::iterator fin = cpy.end();
		basic_string<DigBCD>::iterator  it = cpy.begin();
		for ( ; it != fin ; ++it )
			(*it) = (!(*it));
		cpy.signo = ((cpy.signo==m)?p:m);
		cpy.aux = SParBCD(p,c,c);
		return cpy;
	}

NumB10Str NumB10Str::operator -() const {
		NumB10Str cpy(*this);
		cpy.reduce();
		const basic_string<DigBCD>::iterator fin = cpy.end();
		basic_string<DigBCD>::iterator  it = cpy.begin();
		for ( ; it != fin ; ++it )
			(*it) = (!(*it));

		it = cpy.begin();
		cpy.aux = (*it)+u;
		cpy[0]=cpy.aux.g_first();
		++it;
		if ((cpy.aux/SParBCD(p,u,c))!= SParBCD(p,c,c)) {
				for ( ; it != fin ; ++it ) {
						cpy.aux/=SParBCD(p,u,c);
						if (cpy.aux == SParBCD(p,c,c)) break;
						cpy.aux += SParBCD(p,c,*it);
					}
				cpy.push_back(cpy.aux.g_first());
				cpy.push_back(cpy.aux.g_second());
			}
		cpy.signo = ((cpy.signo==m)?p:m);
		cpy.aux = SParBCD(p,c,c);
		return cpy;
	}

const NumB10Str & NumB10Str::mC10() {
	reduce();
	const basic_string<DigBCD>::iterator fin = end();
	basic_string<DigBCD>::iterator  it = begin();
	for ( ; it != fin ; ++it )
		(*it) = (!(*it));

	it = begin();
	aux = (*it)+u;
	(*this)[0]=aux.g_first();
	++it;
	if ((aux/SParBCD(p,u,c))!= SParBCD(p,c,c)) {
			for ( ; it != fin ; ++it ) {
					aux/=SParBCD(p,u,c);
					if (aux == SParBCD(p,c,c)) break;
					aux += SParBCD(p,c,*it);
				}
			push_back(aux.g_first());
			push_back(aux.g_second());
		}
	signo = ((signo==m)?p:m);
	aux = SParBCD(p,c,c);
	return (*this);
}

const NumB10Str & NumB10Str::mC9() {
	reduce();
	const basic_string<DigBCD>::iterator fin = end();
	basic_string<DigBCD>::iterator  it = begin();
	for ( ; it != fin ; ++it )
		(*it) = (!(*it));
	signo = ((signo==m)?p:m);
	aux = SParBCD(p,c,c);
	return (*this);
}

NumB10Str NumB10Str::abs() const {
	NumB10Str cthis(*this); cthis.reduce();
	if (signo==m) {
		cthis.mC10();
		return cthis;
	}
	return cthis;
}

const NumB10Str & NumB10Str::absp() {
	NumB10Str & cthis = (*this);
	cthis.reduce();
	if (signo==m) {
		cthis.mC10();
		return cthis;
	}
	return cthis;
}

usint NumB10Str::ceros_a_la_izqda () const {//digitos no significativos para números positivos
	bool Exit = false;
	usint sz=0;
	usint k=(size()-1);
	for ( ; (k > 0) and (!Exit) ; --k) {
		if (operator[](k)==c) ++sz;
		else Exit=true;
	}
	if ((k==0) and (operator[](k)==c) and (!Exit)) ++sz;
	return sz;
}//digitos no significativos para números positivos

usint NumB10Str::nueves_a_la_izqda () const {//digitos no significativos para números negativos
	bool Exit = false;
	usint sz=0;
	usint k=(size()-1);
	for ( ; (k > 0) and (!Exit) ; --k) {
		if (operator[](k)==n) ++sz;
		else Exit=true;
	}
	if ((k==0) and (operator[](k)==n) and (!Exit)) ++sz;
	return sz;
}//digitos no significativos para números negativos

usint NumB10Str::digs_no_significativos () const {//digitos no significativos
	if (signo==p) return ceros_a_la_izqda();
	else  return nueves_a_la_izqda();
}//digitos no significativos

usint NumB10Str::ceros_a_la_drcha () const {
	bool Exit = false;
	usint sz=0;
	const usint fin=size();
	usint k = 0;
	for ( ; (k < fin) and (!Exit) ; ++k) {
		if (operator[](k)==c) ++sz;
		else Exit=true;
	}
	return sz;
}

const NumB10Str & NumB10Str::reduce() {
	const usint nsz = digs_no_significativos();
	const usint pos = (size()-nsz)-1;
	erase(pos,nsz);
	return (*this);
}

NumB10Str NumB10Str::reduce() const {
	NumB10Str cpyreducida(*this);
	const usint nsz = cpyreducida.digs_no_significativos();
	const usint pos = (cpyreducida.size()-nsz)-1;
	cpyreducida.erase(pos,nsz);
	return cpyreducida;
}

bool NumB10Str::operator == (const NumB10Str & arg) const {
		const usint thisnsz = ceros_a_la_izqda();
		const usint thisvsz = size()-thisnsz;
		const usint argnsz = arg.ceros_a_la_izqda();
		const usint argvsz = arg.size()-argnsz;
		if ((thisvsz > argvsz)||(thisvsz < argvsz)) return false;
		else {
				for (usint k=(thisvsz-1);k>0;--k) {
						if ((arg[k]!=operator[](k))||(arg[k]==E)||(operator[](E)==E)) return false;
					}
				if (  (arg[0])!=(operator[](0) )
				        ||(arg[0]==E)
				        ||(operator[](0)==E)
				   ) return false;
				else return true;
			}
	}

bool NumB10Str::operator != (const NumB10Str & arg) const {
		const usint thisnsz = ceros_a_la_izqda();
		const usint thisvsz = size()-thisnsz;
		const usint argnsz = arg.ceros_a_la_izqda();
		const usint argvsz = arg.size()-argnsz;
		if ((thisvsz > argvsz)||(thisvsz < argvsz)) return true;
		else {
				for (usint k=(thisvsz-1);k>0;--k) {
						if ((arg[k]!=operator[](k))||(arg[k]==E)||(operator[](k)==E)) return true;
					}
				if (  (arg[0])!=(operator[](0))
				        ||(arg[0]==E)
				        ||(operator[](0)==E)
				   ) return true;
				else return false;
			}
	}

bool NumB10Str::operator >= (const NumB10Str & arg) const {
		const usint thisnsz = ceros_a_la_izqda();
		const usint thisvsz = size()-thisnsz;
		const usint argnsz = arg.ceros_a_la_izqda();
		const usint argvsz = arg.size()-argnsz;
		if (thisvsz > argvsz) return true;
		else if (thisvsz < argvsz) return false;
		else {
				for (usint k=(thisvsz-1);k>0;--k) {
						if ((arg[k] < operator[](k))) return true;
					}
				if ((arg[0])<=(operator[](0))) return true;
				else return false;
			}
	}

bool NumB10Str::operator <= (const NumB10Str & arg) const {
		const usint thisnsz = ceros_a_la_izqda();
		const usint thisvsz = size()-thisnsz;
		const usint argnsz = arg.ceros_a_la_izqda();
		const usint argvsz = arg.size()-argnsz;
		if (thisvsz < argvsz) return true;
		else if (thisvsz > argvsz) return false;
		else {
				for (usint k=(thisvsz-1);k>0;--k) {
						if ((arg[k] > operator[](k))) return true;
					}
				if ((arg[0]) >= (operator[](0))) return true;
				else return false;
			}
	}

bool NumB10Str::operator >  (const NumB10Str & arg) const {
		const usint thisnsz = ceros_a_la_izqda();
		const usint thisvsz = size()-thisnsz;
		const usint argnsz = arg.ceros_a_la_izqda();
		const usint argvsz = arg.size()-argnsz;
		if (thisvsz > argvsz) return true;
		else if (thisvsz < argvsz) return false;
		else {
				for (usint k=(thisvsz-1);k>0;--k) {
						if ((arg[k] < operator[](k))) return true;
					}
				if ((arg[0]) < (operator[](0))) return true;
				else return false;
			}
	}

bool NumB10Str::operator <  (const NumB10Str & arg) const {
		const usint thisnsz = ceros_a_la_izqda();
		const usint thisvsz = size()-thisnsz;
		const usint argnsz = arg.ceros_a_la_izqda();
		const usint argvsz = arg.size()-argnsz;
		if (thisvsz < argvsz) return true;
		else if (thisvsz > argvsz) return false;
		else {
				for (usint k=(thisvsz-1);k>0;--k) {
						if ((arg[k] > operator[](k))) return true;
					}
				if ((arg[0]) > (operator[](0))) return true;
				else return false;
			}
	}

NumB10Str NumB10Str::operator + (const NumB10Str & arg) const {
		NumB10Str ret(*this);
		ret.reduce();
		NumB10Str cpy(arg);
		cpy.reduce();
		SParBCD tempt(p,c,c);
		SParBCD tempa(p,c,c);
		const NumB10Str* po =0;
		usint sza = arg.size();
		usint szt = ret.size();
		p_usint  pszmin=0;
		p_usint  pszmax=0;
		if (sza<=szt) {
				pszmin = &sza;
				pszmax = &szt;
				po     = &ret;
			} else {
				pszmin = &szt;
				pszmax = &sza;
				po     = &cpy;
			}

		usint & szmin = *pszmin;
		usint & szmax = *pszmax;
		const NumB10Str & obj = *po;
		usint k = 0;
		ret.aux = SParBCD(p,c,c);
		for ( ; k<szmin ; ++k) {
				tempt.p_first(ret[k]);
				tempa.p_first(arg[k]);
				tempt += tempa;
				tempt += aux;
				ret[k]=tempt.g_first();
				ret.aux=SParBCD(tempt.g_sign(),((tempt.g_sign()==p)?(c):(n)),tempt.g_second());
			}
		for ( ; k<szmax ; ++k) {
				tempt.p_first(obj[k]);
				tempt += aux;
				ret[k]=tempt.g_first();
				ret.aux=SParBCD(tempt.g_sign(),((tempt.g_sign()==p)?(c):(n)),tempt.g_second());
			}
		ret.aux.p_first(aux.g_first());
		ret.aux.p_second(aux.g_second());
		ret.aux.p_sign(aux.g_sign());
		ret.aux = SParBCD(p,c,c);
		ret.push_back(ret.aux.g_first());
		ret.push_back(ret.aux.g_second());
		ret.aux.p_first(c);
		ret.aux.p_second(c);
		ret.signo=ret.aux.g_sign();
		ret.aux =  SParBCD(p,c,c);
		return ret;
	}

NumB10Str NumB10Str::operator - (const NumB10Str & arg) const {
		NumB10Str ret;
		NumB10Str cpy(-arg);
		ret.reduce();
		cpy.reduce();
		SParBCD tempt(p,c,c);
		SParBCD tempa(p,c,c);
		const NumB10Str* po =0;
		usint sza = cpy.size();
		usint szt = ret.size();
		p_usint  pszmin=0;
		p_usint  pszmax=0;
		if (sza<=szt) {
				pszmin = &sza;
				pszmax = &szt;
				po     = &ret;
			} else {
				pszmin = &szt;
				pszmax = &sza;
				po     = &cpy;
			}

		usint & szmin = *pszmin;
		usint & szmax = *pszmax;
		const NumB10Str & obj = *po;
		usint k = 0;
		ret.aux = SParBCD(p,c,c);
		for ( ; k<szmin ; ++k) {
				tempt.p_first(ret[k]);
				tempa.p_first(cpy[k]);
				tempt += tempa;
				tempt += aux;
				ret[k]=tempt.g_first();
				ret.aux=SParBCD(tempt.g_sign(),((tempt.g_sign()==p)?(c):(n)),tempt.g_second());
			}
		for ( ; k<szmax ; ++k) {
				tempt.p_first(obj[k]);
				tempt += aux;
				ret[k]=tempt.g_first();
				ret.aux=SParBCD(tempt.g_sign(),((tempt.g_sign()==p)?(c):(n)),tempt.g_second());
			}
		ret.aux.p_first(aux.g_first());
		ret.aux.p_second(aux.g_second());
		ret.aux.p_sign(aux.g_sign());
		ret.aux = SParBCD(p,c,c);
		ret.push_back(ret.aux.g_first());
		ret.push_back(ret.aux.g_second());
		ret.aux.p_first(c);
		ret.aux.p_second(c);
		ret.signo=ret.aux.g_sign();
		ret.aux =  SParBCD(p,c,c);
		return ret;
	}

const NumB10Str & NumB10Str::operator += (const NumB10Str & arg) {
	reduce();
	NumB10Str carg(arg.reduce());
	SParBCD tempt(p,c,c);
	SParBCD tempa(p,c,c);
	const NumB10Str* 	 po    =0;
	usint sza = carg.size();
	usint szt = size();
	p_usint          pszmin=0;
	p_usint          pszmax=0;
	if (sza<=szt) {
		pszmin = &sza;
		pszmax = &szt;
		po     = this;
	} else {
		pszmin = &szt;
		pszmax = &sza;
		po     = &carg;
	}
	const NumB10Str & obj = (*po);
	tempt.p_second(c);
	tempa.p_second(c);
	usint & szmin = *pszmin;
	usint & szmax = *pszmax;
	usint k = 0;
	for ( ; k<szmin ; ++k) {
		tempt.p_first((*this)[k]);
		tempa.p_first(carg[k]);
		tempt += tempa;
		(*this)[k]=tempt.g_first();
	}
	for (; k<szmax ; ++k) {
		tempt.p_first(obj[k]);
		tempt += (obj.aux);
		(*this)[k]=tempt.g_first();
	}
	aux.p_first(tempt.g_second());
	aux.p_second(c);
	reduce();
	return (*this);
}

const NumB10Str & NumB10Str::operator -= (const NumB10Str & arg){
	reduce();
	NumB10Str carg((-arg).reduce());
	SParBCD tempt(p,c,c);
	SParBCD tempa(p,c,c);
	const NumB10Str* 	 po    =0;
	usint sza = carg.size();
	usint szt = size();
	p_usint          pszmin=0;
	p_usint          pszmax=0;
	if (sza<=szt) {
		pszmin = &sza;
		pszmax = &szt;
		po     = this;
	} else {
		pszmin = &szt;
		pszmax = &sza;
		po     = &carg;
	}
	const NumB10Str & obj = (*po);
	tempt.p_second(c);
	tempa.p_second(c);
	usint & szmin = *pszmin;
	usint & szmax = *pszmax;
	usint k = 0;
	for ( ; k<szmin ; ++k) {
		tempt.p_first((*this)[k]);
		tempa.p_first(carg[k]);
		tempt += tempa;
		(*this)[k]=tempt.g_first();
	}
	for (; k<szmax ; ++k) {
		tempt.p_first(obj[k]);
		tempt += (obj.aux);
		(*this)[k]=tempt.g_first();
	}
	aux.p_first(tempt.g_second());
	aux.p_second(c);
	reduce();
	return (*this);
}

NumB10Str NumB10Str::operator * (DigBCD a) const {
	ParBCD 		temp;
	DigBCD  	carry=c;
	NumB10Str 	ret(*this);
	ret.reduce();
	for ( usint k=0 ; k < (size()-1) ; ++k ) {
		temp = (*this)[k]*a;
		temp += carry;
		ret[k]= temp.g_first();
		carry=temp.g_second();
	}
	if (carry != c)
		ret.insert(size()-1,1,carry);
	return ret;
}

const NumB10Str & NumB10Str::operator *= (DigBCD arg) {
	ParBCD 		temp;
	DigBCD  	carry=c;
	reduce();
	for ( usint k=0 ; k < (size()-1) ; ++k ) {
		temp = (*this)[k]*arg;
		temp += carry;
		(*this)[k]= temp.g_first();
		carry=temp.g_second();
	}
	if (carry != c)
		insert(size()-1,1,carry);
	return (*this);
}


NumB10Str NumB10Str::operator * (ParBCD a) const {
	ParBCD 		temp;
	DigBCD  	carry=c;
	NumB10Str 	ret(*this);
	ret.reduce();
	for ( usint k=0 ; k < (size()-1) ; ++k ) {
		temp = (*this)[k]*(a.g_first());
		temp += carry;
		ret[k]= temp.g_first();
		carry=temp.g_second();
	}
	if (carry != c)
		ret.insert(size()-1,1,carry);

	carry = c;
	for ( usint k=0 ; k < (size()-1) ; ++k ) {
		temp = (*this)[k]*(a.g_second());
		temp += carry;
		ret.substr(k+1)+= temp.g_first();//¿?
		carry=temp.g_second();
	}
	if (carry != c)
		ret.insert(size()-1,1,carry);
	ret.reduce();
	return ret;
}

const NumB10Str & NumB10Str::operator *= (ParBCD arg) {
	ParBCD 		temp;
	DigBCD  	carry=c;
	NumB10Str & ret = (*this);
	ret.reduce();
	for ( usint k=0 ; k < (size()-1) ; ++k ) {
		temp = (*this)[k]*(arg.g_first());
		temp += carry;
		ret[k]= temp.g_first();
		carry=temp.g_second();
	}
	if (carry != c)
		ret.insert(size()-1,1,carry);

	carry = c;
	for ( usint k=0 ; k < (size()-1) ; ++k ) {
		temp = (*this)[k]*(arg.g_second());
		temp += carry;
		ret.substr(k+1)= temp.g_first();//¿?
		carry=temp.g_second();
	}
	if (carry != c)
		ret.insert(size()-1,1,carry);
	ret.reduce();
	return ret;
}

const NumB10Str & NumB10Str::operator += (DigBCD arg) {
	reduce();
	SParBCD tempt(p,c,c);
	NumB10Str cpy(arg);
	const NumB10Str* 	 po    =0;
	usint sza = 1;
	usint szt = size();
	p_usint          pszmin=0;
	p_usint          pszmax=0;
	if (sza<=szt) {
		pszmin = &sza;
		pszmax = &szt;
		po     = this;
	} else {
		pszmin = &szt;
		pszmax = &sza;
		po     = &cpy;
	}
	const NumB10Str & obj = (*po);
	tempt.p_second(c);
	usint & szmin = *pszmin;
	usint & szmax = *pszmax;
	usint k = 1;

	tempt.p_first((*this)[0]);
	tempt += SParBCD(p,c,arg);
	(*this)[0]=tempt.g_first();
    
	for (; k<szmax ; ++k) {
		tempt.p_first(obj[k]);
		tempt += (obj.aux);
		(*this)[k]=tempt.g_first();
	}
	aux.p_first(tempt.g_second());
	aux.p_second(c);
	reduce();
	return (*this);
}


const NumB10Str & NumB10Str::operator -= (DigBCD arg) {
	reduce();
	SParBCD tempt(p,c,c);
	SParBCD tempa(p,c,arg);
	NumB10Str cpy(arg);
	tempa.mC10();
	const NumB10Str* 	 po    =0;
	usint sza = 1;
	usint szt = size();
	p_usint          pszmin=0;
	p_usint          pszmax=0;
	if (sza<=szt) {
		pszmin = &sza;
		pszmax = &szt;
		po     = this;
	} else {
		pszmin = &szt;
		pszmax = &sza;
		po     = &cpy;
	}
	const NumB10Str & obj = (*po);
	tempt.p_second(c);
	usint & szmin = *pszmin;
	usint & szmax = *pszmax;
	usint k = 1;

	tempt.p_first((*this)[0]);
	tempt += tempa;
	(*this)[0]=tempt.g_first();

	for (; k<szmax ; ++k) {
		tempt.p_first(obj[k]);
		tempt += (obj.aux);
		(*this)[k]=tempt.g_first();
	}
	aux.p_first(tempt.g_second());
	aux.p_second(c);
	reduce();
	return (*this);
}


NumB10Str NumB10Str::operator * (const NumB10Str & arg) const {
	NumB10Str sumatemp;
	NumB10Str multtemp;
	NumB10Str m1(abs());
	m1.reduce();
	NumB10Str m2(arg.abs());
	m2.reduce();

	multtemp = (*this)*m2[0];
	sumatemp = multtemp;
	for (usint j = 1 ; j < m2.size() ; ++j) {
		multtemp = (*this)*m2[j];
		multtemp.insert(0,j,c);
		sumatemp += multtemp;
	}
	if (signo!=arg.signo) sumatemp.mC10();
	return sumatemp;
}

const NumB10Str & NumB10Str::operator *= (const NumB10Str & arg) {
	NumB10Str multtemp;
	NumB10Str m1(abs());
	m1.reduce();
	NumB10Str m2(arg.abs());
	m2.reduce();

	(*this) *= m2[0];
	for (usint j = 1 ; j < m2.size() ; ++j) {
		multtemp = (*this)*m2[j];
		multtemp.insert(0,j,c);
		(*this) += multtemp;
	}
	if (signo!=arg.signo) this->mC10();
	return (*this);
}

NumB10Str NumB10Str::div10 () const {
	NumB10Str cpy(*this);
	cpy.reduce();
	cpy = cpy.abs();
	cpy.erase(0,1);
	if (signo==m) cpy.mC10();
	return cpy;
}

DigBCD NumB10Str::rem10 () const {
	if (signo==m) return (-((*this)[0]));
	else return ((*this)[0]);
}

const NumB10Str & NumB10Str::div10p () {
	abs();
	reduce();
	erase(0,1);
	if (signo==m) mC10();
	return (*this);
}

DigBCD NumB10Str::rem10p () {
	reduce();
	if (signo==m) return (-((*this)[0]));
	else return ((*this)[0]);
}

DigBCD NumB10Str::rem2 () const {
	if (signo==m) return (-Rem2((*this)[0]));
	else return Rem2((*this)[0]);
}

const DigBCD NumB10Str::rem4() const {
	ParBCD rem((*this)[1],(*this)[0]);
	switch (rem.g_second()) {
		case c : case d : case q : case x : case o :
			switch(rem.g_first()) {
				case c : case q : case o :
					return c;
				case u : case z : case n :
					return u;
				case d : case x :
					return d;
				case t : case s : default :
					return t;
			}
		case u : case t : case z : case s : case n :
			switch(rem.g_first()) {
				case d : case x :
					return c;
				case c : case q : case o :
					return d;
				case u : case z : case n :
					return t;
				case t : case s : default :
					return u;
			}
	}
}

const DigBCD NumB10Str::rem8() const {
	const DigBCD rem[]={(*this)[2],(*this)[1],(*this)[0]};
	switch (rem[2]) {
		case c : case d : case q : case x : case o :
			switch(rem[1]) {
				case c : case q : case o :
					switch(rem[0]) {
						case c : case o :
							return c;
						case u : case n :
							return u;
						case d : case t : case q : case z :	case x : case s : default:
							return rem[0];
					}
				case u : case z : case n :
					switch(rem[0]) {
						case x : 			return c;
						case s : 			return u;
						case o : case c : 	return d;
						case n : case u : 	return t;
						case d : 			return q;
						case t : 			return z;
						case q : 			return x;
						case z : default : 	return s;
					}
				case d : case x :
					switch(rem[0]) {
						case q : 		 			return c;
						case z :		 			return u;
						case t :            		return s;
						case x : 					return d;
						case s : 					return t;
						case o : case c : 			return q;
						case n : case u : default :	return z;
				}
				case t : case s : default :
					switch(rem[0]) {
						case d : 			return c;
						case t :			return u;
						case q : 			return d;
						case z :			return t;
						case x :			return q;
						case s : 			return z;
						case o : case c :	return x;
						case n : case u :
						default : 			return s;
					} 
			}
		case u : case t : case z : case s : case n :
			switch(rem[1]) {
				case d : case x :
					switch(rem[0]) {
						case c : case o : 	return c;
						case u : case n : 	return u;
						case d : case t :	case q  :	case z :
						case x : case s :	default : return rem[0];
					}
				case c : case q : case o :
					switch(rem[0]) {
						case q : 			return c;
						case z : 			return u;
						case d : case x : 	return d;
						case t : case s : 	return t;
						case c : case o : 	return q;
						case u : case n :
						default :			return z;
					}
				case u : case z : case n :
					switch(rem[0]) {
						case d : 			return c;
						case t : 			return u; 
						case q : 			return d;
						case z : 			return t;
						case x : 			return q;
						case s : 			return z;
						case c : case o : 	return x;
						case u : case n :
						default: 			return s;
					}
				case t : case s : default :
					switch(rem[0]) {
						case x : 			return c;
						case c : case s : 	return d;
						case u : case o : 	return t;
						case d : case n :	return q;
						case t :
						default : 			return z;
					}
			}
	}
}

const NumB10Str & NumB10Str::div2p () {
	NumB10Str & cthis = (*this);
	cthis.abs();
	cthis.reduce();
	NumB10Str coc(uchint(cthis.size()));
	ParBCD r2;
	r2.p_first(cthis[size()-1]);
	r2.p_second(c);
	ParBCD temp(c,c);
	const ParBCD dos(d,c);
	for (usint k=(size()-1),j=0; k>0 ; --k,++j) {
			temp=(r2/dos);
			coc[j] = temp.g_first();
			temp=(r2%dos);
			r2.p_second(temp.g_first());
			r2.p_first(cthis[k-1]);
		}
	temp=(r2/dos);
	coc.append(1,temp.g_first());
	temp=(r2%dos);
	r2.p_second(temp.g_first());
	r2.p_first(c);
	reverse(coc.begin(),coc.end());
	coc.reduce();
	cthis=coc;
	if (signo==m) cthis.mC10();
	return cthis;
}

NumB10Str NumB10Str::div2 () const{
	const NumB10Str & cthis = abs();
	NumB10Str coc(uchint(cthis.size()));
	ParBCD r2;
	r2.p_first(cthis[size()-1]);
	r2.p_second(c);
	ParBCD temp(c,c);
	const ParBCD dos(d,c);

	for (usint k=(size()-1),j=0; k>0 ; --k,++j) {
			temp=(r2/dos);
			coc[j] = temp.g_first();
			temp=(r2%dos);
			r2.p_second(temp.g_first());
			r2.p_first(cthis[k-1]);
		}
	temp=(r2/dos);
	coc.append(1,temp.g_first());
	temp=(r2%dos);
	r2.p_second(temp.g_first());
	r2.p_first(c);
	reverse(coc.begin(),coc.end());
	coc.reduce();
	if (signo==m) coc.mC10();
	return coc;
}

DigBCD NumB10Str::rem2p () {
	reduce();
	NumB10Str cpy(abs());
	if (signo==m) return (-Rem2((*this)[0]));
	else return Rem2((*this)[0]);
}

const NumB10Str & NumB10Str::operator ++ () {
	(*this) += u;
	return (*this);
}

NumB10Str NumB10Str::operator ++ (int) const {
	NumB10Str cpThis(*this);
	cpThis+=u;
	return cpThis;
}

const NumB10Str & NumB10Str::operator -- () {
	(*this)-=u;
	return (*this);
}

NumB10Str NumB10Str::operator -- (int) const {
	NumB10Str cpThis(*this);
	cpThis-=u;
	return cpThis;
}

// paso para la división (algoritmo privado)
inline void	NumB10Str::div_gen_step( const NumB10Str & dvsor , NumB10Str & rem , NumB10Str & coc , usint & dig ) const {
	const usint maxpos = size()-1;
	const NumB10Str & dvndo = (*this);
	rem.insert(0,1,dvndo[maxpos-dig]);
	if (rem < coc) {
		coc.insert(0,1,c);
	}
	else if (rem == coc) {
		coc.insert(0,1,u);
		rem.erase(0,rem.size()-1);
		rem[0]=c;
	}
	else {
		if (rem.size() > dvsor.size()) {
			ParBCD dighrem        = ParBCD(rem[rem.size()-1],rem[rem.size()-2]);
			ParBCD dighsor        = ParBCD(c,dvsor[dvsor.size()-1]);
			ParBCD & digcocprueba = dighrem;
			digcocprueba /= dighsor;
			NumB10Str remprueba = dvsor*digcocprueba;
			for( DigBCD Id = c ; Id < ParBCD(u,c) ; ++Id ) {
				if ( remprueba > rem ) {
					--digcocprueba;
					remprueba -= dvsor;
				}
				else {
					rem -= remprueba;
					coc.insert(0,1,digcocprueba);
				}
			}
		}
		else {
			DigBCD dighrem        = rem[rem.size()-1];
			DigBCD dighsor        = dvsor[dvsor.size()-1];
			DigBCD & digcocprueba = dighrem;
			digcocprueba /= dighsor;
			NumB10Str remprueba = dvsor*digcocprueba; // no está implementada esta función
			for( DigBCD Id = c ; Id < ParBCD(u,c) ; ++Id ) { 
				if ( remprueba > rem ) {
					--digcocprueba;
					remprueba -= dvsor;
				}
				else {
					rem -= remprueba;
					coc.insert(0,1,digcocprueba);
				}
			}
		}
	}
	++dig;
	return;
}
//inline void NumB10Str::divp_gen_step(tuple< NumB10Str , NumB10Str , usint > & S);
inline void	NumB10Str::divp_gen_step( const NumB10Str & dvsor , NumB10Str & rem , NumB10Str & coc , usint & dig ) {
	const usint maxpos = size()-1;
	NumB10Str & dvndo = (*this);
	rem.insert(0,1,dvndo[maxpos-dig]);
	if (rem < coc) {
		coc.insert(0,1,c);
	}
	else if (rem == coc) {
		coc.insert(0,1,u);
		rem.erase(0,rem.size()-1);
		rem[0]=c;
	}
	else {
		if (rem.size() > dvsor.size()) {
			ParBCD dighrem        = ParBCD(rem[rem.size()-1],rem[rem.size()-2]);
			const ParBCD dighsor  = ParBCD(c,dvsor[dvsor.size()-1]);
			ParBCD & digcocprueba = dighrem;
			digcocprueba /= dighsor;
			NumB10Str remprueba = dvsor*digcocprueba;
			for( DigBCD Id = c ; Id < ParBCD(u,c) ; ++Id ) {
				if ( remprueba > rem ) {
					--digcocprueba;
					remprueba -= dvsor;
				}
				else {
					rem -= remprueba;
					coc.insert(0,1,digcocprueba);
				}
			}
		}
		else {
			DigBCD dighrem        = rem[rem.size()-1];
			const DigBCD dighsor  = dvsor[dvsor.size()-1];
			DigBCD & digcocprueba = dighrem;
			digcocprueba /= dighsor;
			NumB10Str remprueba = dvsor*digcocprueba;
			for( DigBCD Id = c ; Id < ParBCD(u,c) ; ++Id ) { 
				if ( remprueba > rem ) {
					--digcocprueba;
					remprueba -= dvsor;
				}
				else {
					rem -= remprueba;
					coc.insert(0,1,digcocprueba);
				}
			}
		}
	}
	++dig;
	return;
}

inline void NumB10Str::div3_step(pair< N2DigsBCD , usint> & S) const {
	const usint maxpos = size()-1;
	const usint longtndo = size();
	usint & i = S.second;
	N2DigsBCD& R = S.first;
	DigBCD & coc = R.second;
	DigBCD remH;
	DigBCD & remL = R.first;
	if (i==0) {
		remL = (*this)[maxpos];
		switch(remL) {
			case c:remL=c;coc=c;break;
			case u:remL=u;coc=c;break;
			case d:remL=d;coc=c;break;
			case t:remL=c;coc=u;break;
			case q:remL=u;coc=u;break;
			case z:remL=d;coc=u;break;
			case x:remL=c;coc=d;break;
			case s:remL=u;coc=d;break;
			case o:remL=d;coc=d;break;
			case n:remL=c;coc=t;break;
			case E:
			default:remL=E;coc=E;;
		}
	}
	else {
		remH = remL;
		remL = (*this)[ maxpos - i ];
		switch(remH) {
			case c:	switch(remL) {
					case c:remL=c;coc=c;break;
					case u:remL=u;coc=c;break;
					case d:remL=d;coc=c;break;
					case t:remL=c;coc=u;break;
					case q:remL=u;coc=u;break;
					case z:remL=d;coc=u;break;
					case x:remL=c;coc=d;break;
					case s:remL=u;coc=d;break;
					case o:remL=d;coc=d;break;
					case n:remL=c;coc=t;break;
					case E:
					default:remL=E;coc=E;;
					}
					break;
			case u:	switch(remL) {
					case c:remL=u;coc=t;break;
					case u:remL=d;coc=t;break;
					case d:remL=c;coc=q;break;
					case t:remL=u;coc=q;break;
					case q:remL=d;coc=q;break;
					case z:remL=c;coc=z;break;
					case x:remL=u;coc=z;break;
					case s:remL=d;coc=z;break;
					case o:remL=c;coc=x;break;
					case n:remL=u;coc=x;break;
					case E:
					default:remL=E;coc=E;;
					}
					break;
			case d:	switch(remL) {
					case c:remL=d;coc=x;break;
					case u:remL=c;coc=s;break;
					case d:remL=u;coc=s;break;
					case t:remL=d;coc=s;break;
					case q:remL=c;coc=o;break;
					case z:remL=u;coc=o;break;
					case x:remL=d;coc=o;break;
					case s:remL=c;coc=n;break;
					case o:remL=u;coc=n;break;
					case n:remL=d;coc=n;break;
					case E:
					default:remL=E;coc=E;;
					}
					break;
			case E:
			default:remL=E;coc=E;
		}
	}
	++i;
	return;
}

inline void NumB10Str::div3p_step(pair< N2DigsBCD , usint > & S) {
	NumB10Str & cthis = (*this);
	const usint maxpos = size()-1;
	const usint longtndo = size();
	usint & i = S.second;
	N2DigsBCD& R = S.first;
	DigBCD & coc = cthis[maxpos - i];
	DigBCD remH;
	DigBCD & remL = R.first;
	if (i==0) {
		remL = (*this)[maxpos];
		switch(remL) {
			case c:remL=c;coc=c;break;
			case u:remL=u;coc=c;break;
			case d:remL=d;coc=c;break;
			case t:remL=c;coc=u;break;
			case q:remL=u;coc=u;break;
			case z:remL=d;coc=u;break;
			case x:remL=c;coc=d;break;
			case s:remL=u;coc=d;break;
			case o:remL=d;coc=d;break;
			case n:remL=c;coc=t;break;
			case E:
			default:remL=E;coc=E;;
		}
	}
	else {
		remH = remL;
		remL = (*this)[ maxpos - i ];
		switch(remH) {
			case c:	switch(remL) {
					case c:remL=c;coc=c;break;
					case u:remL=u;coc=c;break;
					case d:remL=d;coc=c;break;
					case t:remL=c;coc=u;break;
					case q:remL=u;coc=u;break;
					case z:remL=d;coc=u;break;
					case x:remL=c;coc=d;break;
					case s:remL=u;coc=d;break;
					case o:remL=d;coc=d;break;
					case n:remL=c;coc=t;break;
					case E:
					default:remL=E;coc=E;;
					}
					break;
			case u:	switch(remL) {
					case c:remL=u;coc=t;break;
					case u:remL=d;coc=t;break;
					case d:remL=c;coc=q;break;
					case t:remL=u;coc=q;break;
					case q:remL=d;coc=q;break;
					case z:remL=c;coc=z;break;
					case x:remL=u;coc=z;break;
					case s:remL=d;coc=z;break;
					case o:remL=c;coc=x;break;
					case n:remL=u;coc=x;break;
					case E:
					default:remL=E;coc=E;;
					}
					break;
			case d:	switch(remL) {
					case c:remL=d;coc=x;break;
					case u:remL=c;coc=s;break;
					case d:remL=u;coc=s;break;
					case t:remL=d;coc=s;break;
					case q:remL=c;coc=o;break;
					case z:remL=u;coc=o;break;
					case x:remL=d;coc=o;break;
					case s:remL=c;coc=n;break;
					case o:remL=u;coc=n;break;
					case n:remL=d;coc=n;break;
					case E:
					default:remL=E;coc=E;;
					}
					break;
			case E:
			default:remL=E;coc=E;
		}
	}
	++i;
	return;
}

NumB10Str NumB10Str::div3() const {
	NumB10Str coc_by_3(*this);
	coc_by_3.abs();
	coc_by_3.reduce();
	const usint maxpos = size()-1;
	const usint longtndo = size();
	pair< N2DigsBCD , usint> S = make_pair(make_pair(c,c),0);
	usint & i = S.second;
	N2DigsBCD & R = S.first;
	DigBCD & coc = R.second;
	DigBCD & remL = R.first;
	DigBCD remH;

	while (i < longtndo) {
		div3_step(S);
		coc_by_3.insert(0,1,coc);
	}
	if (coc_by_3.signo==m) coc_by_3.mC10();
	return coc_by_3;
}

const NumB10Str & NumB10Str::div3p() {
	NumB10Str & cthis = (*this);
	cthis.abs();
	cthis.reduce();
	const usint maxpos = size()-1;
	const usint longtndo = size();
	pair< N2DigsBCD , usint> S = make_pair(make_pair(c,c),0);
	usint & i = S.second;
	N2DigsBCD& R = S.first;
	DigBCD & coc = R.second;
	DigBCD & remL = R.first;
	DigBCD remH;

	while (i < longtndo) div3p_step(S);
	for( usint k=0 ; k < longtndo ; ++k) {
		remH = cthis[k];
		cthis[k]=cthis[maxpos-k];
		cthis[maxpos-k]=remH;
	}
	cthis.reduce();
	
	if(cthis.signo==m) cthis.mC10();
	
	return cthis;
}

// paso para la división (algoritmo privado)
inline void NumB10Str::div7_step(pair< N2DigsBCD , usint> & S) const {
	const usint maxpos = size()-1;
	const usint longtndo = size();
	usint & i = S.second;
	N2DigsBCD& R = S.first;
	DigBCD & coc = R.second;
	DigBCD remH;
	DigBCD & remL = R.first;
	if (i==0) {
		remL = (*this)[maxpos];
		switch(remL) {
			case c:remL=c;coc=c;break;
			case u:remL=u;coc=c;break;
			case d:remL=d;coc=c;break;
			case t:remL=t;coc=c;break;
			case q:remL=q;coc=c;break;
			case z:remL=z;coc=c;break;
			case x:remL=x;coc=c;break;
			case s:remL=c;coc=u;break;
			case o:remL=u;coc=u;break;
			case n:remL=d;coc=u;break;
			case E:
			default:remL=E;coc=E;;
		}
	}
	else {
		remH = remL;
		remL = (*this)[ maxpos - i ];
		switch(remH) {
			case c:	switch(remL) {
					case c:remL=c;coc=c;break;
					case u:remL=u;coc=c;break;
					case d:remL=d;coc=c;break;
					case t:remL=t;coc=c;break;
					case q:remL=q;coc=c;break;
					case z:remL=z;coc=c;break;
					case x:remL=x;coc=c;break;
					case s:remL=c;coc=u;break;
					case o:remL=u;coc=u;break;
					case n:remL=d;coc=u;break;
					case E:
					default:remL=E;coc=E;;
					}
					break;
			case u:	switch(remL) {
					case c:remL=t;coc=u;break;
					case u:remL=q;coc=u;break;
					case d:remL=z;coc=u;break;
					case t:remL=x;coc=u;break;
					case q:remL=c;coc=d;break;
					case z:remL=u;coc=d;break;
					case x:remL=d;coc=d;break;
					case s:remL=t;coc=d;break;
					case o:remL=q;coc=d;break;
					case n:remL=z;coc=d;break;
					case E:
					default:remL=E;coc=E;;
					}
					break;
			case d:	switch(remL) {
					case c:remL=x;coc=d;break;
					case u:remL=c;coc=t;break;
					case d:remL=u;coc=t;break;
					case t:remL=d;coc=t;break;
					case q:remL=t;coc=t;break;
					case z:remL=q;coc=t;break;
					case x:remL=z;coc=t;break;
					case s:remL=x;coc=t;break;
					case o:remL=c;coc=q;break;
					case n:remL=u;coc=q;break;
					case E:
					default:remL=E;coc=E;;
					}
					break;
			case t:	switch(remL) {
					case c:remL=d;coc=q;break;
					case u:remL=t;coc=q;break;
					case d:remL=q;coc=q;break;
					case t:remL=z;coc=q;break;
					case q:remL=x;coc=q;break;
					case z:remL=c;coc=z;break;
					case x:remL=u;coc=z;break;
					case s:remL=d;coc=z;break;
					case o:remL=t;coc=z;break;
					case n:remL=q;coc=z;break;
					case E:
					default:remL=E;coc=E;;
					}
					break;
			case q:	switch(remL) {
					case c:remL=z;coc=z;break;
					case u:remL=x;coc=z;break;
					case d:remL=c;coc=x;break;
					case t:remL=u;coc=x;break;
					case q:remL=d;coc=x;break;
					case z:remL=t;coc=x;break;
					case x:remL=q;coc=x;break;
					case s:remL=z;coc=x;break;
					case o:remL=x;coc=x;break;
					case n:remL=c;coc=s;break;
					case E:
					default:remL=E;coc=E;;
					}
					break;
			case z:	switch(remL) {
					case c:remL=u;coc=s;break;
					case u:remL=d;coc=s;break;
					case d:remL=t;coc=s;break;
					case t:remL=q;coc=s;break;
					case q:remL=z;coc=s;break;
					case z:remL=x;coc=s;break;
					case x:remL=c;coc=o;break;
					case s:remL=u;coc=o;break;
					case o:remL=d;coc=o;break;
					case n:remL=t;coc=o;break;
					case E:
					default:remL=E;coc=E;;
					}
					break;
			case x:	switch(remL) {
					case c:remL=q;coc=o;break;
					case u:remL=z;coc=o;break;
					case d:remL=x;coc=o;break;
					case t:remL=c;coc=n;break;
					case q:remL=u;coc=n;break;
					case z:remL=d;coc=n;break;
					case x:remL=t;coc=n;break;
					case s:remL=q;coc=n;break;
					case o:remL=z;coc=n;break;
					case n:remL=x;coc=n;break;
					case E:
					default:remL=E;coc=E;;
					}
					break;
			case E:
			default:remL=E;coc=E;
		}
	}
	++i;
	return;
}

inline void NumB10Str::div7p_step(pair< N2DigsBCD , usint > & S) {
	NumB10Str & cthis = (*this);
	const usint maxpos = size()-1;
	const usint longtndo = size();
	usint & i = S.second;
	N2DigsBCD& R = S.first;
	DigBCD & coc = cthis[maxpos - i];
	DigBCD remH;
	DigBCD & remL = R.first;	if (i==0) {
		remL = (*this)[maxpos];
		switch(remL) {
			case c:remL=c;coc=c;break;
			case u:remL=u;coc=c;break;
			case d:remL=d;coc=c;break;
			case t:remL=t;coc=c;break;
			case q:remL=q;coc=c;break;
			case z:remL=z;coc=c;break;
			case x:remL=x;coc=c;break;
			case s:remL=c;coc=u;break;
			case o:remL=u;coc=u;break;
			case n:remL=d;coc=u;break;
			case E:
			default:remL=E;coc=E;;
		}
	}
	else {
		remH = remL;
		remL = (*this)[ maxpos - i ];
		switch(remH) {
			case c:	switch(remL) {
					case c:remL=c;coc=c;break;
					case u:remL=u;coc=c;break;
					case d:remL=d;coc=c;break;
					case t:remL=t;coc=c;break;
					case q:remL=q;coc=c;break;
					case z:remL=z;coc=c;break;
					case x:remL=x;coc=c;break;
					case s:remL=c;coc=u;break;
					case o:remL=u;coc=u;break;
					case n:remL=d;coc=u;break;
					case E:
					default:remL=E;coc=E;;
					}
					break;
			case u:	switch(remL) {
					case c:remL=t;coc=u;break;
					case u:remL=q;coc=u;break;
					case d:remL=z;coc=u;break;
					case t:remL=x;coc=u;break;
					case q:remL=c;coc=d;break;
					case z:remL=u;coc=d;break;
					case x:remL=d;coc=d;break;
					case s:remL=t;coc=d;break;
					case o:remL=q;coc=d;break;
					case n:remL=z;coc=d;break;
					case E:
					default:remL=E;coc=E;;
					}
					break;
			case d:	switch(remL) {
					case c:remL=x;coc=d;break;
					case u:remL=c;coc=t;break;
					case d:remL=u;coc=t;break;
					case t:remL=d;coc=t;break;
					case q:remL=t;coc=t;break;
					case z:remL=q;coc=t;break;
					case x:remL=z;coc=t;break;
					case s:remL=x;coc=t;break;
					case o:remL=c;coc=q;break;
					case n:remL=u;coc=q;break;
					case E:
					default:remL=E;coc=E;;
					}
					break;
			case t:	switch(remL) {
					case c:remL=d;coc=q;break;
					case u:remL=t;coc=q;break;
					case d:remL=q;coc=q;break;
					case t:remL=z;coc=q;break;
					case q:remL=x;coc=q;break;
					case z:remL=c;coc=z;break;
					case x:remL=u;coc=z;break;
					case s:remL=d;coc=z;break;
					case o:remL=t;coc=z;break;
					case n:remL=q;coc=z;break;
					case E:
					default:remL=E;coc=E;;
					}
					break;
			case q:	switch(remL) {
					case c:remL=z;coc=z;break;
					case u:remL=x;coc=z;break;
					case d:remL=c;coc=x;break;
					case t:remL=u;coc=x;break;
					case q:remL=d;coc=x;break;
					case z:remL=t;coc=x;break;
					case x:remL=q;coc=x;break;
					case s:remL=z;coc=x;break;
					case o:remL=x;coc=x;break;
					case n:remL=c;coc=s;break;
					case E:
					default:remL=E;coc=E;;
					}
					break;
			case z:	switch(remL) {
					case c:remL=u;coc=s;break;
					case u:remL=d;coc=s;break;
					case d:remL=t;coc=s;break;
					case t:remL=q;coc=s;break;
					case q:remL=z;coc=s;break;
					case z:remL=x;coc=s;break;
					case x:remL=c;coc=o;break;
					case s:remL=u;coc=o;break;
					case o:remL=d;coc=o;break;
					case n:remL=t;coc=o;break;
					case E:
					default:remL=E;coc=E;;
					}
					break;
			case x:	switch(remL) {
					case c:remL=q;coc=o;break;
					case u:remL=z;coc=o;break;
					case d:remL=x;coc=o;break;
					case t:remL=c;coc=n;break;
					case q:remL=u;coc=n;break;
					case z:remL=d;coc=n;break;
					case x:remL=t;coc=n;break;
					case s:remL=q;coc=n;break;
					case o:remL=z;coc=n;break;
					case n:remL=x;coc=n;break;
					case E:
					default:remL=E;coc=E;;
					}
					break;
			case E:
			default:remL=E;coc=E;
		}
	}
	++i;
	return;
}

NumB10Str NumB10Str::div7() const {
	NumB10Str coc_by_7(*this);
	coc_by_7.abs();
	coc_by_7.reduce();
	const usint maxpos = size()-1;
	const usint longtndo = size();
	pair< N2DigsBCD , usint> S = make_pair(make_pair(c,c),0);
	usint & i = S.second;
	N2DigsBCD & R = S.first;
	DigBCD & coc = R.second;
	DigBCD & remL = R.first;
	DigBCD remH;

	while (i < longtndo) {
		div7_step(S);
		coc_by_7.insert(0,1,coc);
	}
	if (coc_by_7.signo==m) coc_by_7.mC10();
	return coc_by_7;
}

const NumB10Str & NumB10Str::div7p() {
	NumB10Str & cthis = (*this);
	cthis.abs();
	cthis.reduce();
	const usint maxpos = size()-1;
	const usint longtndo = size();
	pair< N2DigsBCD , usint> S = make_pair(make_pair(c,c),0);
	usint & i = S.second;
	N2DigsBCD& R = S.first;
	DigBCD & coc = R.second;
	DigBCD & remL = R.first;
	DigBCD remH;

	while (i < longtndo) div7p_step(S);
	for( usint k=0 ; k < longtndo ; ++k) {
		remH = cthis[k];
		cthis[k]=cthis[maxpos-k];
		cthis[maxpos-k]=remH;
	}
	cthis.reduce();
	
	if(cthis.signo==m) cthis.mC10();
	
	return cthis;
}

DigBCD NumB10Str::rem3() const {
	NumB10Str cthis(*this),suma;
	cthis.abs();
	cthis.reduce();
	suma.reduce();
	suma.insert(0,1,c);
	suma.erase(0,size()-1);
	do { 
	for( usint i = 0 ; i < cthis.size() ; ++i )
		suma += cthis[i];
		suma.reduce();
	} while (suma.size()>1);
	
	switch(suma[0]) {
		case c  :
		case t  :
		case x  :
		case n  : return c;
		case u  :
		case q  :
		case s  : return u;
		case d  :
		case z  :
		case o  : 
		default : return d;
	}
}


DigBCD NumB10Str::rem6() const {
	NumB10Str cthis(*this),suma;
	cthis.abs();
	cthis.reduce();
	suma.reduce();
	suma.insert(0,1,c);
	suma.erase(0,size()-1);
	do { 
	for( usint i = 0 ; i < cthis.size() ; ++i )
		suma += cthis[i];
		suma.reduce();
	} while (suma.size()>1);
	
	DigBCD x = suma[0];
	DigBCD y = cthis[0];
	DigBCD W = N2DigsBCD(N2DigsBCD(x*d).first+y).first;
	
	switch(W) {
		case c  : return c;
		case t  : return u;
		case q  : return d;
		case u  : return t;
		case d  : return q;
		case z  :
		default : return z;
	}
}

DigBCD NumB10Str::rem9() const {
	NumB10Str cthis(*this),suma;
	cthis.abs();
	cthis.reduce();
	suma.reduce();
	suma.insert(0,1,c);
	suma.erase(0,size()-1);
	do { 
	for( usint i = 0 ; i < cthis.size() ; ++i )
		suma += cthis[i];
		suma.reduce();
	} while (suma.size()>1);
	
	switch(suma[0]) {
		case c  :
		case n  : return c;
		case u  : return u;
		case d  : return d;
		case t  : return t;
		case q  : return q;
		case z  : return z;
		case x  : return x;
		case s  : return s;
		case o  :
		default : return o;
	}
}

DigBCD NumB10Str::rem5() const {
	NumB10Str cthis(*this),suma;
	cthis.abs();
	cthis.reduce();
	
	switch(cthis[0]) {
		case c  : case z  : return c;
		case u  : case x  : return u;
		case d  : case s  : return d;
		case t  : case o  : return t;
		case q  : case n  :
		default : 			return q;
	}
}


const NumB10Str & NumB10Str::rem3p() {
	NumB10Str & cthis = *this;
	NumB10Str suma;
	cthis.abs();
	cthis.reduce();
	suma.reduce();
	suma.insert(0,1,c);
	suma.erase(0,size()-1);
	do { 
	for( usint i = 0 ; i < cthis.size() ; ++i )
		suma += cthis[i];
		suma.reduce();
	} while (suma.size()>1);
	
	switch(suma[0]) {
		case c:
		case t:
		case x:
		case n:   cthis=NumB10Str(c); break;
		case u:
		case q:
		case s:   cthis=NumB10Str(u); break;
		case d:
		case z:
		case o:   cthis=NumB10Str(d); break;
		case E:
		default:  cthis=NumB10Str(E);
	}
	return cthis;
}


DigBCD NumB10Str::rem7() const {
	NumB10Str cthis(*this);
	NumB10Str sH,sL;
	cthis.abs();
	cthis.reduce();
	sH.reduce();sL.reduce();
	sH.insert(0,1,c);sL.insert(0,1,c);
	sH.erase(0,size()-1);sL.erase(0,size()-1);

	NumB10Str suma(c);
	NumB10Str sumando(c);
	bool sig = true;
	for ( usint i = 0 ; i < cthis.size() ; i+=3 ) {
		for(usint k=0 ; (k<3) and ((i+k)<cthis.size()) ; ++k )
			sumando.insert(0,1,cthis[i+k]);
		if (sig) {
			suma+=sumando;
		}
		else {
			suma-=sumando;
		}
		sig = !sig;
	}
	
	while (suma.size() > 1) { 
		sH = suma.div10();
		sL = suma.rem10();
		sL *= d;
		sH -= sL;
		suma = sH;
		suma.reduce();
	}
	
	switch(sH[0]) {
		case c:	case s: return c;
		case u:	case o: return u;
		case d:	case n: return d;
		case t: 		return t;
		case q: 		return q;
		case z: 		return z;
		case x: 
		default : 		return x;
	}
}

DigBCD NumB10Str::rem7p() {
	NumB10Str & cthis = (*this);
	NumB10Str sH(cthis);
	NumB10Str sL(cthis);
	cthis.abs();
	cthis.reduce();

	while (cthis.size() > 1) { 
		sH.div10p();
		sL.rem10p();
		sL *= d;
		sH -= sL;
		sH.reduce();
	}
	
	switch(sH[0]) {
		case c:
		case s: return c;
		case u:
		case o: return u;
		case d:
		case n: return d;
		case t: return t;
		case q: return q;
		case z: return z;
		case x: return x;
		case E:
		default: return E;
	}
}

// div_uno : bloque privado
inline void NumB10Str::div_uno( NumB10Str & rem , NumB10Str & dvndo , NumB10Str & dvsor , const usint long_dvndo , const usint long_dvsor )const {
	rem = dvndo;
	if ((long_dvsor==0)||((long_dvsor==1)&&(dvsor[0]=c))) { // caso de division por 0
		dvndo.erase(0,size()-1);
		dvndo[0]=E;
		rem.erase(0,rem.size()-1);
		rem[0]=E;
	}
	else if ((long_dvndo==0)||(long_dvndo < long_dvsor)) { // caso de 0 dividido por !=0 ó caso de cociente 0
		dvndo.erase(0,size()-1);
		dvndo[0]=c;
		// rem=dvndo; hecho por defecto
	}
	else if (dvndo==dvsor) { // caso de dividir por si mismo
		dvndo.erase(0,size()-1);
		dvndo[0]=u;
		rem.erase(0,rem.size()-1);
		rem[0]=c;
	}
	else if ((long_dvsor==1)&&(dvsor[0]==u)) { // caso de dividir por potencias de 10
		//dvndo;
		rem.erase(0,rem.size()-1);
		rem[0]=c;
	}
	else if ((long_dvsor==1)&&((dvsor[0]==d)||(dvsor[0]==q)||(dvsor[0]==o))) {
	// caso de dividir por potencias de 10 multiplicadas por 2, 4 u 8
		//dvndo;
		switch(dvsor[0]) {
			case d  : rem=NumB10Str(rem.rem2()); break;
			case q  : rem=NumB10Str(rem.rem4()); break;
			case o  :
			default : rem=NumB10Str(rem.rem8());
		}
		dvndo.div2p();
		switch(dvsor[0]) {
			case q:  dvndo.div2p(); break;
			case o:  dvndo.div2p(); dvndo.div2p();
		}
		
	}
	else if ((long_dvsor==1)&&((dvsor[0]==t)||(dvsor[0]==n))) {
	// caso de dividir por potencias de 10 multiplicadas por 3 u 9
		//dvndo;
		switch(dvsor[0]) {
			case t  : rem=NumB10Str(rem.rem3()); break;
			case n  : 
			default : rem=NumB10Str(rem.rem9()); break;
		}
		dvndo.div3p();
		if(dvsor[0]==n) dvndo.div3p();
	}
	else if ((long_dvsor==1)&&(dvsor[0]==x)) {
	// caso de dividir por potencias de 10 multiplicadas por 6
		//dvndo;
		rem.rem6();
		dvndo.div2p();
		dvndo.div3p();
	}
	else if ((long_dvsor==1)&&(dvsor[0]==z)) {
	// caso de dividir por potencias de 10 multiplicadas por 5
		rem.rem5();
		if (long_dvndo > 1) {
			dvndo.erase(0,1);
			// Divido por 10
			dvndo *= d;
			// y he multiplicado por 2 (*2/10 ó *1/5)
		}
		else {
			//dvndo;
			//dvndo.erase(0,size()-1);
			switch (dvndo[0]) {
				case c :
				case u :
				case d :
				case t :
				case q :  dvndo[0] = c; break;
				default : dvndo[0] = u;
			}
		}
	}
	else if ((long_dvsor==1)&&(dvsor[0]==s)) {
	// caso de dividir por potencias de 10 multiplicadas por 7
		//dvndo;
		rem.rem7();
		dvndo.div7();
	}
	else if ((long_dvndo == long_dvsor) && (dvndo < dvsor)) {
		rem = dvndo;
		dvndo.erase(0,size()-1);
		dvndo[0]    =c;
	}
	else {
		// algoritmo de resta general
		// implementar div_step pasamos (resto,cociente,i,dividendo,divisor) devuelve (resto,cociente,i,dividendo,divisor)
		// se puede hacer con una tupla
		//dvndo;
		NumB10Str rem   = dvndo.substr(size()-1-long_dvsor,long_dvsor);
		NumB10Str coc(c);
		usint dig = 0;
		do { div_gen_step(dvsor,rem,coc,dig);
		} while ( rem >= dvsor );
		dvndo = coc;
	}
} 

// BEGIN PRIVATE

pair< NumB10Str , NumB10Str > NumB10Str::EuclidDiv (const NumB10Str & arg) const {
	NumB10Str rem; rem.reduce();
	NumB10Str dvndo_int(abs()); dvndo_int.reduce();
	NumB10Str dvsor_int(arg.abs()); dvsor_int.reduce();
	const usint cssor = dvsor_int.ceros_a_la_izqda(); //¿?
	dvsor_int.erase(0,cssor);// division por una potencia de 10
	NumB10Str dvndo_fra(dvndo_int.substr(0,cssor));
	dvndo_int.erase(0,cssor);
	dvsor_int.reduce();
	dvndo_int.reduce();
	dvndo_fra.reduce();
	const usint longtndo  = dvndo_int.size();
	const usint longtndo2 = dvndo_fra.size();
	const usint longtsor  = dvsor_int.size();
	const usint longsor   = longtsor;

	// hemos dividido por los ceros del divisor (por una potencia de 10)
	// tanto divisor como dividendo, obteniendo dvndo_int y dvsor_int como
	// cocientes enteros.
	div_uno(rem,dvndo_int,dvsor_int,longtndo,longsor);
	// ahora hacemos lo mismo con el cociente de las potencias de 10 del
	// dividendo obteniendo dvndo_fra
	
	/* *
	 RemReal = RemObtenido*10^cssor + Dvndo_fra
	 * */
	 rem.insert(0,cssor,c);
	 rem += dvndo_fra;
	// rehacer el resto tomando en cuenta los ceros quitados
	// acomodar el formato al signo de la operacion
	// determinar el signo de la operacion
	return make_pair(rem,dvndo_int);
}

pair< NumB10Str , const NumB10Str & > NumB10Str::EuclidDivP (const NumB10Str & arg) {
	abs();
	reduce();
	NumB10Str rem(*this);
	rem.reduce();
	NumB10Str & dvndo_int = (*this);
	NumB10Str dvsor_int(arg.abs());
	dvsor_int.reduce();
	const usint cssor = dvsor_int.ceros_a_la_izqda();
	dvsor_int.erase(0,cssor);
	NumB10Str dvndo_fra(dvndo_int.substr(0,cssor));
	dvndo_int.erase(0,cssor);
	dvsor_int.reduce();
	dvndo_int.reduce();
	dvndo_fra.reduce();
	const usint longtndo  = dvndo_int.size();
	const usint longtndo2 = dvndo_fra.size();
	const usint longtsor  = dvsor_int.size();
	const usint longsor  = longtsor;

	// hemos dividido por los ceros del divisor (por una potencia de 10)
	// tanto divisor como dividendo, obteniendo dvndo_int y dvsor_int como
	// cocientes enteros.
	div_uno(rem,dvndo_int,dvsor_int,longtndo,longsor);
	// ahora hacemos lo mismo con el cociente de las potencias de 10 del
	// dividendo obteniendo dvndo_fra
	
	/* *
	 RemReal = RemObtenido*10^cssor + Dvndo_fra
	 * */
	rem.insert(0,cssor,c);
	rem += dvndo_fra;
	// rehacer el resto tomando en cuenta los ceros quitados
	// acomodar el formato al signo de la operacion
	// determinar el signo de la operacion
	return make_pair(rem,dvndo_int);
}
// END PRIVATE
NumB10Str NumB10Str::operator / (const NumB10Str & arg) const {
	NumB10Str dvndo_int(abs()); dvndo_int.reduce();
	NumB10Str rem(dvndo_int); rem.reduce();
	NumB10Str dvsor_int(arg.abs()); dvsor_int.reduce();
	const usint cssor = dvsor_int.ceros_a_la_izqda(); //¿?
	dvsor_int.erase(0,cssor);// division por una potencia de 10
	NumB10Str dvndo_fra(dvndo_int.substr(0,cssor));
	dvndo_int.erase(0,cssor);
	dvsor_int.reduce();
	dvndo_int.reduce();
	dvndo_fra.reduce();
	const usint longtndo  = dvndo_int.size();
	const usint longtndo2 = dvndo_fra.size();
	const usint longtsor  = dvsor_int.size();
	const usint longsor   = longtsor;

	// hemos dividido por los ceros del divisor (por una potencia de 10)
	// tanto divisor como dividendo, obteniendo dvndo_int y dvsor_int como
	// cocientes enteros.
	div_uno(rem,dvndo_int,dvsor_int,longtndo,longsor);
	// ahora hacemos lo mismo con el cociente de las potencias de 10 del
	// dividendo obteniendo dvndo_fra
	
	/* *
	 RemReal = RemObtenido*10^cssor + Dvndo_fra
	 * */
	
	// rehacer el resto tomando en cuenta los ceros quitados
	// acomodar el formato al signo de la operacion
	// determinar el signo de la operacion
	return dvndo_int;
}

const NumB10Str & NumB10Str::operator /= (const NumB10Str & arg) {
	abs();
	reduce();
	NumB10Str & dvndo_int = (*this);
	NumB10Str dvsor_int(arg.abs());
	NumB10Str rem(dvndo_int); rem.reduce();
	dvsor_int.reduce();
	const usint cssor = dvsor_int.ceros_a_la_izqda();
	dvsor_int.erase(0,cssor);
	NumB10Str dvndo_fra(dvndo_int.substr(0,cssor));
	dvndo_int.erase(0,cssor);
	dvsor_int.reduce();
	dvndo_int.reduce();
	dvndo_fra.reduce();
	const usint longtndo  = dvndo_int.size();
	const usint longtndo2 = dvndo_fra.size();
	const usint longtsor  = dvsor_int.size();
	const usint longsor  = longtsor;

	// hemos dividido por los ceros del divisor (por una potencia de 10)
	// tanto divisor como dividendo, obteniendo dvndo_int y dvsor_int como
	// cocientes enteros.
	div_uno(rem,dvndo_int,dvsor_int,longtndo,longsor);
	// ahora hacemos lo mismo con el cociente de las potencias de 10 del
	// dividendo obteniendo dvndo_fra
	
	/* *
	 RemReal = RemObtenido*10^cssor + Dvndo_fra
	 * */
	
	// rehacer el resto tomando en cuenta los ceros quitados
	// acomodar el formato al signo de la operacion
	// determinar el signo de la operacion
	return dvndo_int;
}
