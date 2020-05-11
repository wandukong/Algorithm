#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;
int dr[4] = { 0,1, -1, 0 };
int dc[4] = { 1,0, 0 , -1 };

int N;
int check[26][26];

struct p {
	int row; // 행
	int col; // 열
	int dir; //이전 방향 0 : 오른쪽, 아래쪽, 위쪽, 왼쪽
	int cost; // 가격
};

void bfs(vector<vector<int>> v, int r, int c) {
	check[r][c] = 0;
	queue<p> q;
	q.push({ r, c, 4, 0 });

	while (!q.empty()) {
		int r = q.front().row;
		int c = q.front().col;
		int k = q.front().cost;
		int d = q.front().dir;
		q.pop();

		check[r][c] = check[r][c] == 0 ? k : min(check[r][c], k);
		printf("====================================================================\n");
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				printf("%3d ", check[i][j]);
			}
			printf("\n");
		}

		
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (0 > nr || nr >= N || 0 > nc || nc >= N || v[nr][nc]) continue;

			int nk = k;

			if (!check[nr][nc]) {
				if (d == i || d == 4) q.push({ nr, nc, i, nk + 1 });
				else q.push({ nr, nc, i, nk + 6 });
			}
			else if (check[nr][nc] > check[r][c] + 1 && d == i ) {
				q.push({ nr, nc, i, nk + 1 });
			}
			else if (check[nr][nc] > check[r][c] + 6 && d != i) {
				q.push({ nr, nc, i, nk + 6 });
			}
		}
	}
}

int main() {

	vector<vector<int>> board = {{ 0, 0, 0, 0, 0, 0 }, { 0, 1, 1, 1, 1, 0 }, { 0, 0, 1, 0, 0, 0 }, { 1, 0, 0, 1, 0, 1 }, { 0, 1, 0, 0, 0, 1 }, { 0, 0, 0, 0, 0, 0 }};

	N = board.size();
	bfs(board, 0, 0);

	printf("%d\n", check[N - 1][N - 1]);

	return 0;
}