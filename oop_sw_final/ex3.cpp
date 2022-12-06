#include <iostream>
#include <map>
#include <algorithm>
#include <random>

using namespace std;

int main() {

    default_random_engine gen;
    uniform_int_distribution<int> dis(0, 2);

    int select = 0;
    map<string, string> dic; // make words dictionary

    dic["evening"] = "����"; // key : value
    dic["morning"] = "��ħ";
    dic["afternoon"] = "����";

    vector<string> words; // words vector

    for (auto& v : dic) {
        words.push_back(v.first);
    }

    vector<string> answer; // answer vector
    answer.push_back("��ħ");
    answer.push_back("����");
    answer.push_back("����");

    while (1) {
        int sel;

        string Q = words.at(dis(gen));
        cout << Q << "�� �ǹ̴�? ";
        cout << "(1)��ħ(2)����(3)����\n";
        cout << "��ȣ�� �����Ͻÿ�: ";
        cin >> sel;
        --sel;

        if (dic[Q] == answer.at(sel)) { // check if key and value is pair
            cout << "�¾ҽ��ϴ�.\n";
        }
        else {
            cout << "Ʋ�Ƚ��ϴ�.\n";
        }
    }

    return 0;
}