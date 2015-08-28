num op_bin {pp,mm,Sig,Pre,p,m,x,d,r,assign,passign,massign,xassing,dassing,rassign,lt,leqt,gt,geqt,eq,neq};
enum op_una {minus,CB,CBm1,inv};

template< class T1 , class T2 >
class TestBench {
private:
	T1							 	obj_clase_1;
	T2  						 	obj_clase_2;
	// procedimiento de recorrer dos variables
//	void foreach_v1_v2(bool TestBench::*MethodPtr() arg) {
//		for(int i=0 ; i < obj_clase_1.max() ; ++i) {
//			for(int j=0 ; j < obj_clase_2.max ; ++j) {
//			}
//		}
//	}
	// procedimiento de recorrer una variable
//	void foreach_v1_v2(bool TestBench::*MethodPtr() arg) {
//		for(int i=0 ; i < obj_clase_1.max() ; ++i) {
//		}
//	}

public:
	TestBench(T1 a=T1(),T2 b=T2()):obj_clase_1(a),obj_clase_2(b) {}
	bool test_suma();
	bool test_resta();
	bool test_multiplicacion();
	bool test_division();
	bool test_resto();
	bool test_asignacion();
	bool test_suma_asignacion();
	bool test_resta_asignacion();
	bool test_multiplicacion_asignacion();
	bool test_division_asignacion();
	bool test_resto_asignacion();
	bool test_pre_incremento();
	bool test_pre_decremento();
	bool test_post_incremento();
	bool test_post_decremento();
	bool test_Sig();
	bool test_Pre();
	bool test_lt();   // less than <
	bool test_leqt(); // less or equal than <=
	bool test_gt();   // greater than >
	bool test_geqt(); // greater or equal than >=
	bool test_eq();   // equal than ==
	bool test_noteq();// not equal than !=
	bool test_compl10();
	bool test_compl09();
	bool test_compl10_asignacion();
	bool test_compl09_asignacion();
	bool test_conversiones();
};
