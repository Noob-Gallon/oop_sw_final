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

// 클래스 바깥에서 함수를 정의하고 싶다면
// 이렇게 정의하면 된다.
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

	// Class template은 그 자체로는 instance를 만들 수 없다.
	// 먼저, type을 정해서 Class를 찍어낸 후에 instance를 만들어 낼 수 있다.
	// Class의 Type은 다른 클래스로 지정될 수도 있다. (마치 데이터 클래스의 역할을 함...)
	Box<MyItem> my_box; 
	MyItem i; // 기본 생성자를 만들면, k = 99.
	my_box.setData(i); // 이것을 my_box에 넣어준다.

	MyItem& v = my_box.getData(); // my_box에서 데이터를 얻으면, v.k = 99...
	v.showK();
	return 0;
}