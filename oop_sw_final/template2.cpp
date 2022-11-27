#include <iostream>

using namespace std;

template <typename T>
class Box {
private:
	T data;

public:
	Box() {

	}
	Box(T _data) : data(_data) {

	}
	T& getData() {
		return data;
	}
	void setData(T _data) {
		this->data = _data;
	}
	void showData();
};

// Ŭ���� �ٱ����� �Լ��� �����ϰ� �ʹٸ�
// �̷��� �����ϸ� �ȴ�.
template<typename T>
void Box<T>::showData() {
	cout << data << endl;
}

class MyItem {
private:
	int k;

public:
	MyItem() {
		k = 99;
	}
	void showK() {
		cout << k << endl;
	}
};

int main(void) {

	// Class template�� �� ��ü�δ� instance�� ���� �� ����.
	// ����, type�� ���ؼ� Class�� �� �Ŀ� instance�� ����� �� �� �ִ�.
	// Class�� Type�� �ٸ� Ŭ������ ������ ���� �ִ�. (��ġ ������ Ŭ������ ������ ��...)
	Box<MyItem> my_box; 
	MyItem i; // �⺻ �����ڸ� �����, k = 99.
	my_box.setData(i); // �̰��� my_box�� �־��ش�.

	MyItem& v = my_box.getData(); // my_box���� �����͸� ������, v.k = 99...
	v.showK();
	return 0;
}