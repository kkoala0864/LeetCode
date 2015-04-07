/* Quick Sort */

#include <iostream>
#include "ChaosLib.h"
#include <iterator>

using namespace std;
namespace Chaos {

static void swap ( int& input1 , int& input2 ) {
	int tmp = input1;
	input1 = input2;
	input2 = tmp;
}

static void debugprintf( vector<int> input) {
	for(vector<int>::iterator iter= input.begin() ; iter != input.end() ; ++iter) {
		cout << *iter << " ";
	}
	cout << endl;
}
void qsort(vector<int>& input, int start, int end) {
	if ( start >= end ) return;
	int pivot = start;
	int i = start + 1;
	int j = end;
	while ( true ) {
		while ( (i <= end) && (input[i] <= input[pivot]) ) {
			++i;
		}
		while ( (j > start) && (input[j] >= input[pivot] ) ) {
			--j;
		}

		if ( i > j ) {
			break;
		}
		swap(input[i], input[j]);
	}
	swap(input[start], input[j]);
	qsort(input, start, j - 1);
	qsort(input , j + 1, end);
}

} /* namespace Chaos */
