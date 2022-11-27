#include <iostream>
#include <fstream>

using namespace std;

int main(void) {

	int buffer[] = { 10, 20, 30, 40, 50 };
	char buffer2[] = { 'a', 'b', 'c', 'd', 'e' };

	// binary file은 이와 같이 쓸 수 있다...
	ofstream os("binary.dat", ofstream::binary);
	os.write((char*)buffer, sizeof(buffer));

	os = ofstream("binary2.dat", ofstream::binary);
	os.write(buffer2, 5);

	return 0;
}