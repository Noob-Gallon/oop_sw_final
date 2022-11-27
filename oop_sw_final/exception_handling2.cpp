#include <iostream>
#include <vector>

using namespace std;

int main(void) {

	vector<int> v = { 1,2,3,4,5 };
	/*try {
		cout << v.at(0) << endl;
		cout << v.at(10) << endl;
	}
	catch (out_of_range& _e) {
		cout << "me : " << _e.what() << endl;
	}
	catch (exception& _e) {
		cout << _e.what() << endl;
	}*/

	try {
		v.resize(v.max_size() + 1);
	}
	catch (length_error& _e) {
		cout << "me : " << _e.what() << endl;
	}
	catch (out_of_range& _e) {
		cout << "me : " << _e.what() << endl;
	}
	catch (exception& _e) {
		cout << "me : " << _e.what() << endl;
	}

	cout << "Program Ended" << endl;

	return 0;
}