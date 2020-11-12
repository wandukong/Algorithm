#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int arr[101][101];
int check[101][101];

int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, -1, 1};

void dfs(int r, int c)
{

    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr < 1 || nr > N || nc < 1 || nc > M || !arr[nr][nc])
            continue;

        if (!check[nr][nc] || check[nr][nc] > check[r][c] + 1)
        {
            check[nr][nc] = check[r][c] + 1;
            dfs(nr, nc);
        }
    }
}

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

            if (nr < 1 || nr > N || nc < 1 || nc > M || !arr[nr][nc])
                continue;

            if (!check[nr][nc] || check[nr][nc] > check[r][c] + 1)
            {
                check[nr][nc] = check[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            scanf("%1d", &arr[i][j]);
    check[1][1] = 1;
    //dfs(1, 1);
    bfs(1, 1);
    printf("%d\n", check[N][M]);
    return 0;
}