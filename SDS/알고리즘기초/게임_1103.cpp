#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int N, M, ans;
char arr[51][51];
int chk[51][51];
bool chk2[51][51];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

void dfs(int r, int c, int cnt)
{
    ans = max(cnt, ans);
    if (r < 0 || c < 0 || r >= N || c >= M || arr[r][c] == 'H')
        return;
    if (chk2[r][c])
    {
        printf("-1");
        exit(0);
    }
    if (cnt <= chk[r][c])
        return;
    chk[r][c] = cnt;
    chk2[r][c] = true;
    for (int i = 0; i < 4; i++)
        dfs(r + dr[i] * (arr[r][c] - '0'), c + dc[i] * (arr[r][c] - '0'), cnt + 1);
    chk2[r][c] = false;
}

int main()
{
    scanf("%d %d", &N, &M);
    memset(chk, -1, sizeof(chk));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf(" %c", &arr[i][j]);
    dfs(0, 0, 0);
    printf("%d", ans);
    return 0;
}