#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

int main(void) {

	srand(time(NULL));

	// vector�� 100���� ���� �ֱ� ����
	// vector�� resize�Ѵ�.
	vector<int> vect;
	vect.resize(100);

	// random�ϰ� ���� �����Ѵ�.
	for (int i = 0; i < 100; i++) {
		vect[i] = rand() % 100;
	}

	// count_if�� �̿��ؼ� vector even�� ���ҵ� ��
	// ¦���� ���� ������ ����.
	// ���ٽ��� �̿��Ѵ�.
	int even = count_if(vect.begin(), vect.end(),
		[](int _x) {
		return (_x % 2 == 0);
	});

	cout << "���� ¦���� ����� ����: " << even << endl;

	return 0;
}