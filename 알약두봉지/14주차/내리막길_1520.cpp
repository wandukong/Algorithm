#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int N, M, arr[501][501], check[501][501];
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

int dfs(int r, int c)
{
    if (r == N - 1 && c == M - 1)
        return 1;
    else if (check[r][c] == -1)
    {
        check[r][c] = 0;
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= N || nc >= M || nr < 0 || nc < 0)
                continue;
            if (arr[nr][nc] >= arr[r][c])
                continue;
            check[r][c] += dfs(nr, nc);
        }
    }
    return check[r][c];
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%d", &arr[i][j]);
    memset(check, -1, sizeof(check));
    printf("%d", dfs(0, 0));
    return 0;
}