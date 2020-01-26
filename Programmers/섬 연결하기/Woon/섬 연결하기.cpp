#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int parent[101];

void init_parent() {
	for (int i = 0; i < 101; i++) {
		parent[i] = i;
	}
}

int Find(int a) {

	if (a == parent[a]) {
		return a;
	}
	else {
		return parent[a] =  Find(parent[a]);
	}
}


void Union(int x, int y) {

	x = Find(x);
	y = Find(y);

	if (x != y) {
		parent[y] = x;
	}

}

// ���� �����ϰ�������� Ÿ��
bool cmp(const vector<int> &x, const vector<int> &y) {
	return x[2] < y[2];
}


int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	init_parent();

	// ������������ ����ġ ����
	sort(costs.begin(), costs.end(), cmp);

	int size = costs.size();
	
	// ���ĵ� ���� �����ϰ�, �θ�迭�� ����Ŭ�� �ִ��������� �Ǻ�,
	// �Ǻ������� ����Ŭ�� ���ٸ� Union�� ���� ��������ְ�, ����ġ + �����ֱ�

	for (int i = 0; i < size; i++) {

		if (Find(costs[i][0]) != Find(costs[i][1])) {
			Union(costs[i][0], costs[i][1]);
			answer = answer + costs[i][2];
		}
	}

	return answer;
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	vector<vector<int>> costs = {

		{0,1,1},
		{0,2,2},
		{1,2,5},
		{1,3,1},
		{2,3,8}
	};

	cout << solution(4, costs);
	return 0;
}