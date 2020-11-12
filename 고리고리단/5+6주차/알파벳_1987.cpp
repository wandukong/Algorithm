#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int N, M, ans;
char arr[21][21];
int alphabet[26];
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, -1, 1};

void dfs(int r, int c, int cnt)
{
    ans = ans < cnt ? cnt : ans;
    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr < 0 || nc < 0 || nr >= N || nc >= M || alphabet[arr[nr][nc] - 65])
            continue;
        alphabet[arr[nr][nc] - 65] = 1;
        dfs(nr, nc, cnt + 1);
        alphabet[arr[nr][nc] - 65] = 0;
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf(" %c", &arr[i][j]);
    alphabet[arr[0][0] - 65] = 1;
    dfs(0, 0, 1);
    printf("%d\n", ans);
    return 0;
}