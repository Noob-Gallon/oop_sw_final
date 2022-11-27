#include <iostream>

using namespace std;

template<typename T>
T get_max(T x, T y) {
	if (x > y) {
		return x;
	}
	else {
		return y;
	}
}

int main(void) {

	cout << get_max(3, 4) << endl;
	cout << get_max(3.5, 4.5) << endl;

	return 0;
}