/* power of two */
#include <iostream>
using namespace std;

class Solution {
public:
	bool isPowerOfTwo(int n) {
		if (n <= 0) return false;
		return !(n&(n-1));
	}
};

int main() {
	Solution s;
	cout << s.isPowerOfTwo(2) << endl;
}
