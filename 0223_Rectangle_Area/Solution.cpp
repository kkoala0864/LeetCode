#include <Solution.h>
#include <iostream>
#include <cmath>

using namespace std;

int Solution::computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {

	int result_width = 0;
	int result_length = 0;
	if ( ( A == B == C == D ) || ( E == F == G == H ) ) {
		result_width = ( abs(A) > abs(E) ? A : E ) - ( abs(C) > abs(G) ? C : G);
		result_length = ( abs(B) > abs(F) ? B : F ) - ( abs(D) > abs(H) ? D : H );
		return abs(result_width) * abs(result_length);
	} else {
		int cover_area = 0;
		if ((( C > E ) && ( D > F)) || ((A > G) && (B > H))) {
			result_width = ( abs(A) > abs(E) ? E : A ) - ( abs(C) > abs(G) ? G : C );
			result_length = ( abs(B) > abs(F) ? F : B ) - ( abs(D) > abs(H) ? H : D );
			cover_area = abs(result_width) * abs(result_length);
		}
		int first_area = (C - A) * ( D - B );
		int second_area = ( G - E ) * ( H - F );
		return first_area + second_area - cover_area;
	}

}

void Solution::DebugPrint() {
	cout << "This is Rectangle Area Debug Print" << endl;
}
