include "tipos_basicos.hpp"

template< const uchint B > class dig_t {
	public:
		typedef std::pair< dig_t<B> , dig_t<B> > dig_t<B>::n2digs_t;
	private:
		uchint m_d;
	public:
		dig_t<B>(uchint a=0):m_d(a%B) {}
		dig_t<B>(const dig_t<B> & a):m_d(a.m_d) {}
		dig_t operator = (uchint a) {
			m_d=(a%B);
			return (*this);
		}
		dig_t operator = (dig_t<B> a) {
			m_d=(a.m_d);
			return (*this);
		}
		inline uchint operator()() {
			return (m_d);
		}
		inline bool operator == (uchint a) const {
			return ((a%B)==m_d)? true : false;
		}
		inline bool operator == (dig_t<B> a) const {
				return  ((a.m_d)==m_d)? true : false;
			}
		inline bool operator != (uchint a) const {
				return ((a%B)!=m_d)? true : false;
			}
		inline bool operator != (dig_t<B> a) const {
				return ((a.m_d)!=m_d)? true : false;
			}
		inline bool operator <= (uchint a) const {
				return ((a%B)<=m_d)? true : false;
			}
		inline bool operator <= (dig_t<B> a) const {
				return ((a.m_d)<=m_d)? true : false;
			}
		inline bool operator <  (uchint a) const {
				return  ((a%B) < m_d)? true : false;
			}
		inline bool operator <  (dig_t<B> a) const {
				return  ((a.m_d) < m_d )? true : false;
			}
		inline bool operator >= (uchint a) const {
				return  ((a%B) >= m_d)? true : false;
			}
		inline bool operator >= (dig_t<B> a) const {
				return  ( (a.m_d) >= m_d )? true : false;
			}
		inline bool operator >  (uchint a) const {
				return  ((a%B)> m_d)? true : false;
			}
		inline bool operator >  (dig_t<B> a) const {
				return  ((a.m_d) >  m_d )? true : false;
			}
		inline dig_t<B> operator +=(dig_t<B> arg) {
			m_d += arg.m_d;
			m_d%=B;
			return (*this);
		}
		inline dig_t<B> operator +=(uchint arg) {
			m_d+=(arg%B);
			m_d%=B;
			return (*this);
		}
		inline dig_t<B> operator -=(dig_t<B> arg) {
			ssint t=m_d;
			t-=arg.m_d;
			if (t < 0) t += B;
			t%=B;
			m_d=t;
			return (*this);
		}
		inline dig_t<B> operator -=(uchint arg)
			ssint t=m_d;
			t-=(arg%B);
			if (t < 0) t += B;
			t%=B;
			m_d=t;
			return (*this);
		}
		inline dig_t<B> operator *=(dig_t<B> arg) {
			m_d *= arg.m_d;
			m_d %= B;
			return (*this);
		}
		inline dig_t<B> operator *=(uchint arg) {
			m_d*=(arg%B);
			m_d%=B;
			return (*this);
		}
		inline dig_t<B> operator /=(dig_t<B> arg) {
			m_d/=arg.m_d;
			return (*this);
		}
		inline dig_t<B> operator /=(uchint arg) {
			m_d/=(arg%B);
			return (*this);
		}
		inline dig_t<B> operator %=(dig_t<B> arg) {
			m_d%=arg.m_d;
			return (*this);
		}
		inline dig_t<B> operator %=(uchint arg) {
			m_d%=(arg%B);
			return (*this);
		}
		inline dig_t<B> operator ++ () {
			m_d+=1;
			m_d%=B;
			return(*this);
		}
		inline dig_t<B> operator ++ (int) {
			dig_t<B> t(*this);
			t.m_d+=1;
			t.m_d%=B;
			return t;
		}
		inline dig_t<B> operator -- () {
			m_d-=1;
			m_d%=B;
			return(*this);
		}
		inline dig_t<B> operator -- (int) {
			dig_t<B> t(*this);
			t.m_d-=1;
			t.m_d%=B;
			return t;
		}
		inline dig_t<B> operator + (dig_t<B> arg) const {
			dig_t<B> ret(*this);
			(ret.m_d)+=(arg.m_d);
			(ret.m_d)%=B;
			return (ret);
		}
		inline dig_t<B> operator - (dig_t<B> arg) const {
			m_d%=B;
			dig_t<B> ret(*this);
			(ret.m_d)-=((arg.m_d)%B);
			(ret.m_d)%=B;
			return (ret);
		}
		inline dig_t<B> operator * (dig_t<B> arg) const {
			m_d%=B;
			dig_t<B> ret(*this);
			(ret.m_d)*=((arg.m_d)%B);
			(ret.m_d)%=B;
			return (ret);
		}
		inline dig_t<B> operator / (dig_t<B> arg) const {
			m_d%=B;
			dig_t<B> ret(*this);
			(ret.m_d)/=((arg.m_d)%B);
			(ret.m_d)%=B;
			return (ret);
		}
		inline dig_t<B> operator % (dig_t<B> arg) const {
			m_d%=B;
			dig_t<B> ret(*this);
			(ret.m_d)%=((arg.m_d)%B);
			(ret.m_d)%=B;
			return (ret);
		}
		inline dig_t<B> operator + (uchint arg) const {
			m_d%=B;
			dig_t<B> ret(*this);
			(ret.m_d)+=(arg%B);
			(ret.m_d)%=B;
			return (ret);
		}
		inline dig_t<B> operator - (uchint arg) const {
			m_d%=B;
			dig_t<B> ret(*this);
			(ret.m_d)-=(arg%B);
			(ret.m_d)%=B;
			return (ret);
		}
		inline dig_t<B> operator * (uchint arg) const {
			m_d%=B;
			dig_t<B> ret(*this);
			(ret.m_d)*=(arg%B);
			(ret.m_d)%=B;
			return (ret);
		}
		inline dig_t<B> operator / (uchint arg) const {
			m_d%=B;
			dig_t<B> ret(*this);
			(ret.m_d)/=(arg%B);
			(ret.m_d)%=B;
			return (ret);
		}
		inline dig_t<B> operator % (uchint arg) const {
			m_d%=B;
			dig_t<B> ret(*this);
			(ret.m_d)%=(arg%B);
			(ret.m_d)%=B;
			return (ret);
		}

		inline n2digs_t DivRem (dig_t a) {
			return n2digs_t(((m_d/a.m_d)%B),((m_d%a.m_d)%B));
		}
		inline dig_t Sig() const {
				return (dig_t(m_d+1));
			}
		inline dig_t Pre() const {
				return dig_t((m_d==0)?B-1:m_d-1);
			}
		template<const uchint> friend
		inline dig_t DivB(n2digs_t arg) {
			return arg.first();
		}
		template<const uchint> friend
		inline dig_t RemB(n2digs_t arg) {
			return arg.second();
		}

		inline char Dig2Char() const {
				return static_cast<char>(m_d);
			}
		template<const uchint> friend
		inline dig_t Char2Dig(char arg) {
			return dig_t(static_cast<uchint>(arg));
		}

		inline uchint Dig2UInt() const {
				return (m_d);
			}
		template<const uchint> friend
		inline dig_t UInt2Dig(uchint arg) {
			return dig_t(arg);
		}

		inline int Dig2Int() {
			return static_cast<int>(m_d);
		}
		template<const uchint> friend
		inline dig_t Int2Dig(int arg) {
			return dig_t(static_cast<uchint>(arg));
		}

		template<const uchint> friend
		istream & operator >> (istream & is,dig_t & arg) {
			uchint t;
			is >> t;
			arg.m_d=(t%B);
			return is;
		}
		template<const uchint> friend
		ostream & operator << (ostream & os,dig_t arg) {
			os << ((arg.m_d)%B);
			return os;
		}

	};
