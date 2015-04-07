#include "ChaosLib.h"
#include "main.h"
#include <iterator>
#include <iostream>

using namespace std;

void debugprintf(vector<int> input) {
	for ( vector<int>::iterator iter = input.begin() ; iter != input.end() ; ++iter ) {
		cout << *iter << " ";
	}
	cout << endl;
}



int main(void) {
	vector<int> input = {2, 6, 8, 9, 4, 7};
	debugprintf(input);
	Chaos::qsort(input, 0, input.size() - 1);
	debugprintf(input);

}
