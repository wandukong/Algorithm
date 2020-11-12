#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int N, cnt, ans = 987654321;

int arr[101][101];
int check[101][101];
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, -1, 1};

void init(int r, int c)
{
    check[r][c] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr < 0 || nc < 0 || nr >= N || nc >= N || !arr[nr][nc] || check[nr][nc])
            continue;
        arr[nr][nc] = cnt;
        init(nr, nc);
    }
}

void dfs(int r, int c)
{
    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr < 0 || nc < 0 || nr >= N || nc >= N)
            continue;

        if (arr[nr][nc] == 0)
        {
            if (!check[nr][nc] || check[nr][nc] > check[r][c] + 1)
            {
                check[nr][nc] = check[r][c] + 1;
                dfs(nr, nc);
            }
        }
        else if (arr[nr][nc] != cnt)
        {
            if (check[r][c] < ans)
            {
                printf("%d %d => %d\n", nr, nc, check[r][c]);
                ans = check[r][c];
            }
        }
    }
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &arr[i][j]);

    cnt = 1;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (arr[i][j] && !check[i][j])
            {
                arr[i][j] = cnt;
                init(i, j);
                cnt++;
            }
    memset(check, 0, sizeof(check));

    printf("\n\n");

    // dfs(2, 0);

    // for (int k = 0; k < N; k++)
    // {
    //     for (int l = 0; l < N; l++)
    //     {
    //         printf("%d ", check[k][l]);
    //     }
    //     printf("\n");
    // }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (arr[i][j])
            {
                ans = 987654321;
                printf("==========%d %d==========\n", i, j);
                cnt = arr[i][j];
                dfs(i, j);
                memset(check, 0, sizeof(check));
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}