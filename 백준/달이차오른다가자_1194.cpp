#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct info
{
    int r, c, cnt, key;
};

int N, M, ans = -1;
char arr[52][52];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
bool check[52][52][1 << 6];
queue<info> q;

int bfs()
{
    while (!q.empty())
    {
        int r = q.front().r;
        int c = q.front().c;
        int cnt = q.front().cnt;
        int k = q.front().key;
        q.pop();

        if (arr[r][c] == '1')
            return cnt;

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= N || nc >= M || nr < 0 || nc < 0)
                continue;
            if (check[nr][nc][k])
                continue;

            if (arr[nr][nc] == '.' || arr[nr][nc] == '1')
            {
                q.push({nr, nc, cnt + 1, k});
                check[nr][nc][k] = true;
            }
            else if ('a' <= arr[nr][nc] && arr[nr][nc] <= 'f')
            {
                int nk = k | (1 << (int(arr[nr][nc] - 'a')));
                q.push({nr, nc, cnt + 1, nk});
                check[nr][nc][nk] = true;
            }
            else if ('A' <= arr[nr][nc] && arr[nr][nc] <= 'F')
            {
                if (k & (1 << (int(arr[nr][nc] - 'A'))))
                {
                    q.push({nr, nc, cnt + 1, k});
                    check[nr][nc][k] = true;
                }
            }
        }
    }
    return -1;
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            scanf(" %c", &arr[i][j]);
            if (arr[i][j] == '0')
            {
                q.push({i, j, 0, 0});
                arr[i][j] = '.';
                check[i][j][0] = true;
            }
        }
    printf("%d", bfs());
    return 0;
}