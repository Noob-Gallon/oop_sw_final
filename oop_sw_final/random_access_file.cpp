#include <iostream>
#include <fstream>

using namespace std;

int main(void) {

	ifstream is("binary.dat", ifstream::binary);

	int v;
	// seekg는 읽는 포인터.
	is.seekg(4, ios::beg); // seek + get. file pointer를 n byte 만큼 옮겨서
	is.read((char*)&v, 4); // 데이터를 n byte 읽는다.

	cout << "value is : " << v << endl; // 한 번 읽고나면, 포인터는 20의 끝 부분에 위치한다.

	// ------------------------------------------------------------------------------------ //

	is.seekg(4, ios::cur); // 현재 포인터를 기준으로 4 바이트만큼 이동한다. 20의 끝, 
	// 즉, 30의 첫부분에서 4바이트 이동하므로, 40의 첫 부분으로 간다.
	is.read((char*)&v, 4); // 4바이트를 읽는다.
	
	cout << "value is : " << v << endl; // 40이 읽힘.

	// ------------------------------------------------------------------------------------ //

	is.seekg(-4, ios::end);
	is.read((char*)&v, 4);

	cout << "value is : " << v << endl; // 끝에서 4바이트 앞으로 가고, 다시 4바이트 읽으므로, 50.

	// ------------------------------------------------------------------------------------ //

	// 쓰는 포인터는 seekp이다.
	return 0;
}