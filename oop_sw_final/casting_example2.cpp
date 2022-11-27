#include <iostream>

using namespace std;

class Parent {
public:
	int p;

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
};

class Child : public Parent{
public:
	int c;

	Child() {
		cout << "Child Constructor\n";
		this->c = 2;
	}
	virtual ~Child() {
		cout << "Child Destructor\n";
	}
	void show() {
		cout << "Child\n";
	}
};

int main(void) {

	// 1. upcasting
	Parent* p = new Child();
	p->show(); // Parent, virtual을 붙인다면 Child...

	delete p;

	// ----------------------------------------------------------- //
	cout << "\n\n\n";

	// 2. down casting
	// Child* c = new Parent(); // 불가능. Child*에 Parent를 그냥 넣을 수는 없음.
	Parent* p2 = new Parent();
	Child* c = (Child*)p2; // 이런 방식으로 down casting 가능.
	// 하지만, 이 방식을 이용하면 잘못된 주소에 접근하게 될 수 있음.
	// 왜냐면, 실제로 Child 객체가 만들어진 것이 아니므로 
	// Child의 고유한 메모리 영역이 잡히지 않았음. 따라서 접근하면 이상한 영역임.

	// *********************************************************************** //
	// c->show(); 문제는, 이렇게 하면 Child가 나온다는거... 이건 왠지 모르겠음.//
	// *********************************************************************** //
	cout << "???\n";
	c->Parent::show();
	c->show(); 
	// c는 Child type이므로 당연히, override된 함수에 접근하게 된다.
	// 이것을 불러올 수 있는 이유는, 그냥 class의 형식 자체는 메모리 어딘가에 등록되어 있으므로
	// 그곳에서 불러오기 때문에 문제가 없는 것인가???...

	cout << "p : " << c->p << endl; // Parent 메모리 영역에 접근.
	cout << "c : " << c->c << endl; // 잘못된 접근. 왜냐면, Child 영역은 객체가 만들어지지 않았음.

	delete p2;
	// delete c;
	// delete는 둘중 아무거나 해도 문제는 없음. 가리키는 주소가 같기 때문...
	// 실제로 만들어진 객체는 Parent 뿐이므로, destructor는 Parent의 destructor만 불린다.

	// ----------------------------------------------------------- //
	cout << "\n\n\n";

	// 3. dynamic_cast 이용한 down casintg, 잘못된 경우.
	Parent* p3 = new Parent();
	Child* c3 = dynamic_cast<Child*>(p3); // Parent(superclass)를 Child(subclass)로 downcasting 시도.
	// 그런데, 이렇게 하는 것은 사실은 2번 예제와 같은 내용임.
	// 하지만, dynamic_cast를 이용하면 이 방식이 오류를 발생시킬 가능성이 높다고 판단하여
	// c3에 nullptr을 반환함...

	// 다시 한 번 예를 들자면, c3->c 를 할 경우, 이상한 메모리 위치를 참조하게 되는 것임...
	// 실제로 클래스의 영역으로 할당되지 않은 구역을 건드리는 것.

	if (c3 == nullptr) {
		cout << "c3 == nullptr!\n";
		delete p3;
	}
	else {
		delete c3;
	}

	// ----------------------------------------------------------- //
	cout << "\n\n\n";

	// 4. dynamic_cast 이용한 down casting, 올바른 경우.

	Parent* p4 = (Parent*)new Child(); // down casting으로 인해 잘못된 참조를 하는 일이 없으려면,
	// 이와 같이 Child() 객체를 선언해서 애초에 참조 가능한 구역으로 만들어버려서
	// down casting을 진행해야만 한다...
	// 실제로는 Child 클래스의 모든 메모리 영역이 잡혀있지만, Parent*로는 Child 영역에 접근할 수 없음.
	// down casting을 진행하면 접근할 수 있게 된다... (새로운 포인터를 통해서)
	p4->show(); // 현재 포인터는 Parent type이므로, show()는 Parent를 출력한다.
	// 만약, show()가 virtual이라면, Child를 출력할 것이다...

	Child* c4 = dynamic_cast<Child*>(p4);
	c4->show(); // 현재 포인터는 Child type이므로, show()는 Child를 출력한다.

	delete c4; // Child -> Parent

	// ----------------------------------------------------------- //
	cout << "\n\n\n";

	// 5. static_cast 이용한 up_casting.

	Child* c5 = new Child(); // 얘를 upcasting할 겁니다.
	Parent* p5 = static_cast<Parent*>(c5);
	p5->show(); // 당연히, Parent.
	
	delete p5; // Child -> Parent

	// ----------------------------------------------------------- //
	cout << "\n\n\n";

	return 0;
}