#include <ChaosBase.h>

class Solution : public ChaosBase
{
	public :
		Solution() {}
		bool canWinNim(int n);
		void DebugPrint();
	private :
		Solution(const Solution&);
		Solution& operator=(const Solution& source);
};
