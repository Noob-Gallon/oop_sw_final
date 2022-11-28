#include <iostream>

using namespace std;

class Line {
public:
	int getLength(void) {
		return *ptr;
	}
	Line(int _len) {
		cout << "�Ϲ� ������, ���� : " << _len << endl;
		ptr = new int(_len);
	}
	~Line() {
		cout << "�Ҹ���" << endl;
		if (ptr != nullptr) {
			delete ptr;
		}
	}
	Line(const Line& _other) {
		cout << "���� ������" << endl;
		ptr = new int(*(_other.ptr));
	}

private:
	int* ptr = nullptr;
};

int main(void) {

	Line line1(10);

	{
		Line line2 = line1;
		cout << "line2�� ���� : " << line2.getLength() << endl;
		cout << "line2 �Ҹ�..." << endl;
	}

	cout << endl;

	cout << "line1�� ���� : " << line1.getLength() << endl;
	cout << "���� �����ڰ� �ùٸ��� ������ ���� Ȯ���� �� ����." << endl;

	return 0;
}