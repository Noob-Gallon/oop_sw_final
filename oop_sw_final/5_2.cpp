#include <iostream>

using namespace std;

// Interface�� �������ϴ� Weapon Ŭ������ ������.
class Weapon {
public:
	// virtual mehod load() ����.
	virtual void load() = 0;
};

// Interface ������ �ϴ� Weapon�� ��ӹ޾Ƽ�
// load()�� �������Ѵ�.
class Bomb : public Weapon {
public:
	void load() {
		cout << "��ź�� �����մϴ�." << endl;
	}
};

// Interface ������ �ϴ� Weapon�� ��ӹ޾Ƽ�
// load()�� �������Ѵ�.
class Gun : public Weapon {
public:
	void load() {
		cout << "���� �����մϴ�." << endl;
	}
};

int main(void) {

	Bomb bomb;
	Gun gun;

	// Weapon* �迭�� ����� bomb�� gun�� �ּҸ� ����Ű�� �ϸ�
	// upcasting�� ���� load() �޼��带 �����ų �� ����.
	// �׷���, virtual method�̹Ƿ� �� �ڽ� Ŭ�������� ���ǵ�
	// load()�� �Ҹ��� �ȴ�.
	Weapon* myWeapon[2];
	myWeapon[0] = &bomb;
	myWeapon[1] = &gun;

	for (auto& _e : myWeapon) {
		_e->load();
	}

	return 0;
}