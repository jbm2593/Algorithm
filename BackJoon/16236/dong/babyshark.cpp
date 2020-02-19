#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int dir_x[4] = {0,-1,1,0};
int dir_y[4] = {-1,0,0,1 };
typedef struct NODE {
	int x;
	int y;
	int cnt;
}node;
int n;
int arr[21][21];
bool visit_s[21][21];
int shark = 2;
int shark_eat = 0;
int result = 0;
vector<node> v;
bool desc(const node &a,const node &b) {
	if (a.cnt == b.cnt) {
		if (a.x == b.x) {
			return a.y < b.y;
		}
		else  {
			return a.x < b.x;
		}
	}
	else {
		return a.cnt < b.cnt;
	}
}
void reset_visit() { //�湮�ʱ�ȭ
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] > shark) {
				visit_s[i][j] = true;
			}
			else {
				visit_s[i][j] = false;
			}
		}
	}
}
void bfs(int nx,int ny,int ncnt) {
	int cx=0, cy = 0 ;
	queue<node> q;
	q.push({ nx,ny,ncnt });
	visit_s[nx][ny] = true;
	while (!q.empty()) {

		node nd = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x = nd.x + dir_x[i];
			int y = nd.y + dir_y[i];
			int cnt2 = nd.cnt + 1;

			if (x >= 0 && x < n && y >= 0 && y < n) {


				if (arr[x][y] > shark|| visit_s[x][y] == true) { //�湮���� ���ϴ°�
					continue;
				}
				if (arr[x][y] <= shark && visit_s[x][y] == false) { //���������ְų� ������ �ִ°�
					visit_s[x][y] = true;
					
					if (arr[x][y] != 0 && arr[x][y] != shark) {//��Ƶξ��ٰ� �����ؾ���(�켱���� ���ؼ�)
					
						q.push({ x,y,cnt2 });
						v.push_back({ x,y,cnt2 });
						
					}
					else 
					{
						q.push({ x,y,cnt2 });
					}

				}
			}
		}
	}
	if (v.size() == 0) {
		cout << result << '\n';
	}
	else {
		sort(v.begin(), v.end(), desc); //�켱���� ����

		shark_eat++; //���� Ƚ��
		result += v[0].cnt; //�����
		arr[v[0].x][v[0].y] = 0; //�������� ���������� 0����
		cx = v[0].x;
		cy = v[0].y;
		if (shark_eat == shark) {//���� Ƚ���� �������� Ƚ���ʱ�ȭ,���ũ�� ����
			shark++;
			shark_eat = 0;
		}
		reset_visit(); //ũ�Ⱑ �����ϸ� �湮�� �� �ִ°�üũ
		v.clear();
		bfs(cx,cy,0);
		
	}

}
int main() {
	int nx=0, ny=0, ncnt=0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				nx = i;
				ny = j;
				ncnt = 0;
				arr[i][j] = 0;
			}
		}
	}
	bfs(nx,ny,ncnt);
}