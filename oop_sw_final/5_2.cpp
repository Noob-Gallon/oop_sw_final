#include <iostream>

using namespace std;

class Weapon {
public:
	virtual void load() = 0;
};

class Bomb : public Weapon {
public:
	void load() {
		cout << "ÆøÅºÀ» ÀûÀçÇÕ´Ï´Ù." << endl;
	}
};

class Gun : public Weapon {
public:
	void load() {
		cout << "ÃÑÀ» ÀûÀçÇÕ´Ï´Ù." << endl;
	}
};

int main(void) {

	Bomb bomb;
	Gun gun;

	Weapon* myWeapon[2];
	myWeapon[0] = &bomb;
	myWeapon[1] = &gun;

	for (auto& _e : myWeapon) {
		_e->load();
	}

	return 0;
}