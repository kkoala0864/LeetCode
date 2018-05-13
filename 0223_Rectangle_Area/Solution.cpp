#include <Solution.h>

using namespace std;

int Solution::computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
	int Left = max(A,E);
	int Down = max(B,F);
	int Right = min(C, G);
	int Up = min(D, H);

	int total = (C - A) * (D - B) + (G - E) * (H - F);
	if (Up > Down && Right > Left) {
		total -= (Right - Left) * (Up - Down);
	}
	return total;
}

