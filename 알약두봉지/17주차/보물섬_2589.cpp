#include <algorithm>
#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

char arr[51][51];
int check[51][51];

int N, M, ans, cnt;
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

void bfs(int r, int c)
{
    queue<pair<int, int>> q;
    q.push({r, c});
    while (!q.empty())
    {
        r = q.front().first;
        c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nc < 0 || nr >= N || nc >= M)
                continue;
            if (arr[nr][nc] == 'W')
                continue;
            if (check[nr][nc] == -1 || check[nr][nc] > check[r][c] + 1)
            {
                check[nr][nc] = check[r][c] + 1;
                cnt = max(cnt, check[nr][nc]);
                q.push({nr, nc});
            }
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf(" %c", &arr[i][j]);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] == 'L')
            {
                memset(check, -1, sizeof(check));
                cnt = 0;
                check[i][j] = 0;
                bfs(i, j);
                ans = max(cnt, ans);
            }
        }
    printf("%d", ans);
    return 0;
}