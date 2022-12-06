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
		cout << "�̸�: " << name << endl;
		cout << "�ּ�: " << address << endl;
		cout << "��ȭ��ȣ: " << tel << endl;
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

// Customer�� Person Ŭ������ ��ӹ�����
// �߰����� ������� id�� mileage�� ������.
// �����ڿ��� �θ� Ŭ������ ��� ������ �ڽ��� ��� ������ �ʱ�ȭ�Ѵ�.
class Customer : public Person {
private:
	int id;
	int mileage;

public:
	Customer(string _name, string _addr, string _tel, int _id, int _mileage) : 
	Person(_name, _addr, _tel), id(_id), mileage(_mileage){}
	// �θ� Ŭ�������� ���ǵ� showMyInfo()�� overloading�Ѵ�.
	// �θ� Ŭ������ �޼��带 ����ϰ�, ���Ӱ� �߰��� ��� �����鿡 ����
	// ������ �߰����ش�.
	void showMyInfo() {
		Person::showMyInfo();
		cout << "���̵�: " << id << endl;
		cout << "���ϸ���: " << mileage << endl;
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

	Customer customer("��ö��", "����� ���α�", "010-1111-2222", 1, 1000);
	customer.showMyInfo();

	return 0;
}