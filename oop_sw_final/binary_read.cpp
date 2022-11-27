#include <iostream>
#include <fstream>

using namespace std;

int main(void) {

	int buffer[5];

	ifstream is("binary.dat", ifstream::binary);
	is.read((char*)buffer, 20);

	for (auto& _e : buffer) {
		cout << _e << endl;
	}

	return 0;
}