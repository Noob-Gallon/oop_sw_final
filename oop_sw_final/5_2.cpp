#include <iostream>

using namespace std;

// Interface의 역할을하는 Weapon 클래스를 정의함.
class Weapon {
public:
	// virtual mehod load() 선언.
	virtual void load() = 0;
};

// Interface 역할을 하는 Weapon을 상속받아서
// load()를 재정의한다.
class Bomb : public Weapon {
public:
	void load() {
		cout << "폭탄을 적재합니다." << endl;
	}
};

// Interface 역할을 하는 Weapon을 상속받아서
// load()를 재정의한다.
class Gun : public Weapon {
public:
	void load() {
		cout << "총을 적재합니다." << endl;
	}
};

int main(void) {

	Bomb bomb;
	Gun gun;

	// Weapon* 배열을 만들고 bomb과 gun의 주소를 가리키게 하면
	// upcasting에 의해 load() 메서드를 실행시킬 수 있음.
	// 그런데, virtual method이므로 각 자식 클래스에서 정의된
	// load()가 불리게 된다.
	Weapon* myWeapon[2];
	myWeapon[0] = &bomb;
	myWeapon[1] = &gun;

	for (auto& _e : myWeapon) {
		_e->load();
	}

	return 0;
}