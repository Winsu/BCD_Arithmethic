#include "ParBCD.hpp"

using namespace std;

enum sign_e {p,m};
sign_e Char2Sign(char);
sign_e Int2Sign (int);
sign_e Nat2Sign (uchint);

class SParBCD : protected ParBCD {
		friend istream & operator >> (istream &,SParBCD);
		friend ostream & operator << (ostream &,SParBCD);
	private:
		sign_e		 signo;
	public:
		SParBCD(); // constructor por defecto
		SParBCD(DigBCD,DigBCD);
		SParBCD(sign_e,DigBCD,DigBCD);
		SParBCD(uchint,uchint);
		SParBCD(uchint,uchint,uchint);
		SParBCD(char,char);
		SParBCD(char,char,char);
		SParBCD(const string &);
		SParBCD(int,int);
		SParBCD(int,int,int);
		SParBCD(const SParBCD &); // constructor copia
		explicit SParBCD(SParBCD &); // constructor copia
		const SParBCD & operator = (const SParBCD &);
		SParBCD & operator = (SParBCD &);
		SParBCD(const ParBCD &); // constructor copia
		explicit SParBCD(ParBCD &); // constructor copia
		SParBCD(const N2DigsBCD &); // constructor copia
		explicit SParBCD(N2DigsBCD &); // constructor copia
		operator N2DigsBCD() const;
		operator ParBCD() const;
		operator DigBCD() const;
		SParBCD abs() const;
		bool operator == (SParBCD) const;
		bool operator != (SParBCD) const;
		bool operator <= (SParBCD) const;
		bool operator >= (SParBCD) const;
		bool operator <  (SParBCD) const;
		bool operator >  (SParBCD) const;
		SParBCD operator + (const SParBCD &)const;
		SParBCD operator - (const SParBCD &)const;
		SParBCD operator * (const SParBCD &)const;
		SParBCD operator / (const SParBCD &)const;
		SParBCD operator % (const SParBCD &)const;
		const SParBCD & operator += (const SParBCD &);
		const SParBCD & operator -= (const SParBCD &);
		const SParBCD & operator *= (const SParBCD &);
		const SParBCD & operator /= (const  SParBCD &);
		const SParBCD & operator %= (const  SParBCD &);
		operator ssint () const; // nos da el valor en formato entero del ordenador
		operator usint () const; // nos da el valor en formato entero del ordenador
		SParBCD operator -  () const; // menos unario (cambio de signo, en Complemento BCD);
		SParBCD operator !  () const; // Complemento BCD menos 1
		const SParBCD & mC10  (); // auto modificación menos unario (cambio de signo, en Complemento BCD);
		const SParBCD & mC9   (); // auto modificación Complemento BCD menos 1
		const SParBCD & operator ++ ();
		SParBCD operator ++ (int);
		const SParBCD & operator -- ();
		SParBCD operator -- (int);
		DigBCD g_second() const;
		DigBCD g_first() const;
		void p_second(DigBCD);
		void p_first(DigBCD);
		sign_e g_sign() const;
		void p_sign(sign_e arg);
		SParBCD operator +  (DigBCD) const;
		SParBCD operator -  (DigBCD) const;
		SParBCD operator *  (DigBCD) const;
		SParBCD operator /  (DigBCD) const;
		SParBCD operator %  (DigBCD) const;
		const SParBCD & operator += (DigBCD);
		const SParBCD & operator -= (DigBCD);
		const SParBCD & operator *= (DigBCD);
		const SParBCD & operator /= (DigBCD);
		const SParBCD & operator %= (DigBCD);
		SParBCD operator +  (N2DigsBCD) const;
		SParBCD operator -  (N2DigsBCD) const;
		SParBCD operator *  (N2DigsBCD) const;
		SParBCD operator /  (N2DigsBCD) const;
		SParBCD operator %  (N2DigsBCD) const;
		const SParBCD & operator += (N2DigsBCD);
		const SParBCD & operator -= (N2DigsBCD);
		const SParBCD & operator *= (N2DigsBCD);
		const SParBCD & operator /= (N2DigsBCD);
		const SParBCD & operator %= (N2DigsBCD);
		SParBCD operator +  (ParBCD) const;
		SParBCD operator -  (ParBCD) const;
		SParBCD operator *  (ParBCD) const;
		SParBCD operator /  (ParBCD) const;
		SParBCD operator %  (ParBCD) const;
		const SParBCD & operator += (ParBCD);
		const SParBCD & operator -= (ParBCD);
		const SParBCD & operator *= (ParBCD);
		const SParBCD & operator /= (ParBCD);
		const SParBCD & operator %= (ParBCD);
	};

istream & operator >> (istream & in,SParBCD arg);
ostream & operator << (ostream & on,SParBCD arg);
