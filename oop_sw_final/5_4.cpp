#include <iostream>
#include <ctime>

#define INTERVAL 1

using namespace std;

// GameCharacter 부모 클래스 정의
class GameCharacter {
public:
	GameCharacter() {}
	// 순수 가상 함수 draw 선언.
	virtual void draw() = 0;
};

// Hobbit 클래스는 GameCharacter를 상속받아
// draw 함수를 정의함.
class Hobbit : public GameCharacter {
public:
	void draw() {
		cout << "호빗을 화면에 그립니다..." << endl;
	}
};

// Socerer 클래스는 GameCharacter를 상속받아
// draw 함수를 정의함.
class Socerer : public GameCharacter {
public:
	void draw() {
		cout << "주술사를 화면에 그립니다..." << endl;
	}
};

int main(void) {

	// GameCharacter는 부모 type이므로,
	// 포인터를 선언하여 자식 클래스의 주소를 가리키면
	// upcasting을 통해 draw()를 실행 가능.
	// 그런데, virtual method이므로 자식 클래스에서
	// 정의된 method가 실행된다.
	GameCharacter* myCharacters[2];
	
	Hobbit h;
	Socerer s;

	myCharacters[0] = &h;
	myCharacters[1] = &s;
	
	// 주기적 호출을 위해서 clock() 이용.
	while (1) {

		for (auto& _e : myCharacters) {
			_e->draw();
		}
		
		clock_t start = clock();

		// 주기적으로 호출
		while (1) {
			clock_t end = clock();

			if (double(end - start) / CLOCKS_PER_SEC == INTERVAL) {
				break;
			}
		}
	}

	return 0;
}