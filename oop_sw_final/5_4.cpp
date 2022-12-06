#include <iostream>
#include <ctime>

#define INTERVAL 1

using namespace std;

// GameCharacter �θ� Ŭ���� ����
class GameCharacter {
public:
	GameCharacter() {}
	// ���� ���� �Լ� draw ����.
	virtual void draw() = 0;
};

// Hobbit Ŭ������ GameCharacter�� ��ӹ޾�
// draw �Լ��� ������.
class Hobbit : public GameCharacter {
public:
	void draw() {
		cout << "ȣ���� ȭ�鿡 �׸��ϴ�..." << endl;
	}
};

// Socerer Ŭ������ GameCharacter�� ��ӹ޾�
// draw �Լ��� ������.
class Socerer : public GameCharacter {
public:
	void draw() {
		cout << "�ּ��縦 ȭ�鿡 �׸��ϴ�..." << endl;
	}
};

int main(void) {

	// GameCharacter�� �θ� type�̹Ƿ�,
	// �����͸� �����Ͽ� �ڽ� Ŭ������ �ּҸ� ����Ű��
	// upcasting�� ���� draw()�� ���� ����.
	// �׷���, virtual method�̹Ƿ� �ڽ� Ŭ��������
	// ���ǵ� method�� ����ȴ�.
	GameCharacter* myCharacters[2];
	
	Hobbit h;
	Socerer s;

	myCharacters[0] = &h;
	myCharacters[1] = &s;
	
	// �ֱ��� ȣ���� ���ؼ� clock() �̿�.
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