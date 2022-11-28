#include <iostream>
#include <ctime>

#define INTERVAL 1

using namespace std;

class GameCharacter {
public:
	GameCharacter() {} // ������ ������?
	virtual void draw() = 0;
};

class Hobbit : public GameCharacter {
public:
	void draw() {
		cout << "ȣ���� ȭ�鿡 �׸��ϴ�..." << endl;
	}
};

class Socerer : public GameCharacter {
public:
	void draw() {
		cout << "�ּ��縦 ȭ�鿡 �׸��ϴ�..." << endl;
	}
};

int main(void) {

	GameCharacter* myCharacters[2];
	
	Hobbit h;
	Socerer s;

	myCharacters[0] = &h;
	myCharacters[1] = &s;
	
	while (1) {

		for (auto& _e : myCharacters) {
			_e->draw();
		}
		
		clock_t start = clock();

		// �ֱ������� ȣ��
		while (1) {
			clock_t end = clock();

			if (double(end - start) / CLOCKS_PER_SEC == INTERVAL) {
				break;
			}
		}
	}

	return 0;
}