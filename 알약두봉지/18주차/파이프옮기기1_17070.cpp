#include <iostream>
#include <algorithm>

using namespace std;

int N, arr[17][17], ans;
int dr[] = {0, 1, 1};
int dc[] = {1, 0, 1};

void dfs(int r, int c)
{

    if (r == N - 1 && c == N - 1)
    {
        ans++;
        return;
    }

    if (arr[r][c] == 2) // 현재 파이프 가로
    {
        for (int i = 0; i < 3; i++)
        {
            if (i == 1)
                continue;
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nc < 0 || nr >= N || nc >= N)
                continue;
            if (i == 2 && (arr[nr][nc - 1] != 0 || arr[nr - 1][nc] != 0))
                continue;
            if (arr[nr][nc] == 0)
            {
                arr[nr][nc] = i + 2;
                if (i == 3)
                    arr[nr][nc - 1] = arr[nr - 1][nc] = 1;
                dfs(nr, nc);
                arr[nr][nc] = 0;
                if (i == 3)
                    arr[nr][nc - 1] = arr[nr - 1][nc] = 0;
            }
        }
    }
    else if (arr[r][c] == 3) // 현재 파이프 세로
    {
        for (int i = 0; i < 3; i++)
        {
            if (i == 0)
                continue;
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nc < 0 || nr >= N || nc >= N)
                continue;
            if (i == 2 && (arr[nr][nc - 1] != 0 || arr[nr - 1][nc] != 0))
                continue;
            if (arr[nr][nc] == 0)
            {
                arr[nr][nc] = i + 2;
                if (i == 3)
                    arr[nr][nc - 1] = arr[nr - 1][nc] = 1;
                dfs(nr, nc);
                arr[nr][nc] = 0;
                if (i == 3)
                    arr[nr][nc - 1] = arr[nr - 1][nc] = 0;
                arr[nr][nc] = 0;
            }
        }
    }
    else if (arr[r][c] == 4) // 현재 파이프 대각선
    {
        for (int i = 0; i < 3; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nc < 0 || nr >= N || nc >= N)
                continue;
            if (i == 2 && (arr[nr][nc - 1] != 0 || arr[nr - 1][nc] != 0))
                continue;
            if (arr[nr][nc] == 0)
            {
                arr[nr][nc] = i + 2;
                if (i == 3)
                    arr[nr][nc - 1] = arr[nr - 1][nc] = 1;
                dfs(nr, nc);
                arr[nr][nc] = 0;
                if (i == 3)
                    arr[nr][nc - 1] = arr[nr - 1][nc] = 0;
                arr[nr][nc] = 0;
            }
        }
    }
    return;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &arr[i][j]);

    arr[0][1] = 2;
    dfs(0, 1);
    printf("%d", ans);
    return 0;
}