

/* ≤‚ ‘ */


#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>


using namespace std;


class Int {
public:
	Int() : i(1) {}
	explicit operator int() const { return i; }
private:
	int i;
};


void foo(int i) {

}


int main() {

	Int i;
	foo(static_cast<int>(i));

	if (i<1)
		cout << "1" << endl;

	while (getchar());

	return 0;
}
