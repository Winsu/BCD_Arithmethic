#include "ParBCD.hpp"


using namespace std;

ParBCD::ParBCD() {
	second = c;
	first  = c;
}

ParBCD::ParBCD(DigBCD decenas,DigBCD unidades) {
	second = decenas;
	first  = unidades;
}

ParBCD::ParBCD(uchint decenas,uchint unidades) {
	second = (Nat2Dig(decenas));
	first  = (Nat2Dig(unidades));
}

ParBCD::ParBCD(char decenas,char unidades) {
	second = (Char2Dig(decenas));
	first  = (Char2Dig(unidades));
}

ParBCD::ParBCD(int decenas,int unidades) {
	second = (Int2Dig(decenas));
	first  = (Int2Dig(unidades));
}

ParBCD::ParBCD(const N2DigsBCD & arg) {
	second = (arg.second);
	first  = (arg.first);
}

ParBCD::ParBCD(N2DigsBCD & arg) {
	second = (arg.second);
	first  = (arg.first);
}

ParBCD::ParBCD(const ParBCD & arg) {
	second = (arg.second);
	first  = (arg.first);
}

ParBCD::ParBCD(ParBCD & arg) {
	second = (arg.second);
	first  = (arg.first);
}

ParBCD::ParBCD(const string & arg) {
	second = Char2Dig(arg.at(1));
	first  = Char2Dig(arg.at(0));
}

ParBCD::operator usint () const { 
		return (Dig2Int(first)+(Dig2Int(second)*10));
	} 

ParBCD ParBCD::operator -() const { 
		ParBCD cpy(*this);
		cpy.first = !first;
		cpy.second = !second;
		++cpy;
		return cpy;
	}

ParBCD ParBCD::operator !  () const { 
		ParBCD cpy(*this);
		cpy.first = !first;
		cpy.second = !second;
		return cpy;
	} 

const ParBCD & ParBCD::mC10  () { 
	first = !first;
	second = !second;
	++(*this);
	return (*this);
} 

const ParBCD & ParBCD::mC9   () { 
	first = !(first);
	second = !(second);
	return (*this);
} 

const ParBCD & ParBCD::operator = (const ParBCD & arg) {
	first=arg.first;
	second=arg.second;
	return (*this);
}

ParBCD & ParBCD::operator = (ParBCD & arg) {
	first=arg.first;
	second=arg.second;
	return (*this);
}

bool ParBCD::operator == (ParBCD arg) const {
		if ((second==arg.second)&&(first==arg.first)) return true;
		else return false;
	}

bool ParBCD::operator != (ParBCD arg) const {
		if ((second!=arg.second)||(first!=arg.first)) return true;
		else return false;
	}

bool ParBCD::operator <= (ParBCD arg) const {
		if (second < arg.second) return true;
		else if (second > arg.second) return false;
		else {
				if (first <=  arg.first) return true;
				else return false;
			}
	}

bool ParBCD::operator >= (ParBCD arg) const {
		if (second > arg.second) return true;
		else if (second < arg.second) return false;
		else {
				if (first >=  arg.first) return true;
				else return false;
			}
	}

bool ParBCD::operator <  (ParBCD arg) const {
		if (second < arg.second) return true;
		else if (second > arg.second) return false;
		else {
				if (first <  arg.first) return true;
				else return false;
			}
	}

bool ParBCD::operator >  (ParBCD arg) const {
		if (second > arg.second) return true;
		else if (second < arg.second) return false;
		else {
				if (first > arg.first) return true;
				else return false;
			}
	}

ParBCD ParBCD::operator + (const ParBCD & arg) const {
		ParBCD ret(*this);
		uchint retuds = Dig2Nat(ret.first);
		uchint retdecs = Dig2Nat(ret.second);
		uchint arguds = Dig2Nat(arg.first);
		uchint argdecs = Dig2Nat(arg.second);
		retuds += arguds;
		if (retuds > 9) {
				retuds -= 10;
				++ retdecs;
			}
		retdecs += argdecs;
		ret.second = Nat2Dig(retdecs);
		ret.first = Nat2Dig(retuds);
		return ret;
	}

ParBCD ParBCD::operator - (const ParBCD & arg) const {
		ParBCD ret(*this);
		uchint retuds = Dig2Nat(ret.first);
		uchint retdecs = Dig2Nat(ret.second);
		uchint rettot  = (retuds+(10*retdecs))%100;
		uchint arguds = Dig2Nat(arg.first);
		uchint argdecs = Dig2Nat(arg.second);
		uchint argtot  = (arguds+(10*argdecs))%100;

		if (rettot < argtot) {
				argtot = 100-argtot;
				rettot += argtot;
				retuds = Nat2Dig(rettot%10);
				retdecs = Nat2Dig((rettot/10)%10);
				ret.second = Nat2Dig(retdecs);
				ret.first = Nat2Dig(retuds);
				return ret;
			} else if (rettot == argtot) {
				ret.second = c;
				ret.first  = c;
				return ret;
			} else {
				rettot -= argtot;
				retuds = Nat2Dig(rettot%10);
				retdecs = Nat2Dig((rettot/10)%10);
				ret.second = Nat2Dig(retdecs);
				ret.first = Nat2Dig(retuds);
				return ret;
			}
	}

ParBCD ParBCD::operator * (const ParBCD & arg) const {
		ParBCD ret(*this);
		uchint retuds = Dig2Nat(ret.first);
		uchint retdecs = Dig2Nat(ret.second);
		uchint arguds = Dig2Nat(arg.first);
		uchint argdecs = Dig2Nat(arg.second);
		uchint mult_low,mult_high;
		mult_low = (retuds * arguds);
		mult_high = (retdecs * arguds)+(retuds * argdecs);

		retuds = mult_low % 10;
		retdecs = ((mult_low/10)+mult_high)%10;
		ret.second = Nat2Dig(retdecs);
		ret.first = Nat2Dig(retuds);
		return ret;
	}

ParBCD ParBCD::operator / (const ParBCD & arg) const {
		ParBCD ret(*this);
		uchint retuds = Dig2Nat(ret.first);
		uchint retdecs = Dig2Nat(ret.second);
		uchint arguds = Dig2Nat(arg.first);
		uchint argdecs = Dig2Nat(arg.second);
		uchint cociente,resto;

		if ((arg.second == c)&&(arg.first == c)) {
				ret.second = E;
				ret.first = E;
				return ret;
			} else {
				retuds += (10*retdecs);
				arguds += (10*argdecs);
				retuds /= arguds;
				retdecs = retuds;
				retdecs /= 10;
				retdecs %= 10;
				retuds %= 10;
				ret.second = Nat2Dig(retdecs);
				ret.first = Nat2Dig(retuds);
				return ret;
			}
	}

ParBCD ParBCD::operator % (const ParBCD & arg) const {
		ParBCD ret(*this);
		uchint retuds = Dig2Nat(ret.first);
		uchint retdecs = Dig2Nat(ret.second);
		uchint arguds = Dig2Nat(arg.first);
		uchint argdecs = Dig2Nat(arg.second);
		uchint cociente,resto;

		if ((arg.second == c)&&(arg.first == c)) {
				ret.second = E;
				ret.first = E;
				return ret;
			} else {
				retuds += (10*retdecs);
				arguds += (10*argdecs);
				retuds %= arguds;
				retdecs = retuds;
				retdecs /= 10;
				retuds %= 10;
				ret.second = Nat2Dig(retdecs);
				ret.first = Nat2Dig(retuds);
				return ret;
			}
	}

const ParBCD & ParBCD::operator += (const ParBCD & arg) {
	ParBCD ret(*this);
	uchint retuds = Dig2Nat(ret.first);
	uchint retdecs = Dig2Nat(ret.second);
	uchint arguds = Dig2Nat(arg.first);
	uchint argdecs = Dig2Nat(arg.second);
	retuds += arguds;
	
	if (retuds > 9) {
			retuds -= 10;
			++ retdecs;
		}
	retdecs += argdecs;
	second = Nat2Dig(retdecs);
	first = Nat2Dig(retuds);
	return (*this);
}

const ParBCD & ParBCD::operator -= (const ParBCD & arg) {
	ParBCD ret(*this);
	uchint retuds = Dig2Nat(ret.first);
	uchint retdecs = Dig2Nat(ret.second);
	uchint rettot = (retuds+(10*retdecs))%100;
	uchint arguds = Dig2Nat(arg.first);
	uchint argdecs = Dig2Nat(arg.second);
	uchint argtot = (arguds+(10*argdecs))%100;

	if (rettot < argtot) {
			argtot = 100 - argtot;
			rettot += argtot;
			rettot %= 100;
			first = Nat2Dig(rettot % 10);
			second = Nat2Dig((rettot / 10)%10);
			return (*this);
		} else if (rettot == argtot) {
			first = c;
			second = c;
			return (*this);
		} else {
			rettot -= argtot;
			rettot %= 100;
			first = Nat2Dig(rettot % 10);
			second = Nat2Dig((rettot / 10)%10);
			return (*this);
		}
}

const ParBCD & ParBCD::operator *= (const ParBCD & arg) {
	ParBCD ret(*this);
	uchint retuds = Dig2Nat(ret.first);
	uchint retdecs = Dig2Nat(ret.second);
	uchint arguds = Dig2Nat(arg.first);
	uchint argdecs = Dig2Nat(arg.second);
	uchint mult_low,mult_high;
	
	mult_low = (retuds * arguds); 
	mult_high = (retdecs * arguds)+(retuds * argdecs);
	retuds = mult_low % 10;
	retdecs = ((mult_low/10)+mult_high)%10;
	
	second = Nat2Dig(retdecs);
	first = Nat2Dig(retuds);
	return (*this);
}

const ParBCD & ParBCD::operator /= (const ParBCD & arg) {
	ParBCD ret(*this);
	uchint retuds = Dig2Nat(ret.first);
	uchint retdecs = Dig2Nat(ret.second);
	uchint arguds = Dig2Nat(arg.first);
	uchint argdecs = Dig2Nat(arg.second);
	uchint cociente,resto;

	if ((arg.second == c)&&(arg.first == c)) {
			second = E;
			first = E;
			return (*this);
		} else {
			retuds += (10*retdecs);
			arguds += (10*argdecs);
			retuds /= arguds;
			retdecs = retuds;
			retdecs /= 10;
			retuds %= 10;
			second = Nat2Dig(retdecs);
			first = Nat2Dig(retuds);
			return (*this);
		}
}

const ParBCD & ParBCD::operator %= (const ParBCD & arg) {
	ParBCD ret(*this);
	uchint retuds  = Dig2Nat(ret.first);
	uchint retdecs = Dig2Nat(ret.second);
	uchint arguds  = Dig2Nat(arg.first);
	uchint argdecs = Dig2Nat(arg.second);
	uchint cociente,resto;

	if ((arg.second == c)&&(arg.first == c)) {
			second = E;
			first = E;
			return (*this);
		} else {
			retuds += (10*retdecs);
			arguds += (10*argdecs);
			retuds %= arguds;
			retdecs = retuds;
			retdecs /= 10;
			retuds %= 10;
			second = Nat2Dig(retdecs);
			first = Nat2Dig(retuds);
			return (*this);
		}
}

ParBCD ParBCD::operator + (const N2DigsBCD & arg) const {
		ParBCD ret(*this);
		uchint retuds = Dig2Nat(ret.first);
		uchint retdecs = Dig2Nat(ret.second);
		uchint arguds = Dig2Nat(arg.first);
		uchint argdecs = Dig2Nat(arg.second);
		retuds += arguds;
		if (retuds > 9) {
				retuds -= 10;
				++ retdecs;
			}
		retdecs += argdecs;
		ret.second = Nat2Dig(retdecs);
		ret.first = Nat2Dig(retuds);
		return ret;
	}

ParBCD ParBCD::operator - (const N2DigsBCD & arg) const {
		ParBCD ret(*this);
		uchint retuds = Dig2Nat(ret.first);
		uchint retdecs = Dig2Nat(ret.second);
		uchint rettot  = (retuds+(10*retdecs))%100;
		uchint arguds = Dig2Nat(arg.first);
		uchint argdecs = Dig2Nat(arg.second);
		uchint argtot  = (arguds+(10*argdecs))%100;

		if (rettot < argtot) {
				argtot = 100-argtot;
				rettot += argtot;
				retuds = Nat2Dig(rettot%10);
				retdecs = Nat2Dig((rettot/10)%10);
				ret.second = Nat2Dig(retdecs);
				ret.first = Nat2Dig(retuds);
				return ret;
			} else if (rettot == argtot) {
				ret.second = c;
				ret.first  = c;
				return ret;
			} else {
				rettot -= argtot;
				retuds = Nat2Dig(rettot%10);
				retdecs = Nat2Dig((rettot/10)%10);
				ret.second = Nat2Dig(retdecs);
				ret.first = Nat2Dig(retuds);
				return ret;
			}
	}

ParBCD ParBCD::operator * (const N2DigsBCD & arg) const {
		ParBCD ret(*this);
		uchint retuds = Dig2Nat(ret.first);
		uchint retdecs = Dig2Nat(ret.second);
		uchint arguds = Dig2Nat(arg.first);
		uchint argdecs = Dig2Nat(arg.second);
		uchint mult_low,mult_high;
		mult_low = (retuds * arguds);
		mult_high = (retdecs * arguds)+(retuds * argdecs);

		retuds = mult_low % 10;
		retdecs = ((mult_low/10)+mult_high)%10;
		ret.second = Nat2Dig(retdecs);
		ret.first = Nat2Dig(retuds);
		return ret;
	}


ParBCD ParBCD::operator / (const N2DigsBCD & arg) const {
		ParBCD ret(*this);
		uchint retuds = Dig2Nat(ret.first);
		uchint retdecs = Dig2Nat(ret.second);
		uchint arguds = Dig2Nat(arg.first);
		uchint argdecs = Dig2Nat(arg.second);
		uchint cociente,resto;

		if ((arg.second == c)&&(arg.first == c)) {
				ret.second = E;
				ret.first = E;
				return ret;
			} else {
				retuds += (10*retdecs);
				arguds += (10*argdecs);
				retuds /= arguds;
				retdecs = retuds;
				retdecs /= 10;
				retdecs %= 10;
				retuds %= 10;
				ret.second = Nat2Dig(retdecs);
				ret.first = Nat2Dig(retuds);
				return ret;
			}
	}

ParBCD ParBCD::operator % (const N2DigsBCD & arg) const {
		ParBCD ret(*this);
		uchint retuds = Dig2Nat(ret.first);
		uchint retdecs = Dig2Nat(ret.second);
		uchint arguds = Dig2Nat(arg.first);
		uchint argdecs = Dig2Nat(arg.second);
		uchint cociente,resto;

		if ((arg.second == c)&&(arg.first == c)) {
				ret.second = E;
				ret.first = E;
				return ret;
			} else {
				retuds += (10*retdecs);
				arguds += (10*argdecs);
				retuds %= arguds;
				retdecs = retuds;
				retdecs /= 10;
				retuds %= 10;
				ret.second = Nat2Dig(retdecs);
				ret.first = Nat2Dig(retuds);
				return ret;
			}
	}

const ParBCD & ParBCD::operator += (const N2DigsBCD & arg) {
	ParBCD ret(*this);
	uchint retuds = Dig2Nat(ret.first);
	uchint retdecs = Dig2Nat(ret.second);
	uchint arguds = Dig2Nat(arg.first);
	uchint argdecs = Dig2Nat(arg.second);
	retuds += arguds;
	if (retuds > 9) {
			retuds -= 10;
			++ retdecs;
		}
	retdecs += argdecs;
	second = Nat2Dig(retdecs);
	first = Nat2Dig(retuds);
	return (*this);
}

const ParBCD & ParBCD::operator -= (const N2DigsBCD & arg) {
	ParBCD ret(*this);
	uchint retuds = Dig2Nat(ret.first);
	uchint retdecs = Dig2Nat(ret.second);
	uchint rettot = (retuds+(10*retdecs))%100;
	uchint arguds = Dig2Nat(arg.first);
	uchint argdecs = Dig2Nat(arg.second);
	uchint argtot = (arguds+(10*argdecs))%100;

	if (rettot < argtot) {
			argtot = 100 - argtot;
			rettot += argtot;
			rettot %= 100;
			first = Nat2Dig(rettot % 10);
			second = Nat2Dig((rettot / 10)%10);
			return (*this);
		} else if (rettot == argtot) {
			first = c;
			second = c;
			return (*this);
		} else {
			rettot -= argtot;
			rettot %= 100;
			first = Nat2Dig(rettot % 10);
			second = Nat2Dig((rettot / 10)%10);
			return (*this);
		}
}

const ParBCD & ParBCD::operator *= (const N2DigsBCD & arg) {
	ParBCD ret(*this);
	uchint retuds = Dig2Nat(ret.first);
	uchint retdecs = Dig2Nat(ret.second);
	uchint arguds = Dig2Nat(arg.first);
	uchint argdecs = Dig2Nat(arg.second);
	uchint mult_low,mult_high;
	mult_low = (retuds * arguds);
	mult_high = (retdecs * arguds)+(retuds * argdecs);

	retuds = mult_low % 10;
	retdecs = ((mult_low/10)+mult_high)%10;
	second = Nat2Dig(retdecs);
	first = Nat2Dig(retuds);
	return (*this);
}

const ParBCD & ParBCD::operator /= (const N2DigsBCD & arg) {
	ParBCD ret(*this);
	uchint retuds = Dig2Nat(ret.first);
	uchint retdecs = Dig2Nat(ret.second);
	uchint arguds = Dig2Nat(arg.first);
	uchint argdecs = Dig2Nat(arg.second);
	uchint cociente,resto;

	if ((arg.second == c)&&(arg.first == c)) {
			second = E;
			first = E;
			return (*this);
		} else {
			retuds += (10*retdecs);
			arguds += (10*argdecs);
			retuds /= arguds;
			retdecs = retuds;
			retdecs /= 10;
			retuds %= 10;
			second = Nat2Dig(retdecs);
			first = Nat2Dig(retuds);
			return (*this);
		}
}

const ParBCD & ParBCD::operator %= (const N2DigsBCD & arg) {
	ParBCD ret(*this);
	uchint retuds  = Dig2Nat(ret.first);
	uchint retdecs = Dig2Nat(ret.second);
	uchint arguds  = Dig2Nat(arg.first);
	uchint argdecs = Dig2Nat(arg.second);
	uchint cociente,resto;

	if ((arg.second == c)&&(arg.first == c)) {
			second = E;
			first = E;
			return (*this);
		} else {
			retuds += (10*retdecs);
			arguds += (10*argdecs);
			retuds %= arguds;
			retdecs = retuds;
			retdecs /= 10;
			retuds %= 10;
			second = Nat2Dig(retdecs);
			first = Nat2Dig(retuds);
			return (*this);
		}
}


ParBCD ParBCD::operator + (DigBCD arg) const {
		ParBCD ret(*this);
		uchint retuds = Dig2Nat(ret.first);
		uchint retdecs = Dig2Nat(ret.second);
		uchint arguds = Dig2Nat(arg);

		retuds += arguds;
		if (retuds > 9) {
				retuds -= 10;
				++ retdecs;
			}

		ret.second = Nat2Dig(retdecs);
		ret.first = Nat2Dig(retuds);
		return ret;
	}

ParBCD ParBCD::operator - (DigBCD arg) const {
		ParBCD ret(*this);
		uchint retuds = Dig2Nat(ret.first);
		uchint retdecs = Dig2Nat(ret.second);
		uchint rettot  = (retuds+(10*retdecs));
		uchint argtot = Dig2Nat(arg);

		if (rettot < argtot) {
				argtot = 100-argtot;
				rettot += argtot;
				retuds = Nat2Dig(rettot%10);
				retdecs = Nat2Dig((rettot/10)%10);
				ret.second = Nat2Dig(retdecs);
				ret.first = Nat2Dig(retuds);
				return ret;
			} else if (rettot == argtot) {
				ret.second = c;
				ret.first  = c;
				return ret;
			} else {
				rettot -= argtot;
				retuds = Nat2Dig(rettot%10);
				retdecs = Nat2Dig((rettot/10)%10);
				ret.second = Nat2Dig(retdecs);
				ret.first = Nat2Dig(retuds);
				return ret;
			}
	}

ParBCD ParBCD::operator * (DigBCD arg) const {
		ParBCD ret(*this);
		uchint retuds = Dig2Nat(ret.first);
		uchint retdecs = Dig2Nat(ret.second);
		uchint argtot = Dig2Nat(arg);
		uchint mult_low,mult_high;
		mult_low = (retuds * argtot);
		mult_high = (retdecs * argtot);

		retuds = mult_low % 10;
		retdecs = ((mult_low/10)+mult_high)%10;
		ret.second = Nat2Dig(retdecs);
		ret.first = Nat2Dig(retuds);
		return ret;
	}

ParBCD ParBCD::operator / (DigBCD arg) const {
		ParBCD ret(*this);
		uchint retuds = Dig2Nat(ret.first);
		uchint retdecs = Dig2Nat(ret.second);
		uchint argtot = Dig2Nat(arg);
		uchint cociente,resto;

		if (arg == c) {
				ret.second = E;
				ret.first = E;
				return ret;
			} else {
				retuds += (10*retdecs);
				retuds /= argtot;
				retdecs = retuds;
				retdecs /= 10;
				retdecs %= 10;
				retuds %= 10;
				ret.second = Nat2Dig(retdecs);
				ret.first = Nat2Dig(retuds);
				return ret;
			}
	}

ParBCD ParBCD::operator % (DigBCD arg) const {
		ParBCD ret(*this);
		uchint retuds = Dig2Nat(ret.first);
		uchint retdecs = Dig2Nat(ret.second);
		uchint argtot = Dig2Nat(arg);
		uchint cociente,resto;

		if (arg == c) {
				ret.second = E;
				ret.first = E;
				return ret;
			} else {
				retuds += (10*retdecs);
				retuds %= argtot;
				retdecs = retuds;
				retdecs /= 10;
				retuds %= 10;
				ret.second = Nat2Dig(retdecs);
				ret.first = Nat2Dig(retuds);
				return ret;
			}
	}

const ParBCD & ParBCD::operator += (DigBCD arg) {
	ParBCD ret(*this);
	uchint retuds = Dig2Nat(ret.first);
	uchint retdecs = Dig2Nat(ret.second);
	uchint argtot = Dig2Nat(arg);

	retuds += argtot;
	if (retuds > 9) {
			retuds -= 10;
			++ retdecs;
		}

	second = Nat2Dig(retdecs);
	first = Nat2Dig(retuds);
	return (*this);
}

const ParBCD & ParBCD::operator -= (DigBCD arg) {
	ParBCD ret(*this);
	uchint retuds = Dig2Nat(ret.first);
	uchint retdecs = Dig2Nat(ret.second);
	uchint rettot = (retuds+(10*retdecs))%100;
	uchint argtot = Dig2Nat(arg);

	if (rettot < argtot) {
			argtot = 100 - argtot;
			rettot += argtot;
			rettot %= 100;
			first = Nat2Dig(rettot % 10);
			second = Nat2Dig((rettot / 10)%10);
			return (*this);
		} else if (rettot == argtot) {
			first = c;
			second = c;
			return (*this);
		} else {
			rettot -= argtot;
			rettot %= 100;
			first = Nat2Dig(rettot % 10);
			second = Nat2Dig((rettot / 10)%10);
			return (*this);
		}
}

const ParBCD & ParBCD::operator *= (DigBCD arg) {
	ParBCD ret(*this);
	uchint retuds = Dig2Nat(ret.first);
	uchint retdecs = Dig2Nat(ret.second);
	uchint argtot = Dig2Nat(arg);
	uchint mult_low,mult_high;
	mult_low = (retuds * argtot);
	mult_high = (retdecs * argtot);

	retuds = mult_low % 10;
	retdecs = ((mult_low/10)+mult_high)%10;
	second = Nat2Dig(retdecs);
	first = Nat2Dig(retuds);
	return (*this);
}

const ParBCD & ParBCD::operator /= (DigBCD arg) {
	ParBCD ret(*this);
	uchint retuds = Dig2Nat(ret.first);
	uchint retdecs = Dig2Nat(ret.second);
	uchint argtot = Dig2Nat(arg);
	uchint cociente,resto;

	if (arg == c) {
			second = E;
			first = E;
			return (*this);
		} else {
			retuds += (10*retdecs);
			retuds /= argtot;
			retdecs = retuds;
			retdecs /= 10;
			retuds %= 10;
			second = Nat2Dig(retdecs);
			first = Nat2Dig(retuds);
			return (*this);
		}
}

const ParBCD & ParBCD::operator %= (DigBCD arg) {
	ParBCD ret(*this);
	uchint retuds  = Dig2Nat(ret.first);
	uchint retdecs = Dig2Nat(ret.second);
	uchint argtot  = Dig2Nat(arg);
	uchint cociente,resto;

	if (arg == c) {
			second = E;
			first = E;
			return (*this);
		} else {
			retuds += (10*retdecs);
			retuds %= argtot;
			retdecs = retuds;
			retdecs /= 10;
			retuds %= 10;
			second = Nat2Dig(retdecs);
			first = Nat2Dig(retuds);
			return (*this);
		}
}

const ParBCD & ParBCD::operator ++ () {
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

ParBCD ParBCD::operator ++ (int) {
	ParBCD thism(*this);
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

const ParBCD & ParBCD::operator -- () {
	if (first > c) {
			--first;
			return (*this);
		} else if (first == c) {
			first = n;
			--second;
			return (*this);
		} else {
			first = E;
			second = E;
			return (*this);
		}
}

ParBCD ParBCD::operator -- (int) {
	ParBCD thism(*this);
	if (thism.first > c) {
			--(thism.first);
			(*this)=thism;
			return (thism);
		} else if (thism.first == c) {
			thism.first = n;
			--(thism.second);
			(*this)=thism;
			return thism;
		} else {
			thism.first = E;
			thism.second = E;
			(*this)=thism;
			return thism;
		}
}

DigBCD ParBCD::g_second() const {
		return second;
	}

DigBCD ParBCD::g_first() const {
		return first;
	}

void ParBCD::p_second(DigBCD arg) {
	second = arg;
	return;
}

void ParBCD::p_first(DigBCD arg) {
	first = arg;
	return;
}

ParBCD::operator DigBCD() const {
		return first;
	}

istream & operator >> (istream & in,ParBCD & arg) {
	char C,D;
	uchint decenas,unidades;
	in >> C;
	in >> D;
	if ((('0'-1)<C)&&(C<('9'+1))and(('0'-1)<C)&&(C<('9'+1))) {
			decenas =C-'0';
			unidades =C-'0';
		} else {
			decenas=255;
			unidades=255;
		}
	arg.p_second(Nat2Dig(decenas));
	arg.p_first(Nat2Dig(unidades));
	return in;
}

ostream & operator << (ostream & on,ParBCD arg) {
	on  <<Dig2Char(arg.g_second())
	<< Dig2Char(arg.g_first());
	return on;
}
