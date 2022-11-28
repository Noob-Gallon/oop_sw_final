#include <iostream>

using namespace std;

class Line {
public:
	int getLength(void) {
		return *ptr;
	}
	Line(int _len) {
		cout << "일반 생성자, 길이 : " << _len << endl;
		ptr = new int(_len);
	}
	~Line() {
		cout << "소멸자" << endl;
		if (ptr != nullptr) {
			delete ptr;
		}
	}
	Line(const Line& _other) {
		cout << "복사 생성자" << endl;
		ptr = new int(*(_other.ptr));
	}

private:
	int* ptr = nullptr;
};

int main(void) {

	Line line1(10);

	{
		Line line2 = line1;
		cout << "line2의 길이 : " << line2.getLength() << endl;
		cout << "line2 소멸..." << endl;
	}

	cout << endl;

	cout << "line1의 길이 : " << line1.getLength() << endl;
	cout << "복사 생성자가 올바르게 동작한 것을 확인할 수 있음." << endl;

	return 0;
}