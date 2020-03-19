#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;



vector<int> key;


bool check(int num) {
    int size = key.size();
    for (int i = 0; i < size; i++) {
        if ((key[i] & num) == key[i]) {
            return false;
        }
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;

    int row = relation[0].size();
    int col = relation.size();


    //��Ʈ����ŷ���� ���� �� �ִ� ���� �����
    //�ĺ�Ű �̱� ( ���ϼ� ���� )
    for (int i = 1; i < (1 << row); i++) {
        vector<int> v;
        set<string> group;
        for (int j = 0; (1 << j) <= i; j++) {
            if (i & (1 << j)) {
                v.push_back(j);
            }
        }

        int size = v.size();
        for (int j = 0; j < col; j++) {
            string s = "";
            for (int k = 0; k < size; k++) {

                s = s + relation[j][v[k]];

            }
            group.insert(s);
        }

        int len = group.size();
        if (len == col) {
            if (check(i) == true) {
                key.push_back(i);
            }
        }
    }

    answer = key.size();

    return answer;
}

int main() {

    vector<vector<string>> relation = {

        {"100","ryan","music","2"},
        {"200","apeach","math","2"},
        {"300","tube","computer","3"},
        {"400","con","computer","4"},
        {"500","muzi","music","3"},
        {"600","apeach","music","2" }
    };


    solution(relation);

    return 0;
}