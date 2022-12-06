#include <iostream>

using namespace std;

class Person {
private:
	string name;
	string address;
	string tel;

public:
	Person(string _name, string _addr, string _tel) : name(_name), address(_addr), tel(_tel) {}
	void showMyInfo() {
		cout << "이름: " << name << endl;
		cout << "주소: " << address << endl;
		cout << "전화번호: " << tel << endl;
	}
	// getter, setter
	string getName() {
		return name;
	}
	string getAddress() {
		return address;
	}
	string getTel() {
		return tel;
	}
	void setName(string name) {
		this->name = name;
	}
	void setAddress(string address) {
		this->address = address;
	}
	void setTel(string tel) {
		this->tel = tel;
	}
};

// Customer는 Person 클래스를 상속받으며
// 추가적인 멤버변수 id와 mileage를 가진다.
// 생성자에서 부모 클래스의 멤버 변수와 자신의 멤버 변수를 초기화한다.
class Customer : public Person {
private:
	int id;
	int mileage;

public:
	Customer(string _name, string _addr, string _tel, int _id, int _mileage) : 
	Person(_name, _addr, _tel), id(_id), mileage(_mileage){}
	// 부모 클래스에서 정의된 showMyInfo()를 overloading한다.
	// 부모 클래스의 메서드를 사용하고, 새롭게 추가된 멤버 변수들에 대한
	// 동작을 추가해준다.
	void showMyInfo() {
		Person::showMyInfo();
		cout << "아이디: " << id << endl;
		cout << "마일리지: " << mileage << endl;
	}
	// getter, setter
	int getID() {
		return id;
	}
	void setID(int id) {
		this->id = id;
	}
};

int main(void) {

	Customer customer("김철수", "서울시 종로구", "010-1111-2222", 1, 1000);
	customer.showMyInfo();

	return 0;
}