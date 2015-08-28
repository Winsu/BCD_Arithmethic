#include "DigBCD.hpp"

typedef basic_string<DigBCD> BasicNumB10Str;

class ParBCD : protected N2DigsBCD {//N2DigsBCD is the typedef of a class pair which contains two DigBCD that
		friend istream & operator >> (istream &,ParBCD);//are enum,so it's a templat class with DigBCD types
		friend ostream & operator << (ostream &,ParBCD);
	public:
		ParBCD(); // constructor por defecto
		ParBCD(DigBCD,DigBCD);
		ParBCD(const N2DigsBCD &);
		explicit ParBCD(N2DigsBCD &);
		ParBCD(uchint,uchint);
		ParBCD(char,char);
		ParBCD(const string &);
		ParBCD(int,int);
		ParBCD(const ParBCD &); // constructor copia
		explicit ParBCD(ParBCD &); // constructor copia
		const ParBCD & operator = (const ParBCD &);
		ParBCD & operator = (ParBCD &);
		operator DigBCD() const;
		bool operator == (ParBCD) const;
		bool operator != (ParBCD) const;
		bool operator <= (ParBCD) const;
		bool operator >= (ParBCD) const;
		bool operator <  (ParBCD) const;
		bool operator >  (ParBCD) const;
		ParBCD operator + (const ParBCD &) const;
		ParBCD operator - (const ParBCD &) const;
		ParBCD operator * (const ParBCD &) const;
		ParBCD operator / (const ParBCD &) const;
		ParBCD operator % (const ParBCD &) const;
		const ParBCD & operator += (const ParBCD &);
		const ParBCD & operator -= (const ParBCD &);
		const ParBCD & operator *= (const ParBCD &);
		const ParBCD & operator /= (const ParBCD &);
		const ParBCD & operator %= (const ParBCD &);
		operator usint () const; // nos da el valor en formato entero del ordenador
		ParBCD operator -  () const; // menos unario (cambio de signo, en Complemento BCD);
		ParBCD operator !  () const; // Complemento BCD menos 1
		const ParBCD & mC10  (); // auto modificación menos unario (cambio de signo, en Complemento BCD);
		const ParBCD & mC9   (); // auto modificación Complemento BCD menos 1
		const ParBCD & operator ++ ();
		ParBCD operator ++ (int);
		const ParBCD & operator -- ();
		ParBCD operator -- (int);
		DigBCD g_second() const;
		DigBCD g_first() const;
		void p_second(DigBCD);
		void p_first(DigBCD);
		ParBCD operator +  (DigBCD) const;
		ParBCD operator -  (DigBCD) const;
		ParBCD operator *  (DigBCD) const;
		ParBCD operator /  (DigBCD) const;
		ParBCD operator %  (DigBCD) const;
		const ParBCD & operator += (DigBCD);
		const ParBCD & operator -= (DigBCD);
		const ParBCD & operator *= (DigBCD);
		const ParBCD & operator /= (DigBCD);
		const ParBCD & operator %= (DigBCD);
		ParBCD operator +  (const N2DigsBCD &) const;
		ParBCD operator -  (const N2DigsBCD &) const;
		ParBCD operator *  (const N2DigsBCD &) const;
		ParBCD operator /  (const N2DigsBCD &) const;
		ParBCD operator %  (const N2DigsBCD &) const;
		const ParBCD & operator += (const N2DigsBCD &);
		const ParBCD & operator -= (const N2DigsBCD &);
		const ParBCD & operator *= (const N2DigsBCD &);
		const ParBCD & operator /= (const N2DigsBCD &);
		const ParBCD & operator %= (const N2DigsBCD &);
	};

istream & operator >> (istream & in,ParBCD arg);
ostream & operator << (ostream & on,ParBCD arg);
