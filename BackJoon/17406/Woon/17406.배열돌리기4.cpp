#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct NODE {
    int r;
    int c;
    int s;
}node;

int map[51][51];
int init_map[51][51];
int tmp_map[51][51];

vector<node> v;
vector<int> index;

void m_init(int n, int m) {
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            init_map[i][j] = map[i][j];
            tmp_map[i][j] = map[i][j];
        }
    }

}

void change_tmpmap(int n, int m) {

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            tmp_map[i][j] = init_map[i][j];
        }
    }
}


void rotate(int r, int c, int s) {

    int start_x = r - s; // 1
    int end_x = r + s; // 5
    int start_y = c - s; // 2
    int end_y = c + s; // 6

    while (true) {

        if (start_x > end_x) {
            break;
        }

        //���ʿ��� ������
        for (int i = start_y; i < end_y; i++) {
            init_map[start_x][i + 1] = tmp_map[start_x][i];
        }

        // ������ �Ʒ���
        for (int i = start_x; i < end_x; i++) {
            init_map[i + 1][end_y] = tmp_map[i][end_y];
        }

        //�����ʿ��� ����
        for (int i = end_y; i > start_y; i--) {
            init_map[end_x][i - 1] = tmp_map[end_x][i];
        }

        //�Ʒ����� ����
        for (int i = end_x; i > start_x; i--) {
            init_map[i - 1][start_y] = tmp_map[i][start_y];
        }

        start_x = start_x + 1;
        end_x = end_x - 1;
        start_y = start_y + 1;
        end_y = end_y - 1;

    }
}

int row_sum(int n, int m) {

    int ans = 210000000;
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= m; j++) {
            sum = sum + init_map[i][j];
        }

        if (ans > sum) {
            ans = sum;
        }
    }
    return ans;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
            tmp_map[i][j] = map[i][j];
        }
    }

    for (int i = 0; i < k; i++) {
        int r, c, s;
        cin >> r >> c >> s;

        v.push_back({ r,c,s });
        //next_permutation�� ���� ���ؼ� �ش� �迭�� �ε��� �迭�� ���� �������
        index.push_back(i);
    }
    
    int size = index.size();
    int result = 0;
    int r_min = 210000000;

    do {

        m_init(n, m);


        for (int i = 0; i < size; i++) {
            node now = v[index[i]];
            rotate(now.r, now.c, now.s);
            change_tmpmap(n, m);
        }

        result = row_sum(n, m);
        if (r_min > result) {
            r_min = result;
        }


    } while (next_permutation(index.begin(), index.end()));



    cout << r_min;
    return 0;
}