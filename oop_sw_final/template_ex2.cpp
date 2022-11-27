#include <iostream>

using namespace std;

template<typename T>
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

template<typename T>
void Box<T>::showData() {
	cout << data << endl;
}

class Item {
private:
	int k;

public:
	Item() {
		k = 999;
	}
	void showK() {
		cout << k << endl;
	}
};

int main(void) {

	Box<Item> my_box;
	Item i;
	my_box.setData(i);

	Item& v = my_box.getData();
	v.showK();

	return 0;
}