#include <iostream>
#include <algorithm>

using namespace std;

int R, C, ans, sum = 1;
char arr[21][21];
bool check[26];
int dr[] = {0, 0, -1, 1};
int dc[] = {1, -1, 0, 0};

void dfs(int r, int c)
{
    check[arr[r][c] - 'A'] = true;
    ans = max(ans, sum);
    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr < 0 || nc < 0 || nc >= C || nr >= R)
            continue;
        if (!check[arr[nr][nc] - 65])
        {
            sum++;
            dfs(nr, nc);
            sum--;
            check[arr[nr][nc] - 65] = false;
        }
    }
}

int main()
{
    scanf("%d %d", &R, &C);
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            scanf(" %c", &arr[i][j]);
    dfs(0, 0);
    printf("%d", ans);
    return 0;
}