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

	// ������ id�� pw�� string���� ���� ���� �ȵƴµ�,
	// ������ �ȴ�... ������?
	// down casting���� ��, string ������ �����ϸ�
	// ���� �߻�?

	// loginApi->id = 1234;
	// loginApi->pw = 5678;
	loginApi->displayLoginInfo(); // �̷��� �����ϸ�, ���ʿ� ���� ��ü�� �ȵǾ������Ƿ� �̻��� ���� ����...
	// loginApi2->id = "id"; => ������ �Ұ���...?
	// loginApi2->pw = "pw";
	// cout << loginApi2->id << endl; // ������ ������ ���� ������, �ùٸ� ���� ������ ����.
	// cout << loginApi2->pw << endl; // �ֳĸ�, �̰��� ���� down casting�� �� ���̴�. 
	// ������ ����� ��ü�� HTTPApi�̹Ƿ�, LoginApi*�� ������ ����������,
	// �߸��� ������ �ϰԵȴ�...

	// down casting�� ���� ��, �߸��� �޸𸮿� �����ؼ� ���� �����ߴٸ�
	// delete�� �� �� ������ �߻��Ѵ�...
	delete loginApi; 
	// delete�� �ϰԵǸ�, ������ ������ ��ü�� HTTPApi�̹Ƿ�,
	// HTTPApi�� �Ҹ��ڸ� �Ҹ��� �ȴ�.

	//cout << loginApi2->id << endl;

	return 0;
}