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

    dic["evening"] = "저녁"; // key : value
    dic["morning"] = "아침";
    dic["afternoon"] = "점심";

    vector<string> words; // words vector

    for (auto& v : dic) {
        words.push_back(v.first);
    }

    vector<string> answer; // answer vector
    answer.push_back("아침");
    answer.push_back("점심");
    answer.push_back("저녁");

    while (1) {
        int sel;

        string Q = words.at(dis(gen));
        cout << Q << "의 의미는? ";
        cout << "(1)아침(2)점심(3)저녁\n";
        cout << "번호를 선택하시오: ";
        cin >> sel;
        --sel;

        if (dic[Q] == answer.at(sel)) { // check if key and value is pair
            cout << "맞았습니다.\n";
        }
        else {
            cout << "틀렸습니다.\n";
        }
    }

    return 0;
}