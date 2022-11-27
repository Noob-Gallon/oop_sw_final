#include <iostream>

using namespace std;

class Parent {
public:
	Parent() {
		cout << "Parent Constructor\n";
		this->p = 1;
	}
	virtual ~Parent() {
		cout << "Parent Destructor\n";
	}
	void show() {
		cout << "Parent\n";
	}
	int p;
};

class Child : public Parent {
public:
	Child() {
		cout << "Child Constructor\n";
		this->c = 2;
	}
	virtual ~Child() {
		cout << "Child Constructor\n";
	}
	void show() {
		cout << "Child\n";
	}
	void showC() {
		cout << "this->c : " << this->c << endl;
	}
	int c;
};

int main(void) {

	// -------------------------------------------------------------------------------- //

	// upcasting.
	// 이 경우에는 소멸자에 virtual을 선언해주지 않으면
	// Parent 타입 포인터이므로, 자식 클래스의 메모리가 지워지지 않음...
	// 오류 발생!!!
	Parent* p = new Child();
	p->show();
	// cout << p->c << endl; p는 Child의 메모리에는 접근 불가능. 따라서, c 출력 불가!
	cout << p->p << endl;
	delete p; // child, parent

	// -------------------------------------------------------------------------------- //
	cout << "\n\n\n";

	// down casting.
	// Child* c = new Parent(); 이렇게 직접적으로 down casting은 불가능.
	Parent* p2 = new Parent(); // Parent type pointer를 만들고,
	Child* c2 = (Child*)p2; // Child*로 type casting해서 c에 전달해줌...
	cout << c2->p << endl; // 얘는 합법.
	cout << c2->c << endl; // 그러나, 얘는 가능하지만, 사실상 불법임. 왜냐면, 생성되기를 근본이 Parent()인데, c는 자기 영역이 아님.
	c2->showC();
	// 그렇다면, show()는 왜 가능한 것인가???
	c2->Parent::show();
	c2->show(); // 얘는 왜 가능한 것일까?
	
	// c2->c = 100; // 가능함. 하지만 위에서 봤듯이, 실제 클래스의 메모리 영역이 아닌 곳을 건드리는 것임.
	// cout << c2->c << endl;
	// pointer type이 Child이므로, virtual은 동작하지 않는다.
	// 단, 이건 가능할듯?
	
	delete c2; // Child type pointer로 가리키고 있지만, 실제로 할당된 메모리는 Parent 밖에 없어서, Parent destructor만 불린다...
	// Parent

	// -------------------------------------------------------------------------------- //
	cout << "\n\n\n";

	Parent* p3 = new Parent();
	Child* c3 = dynamic_cast<Child*>(p3); // 위의 예제에서 봤듯이, 이렇게 casting을 하면
	// 실제로는 Parent의 메모리만 참조가 가능하지만, Child의 메모리에 참조를 하게 되면서
	// 에러가 발생할 가능성이 높으므로, nullptr을 반환한다...

	// Parent type을 Child로 casting하는 것은
	// 오류를 발생시킬 가능성이 높으므로,
	// dynamic_cast 에서는 nullptr을 반환한다...

	if (c3 == nullptr) {
		cout << "Error!\n";
	}
	else {
		delete c3;
	}

	// -------------------------------------------------------------------------------- //
	cout << "\n\n\n";

	// 따라서, dynamic casting은 이와 같이 해주어야 한다.
	Parent* p4 = new Child(); // 이건 합법. upcasting...
	// p4->showC(); 아무리 Child로 upcasting을 했다고 해도,
	// Child의 메모리 영역에 Parent type으로 직접 접근은 불가능함...

	Child* c4 = dynamic_cast<Child*>(p4); 
	// Parent* p4를 Child* 로 바꿔줌.
	// 이전의 경우에는 Parent* p = new Parent() 일 때 Child*로 casting을 시도했는데,
	// 이렇게 하면 잘못된 주소에 접근할 확률이 높으므로, nullptr을 반환한다.
	// 하지만 이번 경우에는 p4가 Parent*이지만, Child()를 가리키고 있으므로,
	// Child()의 고유한 메모리에는 접근이 불가능하지만, Child() 내에 선언된
	// Parent()의 메모리에는 접근이 가능한 경우이다.
	// 이 경우에, p4를 Child*로 down casting해주면, casting이 가능하다...

	// 이렇게 하면, 실제로 Child 객체가 모두 만들어진다.
	// 그런데 궁금한 것은... 이렇게 할거면 그냥 Child 객체를 만들어버리면 되는것 아닐까?
	// dynamic_cast가 필요한 경우를 생각해본다면...?
	c4->show(); // Child* 이므로, Child가 나온다.
	c4->showC(); // Child instance이므로, c에 접근 가능. 2
	cout << c4->c << endl; // 당연히 c 접근 가능. 2

	delete c4; // Child -> Parent 순으로 destructor 호출됨.

	// -------------------------------------------------------------------------------- //
	cout << "\n\n\n";

	// static cast, upcasting...
	// Child type을 Parent type으로 casting해서
	// Parent type 포인터로 가리킬 수 있게 함.
	Child* c5 = new Child();
	Parent* p5 = static_cast<Parent*>(c5);

	// p5는 Parent이므로, Child 객체로 선언되었다고는 하지만,
	// 실제 c에는 접근할 수 없을 것.
	// p5->c = 10; 불러올 수 없음.

	p5->show(); // Parent
	// 만약 show를 virtual로 바꾼다면, Child가 나옴.

	delete p5; // destructor가 virtual이므로, Child -> Parent가 불림.
	return 0;
}