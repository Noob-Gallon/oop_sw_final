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
};

class Customer : public Person {
private:
	int id;
	int mileage;

public:
	Customer(string _name, string _addr, string _tel, int _id, int _mileage) : 
	Person(_name, _addr, _tel), id(_id), mileage(_mileage)
	{

	}
	void showMyInfo() {
		Person::showMyInfo();
		cout << "아이디: " << id << endl;
		cout << "마일리지: " << mileage << endl;
	}
};

int main(void) {

	Customer customer("김철수", "서울시 종로구", "010-1111-2222", 1, 1000);
	customer.showMyInfo();

	return 0;
}