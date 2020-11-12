#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int T, M, N, K;
int arr[51][51];
int check[51][51];
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, -1, 1};

void dfs(int r, int c)
{
    check[r][c] = 1;

    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr < 0 || nr >= N || nc < 0 || nc >= M || !arr[nr][nc] || check[nr][nc])
            continue;
        dfs(nr, nc);
    }
}

void bfs(int r, int c)
{
    queue<pair<int, int>> q;
    q.push({r, c});
    check[r][c] = 1;

    while (!q.empty())
    {
        r = q.front().first;
        c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M || !arr[nr][nc] || check[nr][nc])
                continue;
            printf("=> %d %d\n", nr, nc);
            q.push({nr, nc});
            check[nr][nc] = 1;
        }
    }
}

int main()
{
    scanf("%d", &T);

    while (T--)
    {
        memset(arr, 0, sizeof(arr));
        memset(check, 0, sizeof(check));

        int cnt = 0;
        scanf("%d %d %d", &M, &N, &K);
        while (K--)
        {
            int n, m;
            scanf("%d %d", &m, &n);
            arr[n][m] = 1;
        }
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (arr[i][j] && !check[i][j])
                {
                    bfs(i, j);
                    cnt++;
                }
        printf("%d\n", cnt);
    }
    return 0;
}