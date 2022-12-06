#include <iostream>

using namespace std;

// Line 클래스는 생성자로 입력받은 수를
// 동적할당 받은 int*에 저장한다.
class Line {
public:
	int getLength(void) {
		return *ptr;
	}
	// 생성자에서 길이 변수를 입력받아서
	// 동작할당받은 ptr 변수에 넣어준다.
	Line(int _len) {
		cout << "일반 생성자, 길이 : " << _len << endl;
		ptr = new int(_len);
	}
	// 동적할당 받은 메모리를 소멸자에서 해제.
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

	// 소멸자에서 메모리 해제가 올바르게 동작하는지 체크
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