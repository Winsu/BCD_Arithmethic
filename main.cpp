#include "ParBCD.hpp"

#include <iostream>
using namespace std;

int main(int argc, char **argv) {
	cout << boolalpha ;
												//c as other letter means c= cero u = 1, spanish numbers
		DigBCD A=d;								//this block go along two function Sig and Pre and visit each case of
		DigBCD B=o;								// a switch(), the cases are ready to return a char with the next case
		/*
		for(uchint k=0; k<10; ++k) {cout << A;A=Sig(A);}
		cout << endl;							//look at DigBCD.hpp
		for(uchint k=0; k<10; ++k) {cout << A;A=Pre(A);}
		cout << endl;
		
		for(uchint k=0; k<10; ++k)
		{
			if (A!=c)
				cout << A << "; /2=" << Div2(A) << "; y %2=" << Rem2(A) << " ;; " << endl; //divide the number by 2 like / and %

			A=Sig(A);		//get the next number
		}
		cout << endl;
		
		for(uchint k=0; k<10; ++k)
		{
			cout << A << " + c=" << A+c << "; +u=" << A+u << " + d=" << A+d << " + t=" << A+t// I dont knoe why operator <<A
			     << " + q=" << A+q << " + z=" << A+z << " + x=" << A+x << " + s=" << A+s// return i, there must be a casting
				 << " + o=" << A+o<< " + n=" << A+n << " ;; " << endl;

			A=Sig(A);//what this for does is plus a number at any number from 0 to 9,but cout << A has an unexpected behaviour
		}
		cout << endl;
		
		for(uchint k=0; k<10; ++k)
		{
			cout << A << " - c=" << A-c << "; -u=" << A-u << " - d=" << A-d << " - t=" << A-t
			     << " - q=" << A-q << " - z=" << A-z << " - x=" << A-x << " - s=" << A-s
				 << " - o=" << A-o<< " - n=" << A-n << " ;; " << endl;

			A=Sig(A);//It divides the number by a number from 0 to 9, when the result is negative It returns EE
		}			//It's because when operator - return a N2DigsBCD, it return two char EE...
					//******I have to look at that better 
		cout << endl;
		
		
		A=c;B=c;
		for(uchint k=0; k<10; ++k)//this for follow the same logic with DigBCD + DigBCD and DigBCD-DigBCD
		{
			for(uchint j=0; j<10; ++j)
			{
				cout << " A=" << A << " y B=" << B << " A+B=" << A+B << "y A-B=" << A-B << endl;
				A=Sig(A);
			}
			B=Sig(B);
		}
		cout << endl;
		
		
		A=c;B=c;
		for(uchint k=0; k<10; ++k)//this for multiply A times B
		{							//it returns a N2DigsBCD 
			for(uchint j=0; j<10; ++j)
			{
				cout << " A=" << A << " y B=" << B << " A*B=" << A*B << endl;
				B=Sig(B);
			}
			A=Sig(A);
		}
		cout << endl;
		
		
		A=c;B=c;
		for(uchint k=0; k<10; ++k)
		{
			for(uchint j=0; j<10; ++j)//t divides A by B It return a DigBCD...the same happemns,It returns a char
			{							//and I dont know why return that kind of char 
				if (B!=c)
					cout << " A=" << A << " y B=" << B << " A/B=" << A/B << endl;
				B=Sig(B);
			}
			A=Sig(A);
		}
		cout << endl;
		
		A=c;B=c;
		for(uchint k=0; k<10; ++k)
		{
			for(uchint j=0; j<10; ++j)
			{
				if (B!=c)
					cout << " A=" << A << " y B=" << B << " A%B=" << A%B << endl;
				B=Sig(B);
			}
			A=Sig(A);
		}
		cout << endl;
		
		A=n;B=c;
		for(uchint k=0; k<10; ++k)		//this for divide by 2 it return a,b,c,d,e which values are 1,2,3..
		{
			cout << " A=" << A << " y A/2=" << Div2(A) << endl;
			A=Sig(A);
		}
		cout << endl;
		
		
		A=o;B=c;
		for(uchint k=0; k<10; ++k)
		{
			cout << " A=" << A << " y A/2=" << Rem2(A) << endl;//divide the number by 2 like this %
			A=Sig(A);						//it returns a,b,c,...
		}
		cout << endl;

		
		A=x;B=c;
		for(uchint k=0; k<10; ++k)
		{
			for(uchint j=0; j<10; ++j)//operator <= returns a boolean value comparing A versus B
			{
				cout << " A=" << A << " y B=" << B << " y A<=B es " << (A<=B) << endl;
				B=Sig(B);
			}
			A=Sig(A);
		}
		cout << endl;
		
	 	A=s;B=c;
		for(uchint k=0; k<10; ++k)
		{
			for(uchint j=0; j<10; ++j)//the same thna the last one
			{
				cout << " A=" << A << " y B=" << B << " y A<B es " << (A<B) << endl;
				B=Sig(B);
			}
			A=Sig(A);
		}
		cout << endl;
		
		
		A=c;B=c;
		for(uchint k=0; k<10; ++k)//the same than the last one
		{
			for(uchint j=0; j<10; ++j)
			{
				cout << " A=" << A << " y B=" << B << " y A>=B es " << (A>=B) << endl;
				B=Sig(B);
			}
			A=Sig(A);
		}
		cout << endl;
		
		
		
		A=c;B=c;
		for(uchint k=0; k<10; ++k)//the same than the last one
		{
			for(uchint j=0; j<10; ++j)
			{
				cout << " A=" << A << " y B=" << B << " y A>B es " << (A>B) << endl;
				B=Sig(B);
			}
			A=Sig(A);
		}
		cout << endl;
		
		A=c;B=c;
		for(uchint k=0; k<10; ++k)//here is showed the char characters are used as a numbers
		{							//Dig2char(DigBCD a) it plus two charcarter,being `0` + '0' ? #96 ascii 
			cout << " A=" << A << " y char(A)=" << Dig2Char(A) << endl;//equivalent to '`', and '1'+'0' = #97 ascii 'a'
			A=Sig(A);
		}
		cout << endl;
		
		
		A=c;B=c;
		
		for(char k = numeric_limits<char>::min(); k < numeric_limits<char>::max(); k=k+1)
		{//numeric_limits is a template that gives information about the types that we are
		//using,it goes along the whole ASCII code...operator << uses Dig2Char,so 
		//it return the default value that is E which code ascii value plused to '0' always gives 'u'
		//it's always like that until k gets a value that Dig2Char has a case which cointains that value
		//the default value in Char2Dig is E too, so the result is the same...	
			cout << " A=" << A << " y dig(k)=" << Char2Dig(k) << endl;
			A=Char2Dig(k);
			
		}
		cout << endl;
		
		
		A=c;B=c;
		
		for(uchint k = numeric_limits<uchint>::min(); k < numeric_limits<uchint>::max(); k=k+1)//uchint stars from 0 to 255 more..
		{
			cout << " A=" << A << " y dig(k)=" << Nat2Dig(k) << endl;//Nat2Dig changes the numeric starting from 0 to 255
			A=Nat2Dig(k);					//to char value 0 = c,1 = u etc..as Nat2Dig assigns to A his value
										//we'll have in A the same than in Nat2Dig in one iteration minus;
										//the key of this for is that Nat2Dig returns a DigBCD that operator << can 
		}								//understand because uchint k stars from 0 and it changes that to c,so the 
		cout<< count;					//the rest is the same since It goes through the operator << with a DigBCD
		
		
		cout << endl;// ParPCB has no member named fg_m_cifra
		uchint uA=0;
		const ParBCD Q(c,u);
		for(ParBCD K(c,c); K.fg_m_cifra() <= Nat2Dig(9); K=K.fg_m_cifra()+u)
		{
			uA=Dig2Nat(K.fg_m_cifra());
			cout << " A=" << char(uA+'0') << " y dig(k)=A con k=" << K.fg_m_cifra() << endl;
			if (uA==9) break;
		}
		cout << endl;
		
		//**********Here we start using the class ParBCD 
		ParBCD AA(c,c); //operator << for ParBCD is supported by a member function of 
		ParBCD BB(AA); //ParBCD which returns first or second,from that point it calls to a Dig2Char with a DigBCD
		for(uchint k=0; k<10; ++k) {cout << AA;++AA;}//It's the same than with DigBCD but doing a step more
		cout << endl;//operator ++ for ParBCD increase first until 9 after that increase second too,
		for(uchint k=0; k<11; ++k) {cout << AA;--AA;}//here is 11 because AA comes out from
		cout << endl;//increasing his value due to ++AA and not AA++
		
		
		ParBCD AA;
		
		AA=ParBCD(c,o);
		for(uchint k=0; k<100; ++k)//here to do a normal division / and rest division %
		{			//In a BCD object like (c,o)  first is o and second is otherwise it wont work
			cout << AA << "; /2=" << (AA/ParBCD(c,d)) << "; y %2=" << (AA%ParBCD(c,d)) << " ;; " << endl;
			++AA;//It needs to be understood in a better way.
		}
		

		
		for( uchint k=0 ; k < 12 ; ++k)
		{
			for( uchint j=0 ; j < 12 ; ++j)	//ParBCD has no member named fp_m_cifra
			{
				AA.fp_m_cifra(Nat2Dig(k%10));AA.fp_m_carry(Nat2Dig(k/10));
				BB.fp_m_cifra(Nat2Dig(j%10));BB.fp_m_carry(Nat2Dig(j/10));
				cout << AA << " =AA ; " << BB <<  " =BB ; "  << "AA + BB = " << AA+BB << endl;
			}
		}
		cout << endl;
		
		
		for( uchint k=0 ; k < 12 ; ++k)
		{
			for( uchint j=0 ; j < 12 ; ++j)
			{
				AA.fp_m_cifra(Nat2Dig(k%10));AA.fp_m_carry(Nat2Dig(k/10)); //ParBCD has no member named fp_m_cifra
				BB.fp_m_cifra(Nat2Dig(j%10));BB.fp_m_carry(Nat2Dig(j/10));//ParBCD has no member named fp_m_carry
				cout << AA << " - " << BB <<  " = "   << AA-BB << " ; " << endl;
			}
		}
		cout << endl;
		
		for( uchint k=0 ; k < 10 ; ++k)
		{
			for( uchint j=0 ; j < 10 ; ++j)
			{
				AA.fp_m_cifra(Nat2Dig(k%10));AA.fp_m_carry(Nat2Dig(k/10));//ParBCD has no member named fp_m_cifra
				BB.fp_m_cifra(Nat2Dig(j%10));BB.fp_m_carry(Nat2Dig(j/10));//ParBCD has no member named fp_m_carry
				cout << AA << " * " << BB <<  " = "   << AA*BB << " ; " << endl;
			}
		}
		cout << endl;

		
		ParBCD AA,BB;
		for( uchint k=0 ; k < 10 ; ++k)
		{
			for( uchint j=0 ; j < 10 ; ++j)
			{
				AA.fp_m_cifra(Nat2Dig(k%10));AA.fp_m_carry(Nat2Dig(k/10));//ParBCD has no member named fp_m_carry
				BB.fp_m_cifra(Nat2Dig(j%10));BB.fp_m_carry(Nat2Dig(j/10));
				cout << AA << " / " << BB <<  " = "   << ( (BB==ParBCD(c,c)) ? ParBCD(E,E) : (AA/BB)) << " ; " << endl;
			}
		}
		cout << endl;
		/*
		ParBCD AA,BB;//addiction of BCD	 numbers
		ParBCD CC;//It can just plus until 49 + 49 because if a higer number is plused a ParBCD can not represnt it
		for( AA=ParBCD(c,c) ; AA < ParBCD(n,n) ; ++AA )
		{	
			CC=AA;//when a result higher than 99 is represented it uses a E,check what's a E
			for( BB=ParBCD(c,c) ; BB < ParBCD(n,n) ; ++BB )
			{//E is the default value, It comes out when a uchit is bigger than 9..
				CC = AA;//I have added this
				CC+=BB;//what happend is that the function is calling through CC as a this
				cout << AA << " + " << BB <<  " => "   << CC << " ; " << endl;//then It kept the last result as a CC
			}
		}
		cout << endl;
	
		
		ParBCD AA,BB,CC;
		for( AA=ParBCD(c,u) ; AA < ParBCD(u,n) ; ++AA )
		{
			CC=AA;
			for( BB=ParBCD(c,c) ; BB < ParBCD(u,n) ; ++BB )
			{
				CC = AA;//I have added this
				CC-=BB;//Insteead of representing negative values -1 is equivalent to 99 and -2 to 98 
				cout << AA << " - " << BB <<  " => "   << CC << " ; " << endl;//
			}//It's represintg negatives substracting to 100 a number and plusing it to the other one
		}
		cout << endl;
		
		 
		ParBCD AA,BB,CC;
		for( AA=ParBCD(c,u) ; AA < ParBCD(u,c) ; ++AA )//this function can not represent a multiplication bigger
		{//than 100 because ParBCD just have two digits
			CC=AA;//the last digit is omited, but the other part of the multiplication is well done
			for( BB=ParBCD(c,u) ; BB < ParBCD(q,c) ; ++BB )
			{
				CC = AA;//I have added this
				CC*=BB;
				cout << AA << " * " << BB <<  " => "   << CC << " ; " << endl;
			}
		}
		cout << endl;
		
		ParBCD AA,BB,CC;
		for( AA=ParBCD(c,u) ; AA < ParBCD(n,n) ; ++AA )
		{
			CC=AA;
			for( BB=ParBCD(c,u) ; BB < ParBCD(n,n) ; ++BB )
			{
				CC = AA;//I have added this
				CC/=BB;
				cout << AA << " / " << BB <<  " => "   << CC << " ; " << endl;
			}
		}
		cout << endl;
		
		ParBCD AA,BB,CC;
		for( AA=ParBCD(c,u) ; AA < ParBCD(n,n) ; ++AA )
		{
			CC=AA;
			for( BB=ParBCD(c,u) ; BB < ParBCD(n,n) ; ++BB )
			{
				CC = AA;//I have added this
				CC%=BB;//as It is the rest of t a division is possible to represent until 99
				cout << AA << " % " << BB <<  " => "   << CC << " ; " << endl;
			}
		}
		cout << endl;
		*/
	
		
		
		/*
		//bool operator == (ParBCD) const;
		//bool operator != (ParBCD) const;
		//bool operator <= (ParBCD) const;
		//bool operator >= (ParBCD) const;
		//bool operator <  (ParBCD) const;
		//bool operator >  (ParBCD) const;
	//From here I have changed AA to PP and BB to ZZ
*/		
	ParBCD PP(u,u); //this was before than PP was AA
	ParBCD ZZ(u,d); //this was before than ZZ was BB
	
	const ParBCD cero = ParBCD(c,c);
	const ParBCD uno  = ParBCD(c,u);
	const ParBCD diez = ParBCD(u,c);
	const ParBCD doce = ParBCD(u,d);
	const ParBCD veinte = ParBCD(d,c);
	const ParBCD noventaynueve = ParBCD(n,n);
	cout << PP << " ; " << ZZ << endl;
	
	
	
	
	for ( PP=cero ; PP < doce ; ++PP ) {
			for ( ZZ=cero ; ZZ < doce ; ++ZZ ) {
					cout << PP << "==" << ZZ <<  " es "   << (PP==ZZ) << " ; " << endl;
				}
		}
	cout << endl;

	
	for ( PP=cero ; PP < doce ; ++PP ) {
			for ( ZZ=cero ; ZZ < doce ; ++ZZ ) {
					cout << PP << "!=" << ZZ <<  " es "   << (PP!=ZZ) << " ; " << endl;
				}
		}
	cout << PP << " ; " << ZZ << endl << endl;
	PP=doce;
	ZZ=diez;
	cout << "PP==" << PP << " y ZZ==" << ZZ <<  " y "   << (ZZ < PP) << " ; " << endl;
	
	
	return 0;
}
