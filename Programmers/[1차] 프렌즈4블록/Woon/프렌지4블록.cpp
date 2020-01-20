#include <iostream>
#include <string>
#include <vector>

using namespace std;

char map[31][31];
bool visit[31][31];

bool m_check(int m, int n) {

	bool flag = false;
	for (int i = 0; i < m-1; i++) {
		for (int j = 0; j < n-1; j++) {

			char x = map[i][j];
			if (map[i][j] != ' ') {
				if (x == map[i][j + 1] && x == map[i + 1][j] && x == map[i + 1][j + 1]) {

					visit[i][j] = true;
					visit[i][j + 1] = true;
					visit[i + 1][j] = true;
					visit[i + 1][j + 1] = true;

					flag = true;
				}
			}
		}
	}	
	return flag;
}

void c_map(int m, int n) {

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == true) {
				map[i][j] = ' ';
			}
		}
	}
}

void down_map(int m, int n) {

	//�Ʒ��� ���� ���� �˻��ؾ��ϱ⿡ y����� ����

	for (int j = 0; j < n; j++) {
		int count = 0;
		for (int i = m - 1; i >= 0; i--) {

			if (map[i][j] == ' ') {
				count++;
			}
			else {

				if (count != 0) {
					map[i + count][j] = map[i][j];
					map[i][j] = ' ';
				}
			}
		}
	}
}

void init_visit() {
	for (int i = 0; i < 31; i++) {
		for (int j = 0; j < 31; j++) {
			visit[i][j] = false;
		}
	}
}

int solution(int m, int n, vector<string> board) {
	int answer = 0;

	//�� �ʱ�ȭ
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {

			map[i][j] = board[i][j];
			
		}
	}

	while (true) {

		// �翷�� , �밢�� ã��
		bool m_flag = false;
		m_flag = m_check(m, n);

		if (m_flag == false) {
			break;
		}
		// ���� ����� �ִٸ� map���� �����ֱ�
		c_map(m, n);

		// �� ������
		down_map(m, n);

		//�湮�迭�ʱ�ȭ
		init_visit();

	}

	// ���

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == ' ') {
				answer++;
			}
		}
	}

	return answer;
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//int m, n;
	//m = 4;
	//n = 5;
	//vector<string> v = { "CCBDE", "AAADE", "AAABF", "CCBBF" };
	//solution(m, n, v);

	int m1 = 6; int n1= 6;
	vector<string> v1 = {"TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"};
	cout << solution(m1,n1,v1);   

	
	return 0;
}