#include <iostream>

using namespace std;

class REST {
public:
	virtual void get() = 0;
	virtual void post() = 0;
	virtual void del() = 0;
	virtual void update() = 0;
};

class HTTPApi : public REST {
protected:
	string main_address;

public:
	HTTPApi(string _addr) {
		cout << "HTTPApi Constructor\n";
		this->main_address = _addr;
	}
	virtual ~HTTPApi() {
		cout << "HTTPApi Destructor\n";
	}
	void get() {
		cout << "Get\n";
	}
	void post() {
		cout << "Post\n";
	}
	void del() {
		cout << "Delete\n";
	}
	void update() {
		cout << "Update\n";
	}
	void displayAddr() {
		cout << this->main_address << endl;
	}
};

class LoginApi : public HTTPApi {
public:
	LoginApi(string _addr, int _id, int _pw) : HTTPApi(_addr), id(_id), pw(_pw) {
		cout << "LoginApi Constructor\n";
	}
	virtual ~LoginApi() {
		cout << "LoginApi Destructor\n";
	}
	void displayLoginInfo() {
		HTTPApi::displayAddr();
		cout << "ID : " << id << endl;
		cout << "PW : " << pw << endl;
	}

	int id = 1234;
	int pw = 5678;
};

int main(void) {

	/*LoginApi loginApi("www.main.com", "inujdk", "201901768");

	REST* rest = &loginApi;
	rest->get();
	rest->post();
	rest->del();
	rest->update();

	loginApi.displayAddr();
	cout << "\n";
	loginApi.displayLoginInfo();

	HTTPApi* httpApi = &loginApi;
	httpApi->displayAddr();*/

	/*LoginApi* loginApi = new LoginApi("www.main.com", 1234, 5678);
	cout << "\n\n\n";

	loginApi->displayLoginInfo();

	cout << "\n\n\n";
	delete loginApi;*/

	HTTPApi* httpApi = new HTTPApi("www.new.com");
	// httpApi->displayAddr();

	LoginApi* loginApi = (LoginApi*)httpApi;

	// 이전에 id와 pw를 string으로 했을 때는 안됐는데,
	// 지금은 된다... 이유는?
	// down casting했을 때, string 변수에 접근하면
	// 에러 발생?

	// loginApi->id = 1234;
	// loginApi->pw = 5678;
	loginApi->displayLoginInfo(); // 이렇게 실행하면, 애초에 선언 자체가 안되어있으므로 이상한 값이 나옴...
	// loginApi2->id = "id"; => 접근이 불가능...?
	// loginApi2->pw = "pw";
	// cout << loginApi2->id << endl; // 변수에 접근은 가능 하지만, 올바른 값이 나오지 못함.
	// cout << loginApi2->pw << endl; // 왜냐면, 이것은 지금 down casting을 한 것이다. 
	// 실제로 선언된 객체는 HTTPApi이므로, LoginApi*로 접근이 가능하지만,
	// 잘못된 참조를 하게된다...

	// down casting을 했을 때, 잘못된 메모리에 접근해서 값을 수정했다면
	// delete를 할 때 오류가 발생한다...
	delete loginApi; 
	// delete를 하게되면, 실제로 생성된 객체는 HTTPApi이므로,
	// HTTPApi의 소멸자만 불리게 된다.

	//cout << loginApi2->id << endl;

	return 0;
}