include "ParBCD.hpp"
#include <iostream>
using namespace std;

int main(int argc, char **argv) {
	cout << boolalpha ;
		//Inizialization of A and B to execute examples.
		DigBCD A=o;								
		DigBCD B=o;								
	/*
	// *****************************************************************
		for(uchint k=0; k<10; ++k) {cout << A;A=Sig(A);}//It displays an Ascii code, doing a proceed from
		cout << endl;									//DigBCD to char and obtaining a range Ascii code from 
		for(uchint k=0; k<10; ++k) {cout << A;A=Pre(A);}//' to i(it means from 0 to 9)
		cout << endl;									
	// *************************************************************************************************
		
		
	// *************************************************************************************************
	for(uchint k=0; k<10; ++k)
	
		{
			if (A!=c)				//Divide a digit in BCD by two and obtain his quotient and his remainder
				cout << A <<"/2=" << Div2(A) << " and " << 
				A << "%2 = " << Rem2(A) << " ; " << endl; 
				A=Sig(A);
		}
		cout << endl;
	// *************************************************************************************************
		
	// *************************************************************************************************	
	for(uchint k=0; k<10; ++k)
		{
			cout << A << " + c=" << A+c << "; +u=" << A+u << " + d=" << A+d << " + t=" << A+t
			     << " + q=" << A+q << " + z=" << A+z << " + x=" << A+x << " + s=" << A+s
				 << " + o=" << A+o<< " + n=" << A+n << " ;; " << endl;

			A=Sig(A);
		}//Display the sum between two DigBCD and It returns a N2DigsBCD (a pair oif DigBCD)
		cout << endl;
	// **********************************************************************************************
	// **********************************************************************************************	
		for(uchint k=0; k<10; ++k)
		{
			cout <<A << " - c=" << A-c << "; -u=" << A-u << " - d=" << A-d << " - t=" << A-t
			     << " - q=" << A-q << " - z=" << A-z << " - x=" << A-x << " - s=" << A-s
				 << " - o=" << A-o<< " - n=" << A-n << " ;; " << endl;

			A=Sig(A);
		}//Display the subtraction between two DigBCD and whe the result is negative It displays EE			
					
		cout << endl;
	// **************************************************************************************
		
	// **********************************************************************************************
		A=c;B=c;
		for(uchint k=0; k<10; ++k)
		{
			for(uchint j=0; j<10; ++j)
			{
				cout << " A=" << A << " y B=" << B << " A+B=" << A+B << " y A-B=" << A-B << endl;
				A=Sig(A);
			}
			B=Sig(B);
		}
		cout << endl;//Display the result between two DigBCD, returning a N2DigsBCD  and being EE when the result is negative
	// *********************************************************************************************************************
		
	// *****************************************************************************************************************
		A=c;B=c;
		for(uchint k=0; k<10; ++k)
			for(uchint j=0; j<10; ++j)
			{
				cout << " A=" << A << " y B=" << B << " A*B=" << A*B << endl;
				B=Sig(B);
			}
			A=Sig(A);
		}//Multiply two DigBCD and return one N2DigsBCD
		cout << endl;
	// ********************************************************************************************************************
		
	// *******************************************************************************************************************
		
	// ********************************************************************************************************************
		A=c;B=c;
		for(uchint k=0; k<10; ++k)
		{
			for(uchint j=0; j<10; ++j)
			{							
				if (B!=c)
					cout << " A=" << A << " y B=" << B << " A/B=" << A/B << endl;
				B=Sig(B);
			}
			A=Sig(A);
		}//It divides two DigBCD and return a DigBCD giving the quotient of the operation
		cout << endl;
	// *******************************************************************************************************************
		
	// *******************************************************************************************************************
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
		}//It divides two DigBCD and return a DigBCD giving the rest of the operation
		cout << endl;
	// ********************************************************************************************************************
		
		
	// ******************************************************************************************************************
		A=n;B=c;
		for(uchint k=0; k<10; ++k)		
		{
			cout << " A=" << A << " y A/2=" << Div2(A) << endl;
			A=Sig(A);
		}//Divide a DigBCD by two and get a DigBCD as his quotient
		cout << endl;
	// ********************************************************************************************************************
		
	// ********************************************************************************************************************
		
		A=o;B=c;
		for(uchint k=0; k<10; ++k)
		{
			cout << " A=" << A << " y A/2=" << Rem2(A) << endl;
			A=Sig(A);						
		}
		cout << endl;
		//Divide a DigBCD by two and get a DigBCD as his remaidenr
	// ********************************************************************************************************************
		
		
	// ********************************************************************************************************************
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
		//Compare two DigBCD with this premise  "<=" and return a boolean.
	// *******************************************************************************************************************
	// *******************************************************************************************************************
		A=s;B=c;
		for(uchint k=0; k<10; ++k)
		{
			for(uchint j=0; j<10; ++j)
			{
				cout << " A=" << A << " y B=" << B << " y A<B es " << (A<B) << endl;
				B=Sig(B);
			}
			A=Sig(A);
		}
		cout << endl;
		//Compare two DigBCD with this premise  "<" and return a boolean.
	// ********************************************************************************************************************
	// ********************************************************************************************************************
		
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
		//Compare two DigBCD with this premise  ">=" and return a boolean.
	// ********************************************************************************************************************
		
	// ********************************************************************************************************************
		
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
		
		//Compare two DigBCD with this premise  ">=" and return a boolean.
	// ********************************************************************************************************************
		
		
	// ********************************************************************************************************************
		A=c;B=c;
		for(uchint k=0; k<10; ++k)
		{							
			cout << " A=" << A << " y char(A)=" << Dig2Char(A) << endl;
			A=Sig(A);
		}// It displays the relation between BCD code and integers(expresed like chars) being ' = 0, a = 1,b = 2...
		cout << endl;
	// **************************************************************************************************************************
		
		
	// **************************************************************************************************************************
		
		A=c;B=c;
		for(char k = numeric_limits<char>::min(); k < numeric_limits<char>::max(); k=k+1)
		{	
			cout << " A=" << A << " y dig(k)=" << Char2Dig(k) << endl;
			A=Char2Dig(k);
			
		}
		cout << endl;
		//k goes a long the whole char range and it displays a DigBCD when k is on a known value by the program.
		//If it is on an unknown value it will display u.
	// ********************************************************************************************************************************
		
	// *********************************************************************************************************************************
		
		A=c;B=c;
		for(uchint k = numeric_limits<uchint>::min(); k < numeric_limits<uchint>::max(); k=k+1)
		{
			cout<<k;
			cout << " A=" << A << " y dig(k)=" << Nat2Dig(k) << endl;
			A=Nat2Dig(k);					
		}								 
		cout << endl;
		//Uchint has a range from 0 to 255 and Nat2Dig is able to convert an uchint in a DigBCD.
		//It shows a range from 0 to 9 in BCD simbols. 
	// ********************************************************************************************************************************
	// **********************************************************************************************************************
		*/
		ParBCD AA(c,c); 
		ParBCD BB(AA); 
		for(uchint k=0; k<25; ++k) 
			{cout << AA;++AA;cout << endl;}
		cout << endl;
		for(uchint k=0; k<26; ++k){
			cout << AA;
			--AA;
			cout << endl;
		}
		cout << endl;
		//ParBCD contains the methods to treat N2DigsBCD
		//This section displays a range of ParBCD increasing and decreasing their values.
	/*
	// ***********************************************************************************************************************
	// *******************************************************************************************************
		
		ParBCD AA;
		AA=ParBCD(c,o);
		for(uchint k=0; k<100; ++k)
		{			
			cout << AA << "; /2=" << (AA/ParBCD(c,d)) << "; y %2=" << (AA%ParBCD(c,d)) << " ;; " << endl;
			++AA;
		}
		//ParBCD is divided by two increasing his value as manny times as k is set and obtaining his coefficient
		cout <<endl;// and his remainder.
	// *******************************************************************************************************
	// ********************************************************************************************************
		
		ParBCD AA,BB;
		ParBCD CC;
		for( AA=ParBCD(p,c,c) ; AA < ParBCD(m,o,o) ; ++AA )
		{	
			
			for( BB=ParBCD(p,c,c) ; BB < ParBCD(p,o,o) ; ++BB )
			{
				CC = AA;
				CC+=BB;
				cout << AA << " + " << BB <<  " => "   << CC << " ; " << endl;
			}
		}
		cout << endl;
		//Addition of two ParBCD.When the result is bigger than 99 It displays E on the second digit.
		
	// *****************************************************************************************************************************
		
		ParBCD AA,BB,CC;
		for( AA=ParBCD(p,d,d) ; AA < ParBCD(p,t,t) ; ++AA )
		{
				
			for( BB=ParBCD(p,u,u) ; BB < ParBCD(p,u,n) ; ++BB )
			{
				
				
				CC = AA;
				CC-=BB;
				cout << AA << " - " << BB <<  " => "   << CC << " ; " << endl;//
			}
		}
		//Subtraction of two ParBCD, when the result is a negative number the result is transformed to a One's complement without 
		//having in consideration the sign in the CC - BB operation.
		cout << endl;
		
	// *****************************************************************************************************************************
	// ****************************************************************************************************************************
		
		 ParBCD AA,BB,CC;
		for( AA=ParBCD(c,u) ; AA < ParBCD(u,c) ; ++AA )
		{
			CC=AA;
			for( BB=ParBCD(c,u) ; BB < ParBCD(q,c) ; ++BB )
			{
				CC = AA;
				CC*=BB;
				cout << AA << " * " << BB <<  " => "   << CC << " ; " << endl;
			}
		}
		cout << endl;
		//Multiplication between two ParBCD, It can not represent more than two digit(a ParBCD or a number bigger than 99), 
		//so It can not display a result with three digit, nevertheless the digits obtained are right.
	// ****************************************************************************************************************************
	// ****************************************************************************************************************************
		
		
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
		//Division betwenn two ParBCD, the result is the quotient
	// *****************************************************************************************************************************
		
		ParBCD AA,BB,CC;
		for( AA=ParBCD(c,u) ; AA < ParBCD(n,n) ; ++AA )
		{
			CC=AA;
			for( BB=ParBCD(c,u) ; BB < ParBCD(n,n) ; ++BB )
			{
				CC = AA;
				CC%=BB;
				cout << AA << " % " << BB <<  " => "   << CC << " ; " << endl;
			}
		}
		cout << endl;
		//Division between two ParBCD, the result is the remainder	
	// *****************************************************************************************************************************
		
		
	
	// ****************************************************************************************************************************
	const ParBCD cero = ParBCD(c,c);
	const ParBCD uno  = ParBCD(c,u);
	const ParBCD diez = ParBCD(u,c);
	const ParBCD doce = ParBCD(u,d);
	const ParBCD veinte = ParBCD(d,c);
	const ParBCD noventaynueve = ParBCD(n,n);
	//Several const are declared
	// *********************************************************************************************************************************
	
	
	// *********************************************************************************************************************************
	ParBCD PP = cero; 
	ParBCD ZZ = cero;
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
	
	PP=doce;
	ZZ=diez;
	cout << "PP==" << PP << " y ZZ==" << ZZ <<  " y  ZZ < PP es "   << (ZZ < PP) << " ; " << endl;
	//There are several comparisons between two ParBCD.
	// *********************************************************************************************************************************
	
	*/
	return 0;
}
