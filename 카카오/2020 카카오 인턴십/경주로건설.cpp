#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;
int dr[4] = {0, 1, -1, 0};
int dc[4] = {1, 0, 0, -1};

int N, answer = 987654321;

struct p
{
	int row;  // 행
	int col;  // 열
	int dir;  //이전 방향 0 : 오른쪽, 아래쪽, 위쪽, 왼쪽
	int cost; // 가격
};

void bfs(vector<vector<int>> v)
{
	N = v.size();
	v[0][0] = 1;
	queue<p> q;
	q.push({0, 0, 4, 0});

	while (!q.empty())
	{
		int r = q.front().row;	// 행
		int c = q.front().col;	// 열
		int d = q.front().dir;	// 이전 방향
		int k = q.front().cost; // 가격
		q.pop();

		if (r == N - 1 && c == N - 1)
		{
			if (answer > k)
				answer = k;
			continue;
		}

		for (int i = 0; i < 4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (0 > nr || nr >= N || 0 > nc || nc >= N || v[nr][nc] == 1)
				continue;

			int nk = k;

			if (d == i || d == 4)
				nk += 1;
			else if (d != i)
				nk += 6;

			if (v[nr][nc] == 0 || v[nr][nc] >= nk)
			{
				v[nr][nc] = nk;
				q.push({nr, nc, i, nk});
			}
		}
	}
}

int main()
{

	vector<vector<int>> board = {{0, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 1, 0}, {0, 0, 1, 0, 0, 0}, {1, 0, 0, 1, 0, 1}, {0, 1, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0}};

	bfs(board);

	printf("%d\n", answer * 100);

	return 0;
}